// Program1_4.cpp : �������̨Ӧ�ó������ڵ㡣   //�ַ���ת��������
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//����һ����������ɵ��ַ����������ת�������������������"123"�����123.
//����Ӧ��λ������10^nȻ����Ӿ͵õ���Ӧ������
//���ǵ��ж��ǲ��Ǻ��з����ֵ��ַ����Լ������ţ��Ƿ��������Щ������ÿ��ǽ�ȥ
int StrToInt(const char* s,int n)
{//nΪ�ַ����ĳ���
	unsigned int sum=0;
	int sign=1;
	//�жϵ�һλ�ǲ���+����-�Ӷ�ȷ�����ֵ������ţ��������ַ����м���+-�ȷ����ֵ��ַ�
	static const int MAX_int=(int)((unsigned)~0>>1);
	static const int MIN_int=-(int)((unsigned)~0>>1)-1;
	for (int i = 0; i < n; i++)
	{
		if((s[i]=='+')||(s[i]=='-'))
		{
			if(s[0]=='-')
				sign=-1;
			continue;
		}
		if(s[i]==' ')
			continue;
		int t=static_cast<int>(s[i]-'0');//������ַ�ת��������

		if((sign>0) && (sum>(MAX_int/10) || (sum==MAX_int/10) && (t>MAX_int%10)))	
		{
			return sum=MAX_int;
			break;//��ʱ�Ѿ�����ˣ���������ֲ���Ҫ�ٿ�����
		}
		//����������-2147483647ʱ���Ѿ���������Է���������ĸ�����ֹͣת����
		if((sign<0) && (sum>(unsigned)(MIN_int/10) || (sum==(unsigned)MIN_int/10) && (t>(unsigned)MIN_int%10)))	
		{
			return sum=MIN_int;
			break;//��ʱ�Ѿ�����ˣ���������ֲ���Ҫ�ٿ�����
		}
		sum=sum*10+t;
	}
	return sign > 0 ? sum : -1*sum;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char str[]="+122434";
	int n=sizeof(str)/sizeof(char)-1;//�ַ����ĳ���
	char* s=str;
	cout<<StrToInt(s,n);

	system("pause");
	return 0;
}

