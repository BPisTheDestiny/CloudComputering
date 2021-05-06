# 性能测试报告

服务器采用多线程法为每一个连接新建处理线程。

使用*Apache* Bench进行性能测试

## 1.不同平台之间的性能对比

平台1:vmware下运行的ubuntu18.04，处理器2核4线程

平台2:物理机运行的deepin15.11,处理器Core i7 8550U 4核8线程

### 平台1：

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/ubuntu18.04(vm)/10w-8.jpg)

进行10万个http请求测试，并发8个客户端。总耗时3.470秒，服务器每秒可处理28819.41个http请求

### 平台2：

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w-8.png)

进行10万个http请求测试，并发8个客户端。总耗时0.797秒，服务器每秒可处理125502.17个http请求

## 2.非持续连接服务器性能测试

测试平台：物理机运行的deepin15.11, 处理器Core i7 8550U 4核8线程

进行10万个http请求测试，采用非持续性HTTP连接，也就是服务器在发回请求后会立即关闭连接

10万个请求测试，并发8个客户端。

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w%E9%9D%9E%E6%8C%81%E4%B9%85%E8%BF%9E%E6%8E%A5-8.png)

总耗时3.156秒，服务器每秒可处理31690.66个http请求

## 3.不同客户端数量下服务器性能的对比

测试平台：物理机运行的deepin15.11, 处理器Core i7 8550U 4核8线程

进行10万个http持续连接请求测试

### 1个连接

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w-1.png)

总耗时2.572秒，服务器每秒可处理38873.66个http请求

### 2个连接

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w-2.png)

总耗时1.423秒，服务器每秒可处理70292.05个请求

### 4个连接

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w-4.png)

总耗时0.923秒，服务器每秒可处理108347.64个请求

### 8个连接

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w-8.png)

总耗时0.797秒，服务器每秒可处理125502.17个请求

### 16个连接

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w-16.png)

总耗时0.752秒，服务器每秒可处理132950.61个请求

### 32个连接

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w-32.png)

### 64个连接

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w-64.png)

总耗时0.778秒，服务器每秒可处理128487.47个请求

### 128个连接

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w-128.png)

总耗时0.818秒，服务器每秒可处理122287.51个请求

### 256个连接

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w-256.png)

总耗时0.876秒，服务器每秒可处理114173.63个请求

### 512个连接

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w-512.png)

总耗时0.961秒，服务器每秒可处理104027.85个请求

### 1000个连接

![](https://github.com/BPisTheDestiny/CloudComputering/blob/master/Lab2/screen_shot/deepin15.11/10w-1000.png)

总耗时0.984秒，服务器每秒可处理101647.61个请求

## 4.总结

在不同平台下，CPU核心和线程数越多服务器的多线程处理性能越好。而采用持续连接的HTTP相比非持续连接的HTTP，在单个连接的请求数较多时性能差距明显。由于没有频繁的连接操作，持续连接的HTTP性能要优于非持续连接的HTTP。服务器多线程处理HTTP请求的吞吐率要优于单线程，而服务器的处理性能会随着连接线程数的增加而逐渐达到瓶颈，甚至会在线程过多时性能反降

