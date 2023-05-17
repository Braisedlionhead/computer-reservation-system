#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#ifndef TEST

#define TEST
#define NUMBER 20
#define TIME 6
#define None 0		//无
#define Exist 1		//有

typedef struct
{
//	int id;//机位号			好像机位号也不需要，下标就是机器号
	int time[6];//预定时间段（0=未预定	1-已预定）
}Machine;

//声明函数
void Init(Machine machines[]);


#endif






/*


8:00-10:00

10:00-12:00

12:00-14:00

14:00-16:00

16:00-18:00

18:00-20:00




	题目9：机房机位预定系统
	20台机器，编号1到20，从早八点到晚八点。两小时一个时间段，每次可预定一个时间段。功能要求：
	（1）系统以菜单方式工作
	（2）查询，根据输入时间，输出机位信息。
	（3）机位预定，根据输入的时间查询是否有空机位，若有则预约。
	（4）退出预定，根据输入的时间，机器号撤销该事件的预定！




	我要用C语言写一个共有20台机器，早上8点到晚上8点每两个小时为一个时间段的机房机位预定系统





	已解决
	这是我的头文件，我在另一个文件中引入了这个头文件，编译器报错，显示void Init(Machine *, int)函数已有主体


	我想在A头文件中引用B头文件中的一个函数，需要在A头文件中再定义一次这个函数吗？




	*	在每个scanf后加一句	setbuf(stdin, NULL);	*


	你能给我几个C语言程序中系统以菜单方式工作的例子吗


	你觉得c语言编写的机房机位预定系统在用户退出后，要输出些什么？


*/
