// Program1_6.cpp : �������̨Ӧ�ó������ڵ㡣
//����һ���ַ���������������Ӵ��ĳ���

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//������չ������ĳ���ַ�Ϊ���ĵ�ǰ׺�ͺ�׺��ͬ���ǻ��Ĵ�
int longestPalindrom(char* s,int n)//���Ӷ�O(n^2)
{//��iΪ�����ַ����±꣬j��ʾ�����ƶ��ľ���
	int i,j,max=0,current=0;
	for (int i = 0; i < n; i++)
	{
		//��������Ӵ��ĳ���Ϊ����ʱ
		for (int j = 0; (i-j)>=0 && (i+j)<n; j++)//ѭ��1
		{
			if(s[i-j]!=s[i+j])
			{
				break;
			}
			current=j*2+1;//ÿ�������ĵ�ľ����1�����Ӵ��ĳ��ȵļ��㹫ʽ
			if(max<current)
				max=current;
		}
		//��������Ӵ��ĳ���Ϊż��ʱ
		for (int j = 0;(i-j)>=0 && (i+j+1)<n; j++)//ѭ��2��ѭ��1����˭��ǰ��һ������ΪmaxΪ�ֲ�ȫ�ֱ���
		{
			if(s[i-j]!=s[i+j+1])
			{
				break;
			}
			current=j*2+2;//ÿ�������ĵ�ľ����1�����Ӵ��ĳ��ȵļ��㹫ʽ
			if(max<current)
				max=current;
		}
	}
	return max;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char str[]="asafdahgkjhiwuehikjasdafdfasfasd";
	int len=sizeof(str)/sizeof(char)-1;//��ȥ1����Ϊstr������д��ʹ���Ľ�β����һ��������
	char* s=str;
	cout<<longestPalindrom(s,len);
	system("pause");
	return 0;
}

