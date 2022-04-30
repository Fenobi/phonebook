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
	退出,
	添加,
	删除,
	修改,
	查找,
	排序,
	查看
};

//静态版本
//typedef struct PhoneBook
//{
//	phonebook data[MAX_PHONEBOOK];//存放添加人的信息
//	int num;//记录当前通讯录中有效信息的个数
//}PhoneBook;

//动态版本
typedef struct PhoneBook
{
	phonebook *data;//指向动态申请的空间，用来存放联系人的信息
	int num;//记录当前通讯录中有效信息的个数
	int capacity;//记录当前通讯录的最大容量
}PhoneBook;

//初始化通讯录
void InitPhonebook(PhoneBook *pc);

//添加信息
void AddPhonebook(PhoneBook* pc);

//打印信息
void PrintPhonebook(const PhoneBook *pc);

//删除信息
void DelPhonebook(PhoneBook* pc);

//修改信息
void RevPhonebook(PhoneBook* pc);

//查找信息
void SearchPhonebook(const PhoneBook* pc);

//将信息排序
void SortPhonebook(PhoneBook* pc);

//销毁通讯录
void DestoryPhonebook(PhoneBook* pc);

//保存文件
void SavePhonebook(PhoneBook* pc);

//加载文件
void LoadPhonebook(PhoneBook* pc);

//检测扩容
void ChactCapacity(PhoneBook* pc);
