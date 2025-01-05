#include "Friend_Request.h"
using namespace std;

RequestQueue::RequestQueue() {
	front = rear = nullptr;
}

bool RequestQueue::isEmpty() {
	return (front == nullptr);
}

bool RequestQueue::EnQueue(string Val) {
	RequestNode* newNode = new RequestNode;
	newNode->Name = Val;
	newNode->data = Val + " Send you a friend request.";
	newNode->ReqQueuetime = getCurrentDateTimeForQueue();
	newNode->next = nullptr;

	if (isEmpty()) {
		front = rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
	return true;
}

bool RequestQueue::AcceptedEnQueue(string Val) {
	RequestNode* newNode = new RequestNode;
	newNode->Name = Val;
	newNode->data = Val + " accepted your friend request.";
	newNode->ReqQueuetime = getCurrentDateTimeForQueue();
	newNode->next = nullptr;

	if (isEmpty()) {
		front = rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
	return true;
}

bool RequestQueue::DeQueue() {
	if (isEmpty()) {
		cout << "Queue is Empty" << endl;
		return false;
	}

	RequestNode* temp = front;
	front = front->next;
	delete temp;

	if (front == nullptr) {
		rear = nullptr;
	}
	return true;
}

void RequestQueue::Display() {
	RequestNode* temp = front;
	while (temp != nullptr) {
		cout << "Request: " << temp->data << " At: " << temp->ReqQueuetime << endl;
		temp = temp->next;
	}
}

void RequestQueue::DisplayAccepted() {
	if (isEmpty()) {
		cout << "No accepted requests." << endl;
		return;
	}

	RequestNode* temp = front;
	cout << "Accepted Requests:" << endl;
	while (temp != nullptr) {
		cout << temp->Name << " at: " << temp->ReqQueuetime << endl;
		temp = temp->next;
	}
}

void RequestQueue::DisplayFollowers() {
	if (isEmpty()) {
		cout << "No followers." << endl;
		return;
	}

	RequestNode* temp = front;
	cout << "Followers:" << endl;
	while (temp != nullptr) {
		cout << temp->Name << " at: " << temp->ReqQueuetime << endl;
		temp = temp->next;
	}
}

string RequestQueue::getCurrentDateTimeForQueue() {
	time_t currentTime = time(nullptr);
	tm localTime;
	localtime_s(&localTime, &currentTime);

	stringstream dateTimeStream;
	dateTimeStream << put_time(&localTime, "%d %b, %Y") << " ";
	dateTimeStream << put_time(&localTime, "%H:%M:%S");

	return dateTimeStream.str();
}

string RequestQueue::getName() {
	if (front != nullptr) {
		return front->Name;
	}
	return "";
}

bool RequestQueue::checkforRep(string n) {
	RequestNode* temp = front;
	while (temp != NULL) {
		if (temp->Name == n) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}
