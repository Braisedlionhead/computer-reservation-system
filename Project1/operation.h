#define _CRT_SECURE_NO_WARNINGS 1

#include "basic.h"




int if_continue()
{
	printf("是否要继续？	（1-继续	0-返回）\n");
	int a;
	scanf("%d", &a);
	return a ? 1 : 0;
}



//判断时间段
int check_time()
{
	printf("请输入时间段序号：>");
	int time;
	scanf("%d", &time);
	setbuf(stdin, NULL);
	if (time < 1 || time >6)
	{
		printf("输入错误，");
		return check_time();
	}
	return time;
}



//判断机位号
int check_num()
{
	printf("请选择机器：>");
	int num;
	while (1)
	{
		scanf("%d", &num);
		setbuf(stdin, NULL);
		if (num <= 20 && num >= 1)
		{
			break;
		}
		printf("输入错误，");
		return check_num();
	}
	return num;
}



//空闲机器号
void FreeNum(Machine machines[],int time)
{
	printf("---");
	for (int j = 1; j <= NUMBER; j++)
	{
		if (!machines[j - 1].time[time-1])
		{
			if (j < 10)
				printf("%2d", j);
			else
				printf("%3d", j);
		}
	}
	printf(" ---\n\n");
}



//已被预约机器号
void BusyNum(Machine machines[], int time)
{
	for (int j = 1; j <= NUMBER; j++)
	{
		if (machines[j - 1].time[time - 1])
		{
			if (j < 10)
				printf("%2d", j);
			else
				printf("%3d", j);
		}
	}
	printf("\n\n");
}



//根据所选时间段输出机位信息（最好在输出机位信息后，提示哪几个机位是空闲状态）
int show_free(Machine machines[],int time)
{
	int flag = 0;
	for (int j = 1; j <= NUMBER; j++)
	{
		if (machines[j - 1].time[time - 1])
			flag++;
	}

	if (flag == 20)
	{
		printf("%d:00-%2d:00期间没有空闲机器！\n",time * 2 + 6, time * 2 + 8);
		return None;
	}
	else
	{
		if (!flag)
			printf("------------%2d:00-%2d:00期间机器全空闲！------------\n", time * 2 + 6, time * 2 + 8);
		else
		{
			printf("%d:00-%d:00期间空闲的机器有：\n", time * 2 + 6, time * 2 + 8);
			FreeNum(machines, time);
		}
	}
	return Exist;
}



//根据所选时间，输出已被预定的机位号
int show_busy(Machine machines[], int time)
{
	int flag = 0;
	for (int j = 1; j <= NUMBER; j++)
	{
		if (!machines[j - 1].time[time - 1])
			flag++;
	}

	if (flag == 20)
	{
		printf("%d:00-%d:00期间无已被预约的机器！\n", time * 2 + 6, time * 2 + 8);
		return None;
	}
	else
	{
		if(!flag)
			printf("%d:00-%d:00期间机器全被预约！\n", time * 2 + 6, time * 2 + 8);
		else
		{
			printf("%d:00-%d:00期间已被预约的机器有：", time * 2 + 6, time * 2 + 8);
			BusyNum(machines, time);
		}
	}
	return Exist;
}


//预约成功后，显示预定信息
void show_rsv(int time, int num)
{
//	printf("*						*\n");
	printf("-		以下为你的预约信息：		-\n");
	printf("-	第%d个时间段（%d:00 - %d:00）的%d号机	-\n", time, time * 2 + 6, time * 2 + 8, num);	//原左右各8个"-"
	printf("-------------------------------------------------\n\n");
}



//根据所选时间段，预定机位，若有，则自动预约
void Reservation(Machine machines[])
{
	int time = check_time();
	while (1)
	{
		if (show_free(machines, time))
			break;
		time = check_time();
	}

	while (1)
	{
		int num = check_num();
		if (!machines[num - 1].time[time-1])
		{
			machines[num - 1].time[time-1] = 1;
			printf("\n--------------------预约成功!--------------------\n");	//原左右各12个"-"
			show_rsv(time, num);
			break;
		}
		printf("该机器已被预约，");
	}
}



//根据所选时间段和机位，取消预约
void Cancel(Machine machines[])
{
	int time = check_time();
	int c = show_busy(machines, time);
	while (1)
	{
		if (c)
			break;
		time = check_time();
		c = show_busy(machines, time);
	}
	int t = 0;
	while (++t)
	{
		if (c == None)
		{
			printf("重新选择，");
			time = check_time();
		}
		int num = check_num();
		if (machines[num - 1].time[time-1])
		{
			machines[num - 1].time[time-1] = 0;
			printf("取消预约成功！\n");
			break;
		}
		printf("该机器未被预约，");
		if (t > 3)
		{
			show_busy(machines, time);
			t = 2;
		}
	}
}


