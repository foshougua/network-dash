/*************************************************************************
	> File Name: MyThread.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时44分02秒
 ************************************************************************/

#include "MyThread.h"
#include "MyThreadPool.h"
#include <iostream>

using std::cout;
using std::thread;

int MyThread::s_threadnumber = 0;
MyThread::MyThread(MyThreadPool *pool):mythreadpool_(pool), isdetach_(true)
{
    //加锁?
    s_threadnumber++;
	threadid_ = s_threadnumber;
}


void MyThread::setisdetach(bool detach)
{
	isdetach_ = detach;
}


void MyThread::Assign(Task *t)
{
	task_ =t;
}



void MyThread::Run()
{
	cout <<"Thread:"<< threadid_ << " run ";
    //执行任务
	task_->Run();

    //从Busy中移除
	this->mythreadpool_->RemoveThreadFromBusy(this);
}


int MyThread::getthreadid()
{
	return this->threadid_;
}


void MyThread::StartThread()
{
    //设置thread，开始执行
	this->thread_ = thread(&MyThread::Run, this);
	if (isdetach_ == true)
		thread_.detach();
	else
		thread_.join();
}

bool operator==(MyThread my1, MyThread my2)
{
	return my1.threadid_ == my2.threadid_;
}
bool operator!=(MyThread my1, MyThread my2)
{
	return !(my1.threadid_ == my2.threadid_);
}
