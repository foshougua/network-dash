/*************************************************************************
	> File Name: BusyThreadContainer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时32分34秒
 ************************************************************************/
#include "BusyThreadContainer.h"
#include"MyThread.h"
#include<algorithm>

BusyThreadContainer::BusyThreadContainer()
{
}
BusyThreadContainer::~BusyThreadContainer()
{
}

void BusyThreadContainer::push(MyThread *m)
{
    //尾部插入线程
	busy_thread_container_.push_back(m);
}

void  BusyThreadContainer::erase(MyThread *m)
{
	busy_thread_container_.erase(find(busy_thread_container_.begin(),busy_thread_container_.end(),m));
}


std::list<MyThread*>::size_type BusyThreadContainer::size()
{
	return busy_thread_container_.size();
}

