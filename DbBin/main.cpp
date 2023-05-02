#include <iostream>
#include "Database.h"
#include "record.h"
#include <stdlib.h>
#include <termios.h>
#include <functional>
#include <unistd.h>
#include <stdio.h>

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

const char* choices[7] = {
					"add record",
					"remove record",
					"delete db",
					"edit record",
                    "show db",
                    "find record",
					"exit"
};

void print_menu(int choice)
{
	for (int i = 0; i < 7; ++i)
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

	    if(choice > 6) 
		    choice = 0;
        if (choice < 0)
            choice = 6;

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

std::string AskName() {
    std::string name;
    std::cin>>name;
    return name;
}

bool searchById(record r,const std::string &name){

    int id = std::atoi(name.c_str());
    return r.getID() == id;
}

bool searchByName(record r,const std::string &name){
    return r.getName() == name;
}
bool searchBySurname(record r,const std::string &name){
    return r.getSurname() == name;
}
bool searchByParent(record r,const std::string &name){
    return r.getParent() == name;
}
void ChooseSearchType(Database db, record r){
	list<record> listOfRecords; 
    std::cout << "How you want to search by id name surname or parent? press 123 or 4"<<'\n';
    int choice = getch();
    std::string name = AskName();
    
    switch(choice){
        case 1:
            std::cout << "what id you want to find?"<<'\n';
            listOfRecords = db.searchForRecords(searchById,name);
            break;
        case 2:
            std::cout << "what name you want to find?"<<'\n';
            listOfRecords = db.searchForRecords(searchByName,name);
            break;
        case 3:
            std::cout << "what surname you want to find?"<<'\n';
            listOfRecords = db.searchForRecords(searchBySurname,name);
            break;
        case 4:
            std::cout << "what parent you want to find?"<<'\n';
            listOfRecords = db.searchForRecords(searchByParent,name);
            break;
    }
}

int AskID(){
    int name;
    std::cin>>name;
    return name;
}

int RunFunctionSelected(int choice, Database db, record r){
    //std::string name = AskName();
	//list<record> listOfRecords = db.searchForRecords(searchpredicate,name);

	list<record> listOfRecords = db.databaseToList();
    int RecordId = 0;
	switch (choice)
	{
	case 0:
		r = addRecord();
		db.addRecordToDatabase(r);
		break;
	case 1:
        RecordId = AskID();
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
        ChooseSearchType(db,r);
		return 0;
		break;
    case 6:
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
