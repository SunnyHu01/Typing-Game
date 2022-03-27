#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define MAX 50
void fun_context()
{
	printf("\n*****************打字游戏****************\n");
	printf("* 输入过程中无法退出，输错则以_来表示！ *\n");
	printf("* 按任意键开始游戏，按下首字母开始计时！*\n");
	printf("****************************************\n");
}

void fun_data(char *str)
{
	srand((unsigned)time(NULL));  //随机种子
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
			time_start = time(NULL);  //取开始时间
		}
		ch = _getch();		
		if (ch != str[i])
			ch = '_';
		else
			my_count++;
		printf("%c", ch);
	}
	time_end = time(NULL);  //取结束时间
	printf("\n\n本次打字，您共正确输入了%d个字母，正确率为：%.2f %%\n", my_count, (1.0*my_count / MAX)*100);
	printf("本次游戏用时%ld s\n", time_end - time_start);
}

int main()
{
	//打字游戏
	char str[MAX] = { 0 };
	while (1)
	{
		fun_context();  //提示
		fun_data(str);  //生成随机数
		_getch();  //输入字符开始
		fun_start(str);  //开始游戏
		fun_games(str);  //游戏核心
		char ch = _getch(); //用户输入
		if (ch == 27)  //ESC的ASCALL码是27
			break;
		system("cls");  //清屏；
	}
	system("pause");
	return 0;
}