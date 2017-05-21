/*************************************************************************
	> File Name: Task.h
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时40分51秒
 ************************************************************************/

#ifndef _TASK_H
#define _TASK_H

namespace
{
	enum  PRIORITY
	{

		MIN = 1, NORMAL = 25, MAX = 50
	};
}

class Task
{
	
public:
	Task()
	{

	}
	void SetPriority(int priority)
	{
		if (priority > (PRIORITY::MAX))
		{
            this->priority_ = (PRIORITY::MAX);
        }
		else if (priority < (PRIORITY::MIN))
		{
			this->priority_ = (PRIORITY::MIN);
		}
	}	
	virtual void Run() = 0;
protected:
	int priority_;
};
#endif
