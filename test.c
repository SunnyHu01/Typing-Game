#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define MAX 50
void fun_context()
{
	printf("\n*****************������Ϸ****************\n");
	printf("* ����������޷��˳����������_����ʾ�� *\n");
	printf("* ���������ʼ��Ϸ����������ĸ��ʼ��ʱ��*\n");
	printf("****************************************\n");
}

void fun_data(char *str)
{
	srand((unsigned)time(NULL));  //�������
	int i = 0;
	for (; i < MAX; i++)
	{
		str[i] = rand() % 26 + 'a';
	}
	str[i] = '\0';
}

void fun_start(char *str)
{
	system("cls");
	printf("\n\n\n\t%s\n\t", str);
}

void fun_games(char *str)
{
	char ch = '0';
	int my_count = 0;
	time_t time_start, time_end;
	for (int i = 0; i < MAX; i++)
	{
		if (i == 0)
		{
			time_start = time(NULL);  //ȡ��ʼʱ��
		}
		ch = _getch();		
		if (ch != str[i])
			ch = '_';
		else
			my_count++;
		printf("%c", ch);
	}
	time_end = time(NULL);  //ȡ����ʱ��
	printf("\n\n���δ��֣�������ȷ������%d����ĸ����ȷ��Ϊ��%.2f %%\n", my_count, (1.0*my_count / MAX)*100);
	printf("������Ϸ��ʱ%ld s\n", time_end - time_start);
}

int main()
{
	//������Ϸ
	char str[MAX] = { 0 };
	while (1)
	{
		fun_context();  //��ʾ
		fun_data(str);  //���������
		_getch();  //�����ַ���ʼ
		fun_start(str);  //��ʼ��Ϸ
		fun_games(str);  //��Ϸ����
		char ch = _getch(); //�û�����
		if (ch == 27)  //ESC��ASCALL����27
			break;
		system("cls");  //������
	}
	system("pause");
	return 0;
}