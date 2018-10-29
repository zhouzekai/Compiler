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
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <queue>
using namespace std;

struct translate {
	int table[128];

	translate()
	{
		for (int i = 0; i < 128; i++)
		{
			table[i] = -1;
		}
	}
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
	map<int, string> stateIDs;
	//vector<translate> states;
	map<int, translate> states;
	int index = 0;

	int startState;
	vector<int> acceptStates;

	void setStartState(int x);
	void addAcceptState(int x);

	/*
	���һ��״̬
	��ʼ��state��state[int(x)] = ĳһ��״̬��ID
	*/
	void addState(translate state);
	void addState(translate state, string stateID);
	void addStateID(int x, string y);

	/*
	ͨ��stateID�����Ҷ�Ӧvector<translate>�е�λ��
	����-1��ʾû���ҵ���
	*/
	int statesPos(string stateID);

	/*
	����һ���ַ���str,����length��Ȼ�󷵻����DFA�Ƿ���������
	*/
	bool IsAccepted(const char *str, int length);
	bool IsAccepted(string str, int length);

	/*
	����һ���ַ���һ��ת��
	��Ҫ�����״̬����ǰ��state����һ��accept��state
	*/
	void runOneStep(char x, bool &accepted, int &currentStateID);
	void reset();
	int getLastAcceptState();

	void removeUnreachableStates();

	void mergeNondistinguishableStates();

	void minized();

private:
	int lastAcceptState;
	int currentState;

	bool seperate(set<int> input, char x, set<int> &A, set<int> &B);
	//set<int> translateToOneState(char c, set<int> theStates);
	int findOwner(vector<set<int>> P, int x);
};
