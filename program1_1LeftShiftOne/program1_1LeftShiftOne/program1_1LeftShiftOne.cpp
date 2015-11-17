// program1_1LeftShiftOne.cpp : 定义控制台应用程序的入口点。
//字符串的旋转：将一个字符串的前一半若干字符移到后面，后面字符移到前面，字符的顺序不变如：abcdef->defabc

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//方法一：递归调用：通过一个函数数次调用实现最终的结果
//该函数是将第一位移到最后一位，后面的字符均左移。（思考：可以使用队列的思想）
//课本上是char* a但是a为指针，有可能指向字符串常量，则不可以使用for里的赋值语句改变常量的值
void leftOne(char* a,int n)
{
	char t=a[0];//将第一位取出
	//后面的所有字符左移一位
	for (int i = 0; i < n-1; i++)
	{
		a[i]=a[i+1];
	}
	a[n-1]=t;//将字符的首位移到最后一位
}

void repeatRun(char* a,int n,int m)//m表示要执行的调用次数，可以在main中m=n/2等公式实现 
{
	while(m--)
		leftOne(a,n);
	//输出数组a
	for (int i = 0; i < n; i++)
	{
		cout<<a[i];	
	}
}

//方法二：使用二分法求解字符串的反转，同时针对奇数和偶数的长度作相应的调整
/*void reverseString(string &s,int n)//这是字符串的反转
{
	int m=n/2;	//无论奇数偶数都一样
	for (int i = 0; i < m; i++)
			swap(s[i],s[n-i-1]);
}*/
void reverseString(string &s,int t1,int t2)	
{
	int p=(t2-t1+1)/2;//取中点
	for (int i = 0; i < p; i++)
	{
		swap(s[t1+i],s[t2-i]);
	}
}
void repeatRun(string &s,int n)		//二分法的使用
{
	int m=n/2;
	if (n%2!=0)//字符串的长度为奇数，则中间的字符的位置不发生改变即s[n/2]不变
	{//奇数
		//m=n/2-1;
		reverseString(s,0,m-1);
		reverseString(s,m+1,n-1);
	}
	else
	{//偶数
	/*	m=n/2;*/
		reverseString(s,0,m-1);
		reverseString(s,m,n-1);
	}
	reverseString(s,0,n-1);
	cout<<s<<endl;
}


//上述解法还可以使用移位来实现，替换swap函数，
/*//课本上的方法：
void ReverseString(string& s ,int from,int to)//from是开始的元素下标，to是末尾元素下标
{
	while(from<to)	//互换前后两个元素
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

//举一反三习题：将句子中的单词顺序翻转，如:"i am a student."翻转后是"student. a am i"
//思路：先使用二分法将整个字符串反转，然后在以空格作为判别单词的整体性来将单词的顺序返回正常
void reverseWord(string& s,int t1,int t2)//t1为开始元素的下标，t2为元素的个数
{
	int m=(t2-t1)/2;
	for (int i = 0; i < m; i++)
			swap(s[t1+i],s[t2-i-1]);//此时字符串的顺序都倒过来了，然后将两个空格之间的单词再反转一遍就可以了
}

void reverseWordRun(string& s,int n)	//若形参为char* 则在main函数中具体的字符串只能用数组的形式实例化char[n],不能用C风格字符串
{
	reverseWord(s,0,n);
	cout<<s<<"this is the first reverse."<<endl;
	int i=0;//从反转后的字符串的首位开始
	for (int cnt=0; cnt < n;)//cnt为元素所在位置即元素下标值加1
	{
		if(s[cnt]==' ')
		{
			reverseWord(s,i,cnt);//每次遇到一个空格就将前一个单词反转
			i=cnt+1;//下一个单词的开始的下标为cnt+1
		}		
		cnt++;
	}
	cout<<s<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
/*//方法一：
	char a[6]={'a','b','c','d','e','f'};
	repeatRun(a,6,3);
	*/
//方法二：使用二分法
	string s="abcdef";
	int n=static_cast<int>(s.size());
	cout<<n<<endl;
	repeatRun(s,n);

//举一反三习题：将句子中的单词顺序翻转，如:"i am a student."翻转后是"student. a am i"
	string s2="i am a student.";
	int n2=static_cast<int>(s2.size());
	reverseWordRun(s2,n2);
	system("pause");
	return 0;
}

