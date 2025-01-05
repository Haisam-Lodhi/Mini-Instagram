#pragma once

#include "Queue.h" 
#include "_STACK.h"
#include "Friend_Request.h"
#include<string>
using namespace std;

class Profile_Node {
public:
	string name;
	string password;
	string city;
	Stack_ post;
	string time;
	RequestQueue FriendReq;
	string status;
	Profile_Node* Next;
	Queue Notifications;
	int userNumber;
	RequestQueue* accepted; 
	Profile_Node() {
		name = "";
		password = "";
		city = "";
		Next = nullptr;
		status = "inactive";
		userNumber = 0;
		accepted = new RequestQueue;
	}
};
