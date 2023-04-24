#include <iostream>
#include <conio.h>
#include "Database.h"
#include "record.h"
#include <stdlib.h>

int choice=0;
const char* choices[5] = {
					"add record",
					"remove record",
					"delete db",
					"edit record",
					"exit"
};

void print_menu()
{
	for (int i = 0; i < 5; ++i)
	{
		if (choice == i)
		{
			printf("%s%s%c", choices[i], " <-",'\n');
		}
		else
			printf("%s%c", choices[i], '\n');
	}
}

record addRecord() {
	char name[15];
	char surname[15];
	char parent[15];
	
	std::cin >> name;
	std::cin >> surname;
	std::cin >> parent;
	record *r = new record(name,surname,parent);
	return *r;
}

int main()
{
Database db("db");
record r;

while (true)
{
	while (true)
	{
		if(choice > 4 ) 
			choice = 0;
		if (choice < 0)
			choice = 4;

		print_menu();

		list<record> listOfRecords = db.databaseToList();
		db.showRecords(listOfRecords);
		int c = _getch();
		switch (c)
		{
		case 72:
			choice--;
			break;
		case 80:
			choice++;
			break;
		case 13:
			system("cls");
			goto m;
			break;
		}
		system("cls");
	}

	m:
	switch (choice)
	{
	case 0:
		r = addRecord();
		db.addRecordToDatabase(r);
		break;
	case 1:
		db.deleteRecordFromDatabase(2);
		break;
	case 2:
		db.resetDatabase();
		break;
	case 3:
		r.changeName("000");
		break;
	case 4:
		return 0;
		break;
	}
}
	return 0;
}
