#include "person.h"
#include <iostream>
#include <string>
using namespace std;
DataType input_person() //Ввод данных person
{
	DataType sportsman;
	cout << "Name: ";
	cin >> sportsman.name;
	cout << "Gender: ";
	while (strcmp(sportsman.gender, "Male") && strcmp(sportsman.gender,
		"Female"))
	{
		cin >> sportsman.gender;
		if (strcmp(sportsman.gender, "Male") && strcmp(sportsman.gender,
			"Female"))
		{
			cout << "There are only two genders..." << endl << "Enter the sportsman's gender again: ";
		}
	}
	cout << "Sport: ";
	cin >> sportsman.sport;
	cout << "Year: ";
	while (sportsman.year < 1900 || sportsman.year>2016)
	{
		cin >> sportsman.year;
		if (sportsman.year < 1900 || sportsman.year>2016)
			cout << "Enter a real birth year: ";
	}
	cout << "Height: ";
	while (sportsman.height > 220 || sportsman.height < 120)
	{
		cin >> sportsman.height;
		if (sportsman.height > 220 || sportsman.height < 120)
			cout << "Enter a real height: ";
	}
	return sportsman;
}
list new_node(list begin, DataType p_person) //новый элемент в списке
{
	list temp = new node;
	temp->data = p_person;
	temp->next = begin;
	return temp;
}
list delete_node(list begin) //удаление элемента из списка
{
	node* temp;
	if (begin)
	{
		temp = begin;
		begin = temp->next;
		free(temp);
		cout << "Deleted" << endl;
	}
	else
		cout << "There is nothing to delete!" << endl;
	return begin;
}
void show(list cur) //Вывод списка на экран
{
	int count = 0;
	system("cls");
	if (cur == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	while (cur)
	{
		cout << ++count << ". Name: " << cur->data.name << " | Gender: "
			<< cur->data.gender << " | Sport: " << cur->data.sport << " | Year: " << cur -> data.year << " | Height: " << cur->data.height << endl;
		cout << "-------------------------------------------------------------------------" << endl;
			cur = cur->next;
	}
}
void print_data(person p_person) //Вывод данных о спортсмене
{
	cout << "Name: " << p_person.name << " | " << "Gender: " <<
		p_person.gender << " | " << "Sport: " << p_person.sport << " | " << "Year: "
		<< p_person.year << " | " << "Height: " << p_person.height << endl;
}
void search(list cur) //Поиск самого высокого пловца
{
	int max_height = 0, k = -1;
	DataType sportsman;
	system("cls");
	if (cur == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	while (cur)
	{
		k++;
		char sw[30] = "Swimming";
		char male[7] = "Male";
		if (cur->data.height > max_height && strcmp(cur->data.sport,
			sw) == 0 && strcmp(cur->data.gender, male) == 0)
		{
			max_height = cur->data.height;
			sportsman = cur->data;
		}
		cur = cur->next;
	}
	if (max_height == 0)
		cout << "Not found" << endl;
	else
		print_data(sportsman);
}
int write_file(char* filename, list begin) //Запись файла
{
	FILE* f;
	if ((f = fopen(filename, "wb")) == NULL)
	{
		perror("Error while creating a file");
		return 0;
	}
	while (begin)
	{
		if (fwrite(&begin->data, sizeof(DataType), 1, f))
			begin = begin->next;
		else
			return 0;
	}
	return 1;
}
list read_file(char* filename) //Чтение файла
{
	FILE* f;
	DataType sportsman;
	list begin = NULL, cur;
	if ((f = fopen(filename, "rb")) == NULL)
	{
		perror("Error while reading the file");
		return 0;
	}
	if (fread(&sportsman, sizeof(sportsman), 1, f))
		begin = new_node(NULL, sportsman);
	else
		return NULL;
	cur = begin;
	while (fread(&sportsman, sizeof(sportsman), 1, f))
	{
		cur->next = new_node(NULL, sportsman);
		cur = cur->next;
	}
	fclose(f);
	return begin;
}
void delete_list(list begin) //Удаление списка
{
	list temp = begin;
	while (temp)
	{
		begin = temp->next;
		delete(temp);
		temp = begin;
	}
}
void search_juniors(list cur) //Поиск спортсменок-юниоров
{
	int k = 0;
	system("cls");
	if (cur == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	while (cur)
	{
		if (!strcmp(cur->data.gender, "Female") && 2020 - cur -> data.year >= 14 && 2020 - cur->data.year <= 17)
		{
			k++;
			cout << k << ". ";
			print_data(cur->data);
		}
		cur = cur->next;
	}
	if (k == 0)
		cout << "Not found" << endl;

}