#pragma once
#include <iostream>
using namespace std;
struct person
{
	char name[30];
	char gender[7];
	char sport[30];
	int year;
	int height;
};
typedef struct person DataType;
struct node
{
	DataType data;
	node* next;
};
typedef struct node* list;
DataType input_person();
list new_node(list begin, DataType p_person);
list delete_node(list begin);
void show(list cur);
void search(list cur);
void print_data(person p_person);
int write_file(char* filename, list begin);
list read_file(char* filename);
void delete_list(list p_list);
void search_juniors(list cur);