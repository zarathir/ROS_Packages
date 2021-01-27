#ifndef __ROBOTTHREAD_H__
#define __ROBOTTHREAD_H__

#include <iostream>

#include <QtCore>
#include <QThread>
#include <QStringList>
#include <QMutex>

#include "ros/ros.h"
#include "ros/network.h"
#include "std_msgs/String.h"

class RobotThread : public QObject{
    Q_OBJECT

public:
    RobotThread(int argc, char **pArgv, const char *topic);
    virtual ~RobotThread();

    bool init();

public slots:
    void run();


private:
    int m_Init_argc;
    char **m_pInit_argv;
    const char *m_topic;

    QThread *m_pThread;

    ros::Subscriber m_listener;
    ros::Publisher m_publisher;

};


#endif // __ROBOTTHREAD_H__