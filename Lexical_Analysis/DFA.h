/*
ʹ�÷�����
��ʼ����translate��Ȼ����˳��ѹ�뵽DFA�С�DFAҪ���ÿ�ʼ�ͽ��ܡ�
����һ��string��string�ĳ��ȣ�����Ƿ���ܡ�
translate a0, a1, a2;
for (int i = 0; i < 256; i++) {
a0.table[i] = -1;
a1.table[i] = -1;
a2.table[i] = -1;
}

a0.table[int('a')] = 1;
a0.table[int('c')] = 2;
a1.table[int('a')] = 2;
char x = 'b';
do {
a1.table[int(x)] = 1;
x = x + 1;
} while (x != 'z');
a2.table[int('c')] = 2;

DFA dfa;
dfa.setAcceptState(2);
dfa.setStartState(0);
dfa.addState(a0);
dfa.addState(a1);
dfa.addState(a2);

string str;
while (cin >> str) {
bool x = dfa.IsAccepted(str, str.length());
cout << str << (x ? " accept" : " reject") << endl;
}*/

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


class exDFA
{
public:
	exDFA();
	~exDFA();

	vector<translate> states;
	vector<int> acceptStates;
	int startState;
	int lastAcceptState;
	int currentState;

	void resetToStart();
	void setStartState(int x);
	void addAcceptState(int x);
	void addState(translate state);
	int getLastAcceptState();

	void runOneStep(char x, bool &accepted, int &currentStateID);

	void convertFromDFAs(vector<DFA> DFAs);

	// bool IsAccepted(const char *str, int length);
	// bool IsAccepted(string str, int length);
};
 