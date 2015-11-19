// program1_2boolStringContain.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;

//���ַ�����ʱ�临�Ӷ���O(mn):�������ַ������ȵĳ˻�
bool boolStringContain1(string& a,string& b)
{
	int len1=static_cast<int>(a.size());
	int len2=static_cast<int>(b.size());
	if(len1<len2)
	{
		cout<<"your input is wrong,please correct the string which you input."<<endl;
		return false;
	}
	for (int i = 0; i < len2; i++)
	{
		int j;
		for (j = 0; j < len1 ; )
		{
			if (b[i]==a[j])//�����ǰ����������˴�ѭ��
				break;			
			++j;
		}
		if(j>=len1)//����˵����������ַ���������a�У�ֱ�ӽ������򣬷���false
			return false;
	}
	return true;
}
//�ڶ��ַ������Ƚ������ַ�����������Ȼ����һ��һ���ıȽ�
bool boolStringContain2(string& a,string& b)
{
	int len1=static_cast<int>(a.size());
	int len2=static_cast<int>(b.size());
	if(len1<len2)
	{
		cout<<"your input is wrong,please correct the string which you input."<<endl;
		return false;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());//�������������Ժ�ֻҪ�Ƚ������ַ���ǰm���ַ��Ϳ����ˡ��磺ABC��BC
	for (int i = 0,j=0; i < len2;)
	{
		while((i<len1) && (a[i]<b[j]))//�������ǳ���Ҫ�����ܵ���
			i++;
		if ((i>=len1)||(a[i]>b[j]))
			return false;
		/*if (a[i]!=b[j])//�����������ʱ�Ͳ�������
			return false;
		i++;
		*/
		j++;
	}
	return true;
}
//������ʹ�ü�������:ʹ��λ�����������Ӧλ���Ƿ�����ĸ
bool boolStringContain3(string& a,string& b)
{
	int len1=static_cast<int>(a.size());
	int len2=static_cast<int>(b.size());
	if(len1<len2)
	{
		cout<<"your input is wrong,please correct the string which you input."<<endl;
		return false;
	}
	bitset<26> flag;//��ʼ�Ǹ�λΪ0
	for (int i = 0; i < len1; i++)
	{//��Ϊֻ��26����ĸ������26��λ����ʾ
		flag.set(a[i]-'A');//����Ӧλ�õ���ĸ��Ϊ1�����ĸ���ĸû�г������λû��ʹ�ø���䣬Ϊ0
	}
	for (int i = 0; i < len2; i++)
	{
		if(!flag.test(b[i]-'A'))
			return false;
	}
	return true;
}

//����ʹ��ջ�ķ�ʽ���洢b����a��ƥ�䣬ƥ��һ����ջ�е���ʱ�临�Ӷ����O(n+n-1+n-2+..+n-m)���Բ�̫�ʺ�

//�����ֵ��ɢ�б��ʹ�ò���̫��������

//��λ�ʣ�
//��������ַ����е��ַ�һ�������ִ���Ҳһ����ֻ�ǳ��ֵ�˳��һ��������Ϊ�������ַ������ֵ��ַ��������磺abc��bca��Ϊ�ֵ��ַ���
//���ṩһ���ַ����������ֵ������Ѹ�ٵ��ҵ������ֵ��ַ�����
//��ϰ��Ѱ���ֵ��ַ���
//�����ж��Ƿ񳤶���ȣ�������϶������ֵ��ַ���

bool boolStringContain4(string& a,string& b)
{
	int len1=static_cast<int>(a.size());
	int len2=static_cast<int>(b.size());
	if(len1!=len2)
	{
		cout<<"the two strings are not brothers strings."<<endl;
		return false;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if(!a.compare(b))//��Ϊ��ȷ��ص���0�����ڷ��ص���������С�ڷ��ص��Ǹ���
		return false;
	else
		return true;
}
//�����ϻ�����ʹ�������ĳ˻����жϣ������Ϊ�ֵ��ַ���

int _tmain(int argc, _TCHAR* argv[])
{
	string a="ABCD",b="CB";
	//����1��
	cout<<boolStringContain1(a,b)<<endl;
	//����2��
	cout<<boolStringContain2(a,b)<<endl;
	system("pause");
	return 0;
}

