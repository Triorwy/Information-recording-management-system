#define  _CRT_SECURE_NO_WARNINGS 1

#include "maillist.h"

void InitVolume(struct Volume  *vl)			
{
	vl->Exist = 0;
	vl->Modern = M;
	vl->M_people =(struct Message *)malloc(sizeof(struct Message)*M);//出现错误的地方，
	if(vl->M_people == NULL) //申请内存申请失败
	{
		printf("		Out of memory!\n");
		exit(EXIT_FAILURE);
	}
	memset(vl->M_people,0,M*sizeof(struct Message));//通讯录初始化为0
}
void menu2()
{
	printf("		*****************************\n");
	printf("		****        1.扩大       ****\n");
	printf("		****        2.减小       ****\n");
	printf("		*****************************\n");


}
//void  go_menu()
//{
//	char c = 0;
//	printf("返回菜单请按:Y\n");
//	fflush(stdin);
//	while(1)
//	{
//		scanf("%c",&c);
//		if('Y' == c)
//		{
//			return;
//		}
//		
//	}
//}
void ExpandReduce(struct Volume  *vl)
{
	int input2 = 0;
	int num = 0;
	struct Message *str = NULL;
	assert(vl);
	menu2();
	printf("请选择->");
	fflush(stdin);
	scanf("%d",&input2);
	if(Expand == input2)
	{
	    printf("请输入你想要扩大的数量\n");
		fflush(stdin);
		scanf("%d",&num);

		str = (struct Message *)realloc(vl->M_people,sizeof(struct Message)*(vl->Modern + num));

		if(NULL == str)
		{
			printf("Out of memory!\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			 vl->M_people = str;
			 vl->Modern = vl->Modern + num;
		}
	}
	if(Reduce == input2)
	{
		printf("请输入你想要缩小的数量\n");
		fflush(stdin);
		scanf("%d",&num);
		if(vl->Exist > (vl->Modern - num))
		{
			printf("缩小空间过小，不足以容纳当前人数\n");
			return ;
		}
		str = (struct Message *)realloc(vl->M_people,sizeof(struct Message)*(vl->Modern - num));
		if(NULL == str)
		{
			printf("Out of memory!\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			 vl->M_people = str;
			 vl->Modern = vl->Modern - num;
		}
	}
}
void Free(struct Volume  *vl)
{
	if(vl->M_people != NULL)
	{
		free(vl->M_people);
	}
	vl->M_people = NULL;
}
void AddPerson(struct Volume  *vl)
{
	int i = 0;
	assert(vl);
	if(vl->Modern == vl->Exist)
	{
		printf("通讯录已满,请扩大空间\n");
		return;
	}
	else
	{
		printf("请输入姓名->\n");
		fflush(stdin);
		scanf("%s",vl->M_people[vl->Exist].name);
		printf("请输入性别->\n");
		fflush(stdin);
		scanf("%s",vl->M_people[vl->Exist].sex);
		printf("请输入年龄->\n");
		fflush(stdin);
		scanf("%d",&(vl->M_people[vl->Exist].age));
		printf("请输入电话->\n");
		fflush(stdin);
		scanf("%s",vl->M_people[vl->Exist].telephone);
		printf("请输入地址->\n");
		fflush(stdin);
		scanf("%s",vl->M_people[vl->Exist].address);
	}
	vl->Exist++;//储存人数加1
}

static int find_people(struct Volume  *vl,char name[])
{
	int i = 0;
	assert(vl);
	printf("请输入联系人的姓名\n");
	fflush(stdin);
	scanf("%s",name);
	for(i = 0;i < vl->Exist;i++)
	{
		if(strcmp(vl->M_people[i].name,name) == 0)
		{
			return i;
		}
	
	}
	return -1;
}
void DeletePerson(struct Volume  *vl)
{
	
	int ret = 0;
	char name[20] = {0};
	assert(vl);
	ret = find_people(vl,name); //查找是否有这个人
	if(ret == -1)
	{
		printf("没有该联系人\n");
	}
	else
	{
		vl->M_people[ret] = vl->M_people[vl->Exist-1];
		vl->Exist--;
		printf("已删除\n");
	}
}
void QueryPerson(struct Volume  *vl)
{
	
	int ret = 0;
	char name[20] = {0};
	assert(vl);
	ret = find_people(vl,name); //查找是否有这个人
	if(ret == -1)
	{
		printf("没有该联系人\n");
		return ;
	}
	else
	{
		printf("%10s%10s%10s%10s%10s\n", "名字","性别", "年龄", "电话", "地址");
		printf("%9s",vl->M_people[ret].name);
		printf("%9s",vl->M_people[ret].sex);
		printf("%9d",vl->M_people[ret].age);
		printf("%9s",vl->M_people[ret].telephone);
		printf("%9s\n",vl->M_people[ret].address);
	}
}
void menu1()
{
	printf("****************************\n");
	printf("**  请选择你要修改的信息  **\n");
	printf("**        1.姓名          **\n");
	printf("**        2.性别          **\n");
	printf("**        3.年龄          **\n");
	printf("**        4.电话          **\n");
	printf("**        5.地址          **\n");
	printf("****************************\n");


}
void ModifyPerson(struct Volume  *vl)
{
	
	int input1 = 0;
	int ret = 0;
	char name[20] = {0};
	assert(vl);
	ret = find_people(vl,name); //查找是否有这个人
	if(ret == -1)
	{
		printf("没有该联系人\n");
		return ;
	}
	else
	{
		menu1();
		fflush(stdin);
		scanf("%d",&input1);
		switch(input1)
		{
		case 1:
			printf("请输入姓名->\n");
			fflush(stdin);
			scanf("%s",vl->M_people[ret].name);
			break;
		case 2:
			printf("请输入性别->\n");
			fflush(stdin);
			scanf("%s",vl->M_people[ret].sex);
			break;
		case 3:
			printf("请输入年龄->\n");
			fflush(stdin);
			scanf("%d",&(vl->M_people[ret].age));
			break;
		case 4:
			printf("请输入电话->\n");
			fflush(stdin);
			scanf("%s",vl->M_people[ret].telephone);
			break;
		case 5:
			printf("请输入地址->\n");
			scanf("%s",vl->M_people[ret].address);
		default:
			printf("输入错误，请重新输入\n");
			Sleep(2000);
			break;
		}
	}
}
void LookPerson(struct Volume  *vl)
{
	int i = 0;
	assert(vl);
	if (0 == vl->Exist)
    {
        printf("通讯录为空！\n");
        return;
    }
	printf("%12s%12s%12s%12s%12s\n", "名字","性别", "年龄", "电话", "地址");

	{
		printf("%11s",vl->M_people[i].name);
		printf("%11s",vl->M_people[i].sex);
		printf("%11d",vl->M_people[i].age);
		printf("%11s",vl->M_people[i].telephone);
		printf("%11s\n",vl->M_people[i].address);
	}
}

void EmptyPerson(struct Volume  *vl)
{
	vl->Exist = 0;
	printf("清空完毕\n");
	
}
void SortPerson(struct Volume  *vl)//以名字形式排序
{
	int i = 0;
	int j = 0;
	struct Message tmp;
	assert(vl);
	for(i = 0;i < vl->Exist - 1;i++)
	{
		for(j = 0;j < vl->Exist - 1 - i;j++)
		{
			if(strcmp(vl->M_people[j].name,vl->M_people[j+1].name) > 0)
			{
				tmp=vl->M_people[j];
				vl->M_people[j]=vl->M_people[j+1];
				vl->M_people[j+1]=tmp;
			}
		
		}
	
	}
	printf("排序成功\n");
}
void SavePerson(struct Volume  *vl)
{
	int i = 0;
	FILE *pFile=fopen("myconnect.txt","w");
	if(NULL == pFile)
	{
		perror("Error opening File");
		exit(1);
	}
	for(i = 0;i < vl->Exist;i++)
	{
		fwrite(&(vl->M_people[i]),sizeof(struct Message),1,pFile);
	}
	fclose(pFile);																																																			
}
void ReadPerson(struct Volume  *vl)
{
	int i = 0;
	struct Message tmp={0};
	FILE *pRead =fopen("myconnect.txt","r");
	
	if(NULL == pRead)
	{
		perror("Error opening File");
		exit(1);
	}
	//fread((&tmp),sizeof(struct Message),1,pRead);
	 while(fread((&tmp),sizeof(struct Message),1,pRead)!= 0)      
    { 
		if(vl->Exist == vl->Modern)
		{
			ExpandReduce(vl);
		}
		vl->M_people[i]=tmp;      
        i++;      
		vl->Exist++; 
	//	fread((&tmp),sizeof(struct Message),1,pRead);
    }
	fclose(pRead);
}
