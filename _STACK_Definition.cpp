#include "_STACK.h"

Stack_::Stack_() {
	top = nullptr;
}

bool Stack_::isEmpty() {
	return top == nullptr;
}

bool Stack_::push(string Val) {
	StackNode* newNode = new StackNode;
	newNode->data = Val;
	newNode->Stacktime = getCurrentDateTimeForStack();

	if (isEmpty()) {
		top = newNode;
		newNode->next = nullptr;
		return true;
	}

	newNode->next = top;
	top = newNode;
	return true;
}

bool Stack_::pop() {
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
		return false;
	}

	StackNode* temp = top;
	top = top->next;
	delete temp;
	return true;
}

void Stack_::DisplayPost() {
	StackNode* temp = top;
	while (temp != nullptr) {
		cout << temp->data << "\t " << "At: " << temp->Stacktime;
		temp = temp->next;
	}
	cout << endl;
}

void Stack_::display() {
	StackNode* temp = top;
	while (temp != nullptr) {
		cout << "Messages: " << endl;
		cout << temp->data << "\t " << "At: " << temp->Stacktime;
		temp = temp->next;
	}
	cout << endl;
}

string Stack_::getCurrentDateTimeForStack() {
	time_t currentTime = time(nullptr);
	tm localTime;
	localtime_s(&localTime, &currentTime);

	stringstream dateTimeStream;
	dateTimeStream << put_time(&localTime, "%d %b, %Y") << " ";
	dateTimeStream << put_time(&localTime, "%H:%M:%S");

	return dateTimeStream.str();
}
