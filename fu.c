#define _CRT_SECURE_NO_WARNINGS

#include "phonebook.h"

//��һ�棬��̬�ڴ�
//�ڶ��棬��̬�ڴ�
//�����棬�ɱ�����Ϣ���ļ�

void menu()
{
	printf("***********************************************\n");
	printf("**********  1�����    2��ɾ��  ***************\n");
	printf("**********  3���޸�    4������  ***************\n");
	printf("**********  5������    6���鿴  ***************\n");
	printf("**************** 0���˳� **********************\n");
}


int main()
{
	int input = 0;
	//����ͨѶ¼
	PhoneBook PB;//ͨѶ¼

	//��ʼ��ͨѶ¼
	//��data����һ�������Ŀռ��ڶ���
	//num=0
	//capacity ��ʼ��Ϊ��ǰ����������
	InitPhonebook(&PB);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case �˳�:
			//������Ϣ���ļ�
			SavePhonebook(&PB);
			//����ͨѶ¼
			DestoryPhonebook(&PB);
			printf("���˳�\n");
			break;
		case ���:
			AddPhonebook(&PB);
			break;
		case ɾ��:
			DelPhonebook(&PB);
			break;
		case �޸�:
			RevPhonebook(&PB);
			break;
		case ����:
			SearchPhonebook(&PB);
			break;
		case ����:
			SortPhonebook(&PB);
			break;
		case �鿴:
			PrintPhonebook(&PB);
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}