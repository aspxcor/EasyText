#include "stdafx.h"
#include<iostream>  
using namespace std;
struct linkStack {
	char* data;
	linkStack* next;
};
//��ջ�ĳ�ʼ��  
linkStack* initStack()
{
	linkStack* top = new linkStack;
	top = NULL;
	return top;
}
//�ж���ջ�Ƿ�Ϊ��  
bool isEmpty(linkStack* stack)
{
	if (NULL == stack)
		return true;
	return false;
}
//��ջ��ջ  
linkStack* push(linkStack * stack, char* data)
{
	linkStack* node = new linkStack;
	node->data = data;
	node->next = stack;
	stack = node;
	return stack;
}
//��ջ��ջ  
linkStack* pop(linkStack * stack)
{
	if (stack != NULL)
	{
		//cout<<stack->data;
		stack = stack->next;
	}
	else
		cout << "�ǿ�ջ!";
	return stack;
}
//��ջ�ĳ���  
int getLength(linkStack * stack)
{
	int length = 0;
	if (stack == NULL)
		return 0;
	while (stack != NULL)
	{
		length++;
		stack = stack->next;
	}
	return length;
}
//ȡ��ջ��Ԫ��  
char* getTop(linkStack * stack)
{
	char* temp;
	temp = stack->data;
	return temp;
}