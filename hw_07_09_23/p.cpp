#include "header.h"

using namespace std;


Contact book[50];
int ccounter = 0;
int action;

Contact::~Contact()
{
	delete[] firstName;
	delete[] secondName;
	delete[] thirdName;
	delete[] homeNumber;
	delete[] workNumber;
	delete[] mobileNumber;
}
Contact::Contact()
{
	firstName = nullptr;
	secondName = nullptr;
	thirdName = nullptr;
	workNumber = nullptr;
	homeNumber = nullptr;
	mobileNumber = nullptr;
};

Contact::Contact(const char* fn, const char* sn, const char* tn, const char* wn, const char* hn, const char* mn)
{
	setFirstName(fn);
	setSecondName(sn);
	setThirdName(tn);
	setWorkNumber(wn);
	setHomeNumber(hn);
	setMobileNumber(mn);
}

void Contact::inputInfo()
{
	char buff[100];
	cout << "Enter contact's first name: ";
	cin >> buff;
	setFirstName(buff);

	cout << "Enter contact's second name: ";
	cin >> buff;
	setSecondName(buff);

	cout << "Enter contact's third name: ";
	cin >> buff;
	setThirdName(buff);

	cout << "Enter contact's work number: ";
	cin >> buff;
	setWorkNumber(buff);

	cout << "Enter contact's home number: ";
	cin >> buff;
	setHomeNumber(buff);

	cout << "Enter contact's mobile number: ";
	cin >> buff;
	setMobileNumber(buff);
}
void Contact::printContact()
{
	cout << "\nFist name: " << firstName << endl;
	cout << "Second Name: " << secondName << endl;
	cout << "Third Name: " << thirdName << endl;
	cout << "workNumber: " << workNumber << endl;
	cout << "homeNumber: " << homeNumber << endl;
	cout << "mobileNumber: " << mobileNumber << endl;
}

void Contact::setFirstName(const char* n)
{
	if (firstName != nullptr)
	{
		delete[]firstName;
	}
	firstName = new char[strlen(n) + 1];
	strcpy_s(firstName, strlen(n) + 1, n);
}
void Contact::setSecondName(const char* n)
{
	if (secondName != nullptr)
	{
		delete[]secondName;
	}
	secondName = new char[strlen(n) + 1];
	strcpy_s(secondName, strlen(n) + 1, n);
}
void Contact::setThirdName(const char* n)
{
	if (thirdName != nullptr)
	{
		delete[]thirdName;
	}
	thirdName = new char[strlen(n) + 1];
	strcpy_s(thirdName, strlen(n) + 1, n);
}
void Contact::setWorkNumber(const char* n)
{
	if (workNumber != nullptr)
	{
		delete[]workNumber;
	}
	workNumber = new char[strlen(n) + 1];
	strcpy_s(workNumber, strlen(n) + 1, n);
}
void Contact::setHomeNumber(const char* n)
{
	if (homeNumber != nullptr)
	{
		delete[]homeNumber;
	}
	homeNumber = new char[strlen(n) + 1];
	strcpy_s(homeNumber, strlen(n) + 1, n);
}
void Contact::setMobileNumber(const char* n)
{
	if (mobileNumber != nullptr)
	{
		delete[]mobileNumber;
	}
	mobileNumber = new char[strlen(n) + 1];
	strcpy_s(mobileNumber, strlen(n) + 1, n);
}

char* Contact::getFirstName()
{
	return firstName;
}
char* Contact::getSecondName()
{
	return secondName;
}
char* Contact::getThirdName()
{
	return thirdName;
}
char* Contact::getWorkNumber()
{
	return workNumber;
}
char* Contact::getHomeNumber()
{
	return homeNumber;
}
char* Contact::getMobileNumber()
{
	return mobileNumber;
}

void addContact()
{
	book[ccounter].inputInfo();
	ccounter++;
	system("CLS");
	return;
}


void removeContact()
{
	if (ccounter == 0)
	{
		errorMsgEmpty();
		return;
	}
	cout << "\nSelect the Contact you want to remove:\n";
	for (int i = 0; i < ccounter; i++)
	{
		cout << "[" << i + 1 << "]" << book[i].getFirstName() << " " << book[i].getSecondName() << endl;
	}
	int n;
	cin >> n;
	if (cin.fail() || n <= 0 || n > ccounter)
	{
		errorMsgWrongValue();
		return;
	}
	int confirm;
	cout << "\nEnter 1 to confirm, 0 to cancel: ";
	cin >> confirm;
	if (cin.fail() || confirm != 1 || confirm != 0)
	{
		errorMsgWrongValue();
		return;
	}
	if (confirm == 0)
	{
		return;
	}
	for (int i = n; i < ccounter; i++)
	{
		book[n - 1] = book[n];
	}
	ccounter--;
	system("CLS");
	return;
}

void printBook()
{
	if (ccounter == 0)
	{
		errorMsgEmpty();
		return;
	}
	for (int i = 0; i < ccounter; i++)
	{
		book[i].printContact();
	}
	system("pause");
	system("CLS");
	return;
}

void nameSearch()
{
	if (ccounter == 0)
	{
		errorMsgEmpty();
		return;
	}
	char firstName[100];
	char secondName[100];
	char thirdName[100];
	cout << "\nEnter first name: ";
	cin >> firstName;
	cout << "Enter second name: ";
	cin >> secondName;
	cout << "Enter third name: ";
	cin >> thirdName;
	for (int i = 0; i < ccounter; i++)
	{
		if (strcmp(firstName, book[i].getFirstName()) == 0 && strcmp(secondName, book[i].getSecondName()) == 0 && strcmp(thirdName, book[i].getThirdName()) == 0)
		{
			book[i].printContact();
		}
	}
	system("pause");
	system("CLS");
	return;
}

void saveFile()
{
	ofstream out;
	out.open("book.txt");
	if (out.is_open())
	{
		for (int i = 0; i < ccounter; i++)
		{
			out << book[i].getFirstName() << endl;
			out << book[i].getSecondName() << endl;
			out << book[i].getThirdName() << endl;
			out << book[i].getWorkNumber() << endl;
			out << book[i].getHomeNumber() << endl;
			out << book[i].getMobileNumber() << endl;
		}
	}
	out.close();
	system("CLS");
	return;
}

void loadFile()
{
	string line1, line2, line3, line4, line5, line6;
	ccounter = 0;
	ifstream in("book.txt");
	if (in.is_open())
	{

		while (getline(in, line1) && getline(in, line2) && getline(in, line3) && getline(in, line4) && getline(in, line5) && getline(in, line6))
		{
			book[ccounter].setFirstName(line1.c_str());
			book[ccounter].setSecondName(line2.c_str());
			book[ccounter].setThirdName(line3.c_str());
			book[ccounter].setWorkNumber(line4.c_str());
			book[ccounter].setHomeNumber(line5.c_str());
			book[ccounter].setMobileNumber(line1.c_str());
			ccounter++;
		}
	}
	in.close();
	system("CLS");
	return;
}

void printMenu()
{
	cout << "[1] - add Contact\n";
	cout << "[2] - remove Contact\n";
	cout << "[3] - print\n";
	cout << "[4] - Search by name\n";
	cout << "[5] - Save File\n";
	cout << "[6] - Load File\n";
	cout << "choose action: ";
}
void errorMsgEmpty()
{
	system("CLS");
	cout << "ERROR: THE BOOK IS EMPTY\n";
	system("pause");
	system("CLS");
	return;
}
void errorMsgWrongValue()
{
	system("CLS");
	cout << "\nERROR: INCORRECT VALUE\n\n";
	cin.clear();
	cin.ignore(100, '\n');
	system("pause");
	system("CLS");
	return;
}