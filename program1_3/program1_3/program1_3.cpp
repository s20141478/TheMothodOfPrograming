// program1_3.cpp : �������̨Ӧ�ó������ڵ㡣
//����һ���ַ�������ӡ�����ַ������ַ����������У����磺�����ַ�����abc��,��������ַ�a,b,c�������г����������ַ���
//abc,acb,bca,bac,cab,cba
//ȫ������n!���������������������������ʱ�临�Ӷȶ���O(n!).
#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//����һ���ݹ�ʵ�֣����ַ�ʽ�Լ����ó���һ��Ҫ���Σ�

void calcAllPermutation(string &s,int from,int to)//from�������鿪ʼ�±꣬to������������±�
{
	
	if(to<=1)//
		return;
	if (from==to)
	{
		for(int i=0;i<=to;i++)
			cout<<s[i];
		cout<<endl;
	}
	else 
	{
		for (int i = from; i <= to; i++)
		{
			swap(s[i],s[from]);//��ʼ����˳��
			calcAllPermutation(s,from+1,to);//��֮ǰ�����Ļ����������¼���
			swap(s[i],s[from]);//���ص�����֮ǰ			
		}
	}
}

//���������ֵ������У�
//�����ҵ����������һ���������λԪ�ص�λ��i,Ȼ���ҵ���iλԪ�غ�������һ����������Ԫ��λ��j(j>iһ������)
//Ȼ�󽻻�i��j����Ԫ�ص�λ�ã��ٰѵ�iλ�Ժ��Ԫ�ط�ת�͵õ��˱ȿ�ʼʱ������һ�����С�Ȼ��ѭ���������輴�ɵõ����е��������
bool calcAllPermutation2(char* s,int n)
{	
	int t;//�ҵ����һ���������Ԫ��λ��t����Ȼ�ǴӺ���ǰ����ʡʱ��
	for (t = n-2; (t >= 0)&& (s[t+1]<=s[t]);--t )//t���±�
	{
		;
	}
	if(t<0)
		return false;
	//��ʱt��ֵ�������һ���������λԪ�ص��±�
	//��ȫ�ǽ��������λԪ�ؿ�ʼ����
	int k;//kΪ����ıȵ�iλԪ�ش��Ԫ�����һ��Ԫ���±�
	for (k = n-1; (k > t)&&(s[k]<=s[t]);--k)//���ֻֽⷨ����Ը�����ͬ���ַ����������ַ���ͬ����д�㷨
	{
		;
		//��ʱ��kΪ0��û�д�ʱi��û�����򣬼���ʼʱһ����������ϡ���ʱ���Կ����ȷ�ת�ٵݹ�ʹ�øú���
	}
	swap(s[t],s[k]);
	reverse(s+t+1,s+n); 
	//���ÿһ�εĽ��
	for (int i = 0; i < n; i++)
	{
		cout<<s[i]<<' ';
	}
	cout<<endl;
	return true;
}
//��һ������1.��֪�ַ����е��ַ��ǻ�����ͬ�ģ����ڰ����������������磺ab������������aa,ab,ba,bb����̰����ֵ���������е����
//���Բ��õݹ��˼������һ��������ʾ�Ѿ�������ַ��������������ﵽ�ַ����ĳ���ʱ�����
bool calcAllPermutation3(char* s,int n)
{
	//δ���ҵ�������������������
	int i;
	for (int i = 0; i < n; i++)
	{

	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	string str1="abc";
	calcAllPermutation(str1,0,2);
	cout<<str1;
	//���������ֵ������з�
	char str[]={'a','c','b','r'};
	sort(str,str+3);
	char* s=str;
	int len=sizeof(str)/sizeof(char);
	for (int i = 0; i < len; i++)
	{
		cout<<s[i]<<' ';
	}
	cout<<endl;
	bool flag=true;
	while(flag)
	{
		flag=calcAllPermutation2(s,len);
	}
	
	system("pause");
	return 0;
}

