#define _CRT_SECURE_NO_WARNINGS

#include "phonebook.h"

//初始化通讯录 - 静态版本
//void InitPhonebook(PhoneBook* pc)
//{
//	pc->num = 0;
//	memset(pc->data, 0, sizeof(pc->data));//内存设置
//}


//初始化通讯录 - 动态版本
void InitPhonebook(PhoneBook* pc)
{
	pc->data = (phonebook*)malloc(DEFAULT_SZ * sizeof(phonebook));
	if (pc->data == NULL)
	{
		perror("InitPhonebook");
		return;
	}
	pc->num = 0;
	pc->capacity = DEFAULT_SZ;
	//加载文件
	LoadPhonebook(pc);


}

//添加成员 - 静态版本
//void AddPhonebook(PhoneBook* pc)
//{
//	if (pc->num == MAX_PHONEBOOK)
//	{
//		printf("通讯录已满，无法添加\n");
//		return;
//	}
//	//添加一个人的信息
//	printf("请输入添加的信息\n");
//	printf("姓名\n");
//	scanf("%s", pc->data[pc->num].name);
//	printf("性别\n");
//	scanf("%s", pc->data[pc->num].sex);
//	printf("年龄\n");
//	scanf("%d", &(pc->data[pc->num].age));
//	printf("电话号码\n");
//	scanf("%s", pc->data[pc->num].tele);
//	printf("地址\n");
//	scanf("%s", pc->data[pc->num].add);
//	pc->num++;
//	printf("增加成功！\n");
//}

void ChactCapacity(PhoneBook* pc)
{
	if (pc->num == pc->capacity)
	{
		phonebook* ptr = (phonebook*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(phonebook));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功！\n");
		}
		else
		{
			perror("AddPhonebook");
			printf("增容失败\n");
			return;
		}
	}
}



//添加成员 - 动态版
void AddPhonebook(PhoneBook* pc)
{
	ChactCapacity(pc);
	
	//添加一个人的信息
	printf("请输入添加的信息\n");
	printf("姓名\n");
	scanf("%s", pc->data[pc->num].name);
	printf("性别\n");
	scanf("%s", pc->data[pc->num].sex);
	printf("年龄\n");
	scanf("%d", &(pc->data[pc->num].age));
	printf("电话号码\n");
	scanf("%s", pc->data[pc->num].tele);
	printf("地址\n");
	scanf("%s", pc->data[pc->num].add);
	pc->num++;
	printf("增加成功！\n");
}


void DestoryPhonebook(PhoneBook* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->num = 0;
}

void PrintPhonebook(const PhoneBook* pc)
{
	int i = 0;
	//表头
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "性别", "年龄", "电话号码", "地址");
	for (i = 0; i < pc->num; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].add);
	}
}

int FindByName(const PhoneBook* pc,char name[])
{
	for (int i = 0; i < pc->num; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelPhonebook(PhoneBook* pc)
{

	if (pc->num == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	printf("请选择要删除的人的名字:>\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", &name);

	//查找有没有要删除的人
	int n = FindByName(pc, name);
	if (n == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	else
	{
		//删除
		int i = 0;
		for (i = n; i < pc->num - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->num--;
		printf("删除成功\n");
	}
}

void RevPhonebook(PhoneBook* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改的人的姓名\n");
	scanf("%s", &name);
	int i = FindByName(pc, name);
	if (i == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		printf("请输入修改的信息\n");
		printf("姓名\n");
		scanf("%s", pc->data[i].name);
		printf("性别\n");
		scanf("%s", pc->data[i].sex);
		printf("年龄\n");
		scanf("%d", &(pc->data[i].age));
		printf("电话号码\n");
		scanf("%s", pc->data[i].tele);
		printf("地址\n");
		scanf("%s", pc->data[i].add);
		printf("修改成功！\n");
	}
}


void SearchPhonebook(const PhoneBook* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找的人的姓名\n");
	scanf("%s", &name);
	int n = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "性别", "年龄", "电话号码", "地址");
	for (int i = 0; i < pc->num; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].add);
			n++;
		}
	}
	if (n==0)
	{
		printf("要查找的人不存在\n");
		return;
	}
}

int CmpByName(const void* e1, const void* e2)
{
	return *(char*)e1 - *(char*)e2;
}

int CmpByAge(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void SortPhonebook(PhoneBook* pc)
{
	int n = 0;
	printf("请选择排序方式（1、姓名 0、年龄）:>");
	scanf("%d", &n);
	if (n)
	{
		//以姓名排序
		qsort(pc->data, pc->num, sizeof(pc->data[0]), CmpByName);
		printf("排序成功!\n");
	}
	else
	{
		//以年龄排序
		qsort(pc->data, pc->num, sizeof(pc->data[0]), CmpByAge);
		printf("排序成功!\n");
	}
}


void SavePhonebook(const PhoneBook* pc)
{
	FILE* pf = fopen("phonebook.dat", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	for (int i = 0; i < pc->num; i++)
	{
		fwrite(pc->data + i, sizeof(phonebook), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}

void LoadPhonebook(PhoneBook* pc)
{
	FILE* pf = fopen("phonebook.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	phonebook tmp = { 0 };
	while (fread(&tmp, sizeof(phonebook), 1, pf))
	{
		//是否需要增容
		ChactCapacity(pc);
		pc->data[pc->num] = tmp;
		pc->num++;
	}


	fclose(pf);
	pf = NULL;
}