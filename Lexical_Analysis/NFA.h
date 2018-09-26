/*
ʹ���ڽ��������洢NFA����Ϣ����ģ�����У������洢��Ϣ���ɡ�
vector<pair<int, char>> G[]
*/

#pragma once
#include <iostream>
#include <vector>
#include "DFA.h"
using namespace std;
class NFA
{
public:
	NFA();
	NFA(int stateCount);
	~NFA();

	int startState;
	vector<int> acceptStates;
	vector<pair<int, char>> *G;

	void setStartState(int x);
	void addAcceptState(int state);
	void addEdge(int state1, int state2, char c);

	DFA convertToDFA();
};

