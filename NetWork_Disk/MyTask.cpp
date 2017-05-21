/*************************************************************************
	> File Name: MyTask.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 09时42分24秒
 ************************************************************************/

#include<fstream>
#include"MyTask.h"

#include<thread>
#include<iostream>
#include<zmq.h>
#include<string>


using std::string;
using std::cout;
using std::endl;
void MyTask::Run()
{
    cout << this->blockID << "Run: ";
    void *pCtx = NULL;
    void *pSock = NULL;
    const char * pAddr = "tcp://127.0.0.1:7766";

    if((pCtx = zmq_ctx_new()) == NULL)
    {
        return ;
    }

    if((pSock = zmq_socket(pCtx, ZMQ_DEALER)) == NULL)
    {
        zmq_ctx_destroy(pCtx);
        return ;
    }

    int iSndTimeOut = 5000;

    if(zmq_setsockopt(pSock, ZMQ_RCVTIMEO, &iSndTimeOut, sizeof(iSndTimeOut)) < 0)
    {
        zmq_close(pSock);
        zmq_ctx_destroy(pCtx);
        return ;
    }

    if(zmq_connect(pSock, pAddr) < 0)
    {
        zmq_close(pSock);
        zmq_ctx_destroy(pCtx);
    }


    char block[1024 * 1024 * 4];
    this->file->file.seekg((blockID - 1) * 1024 * 1024 * 4, std::ios::beg);
    this->file->file.read(block, sizeof(block));


    if(zmq_send(pSock, block, sizeof(block), 0) < 0)
    {
        std::cout<<"Send message error!!"<<std::endl;
    }
    else
    {
        std::cout<<"Block "<< this->blockID  << "  Send" << std::endl;
        
    }


	std::this_thread::sleep_for(std::chrono::seconds(1));
}

