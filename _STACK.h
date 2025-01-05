#pragma once

#include <iostream>
#include<string>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

class StackNode {
public:
	string data;
	string Stacktime;
	StackNode* next;
};

class Stack_ {
private:
	StackNode* top;

public:
	Stack_();
	bool isEmpty();
	bool push(string Val);
	bool pop();
	void DisplayPost();
	void display();
	string getCurrentDateTimeForStack();
};

