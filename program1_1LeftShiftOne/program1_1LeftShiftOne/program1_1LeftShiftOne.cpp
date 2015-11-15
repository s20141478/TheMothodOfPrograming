// program1_1LeftShiftOne.cpp : 定义控制台应用程序的入口点。
//字符串的旋转：将一个字符串的前一半若干字符移到后面，后面字符移到前面，字符的顺序不变如：abcdef->defabc

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//方法一：通过一个函数数次调用实现最终的结果
//该函数是将第一位移到最后一位，后面的字符均左移。（思考：可以使用队列的思想）
//课本上是char* a但是a为指针，有可能指向字符串常量，则不可以使用for里的赋值语句改变常量的值
void leftOne(char* a,int n)
{
	char t=a[0];//将第一位取出
	//后面的所有字符左移一位
	for (int i = 0; i < n-1; i++)
	{
		a[i]=a[i+1];
	}
	a[n-1]=t;//将字符的首位移到最后一位
}

void repeatRun(char* a,int n,int m)//m表示要执行的调用次数，可以在main中m=n/2等公式实现 
{
	while(m--)
		leftOne(a,n);
	//输出数组a
	for (int i = 0; i < n; i++)
	{
		cout<<a[i];	
	}
}




int _tmain(int argc, _TCHAR* argv[])
{
	char a[6]={'a','b','c','d','e','f'};
	repeatRun(a,6,3);

	system("pause");
	return 0;
}

