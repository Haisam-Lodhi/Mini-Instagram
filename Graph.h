#pragma once

#include "Profile.h"
#include <iostream>  
#include "_STACK.h"        

using namespace std;

class GraphNode {
public:
	Profile_Node* data;
	GraphNode* next;
	Stack_ Message;
};

class Adjacency_List {
public:
	GraphNode* head;
	GraphNode* tail;

	Adjacency_List();
	bool Insertion_in_Adjacency_List(Profile_Node*& n);
};

class Graphs {

	Adjacency_List* adj;
	int n;

public:
	Graphs(int n = 0);
	~Graphs();
	void Insert_Edge(Profile_Node*& s, Profile_Node*& d);
	void Resize(int newSize);
	void DisplayFriendPost(int vertex);
	void WriteMessage(int vertex, string n, string msg, string sender);
	void DisplayMessage(int vertex, string n);
	void displayFriends(int vertex);
};
