#pragma once

#include<iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Profile.h"   
#include "Queue.h"          
#include "_STACK.h"        
#include "Binary_Search_Tree.h" 
#include "Friend_Request.h"
#include "Graph.h"

class Mini_Instagram {
	Profile_Node* head;
	Graphs* UserGraph;
	IntBinaryTree* bst;
	int no_users;

public:

	// Constructor
	Mini_Instagram();
	void Followers();
	// Function Declarations
	void sendMessage();
	string getCurrentUser();
	void search();
	void viewPost();
	void SeeMessageFriend();
	void viewFriendReq();
	void EnterPost();
	void NewsFeed();
	void showNotifications();
	void Signup();
	void SendFriendRequest();
	void AcceptedReq();
	bool Signin();
	void Signout();
	bool DataIsEmpty();
	string getCurrentDateTime();
	bool checkUnique_name(std::string n);
};


