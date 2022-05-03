#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_NAME 20
#define MAX_SXE 5
#define MAX_TELE 12
#define MAX_ADD 30

#define MAX_PHONEBOOK 1000

#define DEFAULT_SZ 3
#define INC_SZ 2

typedef struct phonebook
{
	char name[MAX_NAME];
	char sex[MAX_SXE];
	int age;
	char tele[MAX_TELE];
	char add[MAX_ADD];
}phonebook;

enum E
{
	�˳�,
	���,
	ɾ��,
	�޸�,
	����,
	����,
	�鿴
};

//��̬�汾
//typedef struct PhoneBook
//{
//	phonebook data[MAX_PHONEBOOK];//�������˵���Ϣ
//	int num;//��¼��ǰͨѶ¼����Ч��Ϣ�ĸ���
//}PhoneBook;

//��̬�汾
typedef struct PhoneBook
{
	phonebook *data;//ָ��̬����Ŀռ䣬���������ϵ�˵���Ϣ
	int num;//��¼��ǰͨѶ¼����Ч��Ϣ�ĸ���
	int capacity;//��¼��ǰͨѶ¼���������
}PhoneBook;

//��ʼ��ͨѶ¼
void InitPhonebook(PhoneBook *pc);

//�����Ϣ
void AddPhonebook(PhoneBook* pc);

//��ӡ��Ϣ
void PrintPhonebook(const PhoneBook *pc);

//ɾ����Ϣ
void DelPhonebook(PhoneBook* pc);

//�޸���Ϣ
void RevPhonebook(PhoneBook* pc);

//������Ϣ
void SearchPhonebook(const PhoneBook* pc);

//����Ϣ����
void SortPhonebook(PhoneBook* pc);

//����ͨѶ¼
void DestoryPhonebook(PhoneBook* pc);

//�����ļ�
void SavePhonebook(PhoneBook* pc);

//�����ļ�
void LoadPhonebook(PhoneBook* pc);

//�������
void ChactCapacity(PhoneBook* pc);
