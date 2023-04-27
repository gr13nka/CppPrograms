#pragma once
#include "Database.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

const int N = 15;

class record
{
private:
	int id;
	char name[N];
	char surname[N];
	char parent[N];
public:
	record();
	record(const char* name, const char* surname, const char* parent);
    char * InputText();
	void changeName();
	void changeSurname(char n[]);
	void changeParent(char n[]);
	int getID();
	const char* getName();
	const char* getSurname();
	char* getParent();
	friend class Database;
    friend std::ostream &operator<<(std::ostream &out, record &rec);
};

