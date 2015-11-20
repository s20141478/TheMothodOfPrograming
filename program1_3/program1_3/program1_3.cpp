// program1_3.cpp : 定义控制台应用程序的入口点。
//输入一个字符串，打印出该字符串中字符的所有排列；例如：输入字符串“abc”,则输出由字符a,b,c所能排列出来的所有字符串
//abc,acb,bca,bac,cab,cba
//全排列有n!种排列情况，所以无论怎样他的时间复杂度都是O(n!).
#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//方法一：递归实现：这种方式自己不擅长，一定要记牢，

void calcAllPermutation(string &s,int from,int to)//from代表数组开始下标，to代表数组结束下标
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
			swap(s[i],s[from]);//开始调换顺序
			calcAllPermutation(s,from+1,to);//在之前调换的基础上再往下继续
			swap(s[i],s[from]);//返回到调换之前			
		}
	}
}

//方法二：字典序排列：
//首先找到排列中最后一个升序的首位元素的位置i,然后找到第i位元素后面的最后一个大于他的元素位置j(j>i一定满足)
//然后交换i，j两个元素的位置，再把第i位以后的元素翻转就得到了比开始时的数下一个排列。然后循环上述步骤即可得到所有的排列组合
bool calcAllPermutation2(char* s,int n)
{	
	int t;//找到最后一个升序的首元素位置t，当然是从后往前找最省时间
	for (t = n-2; (t >= 0)&& (s[t+1]<=s[t]);--t )//t是下标
	{
		;
	}
	if(t<0)
		return false;
	//此时t的值就是最后一个升序的首位元素的下标
	//若全是降序则从首位元素开始调换
	int k;//k为后面的比第i位元素大的元素最后一个元素下标
	for (k = n-1; (k > t)&&(s[k]<=s[t]);--k)//这种解法只是针对各不相同的字符若有两个字符相同则另写算法
	{
		;
		//此时若k为0则没有此时i比没有升序，即初始时一定是最大的组合。此时可以考虑先翻转再递归使用该函数
	}
	swap(s[t],s[k]);
	reverse(s+t+1,s+n); 
	//输出每一次的结果
	for (int i = 0; i < n; i++)
	{
		cout<<s[i]<<' ';
	}
	cout<<endl;
	return true;
}
//举一反三：1.已知字符串中的字符是互不相同的，现在把他们任意排列例如：ab则任意排列是aa,ab,ba,bb，编程按照字典序输出所有的组合
//可以采用递归的思想设置一个变量表示已经输出的字符个数，当个数达到字符串的长度时就输出
bool calcAllPermutation3(char* s,int n)
{
	//未能找到方法？？？？？？？
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
	//方法二：字典序排列法
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

