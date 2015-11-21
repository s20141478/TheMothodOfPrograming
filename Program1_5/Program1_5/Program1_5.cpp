// Program1_5.cpp : �������̨Ӧ�ó������ڵ㡣
//���Ĵ��жϵ����⣺���Ĵ���ָ�����ͷ�����һ�����ַ���

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;
//����ͷ���м�ɨ�裬ʱ�临�Ӷ���O(n),�ռ临�Ӷ���O(1)��
//������±�����ʾ����ʵ��ָ�������
bool Ispalindrome(const char* s,int n)
{
	if(s==NULL)
		return false;
	//ʹ���±�ı�ʾ��
	for (int i = 0; i < n/2; i++)
	{
		if (s[i] != s[n-1-i])
			return false;
	}
	//ʹ��ָ�뷨
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

//���м�����ͷɨ�裬ʱ�临�Ӷ���O(n),�ռ临�Ӷ���O(1)����������ĳ���
bool Ispalindrome2(const char* s,int n)
{
	if(s==NULL)
		return false;
	//��ʹ�������±�ı�ʾ������Ҫ�ж�����ż����
	//����ʹ��ָ��ı�ʾ��
	const char* front,*back;
	int m=((n>>1)-1)>=0? (n>>1)-1 : 0;//m��λ���ַ����м��λ��
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

//������ģ��жϵ��������ǲ��ǻ��ġ�
//���ڵ�������û�д����߿�ʼ������ֱ�Ӱ취�����Կ����ȱ�����һ���¼����ĳ��ȡ�Ȼ���ٴ�ͷ����ʼ��ǰ��ε�Ԫ��ѹ��һ��ջ��\
   Ȼ���ջ����Ԫ�ؿ�ʼ�������ж��Ժ��Ԫ�رȽ�֪������Ԫ��Ϊ�գ��ж��Ƿ���ͬ���������ַ�������ݸ�������ż������������
  
//���ϵ�һ��ʹ�ÿ���ָ��ķ���ͦ����ġ�ʵ�ִ������£�
template<class T>
struct listNode	//����ڵ�Ķ���
{
	T value;//�洢����ڵ��������ֵ
	listNode* next;//�洢����ڵ������ֵ
	//һ�²��ֵĳ�ʼ�������Բ���Ҫ��
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
//�ж������Ƿ��ǻ��ĵľ���ʵ��
template<class T>
bool Ispalindrome3(listNode<T>* theNode)//listNode<T>* theNode��ָ��һ�������׽ڵ��ָ��
{
	listNode<T>* slow=theNode;//��ָ��ָ���β������
	listNode<T>* fast=theNode;//��ڵ��ָ��,ֻ�е�fast�ĵڶ���Ԫ����NUllʱ��ΪNULL
	bool flag=true;
	stack<listNode<T>*> stk;//����һ���յ�ջ
	while(fast!=NULL)//ֻҪ��ָ��û�е���β��û�е��е�
	{
		stk.push(slow);//ջ���Ƚ������
		slow=slow->next;//slowÿ�α���һ��Ԫ��
		fast=fast->next;//fastÿ�α���һ��Ԫ�أ�Ȼ���ж�fast�����Ƿ��нڵ�
		if(fast!=NULL)
			fast=fast->next;
		else
			flag=false;
	}
	
	//��������if������Ҫ���Ƕ�����ڵ�����������ż�������ĵ���
	if (!flag)//��flagΪtrue�����Ϊ���������һ��ѹ����������е��Ԫ�أ��൱�ڶ�ѹһ��
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

//ջ���ĵ��ж�
//�����ж��ַ����ǲ��ǻ��ĵģ�ֻ����ʹ��ջ�ķ�ʽ���������
//���ַ�������ջ�У�ջ����ջ�׵�Ԫ��ǡ����ԭ��Ԫ�ص�����һ��һ���Ƚϣ�������ջ����������ǻ���
bool Ispalindrome4(const char* s,int n)
{
	if(s==NULL)
		return false;
	const char* p=s;
	stack<char> stkChar;//һ����ջ�������char���͵��ַ�
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

