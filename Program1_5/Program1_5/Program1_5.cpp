// Program1_5.cpp : 定义控制台应用程序的入口点。
//回文串判断的问题：回文串是指正读和反读都一样的字符串

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;
//从两头往中间扫描，时间复杂度是O(n),空间复杂度是O(1)。
//如果用下标来表示，其实用指针更合适
bool Ispalindrome(const char* s,int n)
{
	if(s==NULL)
		return false;
	//使用下标的表示法
	for (int i = 0; i < n/2; i++)
	{
		if (s[i] != s[n-1-i])
			return false;
	}
	//使用指针法
	/*
	const char* front,*back;
	front=s;
	back=s+n-1;
	while(front<back)
	{
		if (*front!=*back)
			return false;
		++front;
		--back;  
	}

	*/	
	return true;
}

//从中间往两头扫描，时间复杂度是O(n),空间复杂度是O(1)。类似上面的程序
bool Ispalindrome2(const char* s,int n)
{
	if(s==NULL)
		return false;
	//若使用数组下标的表示法则需要判断奇数偶数了
	//所以使用指针的表示法
	const char* front,*back;
	int m=((n>>1)-1)>=0? (n>>1)-1 : 0;//m定位到字符串中间的位置
	front=s+m;
	back=s+n-1-m;
	while (front>=0)
	{
		if(*front!=*back)
			return false;
		--front;
		++back;
	}
	return true;
}

//链表回文：判断单向链表是不是回文。
//对于单向链表，没有从两边开始遍历的直接办法，所以可以先遍历完一遍记录链表的长度。然后再从头部开始将前半段的元素压入一个栈中\
   然后从栈顶的元素开始与链表中断以后的元素比较知道链表元素为空，判断是否相同。但是这种方法会根据个数的奇偶性有所调整。
  
//书上的一种使用快慢指针的方法挺不错的。实现代码如下：
template<class T>
struct listNode	//链表节点的定义
{
	T value;//存储链表节点的数据域值
	listNode* next;//存储链表节点的链域值
	//一下部分的初始函数可以不需要的
	listNode(){}
	listNode(const T& element)
	{
		this->value=element;
	}
	listNode(const T& element,listNode<T>* next)
	{
		this->value=element;
		this->next=next;
	}
};
//判断链表是否是回文的具体实现
template<class T>
bool Ispalindrome3(listNode<T>* theNode)//listNode<T>* theNode是指向一个链表首节点的指针
{
	listNode<T>* slow=theNode;//慢指针指向形参链表的
	listNode<T>* fast=theNode;//快节点的指针,只有当fast的第二个元素是NUll时才为NULL
	bool flag=true;
	stack<listNode<T>*> stk;//声明一个空的栈
	while(fast!=NULL)//只要快指针没有到链尾则没有到中点
	{
		stk.push(slow);//栈是先进后出的
		slow=slow->next;//slow每次遍历一个元素
		fast=fast->next;//fast每次遍历一个元素，然后判断fast后面是否还有节点
		if(fast!=NULL)
			fast=fast->next;
		else
			flag=false;
	}
	
	//下面的这个if语句很重要这是对链表节点是奇数还是偶数所做的调整
	if (!flag)//若flag为true则个数为奇数，最后一次压入的是奇数中点的元素，相当于多压一次
		stk.pop();
	while(!stk.empty())
	{
		if((stk.top())->value==slow->value)
		{
			stk.pop();
			slow=slow->next;
		}
		else
			return false;
	}

	return true;
}

//栈回文的判断
//类似判断字符串是不是回文的，只不过使用栈的方式来解题而已
//将字符串加入栈中，栈顶到栈底的元素恰好是原来元素的逆序，一个一个比较，相等则出栈，不相等则不是回文
bool Ispalindrome4(const char* s,int n)
{
	if(s==NULL)
		return false;
	const char* p=s;
	stack<char> stkChar;//一个空栈用来存放char类型的字符
	while (p!=(p+n))
	{
		stkChar.push(*p);
		p++;
	}

	while(!stkChar.empty())
	{
		if(stkChar.top()==*s)
		{
			stkChar.pop();
			s++;
		}
		else
			return false;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

