#define  _CRT_SECURE_NO_WARNINGS 1

#include "maillist.h"

void menu()
{
	
	printf("		********************************************\n");
	printf("		*****          简易通讯录              *****\n");
	printf("		*****    1.添加联系人   2.删除联系人   *****\n");
	printf("		*****    3.查找联系人   4.修改联系人   *****\n");
	printf("		*****    5.显示所有     6.清空所有     *****\n");
	printf("		*****    7.以名字排序   8.扩大或缩小   *****\n");
	printf("		*****    9.读取         0.退出并保存   *****\n");
	printf("		********************************************\n");
}
void test()
{
	struct Volume  VL;
	int input = 0;
	InitVolume(&VL);
	do
	{
		menu();
		printf("请输入你选择的功能-> ");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			AddPerson(&VL);
			break;
		case 2:
			DeletePerson(&VL);
			break;
		case 3:
			QueryPerson(&VL);
			break;
		case 4:
			ModifyPerson(&VL);
			break;
		case 5:
			LookPerson(&VL);
			break;
		case 6:
			EmptyPerson(&VL);
			break;
		case 7:
			SortPerson(&VL);
			break;
		case 8:
			ExpandReduce(&VL);
			break;
		case 9:
			ReadPerson(&VL);
			break;
		case 0:
			{
				SavePerson(&VL);
				Free(&VL);
				return;
			}
			break;
		default:
			printf("输入错误，请重新输入\n");
			Sleep(2000);
			break;
		}
		
	}while(1);
}
int main()
{
	test();
	return 0;
}
