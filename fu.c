#define _CRT_SECURE_NO_WARNINGS

#include "phonebook.h"

void menu()
{
	printf("***********************************************\n");
	printf("**********  1、添加    2、删除  ***************\n");
	printf("**********  3、修改    4、查找  ***************\n");
	printf("**********  5、排序    6、查看  ***************\n");
	printf("**************** 0、退出 **********************\n");
}


int main()
{
	int input = 0;
	//创建通讯录
	PhoneBook PB;//通讯录

	//初始化通讯录
	//给data申请一块连续的空间在堆上
	//num=0
	//capacity 初始化为当前的最大的容量
	InitPhonebook(&PB);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 退出:
			//销毁通讯录
			DestoryPhonebook(&PB);
			printf("已退出\n");
			break;
		case 添加:
			AddPhonebook(&PB);
			break;
		case 删除:
			DelPhonebook(&PB);
			break;
		case 修改:
			RevPhonebook(&PB);
			break;
		case 查找:
			SearchPhonebook(&PB);
			break;
		case 排序:
			SortPhonebook(&PB);
			break;
		case 查看:
			PrintPhonebook(&PB);
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}