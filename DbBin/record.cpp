#include "record.h"

record::record() : id(0)
{
	strcpy(name, " "); strcpy(surname, " "); strcpy(parent, " ");
}

record::record(const char* name, const char* surname, const char* parent) : id(0)
{
	strcpy(this->name, name);
	strcpy(this->surname, surname);
	strcpy(this->parent, parent);
}

char* record::InputText()
{
    char * text = new char[15];
    cout<<"Enter text: ";
    cin>>text;
    return text;
}

void record::changeName()
{
    char* n= new char[15]; 
    n = InputText();
	memset(name, ' ', N);
	strcpy(name, n);
}

void record::changeSurname(char n[])
{
	memset(surname, ' ', N);
	strcpy(surname, n);
}

void record::changeParent(char n[])
{
	memset(parent, ' ', N);
	strcpy(parent, n);
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

std::ostream &operator<<(ostream &out, record &rec)
{
	out << "-----------------------------"<< '\n';
    out << "ID:"<<  rec.id << '\n';
    out << "Name: "<<  rec.name << '\n';
    out << "Surname:"<<  rec.surname << '\n';
    out << "parent:"<<  rec.parent << '\n';
    return out;
}
