#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct translate {
	int table[256];
};

class DFA
{
public:
	DFA();
	~DFA();

	/*
	���������char��x��translate[int(x)]�õ�����ת�ƹ�ȥ��״̬�����Ϊ-1����ʾ������������ת�ƺ�����
	�����Ҫ���һ���µ�״̬����ôֻ��Ҫ��ʼ����translate֮����states pushһ��translate��
	*/
	vector<translate> states;
	int startState;
	int acceptState;

	void setStartState(int x);
	void setAcceptState(int x);

	/*
	���һ��״̬
	��ʼ��state��state[int(x)] = ĳһ��״̬��ID
	*/
	void addState(translate state);

	/*
	����һ���ַ���str,����length��Ȼ�󷵻����DFA�Ƿ���������
	*/
	bool IsAccepted(const char *str, int length);
	bool IsAccepted(string str, int length);
};

