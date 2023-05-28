#define _CRT_SECURE_NO_WARNINGS 1

#include "basic.h"



//初始信息
void Start()
{
	printf("\n	      欢迎使用我们的系统！\n\n");
	printf("*************************************************\n");
	printf("*		机房机位预定系统		*\n");
	printf("*						*\n");
	printf("* 本系统共有20台机器，且有以下6个时间段可供预约 *\n");
	printf("*						*\n");
	printf("* 8:00-10:00	10:00-12:00	12:00-14:00	*\n");
	printf("* 14:00-16:00	16:00-18:00	18:00-20:00	*\n");
	printf("*						*\n");
	printf("*************************************************\n\n");
	printf("---------------------友情提示--------------------\n");
	printf("-----选择时间段时请按序号1到序号6的顺序选择------\n");
	printf("--例：8:00-10:00的序号是1，18:00-20:00的序号是6--\n");
	printf("-----------机器号则按从1-20的顺序选择------------\n\n\n");
}



//打印“机房预定系统”菜单
void Menu()
{
	printf("\n\n\n\n");
	printf("*************************************************\n");
	printf("*		机房机位预定系统		*\n");
	printf("*						*\n");
	printf("*		    主菜单			*\n");
	printf("*						*\n");
	printf("*		1.查询				*\n");
	printf("*		2.预定				*\n");
	printf("*		3.取消预定			*\n");
	printf("*		0.退出				*\n");
	printf("*						*\n");
	printf("*						*\n");
	printf("*************************************************\n");
	printf("\n\n");
}



//	读取上次运行程序结束前机器状态
void Read(Machine machines[])
{
	FILE* fp;

	fp = fopen("status.dat", "rb");

	if(fp)//如果文件打开失败（正常是由于不存在）
	{
		fread(machines, sizeof(Machine), NUMBER, fp);
		fclose(fp);
	}

	else
	{
		for (int j = 1; j <= NUMBER; j++)
		{
			for (int i = 1; i <= TIME; i++)
				machines[j - 1].time[i - 1] = 0;
		}
	}
}



// 保存系统结束前机器状态
void Save(Machine machines[])
{
	FILE* fp;

	fp = fopen("status.dat", "wb");
	if (fp)
	{
		fwrite(machines, sizeof(Machine), NUMBER, fp);
		fclose(fp);
	}
}











































/*

please chooose the function you want to realize
						主菜单
				1.查询所选时间机器空闲状态
				2.预定所选时间的特定机器
				3.退出所选时间段的机器的预定状态预定

|-------------------------------------------------------------------------------------------------------|
|								Computer Room Reservation System										|
|									机房机位预定系统													|
|																										|
|																										|
|										主菜单															|
|								1.查询所选时间机器空闲状态												|
|								2.预定所选时间的特定机器												|
|								3.退出所选时间段的机器的预定状态预定									|
|								0.退出																	|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|																										|
|-------------------------------------------------------------------------------------------------------|



*/