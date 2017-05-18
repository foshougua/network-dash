/*************************************************************************
	> File Name: MyThreadPool.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时44分44秒
 ************************************************************************/

#include "MyThreadPool.h"
#include <iostream>
using namespace std;
MyThreadPool::MyThreadPool(int number)
{
	issurvive_ = true;
	number_of_thread_ = number;
    //创建线程 到 空闲容器
	idle_thread_container_.assign(number, this);
	thread_this_ = thread(&MyThreadPool::Start, this);
	thread_this_.detach();
}
MyThreadPool::~MyThreadPool()
{

}
void MyThreadPool::EndMyThreadPool()
{
	issurvive_ =false;
}

void  MyThreadPool::AddIdleThread(int n)
{
	idle_mutex_.lock();
	idle_thread_container_.assign(n, this);
	number_of_thread_ += n;
	idle_mutex_.unlock();
}
void MyThreadPool::Start()
{
    cout<<"Main Thread Run"<<endl;
	
	while (true)
	{
		if (issurvive_==false)
		{
            //如果线程池结束运行，那么循环等待 工作容器中的 所有线程 结束(size 为0)
			busy_mutex_.lock();
			if (busy_thread_container_.size()!=0)
			{
				busy_mutex_.unlock();
				continue;
			}
			busy_mutex_.unlock();
			break;
		}
		idle_mutex_.lock();
		if (idle_thread_container_.size() == 0)
		{
			idle_mutex_.unlock();
			continue;
		}
		idle_mutex_.unlock();
		task_mutex_.lock();
		if (task_container_.size() == 0)
		{
			task_mutex_.unlock();
			continue;
		}

        //空闲容器 不为空
        //任务容器 不为空
		Task *newTask = task_container_.top();
		task_container_.pop();
		task_mutex_.unlock();
		
		idle_mutex_.lock();
		MyThread *topIdleThread = idle_thread_container_.top();
		idle_thread_container_.pop();
		topIdleThread->Assign(newTask);
		idle_mutex_.unlock();

		busy_mutex_.lock();
		busy_thread_container_.push(topIdleThread);
		busy_mutex_.unlock();
		topIdleThread->StartThread();
	}
}
void MyThreadPool::AddTask(Task *Task, int priority = (PRIORITY::NORMAL))
{
	
	Task->SetPriority(priority);
	task_mutex_.lock();
	task_container_.push(Task);
	task_mutex_.unlock();
}
void MyThreadPool::RemoveThreadFromBusy(MyThread *myThread)
{

	busy_mutex_.lock();
	cout << "Thread:" << myThread->getthreadid()<< " remove from busylist" << endl;
	busy_thread_container_.erase(myThread);
	busy_mutex_.unlock();

	idle_mutex_.lock();
	idle_thread_container_.push(myThread);
	idle_mutex_.unlock();
}
