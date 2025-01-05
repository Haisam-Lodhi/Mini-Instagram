#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

class RequestNode {
public:
	string ReqQueuetime;
	string data;
	string Name;
	bool accept;
	RequestNode* next;
	RequestNode() {
		ReqQueuetime = "";
		data = "";
		accept = false;
		next = nullptr;
	}
};

class RequestQueue {
private:
	RequestNode* front;
	RequestNode* rear;


public:
	RequestQueue();
	void DisplayFollowers();
	bool checkforRep(string n);
	bool isEmpty();
	void DisplayAccepted();
	bool AcceptedEnQueue(string Val);
	bool EnQueue(string Val);
	bool DeQueue();
	void Display();
	string getCurrentDateTimeForQueue();
	string getName();
};

