#include "Graph.h"
#include "Profile.h"

Adjacency_List::Adjacency_List() {
	head = nullptr;
	tail = nullptr;
}

bool Adjacency_List::Insertion_in_Adjacency_List(Profile_Node*& n) {
	GraphNode* newNode = new GraphNode;
	newNode->data = n;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	return true;
}

Graphs::Graphs(int n) {
	this->n = n;
	adj = new Adjacency_List[n];
}

Graphs::~Graphs() {
	for (int i = 0; i < n; ++i) {
		GraphNode* temp = adj[i].head;
		while (temp != nullptr) {
			GraphNode* toDelete = temp;
			temp = temp->next;
			delete toDelete;
		}
	}
	delete[] adj;
}

void Graphs::Insert_Edge(Profile_Node*& s, Profile_Node*& d) {
	adj[s->userNumber].Insertion_in_Adjacency_List(d);
	adj[d->userNumber].Insertion_in_Adjacency_List(s);
}

void Graphs::Resize(int newSize) {

	Adjacency_List* newAdj = new Adjacency_List[newSize];

	if (n != 0) {
		for (int i = 0; i < n; ++i) {
			newAdj[i] = adj[i];
		}
	}

	delete[] adj;
	adj = newAdj;
	n = newSize;
	return;
}

void Graphs::DisplayFriendPost(int vertex) {
	GraphNode* temp = adj[vertex].head;
	while (temp != nullptr) {
		temp->data->post.DisplayPost();
		temp = temp->next;
	}
}

void Graphs::WriteMessage(int vertex, string n, string msg, string sender) {
	GraphNode* temp = adj[vertex].head;
	while (temp != nullptr) {
		if (temp->data->name == n) {
			temp->Message.push(sender + "   :" + msg);

			GraphNode* temp2 = adj[temp->data->userNumber].head;
			while (temp2 != nullptr) {
				if (temp2->data->name == sender) {
					temp2->Message.push(sender + "   :" + msg);
				}
				temp2 = temp2->next;
			}

			return;
		}
		temp = temp->next;
	}
	cout << "Friend not found!" << endl;
}

void Graphs::DisplayMessage(int vertex, string n) {
	GraphNode* temp = adj[vertex].head;
	while (temp != nullptr) {
		if (temp->data->name == n) {
			if (temp->Message.isEmpty()) {
				cout << "No messages available." << endl;
			}
			else {
				temp->Message.display();
			}
			return;
		}
		temp = temp->next;
	}
	cout << "Friend not found!" << endl;
}

void Graphs::displayFriends(int vertex) {
	GraphNode* temp = adj[vertex].head;
	while (temp != nullptr) {
		cout << temp->data->name << endl;
		temp = temp->next;
	}
	cout << endl;
}
