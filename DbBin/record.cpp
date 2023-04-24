#include "record.h"

record::record() : id(0)
{
	strcpy_s(name, " "); strcpy_s(surname, " "); strcpy_s(parent, " ");
}

record::record(const char* name, const char* surname, const char* parent) : id(0)
{
	strcpy_s(this->name, name);
	strcpy_s(this->surname, surname);
	strcpy_s(this->parent, parent);
}

void record::changeName(const char n[])
{
	memset(name, ' ', N);
	strcpy_s(name, n);
}

void record::changeSurname(char n[])
{
	memset(surname, ' ', N);
	strcpy_s(surname, n);
}

void record::changeParent(char n[])
{
	memset(parent, ' ', N);
	strcpy_s(parent, n);
}
int record::getID()
{
	return id;
}

const char * record::getName()
{
	return name;
}

const char * record::getSurname()
{
	return surname;
}

char* record::getParent()
{
	return parent;
}

template <typename T>
static void record::singleStyling(ostream& out, const char* field, T value, int wide_field, int wide_value, int color)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	out << left << setw(wide_field) << field << setw(wide_value) << value << endl;
	SetConsoleTextAttribute(hConsole, 15);
}

ostream& operator<<(ostream& out, record& rec)
{
	int wide_field = 20, wide_value = 15;
	char styling[] = "-----------------------------";
	record::singleStyling(out, "ID:", rec.id, wide_field, wide_value, 2);
	record::singleStyling(out, "Name:", rec.name, wide_field, wide_value, 3);
	record::singleStyling(out, "Surname:", rec.surname, wide_field, wide_value, 2);
	record::singleStyling(out, "parent:", rec.parent, wide_field, wide_value, 3);
	out << styling << endl;
	return out;
}