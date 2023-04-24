/**
/#pragma once
#include <iostream>
#include <conio.h>
#include "Database.h"
#include "record.h"
   
class menu {
public:
	int choice;
	const char* choices[10] = {
				"add record",
				"remove record",
				"delete db",
				"edit record",
				"exit"
	};
	int n_choices = sizeof(choices) / sizeof(char*);

	void print_menu();
	void addRecord(record r);
	void act();
	void handleInput();
};
*/