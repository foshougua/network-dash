/*************************************************************************
	> File Name: MyThreadPool.h
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时39分00秒
 ************************************************************************/

#ifndef _MYTHREADPOOL_H
#define _MYTHREADPOOL_H

#include <thread>
#include <mutex>
#include "Task.h"
#include "MyThread.h"
#include "BusyThreadContainer.h"
#include "IdleThreadContainer.h"
#include "TaskContainer.h"

class MyThread;
class MyThreadPool
{
public:
	
	MyThreadPool() = delete;

    /*
     * 构造包含number个线程的空闲容器
     */
	MyThreadPool(int number);

	~MyThreadPool();

    /*
     * 添加一个 优先级为priority 的任务 到任务队列
     */
	void AddTask(Task *Task,int priority);

    /*
     * 创建并加入n个线程 到 空闲容器
     */
	void AddIdleThread(int n);

    /*
     * 将指定线程从 工作容器中删除
     */
	void RemoveThreadFromBusy(MyThread *myThread);

    /*
     * 判断是否有空闲线程，如果有，将任务从任务容器
     * 中提出，放入空闲容器中，等待执行
     */
	void Start();

    /*
     * 结束线程池运行
     */
	void EndMyThreadPool();
private:
	BusyThreadContainer busy_thread_container_;
	IdleThreadContainer idle_thread_container_;
	bool issurvive_;
	TaskContainer task_container_;
	std::thread thread_this_;     //线程池运行线程
	std::mutex busy_mutex_;
	std::mutex idle_mutex_;
	std::mutex task_mutex_;
	int number_of_thread_;
};


#endif
