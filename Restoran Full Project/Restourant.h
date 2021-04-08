#pragma once
#include"AdminSide.h"
#include<string>
#include"Table.h"
using namespace std;
using namespace AdminSide;
class Restourant {
	string name;
	string adress;
	string city;
	double budget;
	Admin** admins;
	Table** tables;
	int admincount = 3;
	int tablescount;
public:
	Restourant(const string& name, const string& adress, const string& city,
		double budget, Admin** admins, Table** tables, int tableCount = 4, int admincount = 3)
	{
		setName(name);
		setAdress(adress);
		setCity(city);
		setBudget(budget);
		setAdmins(admins);
		setTables(tables);
	}
	string getName()const {
		return name;
	}
	string getAdress()const {
		return adress;
	}
	string getCity()const {
		return city;
	}
	double getBudget()const {
		return budget;
	}
	Admin** getAdmins()const {
		return admins;
	}
	Table** getTables()const {
		return tables;
	}
	void setName(const string& name) {
		if (!name.empty()) {
			this->name = name;
		}
		else {
			throw InvalidArgumentException("Name is Empty", __LINE__, "Exception.txt");

		}
	}
	void setAdress(const string& adress) {
		if (!adress.empty()) {
			this->adress = adress;
		}
		else {
			throw InvalidArgumentException("adress is Empty", __LINE__, "Exception.txt");

		}
	}
	void setCity(const string& city) {
		if (!city.empty()) {
			this->city = city;
		}
		else {

			throw InvalidArgumentException("City is Empty", __LINE__, "Exception.txt");
		}




	}
	void setBudget(const double budget) {
		if (budget >= 0) {
			this->budget = budget;
		}
		else {

			throw InvalidArgumentException("Budget<0", __LINE__, "Exception.txt");
		}

	}
	void setAdmins(Admin** admins) {
		this->admins = new Admin * [admincount] {};
		for (int i = 0; i < admincount; i++)
		{
			this->admins[i] = admins[i];
		}
	}
	void setTables(Table** tables) {
		this->tables = new Table * [tablescount] {};
		for (int i = 0; i < tablescount; i++)
		{
			this->tables[i] = tables[i];
		}
	}
	void show()const {
		cout << "Name: " << getName() << endl;
		cout << "Adress: " << getAdress() << endl;
		cout << "City: " << getCity() << endl;
		cout << "Budget: " << getBudget() << endl;
		cout << "Admins Informations: \n" << endl;
		for (int i = 0; i < admincount; i++)
		{
			admins[i]->show();
		}
		cout << "Tables Information: \n" << endl;
		for (int i = 0; i < tablescount; i++)
		{
			tables[i]->show();
		}
	}
	bool AdminCheck(const string username, const string password) {
		for (int i = 0; i < admincount; i++)
		{
			if (admins[i]->getUsername() == username && admins[i]->getPassword() == password) {
				return true;
			}
		}
		return false;
	}
};