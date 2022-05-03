#define _CRT_SECURE_NO_WARNINGS

#include "phonebook.h"

//��ʼ��ͨѶ¼ - ��̬�汾
//void InitPhonebook(PhoneBook* pc)
//{
//	pc->num = 0;
//	memset(pc->data, 0, sizeof(pc->data));//�ڴ�����
//}


//��ʼ��ͨѶ¼ - ��̬�汾
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
	//�����ļ�
	LoadPhonebook(pc);


}

//��ӳ�Ա - ��̬�汾
//void AddPhonebook(PhoneBook* pc)
//{
//	if (pc->num == MAX_PHONEBOOK)
//	{
//		printf("ͨѶ¼�������޷����\n");
//		return;
//	}
//	//���һ���˵���Ϣ
//	printf("��������ӵ���Ϣ\n");
//	printf("����\n");
//	scanf("%s", pc->data[pc->num].name);
//	printf("�Ա�\n");
//	scanf("%s", pc->data[pc->num].sex);
//	printf("����\n");
//	scanf("%d", &(pc->data[pc->num].age));
//	printf("�绰����\n");
//	scanf("%s", pc->data[pc->num].tele);
//	printf("��ַ\n");
//	scanf("%s", pc->data[pc->num].add);
//	pc->num++;
//	printf("���ӳɹ���\n");
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
			printf("���ݳɹ���\n");
		}
		else
		{
			perror("AddPhonebook");
			printf("����ʧ��\n");
			return;
		}
	}
}



//��ӳ�Ա - ��̬��
void AddPhonebook(PhoneBook* pc)
{
	ChactCapacity(pc);
	
	//���һ���˵���Ϣ
	printf("��������ӵ���Ϣ\n");
	printf("����\n");
	scanf("%s", pc->data[pc->num].name);
	printf("�Ա�\n");
	scanf("%s", pc->data[pc->num].sex);
	printf("����\n");
	scanf("%d", &(pc->data[pc->num].age));
	printf("�绰����\n");
	scanf("%s", pc->data[pc->num].tele);
	printf("��ַ\n");
	scanf("%s", pc->data[pc->num].add);
	pc->num++;
	printf("���ӳɹ���\n");
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
	//��ͷ
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰����", "��ַ");
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
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	printf("��ѡ��Ҫɾ�����˵�����:>\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", &name);

	//������û��Ҫɾ������
	int n = FindByName(pc, name);
	if (n == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	else
	{
		//ɾ��
		int i = 0;
		for (i = n; i < pc->num - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->num--;
		printf("ɾ���ɹ�\n");
	}
}

void RevPhonebook(PhoneBook* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸ĵ��˵�����\n");
	scanf("%s", &name);
	int i = FindByName(pc, name);
	if (i == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		printf("�������޸ĵ���Ϣ\n");
		printf("����\n");
		scanf("%s", pc->data[i].name);
		printf("�Ա�\n");
		scanf("%s", pc->data[i].sex);
		printf("����\n");
		scanf("%d", &(pc->data[i].age));
		printf("�绰����\n");
		scanf("%s", pc->data[i].tele);
		printf("��ַ\n");
		scanf("%s", pc->data[i].add);
		printf("�޸ĳɹ���\n");
	}
}


void SearchPhonebook(const PhoneBook* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ���ҵ��˵�����\n");
	scanf("%s", &name);
	int n = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰����", "��ַ");
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
		printf("Ҫ���ҵ��˲�����\n");
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
	printf("��ѡ������ʽ��1������ 0�����䣩:>");
	scanf("%d", &n);
	if (n)
	{
		//����������
		qsort(pc->data, pc->num, sizeof(pc->data[0]), CmpByName);
		printf("����ɹ�!\n");
	}
	else
	{
		//����������
		qsort(pc->data, pc->num, sizeof(pc->data[0]), CmpByAge);
		printf("����ɹ�!\n");
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
		//�Ƿ���Ҫ����
		ChactCapacity(pc);
		pc->data[pc->num] = tmp;
		pc->num++;
	}


	fclose(pf);
	pf = NULL;
}
