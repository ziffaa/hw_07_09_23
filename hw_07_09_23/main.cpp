#include "header.h"

using namespace std;

int main()
{
	while (true)
	{
		int action = 0;
		printMenu();
		cin >> action;

		switch (action)
		{
		case 1:
			addContact();
			break;
		case 2:
			removeContact();
			break;
		case 3:
			printBook();
			break;
		case 4:
			nameSearch();
			break;
		case 5:
			saveFile();
			break;
		case 6:
			loadFile();
			break;
		default:
			errorMsgWrongValue();
			break;
		}
	}
}