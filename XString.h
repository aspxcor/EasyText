#include "stdafx.h"
#include <iostream>
#include "CharInfo.h"
using namespace std;
class MyString {
private:
	char* ch;
	int length;

public:
	MyString() {
		this->length = 0;
	}
	MyString(char* c) {
		length = strlen(c);
		ch = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->ch[i] = c[i];
		}
		ch[length] = '\0';
	}
	~MyString() {
		delete(ch);

	}
	int strlength();//���ĳ���
	int strcompare(MyString s, char* t);//���ıȽ� ��s>t��������ַ���������s=t����0,��s<t����-1
	int clearstring();//��մ�.0����ʧ�ܣ�1����ɹ�
	int concat(MyString& n, char* t);//nΪ���ص����ַ���
	char* data();	//���ص�ǰ������ַ�������
	int indexof(char* t);//�����Ӵ�����λ��,-1����ʧ�ܣ�
	char* substring(int start, int length);//start��0��ʼ��lengthָ����ȡ�ַ�������
	void  replace(MyString& n, MyString& s, char* c, char* flag, bool search);//n�������ַ�����s����ԭ���ַ�����c�滻�ַ�����flag�滻��־��search�����Ƿ�ȫ���滻��
	CharInfo CharCount();//�����ַ���ͳ����Ϣ�Ľṹ��
	void setchar(char* c);//��ch���鸳ֵ
	void insert(char* c, int index);//cָ�������ݣ�index�������λ��
	char* operator+(char* c);//�������+������---ʹ�÷���Mystring s=s+"12321";
	void  operator=(char* c);//�������=������

};
int MyString::strlength() {
	return this->length;
}
void MyString::setchar(char* c) {
	this->length = strlen(c);
	this->ch = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->ch[i] = c[i];
	}
	ch[length] = '\0';
}
//��index+1����ǰλ�ĺ�һλ����λ�ã�index��0��ʼ���㣩��ʼ��ȡ���ֳ�2�룬����ǰ�벿->�����������->���ƺ�벿
void MyString::insert(char* c, int index) {
	int nLength = strlen(c) + this->length;
	char* k = new char[nLength + 1];

	if (index >= 0)
	{
		char* a = this->substring(0, index + 1);

		char* b = this->substring(index + 1, this->length - index + 1);
		cout << a << " " << b << endl;
		for (int i = 0; i < (int)strlen(a); i++)
		{
			k[i] = a[i];
		}

		for (int i = 0; i < (int)strlen(c); i++)
		{
			k[i + strlen(a)] = c[i];
		}

		for (int i = 0; i < (int)strlen(b); i++)
		{
			k[strlen(a) + strlen(c) + i] = b[i];
		}
		k[nLength] = '\0';


		this->ch = k;
	}
	else {
		cout << "�Ҳ�������λ��" << endl;
	}

}
int MyString::strcompare(MyString s, char* t) {
	for (int i = 0; i < s.length && strlen(t); i++) {
		if (s.ch[i] != t[i])
		{
			return s.ch[i] - t[i];
		}
		else
		{
			return s.length - strlen(t);
		}
	}
	return 0;
}
int MyString::clearstring() {
	if (this->ch)
	{
		delete(this->ch);
		this->ch = NULL;
		this->length = 0;
		return 1;
	}
	else {
		return 0;
	}

}
int MyString::concat(MyString& n, char* t) {
	if (clearstring())
	{
		if (n.ch = new char[this->length + strlen(t) + 1])
		{
			for (int i = 0; i < this->length; i++) {
				n.ch[i] = this->ch[i];
			}
			for (int i = 0; i < strlen(t); i++) {
				n.ch[i + this->length - 1] = t[i];
			}
			n.ch[this->length + strlen(t)] = '\0';
			n.length = this->length + strlen(t);
			return 1;
		}
		else {
			cout << "�����ڴ�ʧ��" << endl;
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
char* MyString::data() {
	return this->ch;
}
//���ݷ�����
int MyString::indexof(char* t) {
	int i = 0, j = 0;
	int slen = strlen(this->ch);
	int plen = strlen(t);

	while (j < plen && i < slen) {
		if (this->ch[i] == t[j]) {
			i++;
			j++;

		}
		else {
			i = i - j + 1;
			j = 0;

		}
	}

	if (j == plen)
	{
		return i - plen + 1;
	}
	else
	{
		return 0;
	}
}
//��ȡ
char* MyString::substring(int start, int length) {
	if (char* c = new char[length + 1]) {

		for (int i = 0; i < length; i++)
		{
			c[i] = this->ch[start + i];
		}
		c[length] = '\0';
		return c;
	}
	else {
		return NULL;
	}

}
//�滻
void MyString::replace(MyString& n, MyString& s, char* pSrc, char* pDst, bool search)
{
	char* pi, * po, * p;
	int nSrcLen, nDstLen, nLen;

	// ָ�������ַ������ζ�ָ��.   
	pi = s.ch;
	// ָ������ַ������ζ�ָ��.   
	po = n.ch;
	// ���㱻�滻�����滻���ĳ���.   
	nSrcLen = strlen(pSrc);
	nDstLen = strlen(pDst);

	// ����piָ���ַ����е�һ�γ����滻����λ��,������ָ��(�Ҳ����򷵻�null).   
	p = strstr(pi, pSrc);
	if (p)
	{
		// �ҵ�.   
		while (p)
		{
			// ���㱻�滻��ǰ���ַ����ĳ���.   
			nLen = (int)(p - pi);
			// ���Ƶ�����ַ���.   
			memcpy(po, pi, nLen);
			memcpy(po + nLen, pDst, nDstLen);
			// �������滻��.   
			pi = p + nSrcLen;
			// ����ָ���������ָ��λ��.   
			po = po + nLen + nDstLen;
			// ��������.
			if (search) {
				p = strstr(pi, pSrc);
			}
			else {
				break;
			}

		}
		// ����ʣ���ַ���.   
		strcpy(po, pi);
	}
	else
	{
		// û���ҵ���ԭ������.   
		strcpy(po, pi);
	}
}
CharInfo MyString::CharCount() {

	CharInfo charinfo;
	charinfo.length = 0;
	charinfo.number = 0;
	charinfo.schar = 0;
	charinfo.bchar = 0;
	charinfo.space = 0;
	for (int i = 0;; i++)
	{
		charinfo.length = i;
		if (this->ch[i] >= 65 && this->ch[i] <= 90)   //�ж��Ƿ�ΪСд
		{
			charinfo.bchar += 1;
			continue;
		}
		if (this->ch[i] >= 97 && this->ch[i] <= 122)     //�ж��Ƿ�Ϊ��д
		{
			charinfo.schar += 1;
			continue;
		}
		if (this->ch[i] == 32)     //�ж��Ƿ�Ϊ�ո�
		{
			charinfo.space += 1;
			continue;
		}
		if (this->ch[i] >= '0' && this->ch[i] <= '9')   //�ж��Ƿ�Ϊ����
		{
			charinfo.number += 1;
			continue;
		}
		if (this->ch[i] == '\0') break;      //�ж��ַ����Ƿ����

	}
	charinfo.length = this->length;
	return charinfo;
}
char* MyString::operator+(char* c) {
	char* nch = new char[strlen(this->ch) + strlen(c) + 1];
	for (int i = 0; i < this->length; i++)
	{
		nch[i] = this->ch[i];
	}
	for (int i = 0; i < strlen(c); i++)
	{
		nch[i + strlen(this->ch)] = c[i];
	}
	nch[strlen(this->ch) + strlen(c) + 1] = '\0';
	return nch;
}
void  MyString::operator =(char* c) {
	this->length = strlen(c);
	this->ch = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->ch[i] = c[i];
	}
	ch[length] = '\0';

}