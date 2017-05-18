/*************************************************************************
	> File Name: IdleThreadContainer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时35分01秒
 ************************************************************************/

#include "IdleThreadContainer.h"
#include "MyThread.h"
#include <iostream>
#include<algorithm>

using std::cout;
using std::endl;
IdleThreadContainer::IdleThreadContainer()
{
}


IdleThreadContainer::~IdleThreadContainer()
{
	int i = 0;
	for (Iterator it = idle_thread_container_.begin(); it != idle_thread_container_.end(); it++)
	{
		cout << i++ << endl;
		delete *it;
	}
}

std::vector<MyThread*>::size_type IdleThreadContainer::size()
{
	return idle_thread_container_.size();
}


void IdleThreadContainer::push(MyThread *m)
{
	idle_thread_container_.push_back(m);
}


void IdleThreadContainer::pop()
{
	idle_thread_container_.pop_back();
}


void IdleThreadContainer::erase(MyThread *m)
{
	idle_thread_container_.erase(find(idle_thread_container_.begin(), idle_thread_container_.end(), m));
}


void IdleThreadContainer::assign(int number, MyThreadPool *m)
{
	for (int i = 0; i < number; i++)
	{
		MyThread *p = new MyThread(m);
		idle_thread_container_.push_back(p);
	}
}


MyThread* IdleThreadContainer::top()
{
	
	return idle_thread_container_.back();
}
