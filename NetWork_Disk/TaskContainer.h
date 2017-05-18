/*************************************************************************
	> File Name: TaskContainer.h
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时39分59秒
 ************************************************************************/

#ifndef _TASKCONTAINER_H
#define _TASKCONTAINER_H
#include <queue>
class Task;
class TaskContainer
{
public:
	TaskContainer();
	~TaskContainer();
	void push(Task *);
	Task* top();
	void pop();
	std::priority_queue<Task*>::size_type size();
private:
	std::priority_queue<Task*> task_container_;
};

#endif
