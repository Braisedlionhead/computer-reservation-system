#define _CRT_SECURE_NO_WARNINGS 1

#include "menu.h"
#include "operation.h"



void main()
{
	Machine machines[NUMBER];
	Init(machines);
	Start();



	int choice,x = 1,t = 0;
	printf("按数字键选择要执行的操作：");

	Menu();
	while (x)
	{
		printf("\n\n\n");
		if(t)
		printf("输入错误，");
		t = 0;
		printf("请选择你要执行的操作：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\n-------------------空闲机器查询--------------------\n");
			if (!if_continue())
				break;
			show_free(machines,check_time());
			break;
		case 2:
			printf("\n--------------------预约机器---------------------\n");
			if (!if_continue())
				break;
			Reservation(machines);
			break;
		case 3:
			printf("\n--------------------取消预约---------------------\n");
			if (!if_continue())
				break;
			Cancel(machines);
			break;
		case 0:
			if (!if_continue())
				break;
			x = 0;
			printf("感谢您选择使用我们的服务！您已成功退出系统。");
			break;
		default:
			t = 1;
		}
	}

	//printf("结束标记（手动标记）");			//待完善！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
}



//初始化机器操作
void Init(Machine machines[])
{
	for (int j=1; j<=NUMBER; j++)
	{
		for (int i = 1; i <= TIME; i++)
			machines[j - 1].time[i-1] = 0;
	}
}







