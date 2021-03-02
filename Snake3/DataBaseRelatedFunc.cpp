#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static string Mail , User , PassWord;
static bool CreateAccountMenuOpen = true;
enum ServerKeys { MailTaken=0 , UserTaken};

void CheckIfDataAvailableAndWrite();
void CreateAcc() 
{
	CreateAccountMenuOpen = true;

	while (CreateAccountMenuOpen) {
		cout << "---------NewAccount---------" << endl;
		cout << "Mail: ";
		cin >> Mail;
		cout << endl;
		cout << "Username: ";
		cin >> User;
		cout << endl;
		cout << "Password: ";
		cin >> PassWord;
		cout << endl;

		CheckIfDataAvailableAndWrite();
	}
}
void CheckIfDataAvailableAndWrite() 
{

	static string MailChecker, UserChecker;
	int StoreCheckerEvaluation=10, StoreCheckerEvaluation2=10;

	fstream Server("snakegameT.txt", fstream::in | fstream::out);
	
	while (!Server.eof()) {
		Server >> MailChecker >> UserChecker;
		if (MailChecker == Mail) {
			StoreCheckerEvaluation=MailTaken;
		}
		else if (UserChecker == User) {
			StoreCheckerEvaluation2 = UserTaken;
		}
	}
    Server.close();

	if (StoreCheckerEvaluation == MailTaken && StoreCheckerEvaluation2 == UserTaken) {
		cout << "Email and User already in use "<<endl;
		system("pause");
		system("cls");
	}
	else if (StoreCheckerEvaluation == MailTaken) {
		cout << "Email already in use "<<endl;
		system("pause");
		system("cls");
	}
	else if (StoreCheckerEvaluation2 == UserTaken) {
		cout << "User already in use "<<endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "New Account registed succesfully!"<<endl;

		Server << Mail << " " << User << " " << PassWord;
		Server.close();

		system("pause");
		CreateAccountMenuOpen = false;
		system("cls");
	}
}