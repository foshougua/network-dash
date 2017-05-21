/*************************************************************************
	> File Name: server.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月07日 星期日 10时08分05秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
#include<zmq.h>
#include<time.h>

using namespace std;

int main()
{
    void *pCtx = NULL;
    void *pSock = NULL;
    const char * pAddr = "tcp://*:7766";

    if((pCtx = zmq_ctx_new()) == NULL)
    {
        return 0;
    }

    if((pSock = zmq_socket(pCtx, ZMQ_DEALER)) == NULL)
    {
        zmq_ctx_destroy(pCtx);
        return 0;
    }

    int iRvcTimeOut = 5000;

    if(zmq_setsockopt(pSock, ZMQ_RCVTIMEO, &iRvcTimeOut, sizeof(iRvcTimeOut)) < 0)
    {
        zmq_close(pSock);
        zmq_ctx_destroy(pCtx);
        return 0;
    }

    if(zmq_bind(pSock, pAddr) < 0)
    {
        zmq_close(pSock);
        zmq_ctx_destroy(pCtx);
        return 0;
    }




    std::cout<<"receive"<<std::endl;
    int i = 0;
    while(1)
    {
        auto begin = time(NULL);
        char buffer[1024 * 1024];
        if(zmq_recv(pSock, buffer, sizeof(buffer), 0) < 0)
        {
            std::cout<<zmq_strerror(errno);
            continue;
        }
        else
        {
            std::cout << buffer << std::endl;
        }
        auto end = time(NULL);

    }

    return 0;
}


