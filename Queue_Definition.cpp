#include "Queue.h"
using namespace std;

Queue::Queue() {
	front = rear = nullptr;
}

bool Queue::isEmpty() {
	return (front == nullptr);
}

bool Queue::EnQueue(string Val) {
	QueueNode* newNode = new QueueNode;
	newNode->data = Val;
	newNode->Queuetime = getCurrentDateTimeForQueue();
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

bool Queue::DeQueue() {
	if (isEmpty()) {
		cout << "Queue is Empty" << endl;
		return false;
	}

	QueueNode* temp = front;
	front = front->next;

	delete temp;

	if (front == nullptr) {
		rear = nullptr;
	}
	return true;
}

void Queue::Display() {
	QueueNode* temp = front;
	while (temp != nullptr) {
		cout << temp->data << "\t " << " At :" << temp->Queuetime;
		temp = temp->next;
	}
	cout << endl;
}

string Queue::getCurrentDateTimeForQueue() {
	time_t currentTime = time(nullptr);
	tm localTime;
	localtime_s(&localTime, &currentTime);

	stringstream dateTimeStream;
	dateTimeStream << put_time(&localTime, "%d %b, %Y") << " ";
	dateTimeStream << put_time(&localTime, "%H:%M:%S");

	return dateTimeStream.str();
}
