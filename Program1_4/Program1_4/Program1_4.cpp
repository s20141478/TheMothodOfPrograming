// Program1_4.cpp : 定义控制台应用程序的入口点。   //字符串转换成整数
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//输入一个由数字组成的字符串，请把它转换成整数并输出。例如"123"输出是123.
//将对应的位数乘以10^n然后相加就得到相应的整数
//但是得判断是不是含有非数字的字符，以及正负号，是否溢出，这些情况都得考虑进去
int StrToInt(const char* s,int n)
{//n为字符串的长度
	unsigned int sum=0;
	int sign=1;
	//判断第一位是不是+或者-从而确定数字的正负号，不考虑字符串中间有+-等非数字的字符
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
		int t=static_cast<int>(s[i]-'0');//将这个字符转换成整数

		if((sign>0) && (sum>(MAX_int/10) || (sum==MAX_int/10) && (t>MAX_int%10)))	
		{
			return sum=MAX_int;
			break;//此时已经溢出了，后面的数字不需要再考虑了
		}
		//当负数大于-2147483647时就已经溢出，所以返回这个最大的负数就停止转换了
		if((sign<0) && (sum>(unsigned)(MIN_int/10) || (sum==(unsigned)MIN_int/10) && (t>(unsigned)MIN_int%10)))	
		{
			return sum=MIN_int;
			break;//此时已经溢出了，后面的数字不需要再考虑了
		}
		sum=sum*10+t;
	}
	return sign > 0 ? sum : -1*sum;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char str[]="+122434";
	int n=sizeof(str)/sizeof(char)-1;//字符串的长度
	char* s=str;
	cout<<StrToInt(s,n);

	system("pause");
	return 0;
}

