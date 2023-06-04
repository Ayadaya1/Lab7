#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "person.h"
#include <locale.h>
using namespace std;
int main()
{
	bool running = true;
	char* locale = setlocale(LC_ALL, "");
	person p1, p2;
	list List = NULL;
	char filename[30];
	char menu;
	cout << "Введите имя файла: ";
	cin >> filename;
	List = read_file(filename);
	while (running)
	{
		system("cls");
		cout << "1. Insert" << endl << "2. Show" << endl << "3. Search" <<
			endl << "4. Delete" << endl << "5. Search female juniors" << endl << "6.Exit"<<endl<<endl<<"Choose one of the menu options : ";
			cin >> menu;
		switch (menu)
		{
		case '1': List = new_node(List, input_person()); break;
		case '2': show(List);
			system("pause");
			break;
		case '3': search(List);
			system("pause");
			break;
		case '4': List = delete_node(List);
			system("pause");
			break;
		case '6': running = false; break;
		case '5': search_juniors(List);
			system("pause");
			break;
		default:
			cout << "Enter a menu option!!! (1-5)" << endl;
			system("pause");
			break;
		}
	}
	if (write_file(filename, List))
		cout << "File saved.";
	else
		cout << "File not saved";
	delete_list(List);
	return 0;
}