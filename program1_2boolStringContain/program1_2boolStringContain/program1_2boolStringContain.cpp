// program1_2boolStringContain.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;

//这种方法的时间复杂度是O(mn):即两个字符串长度的乘积
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
			if (b[i]==a[j])//如果当前相等则跳出此次循环
				break;			
			++j;
		}
		if(j>=len1)//否则说明至少这个字符不包含在a中，直接结束程序，返回false
			return false;
	}
	return true;
}
//第二种方法是先将两个字符串进行排序然后在一个一个的比较
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
	sort(b.begin(),b.end());//经过快速排序以后只要比较两个字符串前m个字符就可以了。如：ABC，BC
	for (int i = 0,j=0; i < len2;)
	{
		while((i<len1) && (a[i]<b[j]))//这两步非常重要，不能等于
			i++;
		if ((i>=len1)||(a[i]>b[j]))
			return false;
		/*if (a[i]!=b[j])//对于以上情况时就不可以了
			return false;
		i++;
		*/
		j++;
	}
	return true;
}
//还可以使用计数运算:使用位运算来标记相应位置是否有字母
bool boolStringContain3(string& a,string& b)
{
	int len1=static_cast<int>(a.size());
	int len2=static_cast<int>(b.size());
	if(len1<len2)
	{
		cout<<"your input is wrong,please correct the string which you input."<<endl;
		return false;
	}
	bitset<26> flag;//初始是各位为0
	for (int i = 0; i < len1; i++)
	{//因为只有26个字母所以用26个位来表示
		flag.set(a[i]-'A');//将对应位置的字母置为1，若哪个字母没有出现则该位没有使用该语句，为0
	}
	for (int i = 0; i < len2; i++)
	{
		if(!flag.test(b[i]-'A'))
			return false;
	}
	return true;
}

//可以使用栈的方式来存储b，用a来匹配，匹配一个从栈中但是时间复杂度最坏是O(n+n-1+n-2+..+n-m)所以不太适合

//对于字典或散列表的使用不是太懂？？？

//变位词：
//如果两个字符串中的字符一样，出现次数也一样，只是出现的顺序不一样，则认为这两个字符串是兄弟字符串，例如：abc和bca即为兄弟字符串
//现提供一个字符串请问在字典中如何迅速地找到他的兄弟字符串？
//练习题寻找兄弟字符串
//首先判断是否长度相等，不等则肯定不是兄弟字符串

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
	if(!a.compare(b))//因为相等返回的是0，大于返回的是正数，小于返回的是负数
		return false;
	else
		return true;
}
//理论上还可以使用素数的乘积来判断，相等则为兄弟字符串

int _tmain(int argc, _TCHAR* argv[])
{
	string a="ABCD",b="CB";
	//方法1：
	cout<<boolStringContain1(a,b)<<endl;
	//方法2：
	cout<<boolStringContain2(a,b)<<endl;
	system("pause");
	return 0;
}

