/*
    TODO: finish class implementation and write functions
*/

#include "../include/RobotThread.h"


RobotThread::RobotThread(int argc, char **pArgv, const char *topic) 
    :   m_Init_argc(argc),
        m_pInit_argv(pArgv),
        m_topic(topic)
{
    /* Constructor for the robot thread */
}

RobotThread::~RobotThread()
{
    if (ros::isStarted())
    {
        ros::shutdown();
        ros::waitForShutdown();
    }

    m_pThread->wait();
}


bool RobotThread::init() 
{
    m_pThread = new QThread;
    this->moveToThread(m_pThread);

    connect(m_pThread, &QThread::started, this, &RobotThread::run);

    ros::init(m_Init_argc, m_pInit_argv, m_topic);

    if (!ros::master::check())
    {
        return false;
    }

    ros::NodeHandle nh;

    m_publisher = nh.advertise<std_msgs::String>("chatter", 1000);

    m_pThread->start();
    
    return true;
}

void RobotThread::run() 
{
    ros::Rate loop_rate(10);
    QMutex *pMutex;

    int count {0};

    while (ros::ok())
    {
        pMutex = new QMutex();

        pMutex->lock();

        std_msgs::String msg;
        std::stringstream ss;

        ss << "Hello world! " << count << "\n";
        msg.data = ss.str();
        ++count;

        pMutex->unlock();

        m_publisher.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();

        delete pMutex;
    }
}

