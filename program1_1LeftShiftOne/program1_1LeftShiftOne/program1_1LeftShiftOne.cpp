// program1_1LeftShiftOne.cpp : �������̨Ӧ�ó������ڵ㡣
//�ַ�������ת����һ���ַ�����ǰһ�������ַ��Ƶ����棬�����ַ��Ƶ�ǰ�棬�ַ���˳�򲻱��磺abcdef->defabc

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//����һ���ݹ���ã�ͨ��һ���������ε���ʵ�����յĽ��
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

//��������ʹ�ö��ַ�����ַ����ķ�ת��ͬʱ���������ż���ĳ�������Ӧ�ĵ���
/*void reverseString(string &s,int n)//�����ַ����ķ�ת
{
	int m=n/2;	//��������ż����һ��
	for (int i = 0; i < m; i++)
			swap(s[i],s[n-i-1]);
}*/
void reverseString(string &s,int t1,int t2)	
{
	int p=(t2-t1+1)/2;//ȡ�е�
	for (int i = 0; i < p; i++)
	{
		swap(s[t1+i],s[t2-i]);
	}
}
void repeatRun(string &s,int n)		//���ַ���ʹ��
{
	int m=n/2;
	if (n%2!=0)//�ַ����ĳ���Ϊ���������м���ַ���λ�ò������ı伴s[n/2]����
	{//����
		//m=n/2-1;
		reverseString(s,0,m-1);
		reverseString(s,m+1,n-1);
	}
	else
	{//ż��
	/*	m=n/2;*/
		reverseString(s,0,m-1);
		reverseString(s,m,n-1);
	}
	reverseString(s,0,n-1);
	cout<<s<<endl;
}


//�����ⷨ������ʹ����λ��ʵ�֣��滻swap������
/*//�α��ϵķ�����
void ReverseString(string& s ,int from,int to)//from�ǿ�ʼ��Ԫ���±꣬to��ĩβԪ���±�
{
	while(from<to)	//����ǰ������Ԫ��
	{
		char t=s[from];
		s[from++]=s[to];
		s[to--]=t;
	}
}
void LeftRotateString(string& s,int n,int m)
{
	m%=n;
	ReverseString(s,0,m-1);
	ReverseString(s,m,n-1);
	ReverseString(s,0,m-1);
}
*/

//��һ����ϰ�⣺�������еĵ���˳��ת����:"i am a student."��ת����"student. a am i"
//˼·����ʹ�ö��ַ��������ַ�����ת��Ȼ�����Կո���Ϊ�б𵥴ʵ��������������ʵ�˳�򷵻�����
void reverseWord(string& s,int t1,int t2)//t1Ϊ��ʼԪ�ص��±꣬t2ΪԪ�صĸ���
{
	int m=(t2-t1)/2;
	for (int i = 0; i < m; i++)
			swap(s[t1+i],s[t2-i-1]);//��ʱ�ַ�����˳�򶼵������ˣ�Ȼ�������ո�֮��ĵ����ٷ�תһ��Ϳ�����
}

void reverseWordRun(string& s,int n)	//���β�Ϊchar* ����main�����о�����ַ���ֻ�����������ʽʵ����char[n],������C����ַ���
{
	reverseWord(s,0,n);
	cout<<s<<"this is the first reverse."<<endl;
	int i=0;//�ӷ�ת����ַ�������λ��ʼ
	for (int cnt=0; cnt < n;)//cntΪԪ������λ�ü�Ԫ���±�ֵ��1
	{
		if(s[cnt]==' ')
		{
			reverseWord(s,i,cnt);//ÿ������һ���ո�ͽ�ǰһ�����ʷ�ת
			i=cnt+1;//��һ�����ʵĿ�ʼ���±�Ϊcnt+1
		}		
		cnt++;
	}
	cout<<s<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
/*//����һ��
	char a[6]={'a','b','c','d','e','f'};
	repeatRun(a,6,3);
	*/
//��������ʹ�ö��ַ�
	string s="abcdef";
	int n=static_cast<int>(s.size());
	cout<<n<<endl;
	repeatRun(s,n);

//��һ����ϰ�⣺�������еĵ���˳��ת����:"i am a student."��ת����"student. a am i"
	string s2="i am a student.";
	int n2=static_cast<int>(s2.size());
	reverseWordRun(s2,n2);
	system("pause");
	return 0;
}

