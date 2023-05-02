#pragma once
#include <string>
#include "record.h"
#include <list>
#include <vector>

using namespace std;
class record;

class Database
{
private:
	int count;
	string filename;
public:
	Database(string filename);
	Database(string filename, list<record> list_of_records);
	list<record> databaseToList();
	void addRecordToDatabase(record& r);
	void showRecords(list<record> listOfRecords);
	void resetDatabase();
	friend ostream& operator<<(ostream& out, Database& dt);
	void deleteRecordFromDatabase(int serialNumber);
    bool SearchById(record r, const int &i);
    //friend int SearchForParent(char parent[15]);
	list<record> searchForRecords(bool predicate(record parameter,const std::string &name),const std::string &name);
	record getRecordFromDatabase(int serialNumber);
};
