#define _CRT_SECURE_NO_WARNINGS 1

#include "menu.h"
#include "operation.h"



void main()
{
	Machine machines[NUMBER];
	Read(machines);
	Start();
	int choice,x = 1,t = 0;
	printf("�����ּ�ѡ��Ҫִ�еĲ�����");
	Menu();
	while (x)
	{
		printf("\n\n\n");
		if(t)
		printf("�������");
		t = 0;
		printf("��ѡ����Ҫִ�еĲ�����");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\n-------------------���л�����ѯ--------------------\n");
			if (!if_continue())
				break;
			show_free(machines,check_time());
			break;
		case 2:
			printf("\n--------------------ԤԼ����---------------------\n");
			if (!if_continue())
				break;
			Reservation(machines);
			break;
		case 3:
			printf("\n--------------------ȡ��ԤԼ---------------------\n");
			if (!if_continue())
				break;
			Cancel(machines);
			break;
		case 0:
			if (!if_continue())
				break;
			x = 0;
			printf("��л��ѡ��ʹ�����ǵķ������ѳɹ��˳�ϵͳ��");
			break;
		default:
			t = 1;
		}
	}
	Save(machines);
}


















