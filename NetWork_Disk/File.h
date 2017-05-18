/*************************************************************************
	> File Name: File.h
	> Author: 
	> Mail: 
	> Created Time: 2017年05月10日 星期三 18时44分26秒
 ************************************************************************/

#ifndef _FILE_H
#define _FILE_H
#include<fstream>

class File
{
public:
    File(const std::string &fileName);
    ~File(){}
    long getSize();
    void Close();
    int getBlockNum();

    std::ifstream file;
private:
    int blockNum;
    long fileSize;

};



#endif
