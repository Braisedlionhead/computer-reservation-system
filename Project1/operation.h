#define _CRT_SECURE_NO_WARNINGS 1

#include "basic.h"




int if_continue()
{
	printf("�Ƿ�Ҫ������	��1-����	0-���أ�\n");
	int a;
	scanf("%d", &a);
	return a ? 1 : 0;
}



//�ж�ʱ���
int check_time()
{
	printf("������ʱ�����ţ�>");
	int time;
	scanf("%d", &time);
	setbuf(stdin, NULL);
	if (time < 1 || time >6)
	{
		printf("�������");
		return check_time();
	}
	return time;
}



//�жϻ�λ��
int check_num()
{
	printf("��ѡ�������>");
	int num;
	while (1)
	{
		scanf("%d", &num);
		setbuf(stdin, NULL);
		if (num <= 20 && num >= 1)
		{
			break;
		}
		printf("�������");
		return check_num();
	}
	return num;
}



//���л�����
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



//�ѱ�ԤԼ������
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



//������ѡʱ��������λ��Ϣ������������λ��Ϣ����ʾ�ļ�����λ�ǿ���״̬��
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
		printf("%d:00-%2d:00�ڼ�û�п��л�����\n",time * 2 + 6, time * 2 + 8);
		return None;
	}
	else
	{
		if (!flag)
			printf("------------%2d:00-%2d:00�ڼ����ȫ���У�------------\n", time * 2 + 6, time * 2 + 8);
		else
		{
			printf("%d:00-%d:00�ڼ���еĻ����У�\n", time * 2 + 6, time * 2 + 8);
			FreeNum(machines, time);
		}
	}
	return Exist;
}



//������ѡʱ�䣬����ѱ�Ԥ���Ļ�λ��
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
		printf("%d:00-%d:00�ڼ����ѱ�ԤԼ�Ļ�����\n", time * 2 + 6, time * 2 + 8);
		return None;
	}
	else
	{
		if(!flag)
			printf("%d:00-%d:00�ڼ����ȫ��ԤԼ��\n", time * 2 + 6, time * 2 + 8);
		else
		{
			printf("%d:00-%d:00�ڼ��ѱ�ԤԼ�Ļ����У�", time * 2 + 6, time * 2 + 8);
			BusyNum(machines, time);
		}
	}
	return Exist;
}


//ԤԼ�ɹ�����ʾԤ����Ϣ
void show_rsv(int time, int num)
{
//	printf("*						*\n");
	printf("-		����Ϊ���ԤԼ��Ϣ��		-\n");
	printf("-	��%d��ʱ��Σ�%d:00 - %d:00����%d�Ż�	-\n", time, time * 2 + 6, time * 2 + 8, num);	//ԭ���Ҹ�8��"-"
	printf("-------------------------------------------------\n\n");
}



//������ѡʱ��Σ�Ԥ����λ�����У����Զ�ԤԼ
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
			printf("\n--------------------ԤԼ�ɹ�!--------------------\n");	//ԭ���Ҹ�12��"-"
			show_rsv(time, num);
			break;
		}
		printf("�û����ѱ�ԤԼ��");
	}
}



//������ѡʱ��κͻ�λ��ȡ��ԤԼ
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
			printf("����ѡ��");
			time = check_time();
		}
		int num = check_num();
		if (machines[num - 1].time[time-1])
		{
			machines[num - 1].time[time-1] = 0;
			printf("ȡ��ԤԼ�ɹ���\n");
			break;
		}
		printf("�û���δ��ԤԼ��");
		if (t > 3)
		{
			show_busy(machines, time);
			t = 2;
		}
	}
}


