#include "Mini_insta.h"
#include "Profile.h"
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

Mini_Instagram::Mini_Instagram() {
	head = nullptr;
	no_users = 0;
	bst = new IntBinaryTree();
	UserGraph = new Graphs();
}

void Mini_Instagram::search() {
	string n;
	cout << "Enter a name to search: ";
	getline(cin, n);
	cin.ignore();

	if (bst->search(n)) {
		cout << "User exists:" << endl;
		Profile_Node* temp = head;
		do {
			if (temp->name == n) {
				cout << "Posts by user:" << endl;
				temp->post.DisplayPost();
				cout << "\nUser's Status : " << temp->status << endl;
				cout << endl;
				break;
			}
			temp = temp->Next;
		} while (temp != head);
	}
	else {
		cout << "User does not exist" << endl;
	}
}

void Mini_Instagram::AcceptedReq() {
	cout << endl;
	head->accepted->DisplayAccepted();
	cout << endl;
}

void Mini_Instagram::Followers() {
	cout << endl;
	head->accepted->DisplayFollowers();
	cout << endl;
}

void Mini_Instagram::NewsFeed() {
	cout << "Posts:\n";
	head->post.DisplayPost();
	cout << endl;
}

void Mini_Instagram::viewPost() {
	cout << "\nPosts:" << endl;
	UserGraph->DisplayFriendPost(head->userNumber);
	cout << endl;
}

void Mini_Instagram::SeeMessageFriend() {
	cout << "\nYour Friends are as followed: " << endl;
	UserGraph->displayFriends(head->userNumber);
	string choice;
	cout << "Enter Friend Name: ";
	getline(cin, choice);
	UserGraph->DisplayMessage(head->userNumber, choice);
	cin.ignore();
}

void Mini_Instagram::viewFriendReq() {
	cout << endl;
	head->FriendReq.Display();
	string acceptReq;
	cout << "Enter 1 to accept request and press any button to reject: ";
	cin >> acceptReq;

	if (acceptReq == "1") {
		head->accepted->AcceptedEnQueue(head->FriendReq.getName());
		string temp = head->FriendReq.getName();
		Profile_Node* temp2 = head->Next;
		while (temp2 != head) {
			if (temp2->name == temp) {
				UserGraph->Insert_Edge(head, temp2);
				break;
			}
			temp2 = temp2->Next;
		}
	}
	head->FriendReq.DeQueue();
}

void Mini_Instagram::EnterPost() {
	string s;
	cout << endl << "Enter post: ";
	getline(cin, s);
	cin.ignore();
	head->post.push(head->name + "  :" + s);
}

void Mini_Instagram::showNotifications() {
	cout << "Notifications are as followed: ";
	cout << endl;
	head->Notifications.Display();
	while (!head->Notifications.isEmpty()) {
		head->Notifications.DeQueue();
	}
	return;
}

bool Mini_Instagram::checkUnique_name(string n) {
	if (head == nullptr) {
		return true;
	}
	Profile_Node* temp = head;
	do {
		if (temp->name == n) {
			return false;
		}
		temp = temp->Next;
	} while (temp != head);

	return true;
}

void Mini_Instagram::Signup() {
	string n;
	while (true) {
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, n);

		if (checkUnique_name(n)) {
			string p;
			bool correct_pass = false;
			do {
				cout << "\nEnter password: ";
				cin.ignore();
				getline(cin, p);
				if (p.size() < 8) {
					cout << "\nEnter a strong password!! , Try again.\n " << endl;
					correct_pass = false;
					continue;
				}
				else {
					for (int i = 0; i < p.size(); i++) {
						if ((p[i] >= 'A' && p[i] <= 'Z')) {
							correct_pass = true;
						}
						else if (p[i] >= 'a' && p[i] <= 'z') {
							correct_pass = true;
						}
					}
				}
			} while (correct_pass == false);

			string c;
			cout << "Enter city: ";
			getline(cin, c);

			Profile_Node* newNode = new Profile_Node;
			newNode->name = n;
			newNode->password = p;
			newNode->city = c;
			newNode->userNumber = no_users;
			newNode->status = "active";
			newNode->Next = head;
			no_users++;

			UserGraph->Resize(no_users);

			if (DataIsEmpty()) {
				head = newNode;
				head->Next = head;
				bst->insertNode(head->name);
				return;
			}

			Profile_Node* curr = head;
			while (curr->Next != head) {
				curr = curr->Next;
			}
			curr->Next = newNode;
			newNode->Next = head;
			head = newNode;

			bst->insertNode(newNode->name);
			return;
		}
		else {
			cout << "Name already taken, please choose another." << endl;
		}
	}
}

void Mini_Instagram::SendFriendRequest() {
	string n;
	cout << "Enter name of user to send request: ";
	getline(cin, n);

	if (head->name == n) {
		cout << "Invalid name" << endl;
		return;
	}

	if (head->accepted->checkforRep(n)) {
		cout << "\nAlready in your Friends.\n";
		return;
	}

	Profile_Node* temp = head->Next;
	bool found = false;
	while (temp != head) {
		if (temp->name == n) {
			string str = head->name + " : sent you a friend request";
			if (temp->FriendReq.checkforRep(head->name)) {
				cout << "\nreq already send.\n";
				return;
			}
			temp->Notifications.EnQueue(str);
			temp->FriendReq.EnQueue(head->name);
			found = true;
			break;
		}
		temp = temp->Next;
	}
	if (!found) {
		cout << "Account does not exist" << endl;
	}
}

bool Mini_Instagram::Signin() {
	if (head == nullptr)
	{
		cout << "No accounts available" << endl;
		return false;
	}

	string n;
	cout << "Enter name: ";
	getline(cin, n);

	if (head->name == n) {
		string pass;
		cout << "Enter Password:";
		getline(cin, pass);
		if (head->password == pass) {
			head->status = "active";
			return true;
		}
		else {
			int tries = 5;
			while (tries != 0) {
				cout << "Invalid Input,try again.\n Note: \n *You have " << tries << " tries.\n" << endl;
				cout << "Enter Password:";
				getline(cin, pass);
				if (head->password == pass) {
					head->status = "active";
					return true;
				}
				tries--;
			}
		}
		int forgot = 0;
		cout << "\n 1: Forget you pass.\n 0:Not Forget" << endl;
		cout << " Enter: ";
		cin >> forgot;
		cin.ignore();
		if (forgot == 1) {
			string chance;
			cout << "Enter your city Name: ";
			getline(cin, chance);
			if (head->city == chance) {
				cout << "Enter New Password:";
				getline(cin, pass);
				head->password = pass;
				head->status = "active";
				return true;
			}
		}

		return false;
	}

	Profile_Node* temp = head->Next;
	while (temp != head) {
		if (temp->name == n) {
			string pass;
			cout << "Enter Password:";
			getline(cin, pass);
			if (temp->password == pass) {
				head = temp;
				return true;
			}
			cout << "wrong Password.\n";
			return false;
		}
		temp = temp->Next;
	}

	cout << "Account does not exist" << endl;
	return false;
}

void Mini_Instagram::sendMessage() {
	cout << "\nYour Friends are as followed: " << endl;
	UserGraph->displayFriends(head->userNumber);
	string choice;
	cout << "Enter Friend Name: ";
	getline(cin, choice);
	string choice2;
	cout << "Write Message: ";
	getline(cin, choice2);

	UserGraph->WriteMessage(head->userNumber, choice, choice2, head->name);
	Profile_Node* temp = head;
	do {
		if (temp->name == choice)
			temp->Notifications.EnQueue(head->name + "  :" + " send you a message.");
		temp = temp->Next;
	} while (temp != head);
}

void Mini_Instagram::Signout() {
	head->time = getCurrentDateTime();
	head->status = "inactive";
	return;
}

bool Mini_Instagram::DataIsEmpty() {
	return head == nullptr;
}

string Mini_Instagram::getCurrentDateTime() {
	time_t currentTime = time(nullptr);
	tm localTime;
	localtime_s(&localTime, &currentTime);

	stringstream dateTimeStream;
	dateTimeStream << put_time(&localTime, "%d %b, %Y") << " ";
	dateTimeStream << put_time(&localTime, "%H:%M:%S");

	return dateTimeStream.str();
}

string Mini_Instagram::getCurrentUser() {
	return head->name;
}
