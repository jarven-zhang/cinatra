/*************************************************************************
#	> File Name:main.cpp
#	> Author: jarven
#	> Mail: whuaw@aliyun.com
#	> Created Time: Tue 09 Mar 2021 11:23:05 AM CST
 ************************************************************************/

#include <iostream>
#include "WsServer.h"
#include <memory>

using namespace std;
int main()
{
	unique_ptr<WsServer> p = make_unique<WsServer>();
	p->Start("0.0.0.0", "8082");
	
	return 0;
}
