#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

void launch();
void menu();
void signIn();
void registration();
string pswdvalidation(string msg, int length);
int validation(int min, int max, string msg);

int main() {
	launch();
	menu();
	int signInSelect = validation(1, 2, "Select an option: ");
	if (signInSelect == 1) {

	}
	else {
		registration();
	}
	return 0;
}

void launch() {  //launch screen
	cout << "Welcome\n";
	system("PAUSE");
	system("CLS");  //clear screen
}

void menu() {
	cout << "User Sign In System\n";
	cout << "1. User Sign In\n2. User Registration\n";
}

void signIn() {
	cout << "\nSign In Menu\n\n";
	cout << "Enter username\n> ";
	string username;
	cin >> username;
	cout << "Enter password\n> ";
	string password;
	cin >> password;
	string loginInfo = username + " " + password;

	ifstream Users("users.txt");
	string query;
	while (getline(Users, query)) {
		string textLine = getline(Users, query);
		if (loginInfo.compare(getline(Users, query)) {

		}
	}
}

void registration() {
	ofstream Users("users.txt");
	string username;
	cout << "\nRegistration Menu\n\nPassword must be 8 characters\n";
	cout << "Enter a username\n> ";
	cin >> username;
	string password = pswdvalidation("Enter a password\n> ",8);
	Users << username + " " + password;
	Users.close();
}

string pswdvalidation(string msg, int length) {
	string input;
	cout << msg;
	cin >> input;

	while (input.length() < length) {
		cout << "Password too short. Enter a password\n> ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> input;
	}
	return input;
}

int validation(int min, int max, string msg) {
	int input;
	cout << msg;
	cin >> input;

	while (cin.fail() || input < min || input > max || cin.peek() != '\n') {
		cout << "Invalid Input." << msg;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> input;
	}
	return input;
}