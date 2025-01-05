#include <iostream>
#include <windows.h>
#include <fstream>
#include "Mini_insta.h"
using namespace std;

void readFile(const string& fileName);
void setConsoleColors();
void setConsoleFont(const wchar_t* fontName, SHORT fontSize);
void Menu(Mini_Instagram& M1);

int main() {
	setConsoleColors();
	setConsoleFont(L"Courier", 20);
	Mini_Instagram M1;

	readFile("instaText.txt");

	string choice;

	do {
		system("cls");
		readFile("instaText.txt");

		cout << "\n1: Sign In\n";
		cout << "2: Sign Up\n";
		cout << "0: Exit\n";

		cout << "\nEnter your choice: ";
		cin >> choice;

		if (choice == "1") {
			if (M1.Signin()) {
				Menu(M1);
			}
			else {
				cout << "\nInvalid login credentials. Please try again.\n";
			}
		}
		else if (choice == "2") {
			M1.Signup();
			system("cls");
			cout << "Welcome, " << M1.getCurrentUser() << "!! \n";
			Menu(M1);
		}
		else if (choice == "0") {
			cout << "\nThank you for using Mini Instagram! Goodbye.\n";
		}
		else {
			cout << "\nInvalid input. Please try again.\n";
		}

		system("pause");
	} while (choice != "0");

	return 0;
}

void readFile(const string& fileName) {
	ifstream file(fileName);

	if (!file.is_open()) {
		cerr << "Error: Could not open the file " << fileName << endl;
		return;
	}

	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}

	file.close();
}

void setConsoleColors() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD topLeft = { 0, 0 };
	DWORD written;

	FillConsoleOutputAttribute(hConsole, 240, consoleSize, topLeft, &written);
	FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &written);
	SetConsoleCursorPosition(hConsole, topLeft);
}

void setConsoleFont(const wchar_t* fontName, SHORT fontSize) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);

	wcscpy_s(cfi.FaceName, fontName);
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = fontSize;
	cfi.FontWeight = FW_NORMAL;

	SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void Menu(Mini_Instagram& M1) {
	string choice;

	do {
		cout << "\n1: View Your Posts\n";
		cout << "2: Send a Friend Request\n";
		cout << "3: Check Pending Friend Requests\n";
		cout << "4: Approve or Reject Friend Requests\n";
		cout << "5: View Notifications\n";
		cout << "6: Search for a User\n";
		cout << "7: View Messages with Friends\n";
		cout << "8: View Your Followers List\n";
		cout << "9: Browse Your News Feed\n";
		cout << "10: Create a New Post\n";
		cout << "11: Send a Message to a Friend\n";
		cout << "0: Log Out and Exit\n";

		cout << "\nEnter your choice: ";
		cin >> choice;

		if (choice == "1") {
			cout << "\nOpening your posts...\n";
			M1.viewPost();
		}
		else if (choice == "2") {
			cout << "\nSending a friend request...\n";
			M1.SendFriendRequest();
		}
		else if (choice == "3") {
			cout << "\nFetching your pending friend requests...\n";
			M1.viewFriendReq();
		}
		else if (choice == "4") {
			cout << "\nOpening approval menu for requests...\n";
			M1.AcceptedReq();
		}
		else if (choice == "5") {
			cout << "\nDisplaying your notifications...\n";
			M1.showNotifications();
		}
		else if (choice == "6") {
			cout << "\nSearching for users...\n";
			M1.search();
		}
		else if (choice == "7") {
			cout << "\nOpening your messages with friends...\n";
			M1.SeeMessageFriend();
		}
		else if (choice == "8") {
			cout << "\nDisplaying your followers...\n";
			M1.Followers();
		}
		else if (choice == "9") {
			cout << "\nOpening your news feed...\n";
			M1.NewsFeed();
		}
		else if (choice == "10") {
			cout << "\nEntering a new post...\n";
			M1.EnterPost();
		}
		else if (choice == "11") {
			cout << "\nMessaging a friend...\n";
			M1.sendMessage();
		}
		else if (choice == "0") {
			cout << "\nSigning out... Goodbye!\n";
			break;
		}
		else {
			cout << "\nInvalid choice. Please enter a valid option.\n";
		}

	} while (choice != "0");
}
