/*
�ο� Modern Compiler Implementation in C P24 figure 2.5
��������״̬������һ����ʾ��һ�ν���accept stateʱ��state�ϵı�š�һ����ʾ��ǰ�����״̬�ı�š�
ɨ��Ĺ��̣���������λ�ñ�����һ�������ڲ��ϵ�ǰ����һ������������һ��ɨ�迪ʼʱ��λ�ã�
����һ������������һ����һ��ǰ���ɹ���λ�á��������ǰ����Ҫ���µ�����������
�������ǰ������ô����ڶ����������������������λ�÷�Χ���ַ������������һ�ν���accpet state��״̬�ı�š�
Ȼ���������λ�ñ���Ϊ�ڶ�λ�ñ�������ֵ��
*/

#pragma once
#include "DFA.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
class Lexer
{
public:
	Lexer();
	~Lexer();

	vector<string> patterns;
	DFA dfa;
	string text;
	int textPos;

	void readText(const char *fileName);
	void addPattern(string pattern);
	void convertToDFA();
	vector<pair<string, string>> scan();
};

