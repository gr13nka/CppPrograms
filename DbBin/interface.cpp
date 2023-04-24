/*/#include "interface.h"

void menu::print_menu()
{
	for (int i = 0; i < n_choices; ++i)
	{
		if (choice == i + 1)
		{
			printf("%s%s", choices[i], " <-");
		}
		else
			printf("%s", choices[i]);
	}
}

void addRecord(record r) {
	char name[15];
	char surname[15];
	char parent[15];

	std::cin >> name;
	std::cin >> surname;
	std::cin >> parent;
	
	r.changeName(name);
	r.changeSurname(surname);
	r.changeParent(parent);
}

void menu::act() {
	Database db("db");
	record r;

	while (true) 
	{
		handleInput();
		switch (choice)
		{
		case 0:
			addRecord(r);
			db.addRecordToDatabase(r);
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			db.resetDatabase();
			break;
		case 4:
			break;
		}


		list<record> listOfRecords = db.databaseToList();
		db.showRecords(listOfRecords);
	}
}
void menu::handleInput() {

	while (true)
	{
		if (choice > 5 || choice < 0) {
			choice = 0;
		}

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
			act();
			break;
		}
		print_menu();
	}
}
*/