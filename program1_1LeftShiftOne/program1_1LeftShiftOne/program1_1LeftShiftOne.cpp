// program1_1LeftShiftOne.cpp : �������̨Ӧ�ó������ڵ㡣
//�ַ�������ת����һ���ַ�����ǰһ�������ַ��Ƶ����棬�����ַ��Ƶ�ǰ�棬�ַ���˳�򲻱��磺abcdef->defabc

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//����һ��ͨ��һ���������ε���ʵ�����յĽ��
//�ú����ǽ���һλ�Ƶ����һλ��������ַ������ơ���˼��������ʹ�ö��е�˼�룩
//�α�����char* a����aΪָ�룬�п���ָ���ַ����������򲻿���ʹ��for��ĸ�ֵ���ı䳣����ֵ
void leftOne(char* a,int n)
{
	char t=a[0];//����һλȡ��
	//����������ַ�����һλ
	for (int i = 0; i < n-1; i++)
	{
		a[i]=a[i+1];
	}
	a[n-1]=t;//���ַ�����λ�Ƶ����һλ
}

void repeatRun(char* a,int n,int m)//m��ʾҪִ�еĵ��ô�����������main��m=n/2�ȹ�ʽʵ�� 
{
	while(m--)
		leftOne(a,n);
	//�������a
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

