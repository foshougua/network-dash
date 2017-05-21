/*************************************************************************
	> File Name: TaskContainer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时45分21秒
 ************************************************************************/

#include "TaskContainer.h"


TaskContainer::TaskContainer()
{
}


TaskContainer::~TaskContainer()
{
}
void TaskContainer::push(Task* t)
{
	task_container_.push(t);
}
Task* TaskContainer::top()
{
	return task_container_.top();
}
void TaskContainer::pop()
{
	task_container_.pop();
}
std::priority_queue<Task*>::size_type  TaskContainer::size()
{
	return task_container_.size();
}
