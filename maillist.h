#ifndef __MAILLIST_H__
#define __MAILLIST_H__


#include <stdio.h>
#include <windows.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#define M 2 //默认通讯录大小


enum ER
{
	Expand = 1,
	Reduce

};
struct Message
{
	char name[20];//姓名
	char sex[10]; //性别
	int age;// 年龄
	char telephone[20]; //电话
	char address[100]; //地址

};
struct Volume  //通讯轮的容量
{
	int Modern; //当前最大的储存空间
	int Exist;   //现在存储的空间
	struct Message *M_people;
};

void InitVolume(struct Volume  *vl); //初始化函数
void ExpandReduce(struct Volume  *vl);//扩大或缩小通讯录空间
void Free(struct Volume  *vl);//释放动态内存大小

void AddPerson(struct Volume  *vl);//添加联系人信息 
void DeletePerson(struct Volume  *vl);//删除指定联系人信息
void QueryPerson(struct Volume  *vl);//查找指定联系人信息
void ModifyPerson(struct Volume  *vl);//修改指定联系人信息
void LookPerson(struct Volume  *vl);//显示所有联系人信息
void EmptyPerson(struct Volume  *vl);//清空所有联系人
void SortPerson(struct Volume  *vl);//以名字排序所有联系人

void SavePerson(struct Volume  *vl);//以二进制文件形式保存
void ReadPerson(struct Volume  *vl);//以二进制文件形式读取



#endif //__MAILLIST_H__
