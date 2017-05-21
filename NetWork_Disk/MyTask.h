/*************************************************************************
	> File Name: MyTask.h
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时35分52秒
 ************************************************************************/

#ifndef _MYTASK_H
#define _MYTASK_H

#include "Task.h"
#include"File.h"


class MyTask : public Task
{
public:
    MyTask(int id, File *file1):blockID(id)
, file(file1)   
    {}
    ~MyTask(){}
    virtual void Run();


private:
    int blockID;
    File *file;
};


#endif
