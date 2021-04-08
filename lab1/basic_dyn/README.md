## 注意事项

建议：makefile文件中增加编译选项-std=c++11,否则可能会莫名其妙会无法链接到库，为了防止图片无法显示，可以看readme.pdf文件

1.make后执行sudoku_solve（可输入第二个参数，代表线程数。不输入则默认为双线程），开始输入测试文件

2.可输入多个测试文件，以**回车键分隔**

3.**连续键入两个回车键**代表输入结束

4.输入结束后开始求解数独

5.求解完成后会将所有数独的解输出至文件`outfile`中（也可输出至标准输出，在`main.cc`中取消注释输出语句即可）

![image-20210408233304298](C:\Users\15927\AppData\Roaming\Typora\typora-user-images\image-20210408233304298.png)

6.本文件夹内使用的方式为solve_sudoku_basic，为多线程分配任务的方式为动态

7.可求解的puzzle个数为`1e6+5`，若想求解更多，在`sudoku.h`中修改`num_of_puzzle`即可

## 文件截图

`test1`文件：

![image-20210408233421580](C:\Users\15927\AppData\Roaming\Typora\typora-user-images\image-20210408233421580.png)

`test4`文件：

![image-20210408233439093](C:\Users\15927\AppData\Roaming\Typora\typora-user-images\image-20210408233439093.png)

`outfile`文件（部分）：

![image-20210408233547472](C:\Users\15927\AppData\Roaming\Typora\typora-user-images\image-20210408233547472.png))

outfile文件中只展示了test4的输出结果，只做说明作用。