#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

class Contact
{
	char* firstName;
	char* secondName;
	char* thirdName;
	char* workNumber;
	char* homeNumber;
	char* mobileNumber;
public:
	Contact();
	~Contact();
	Contact(const char*, const char*, const char*, const char*, const char*, const char*);
	void inputInfo();
	void print();
	void setFirstName(const char*);
	void setSecondName(const char*);
	void setThirdName(const char*);
	void setWorkNumber(const char*);
	void setHomeNumber(const char*);
	void setMobileNumber(const char*);
	char* getFirstName();
	char* getSecondName();
	char* getThirdName();
	char* getWorkNumber();
	char* getHomeNumber();
	char* getMobileNumber();
	void printContact();
};

void addContact();
void removeContact();
void printBook();
void nameSearch();
void saveFile();
void loadFile();
void printMenu();
void errorMsgEmpty();
void errorMsgWrongValue();