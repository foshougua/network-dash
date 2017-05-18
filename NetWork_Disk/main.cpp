/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时47分21秒
 ************************************************************************/

#include "MyThreadPool.h"
#include "MyTask.h"
#include <iostream>
#include<unistd.h>
#include<vector>
using namespace std;






int main()
{
	MyThreadPool mythreadPool(10);

    string filename = "./MyThreadPool.cpp";
	File file(filename);
    int blockNum = file.getBlockNum();
    vector<MyTask*> vec;
    for(int i = 0; i < blockNum; i++)
    {
        MyTask *block = new MyTask(i + 1, &file);
        vec.push_back(block);
    }
	for (int i = 0; i < blockNum; i++)
	{
		mythreadPool.AddTask(vec[i], 0);
	}

    sleep(10);
}

