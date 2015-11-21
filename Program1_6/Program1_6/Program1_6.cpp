// Program1_6.cpp : 定义控制台应用程序的入口点。
//给定一个字符串求他的最长回文子串的长度

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//中心扩展法：以某个字符为中心的前缀和后缀相同则是回文串
int longestPalindrom(char* s,int n)//复杂度O(n^2)
{//以i为中心字符的下标，j表示左右移动的距离
	int i,j,max=0,current=0;
	for (int i = 0; i < n; i++)
	{
		//当最长回文子串的长度为奇数时
		for (int j = 0; (i-j)>=0 && (i+j)<n; j++)//循环1
		{
			if(s[i-j]!=s[i+j])
			{
				break;
			}
			current=j*2+1;//每次离中心点的距离加1回文子串的长度的计算公式
			if(max<current)
				max=current;
		}
		//当最长回文子串的长度为偶数时
		for (int j = 0;(i-j)>=0 && (i+j+1)<n; j++)//循环2和循环1无论谁在前都一样，因为max为局部全局变量
		{
			if(s[i-j]!=s[i+j+1])
			{
				break;
			}
			current=j*2+2;//每次离中心点的距离加1回文子串的长度的计算公式
			if(max<current)
				max=current;
		}
	}
	return max;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char str[]="asafdahgkjhiwuehikjasdafdfasfasd";
	int len=sizeof(str)/sizeof(char)-1;//减去1是因为str的这种写法使他的结尾包含一个结束符
	char* s=str;
	cout<<longestPalindrom(s,len);
	system("pause");
	return 0;
}

