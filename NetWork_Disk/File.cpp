/*************************************************************************
	> File Name: File.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月10日 星期三 18时51分36秒
 ************************************************************************/

#include"File.h"
#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
File::File(const std::string &fileName)
{
    this->file.open(fileName, std::ios::binary);
    if(this->file.is_open())
    {
        std::cout << "File get!" << std::endl;
    }
    else
    {
        std::cout << "File unget!" << std::endl;
    }
    this->file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    std::cout << "File Size : " << fileSize << std::endl; 
    blockNum = ceil(static_cast<double>(fileSize) / (1024 * 1024 * 4));
    std::cout << "Block Count: " << blockNum <<std::endl;
}
void File::Close()
{
    (this->file).close();
}
int File::getBlockNum()
{
    return this->blockNum;
}

