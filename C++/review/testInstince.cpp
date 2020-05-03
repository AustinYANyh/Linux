#define _CRT_SECURE_NO_WARNINGS		//用来忽略scanf的安全报警
#include <string>
#include <iostream>
#include <mutex>
#include <stdlib.h>

using namespace std;

//①宏定义后不需要加分号
#define  MAX_COLUMS 20
#define MAX_INPUT 1000

int read_colums_numbers(int columns[], int max)
{
	int num = 0;
	int ch;		//此处为何定义为int?

	//scanf中,除数组名或指针变量本身,需传入地址
	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >0)		//scanf的返回值是读取成功的数据项数
	{
		num += 1;
	}

	if (num % 2 != 0)
		exit(0);

	//EOF是定义在stdio.h中的宏,值为-1
	while ((ch = getchar()) != EOF && ch != '\n')	//""类型为const char* 而''类型为int
		;

	return num;
}

mutex g_mutex;

class TeseInstance
{
public:
	static TeseInstance* GetInstance()
	{
		g_mutex.lock();
		static TeseInstance* _instance;
		if (_instance == nullptr)
			_instance = new TeseInstance();
		g_mutex.unlock();
		return _instance;
	}

	int Add(int a, int b)
	{
		return a + b;
	}
private:
	TeseInstance()
	{

	}
};

int main()
{
	int n_columns;				//要处理的行数
	int columns[MAX_COLUMS];	//要处理的数据源
	char* input[MAX_INPUT];		//读取之后的输入
	char* putput[MAX_INPUT];	//解析之后的输出

	cout << TeseInstance::GetInstance()->Add(1, 2) << endl;

	cout << "Hello World!\n";

	read_colums_numbers(columns, MAX_COLUMS);
}


