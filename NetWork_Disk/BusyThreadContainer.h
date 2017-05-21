/*************************************************************************
	> File Name: BusyThreadContainer.h
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时41分29秒
 ************************************************************************/

#ifndef _BUSYTHREADCONTAINER_H
#define _BUSYTHREADCONTAINER_H
#include <list>

/*
 * 工作容器类
 */

class MyThread;

class BusyThreadContainer
{
public:
	BusyThreadContainer();
	~BusyThreadContainer();

    /*
     * 将一个线程加入工作容器
     */
	void push(MyThread *m);

    /*
     *返回工作容器大小
     */
	std::list<MyThread*>::size_type size();

    /*
     * 删除一个制定线程
     */
	void erase(MyThread *m);

private:
	std::list<MyThread*> busy_thread_container_;
	typedef std::list<MyThread*> Container;
	typedef Container::iterator Iterator;
};

#endif
