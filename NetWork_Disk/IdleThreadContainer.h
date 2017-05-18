/*************************************************************************
	> File Name: IdleThreadContainer.h
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时41分56秒
 ************************************************************************/

#ifndef _IDLETHREADCONTAINER_H
#define _IDLETHREADCONTAINER_H
#include <vector>

class MyThread;
class MyThreadPool;
class IdleThreadContainer
{
	
public:
	IdleThreadContainer();
	~IdleThreadContainer();
	std::vector<MyThread*>::size_type size();

    /*
     * 将一个线程放入空闲容器
     */
	void push(MyThread *m);

    /*
     *  创建n个线程 与 线程池m 相关联的线程放入
     * 空闲容器。
     *  初始化。
     */
	void assign(int n,MyThreadPool* m);	

    /*
     * 返回容器顶端的线程
     */
	MyThread* top();

    /*
     * 弹出容器顶端的线程
     */
	void pop();

    /*
     * 删除一个指定的线程
     */
	void erase(MyThread *m);
private:
	std::vector<MyThread*> idle_thread_container_;
	typedef std::vector<MyThread*> Container;
	typedef Container::iterator Iterator;
};

#endif
