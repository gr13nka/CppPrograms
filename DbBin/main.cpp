#include <iostream>
#include "Database.h"
#include "record.h"
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

const char* choices[6] = {
					"add record",
					"remove record",
					"delete db",
					"edit record",
                    "show db",
					"exit"
};

void print_menu(int choice)
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

record addRecord() 
{
	char name[15];
	char surname[15];
	char parent[15];
	
	std::cin >> name;
	std::cin >> surname;
	std::cin >> parent;
	record *r = new record(name,surname,parent);
	return *r;
}

int ChooseFunction() 
{
    int choice = 0;

    while (true) {

	    if(choice > 4 || choice < 0) 
		    choice = 0;
    
	    print_menu(choice);
	
        int ch = getch();
	    switch (ch)
		{
		case 65:
			choice--;
			break;
		case 66:
			choice++;
			break;
		case 10:
            printf("\e[2J\e[H");//clear screen
			return choice;
		}
        printf("\e[2J\e[H");
    }
}

void EditRecord(record r)
{
    cout << "Which you want to edit?"<< '\n';
    int RecordId;
    cin >> RecordId;

    if (isdigit(RecordId)){
        cout << "Press 1 2 or 3 to edit name surname or parent"<< '\n';
        int ch;
        cin >> ch;
        switch(ch)
        {
            case 1:
                r.changeName();
                return;
            case 2:
              //  r.changeSurname(RecordId);
                return;
            case 3:
                //r.changeParent(RecordId);
                return;
        }
    }
}

int RunFunctionSelected(int choice, Database db, record r){

	list<record> listOfRecords = db.databaseToList();
	switch (choice)
	{
	case 0:
		r = addRecord();
		db.addRecordToDatabase(r);
		break;
	case 1:
        int RecordId = 0;
		db.deleteRecordFromDatabase(RecordId);
		break;
	case 2:
		db.resetDatabase();
		break;
	case 3:
        db.showRecords(listOfRecords);
        EditRecord(r);
        break;
	case 4:
        db.showRecords(listOfRecords);
        break;
    case 5:
		return 0;
		break;
	}
}

int main()
{
    Database db("db");
    record r;
    int running = 1;

    while(running)
    {
        running=RunFunctionSelected(ChooseFunction(),db,r);
    }
	return 0;
}
