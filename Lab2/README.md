# CloudComputingLab2

摸fish组  组员：蔡俊祺，周亚男，伍佳伟，张宇

### 文件说明

主要代码：main.cpp, MyHttpServer.cpp, MyHttpServer.h

server文件夹存放web服务器的页面

screen_shot文件夹存放性能测试截图



### 代码运行方法

环境：Linux，g++

```
./make
./http_server --ip [ip_addr] --port [port_num]
```

[ip_addr]为服务器ip地址，[port_num]为服务器监听端口



### 服务器正确运行后的输出

Server Information：

ip:xxx.xxx.xxx.xxx  port:xxx

listening...



### 注意事项

可使用curl或浏览器进行GET和POST请求的测试，其他请求会返回501。

服务器中默认仅有/index.html和其他几个错误页面。

服务器如果收到的url指向一个目录而不是文件，则会自动查找目录下的index.html。

服务器对于持续连接和非持续连接都支持。

服务器并没有使用线程池，因此没有--number-thread命令行参数
