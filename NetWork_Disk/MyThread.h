/*************************************************************************
	> File Name: MyThread.h
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时37分02秒
 ************************************************************************/

#ifndef _MYTHREAD_H
#define _MYTHREAD_H

#include "Task.h"
#include <thread>

class MyThreadPool;
class Task;

class MyThread
{

	friend bool operator==(MyThread my1, MyThread my2);
	friend bool operator!=(MyThread my1, MyThread my2);
public:
    //构造函数，将与一个 线程池 关联
	MyThread(MyThreadPool *pool);

    //将线程与一个 任务 关联
	void Assign(Task *Task);

    /*
     * 调用task 的 run方法，同时在Task的Run()方法结束后将自己
     * 从工作工作容器 移会 空闲容器
     */
	void Run();

    /*
     * 执行线程的Run方法，即执行任务的Run方法
     */
	void StartThread();

    /*
     * 获取线程的id号
     */
	int getthreadid();

    /*
     * 设置线程在运行时是join还是detach
     */
	void setisdetach(bool isdetach);	
private:
	MyThreadPool *mythreadpool_; //指向关联的线程池
	static int  s_threadnumber;  
	bool isdetach_;
	Task *task_;                //关联的任务
	int threadid_;              //线程id
    std::thread thread_;
};




#endif
