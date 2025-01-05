#pragma once


#include<string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

class QueueNode {
public:
	string Queuetime;
	string data;
	QueueNode* next;
};

class Queue {
private:
	QueueNode* front;
	QueueNode* rear;
public:
	Queue();
	bool isEmpty();
	bool EnQueue(string Val);
	bool DeQueue();
	void Display();
	string getCurrentDateTimeForQueue();
};

