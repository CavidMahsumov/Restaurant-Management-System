#pragma once
#include<string>
#include"Base.h"
using namespace std;
class Ingredient :public Base {
	string name;
	double money;
	double fat;
	double protein;
	double carbohydrates;
	double kcal;
public:
	static int ingredietnid;
	Ingredient() :name(""), fat(0), protein(0), carbohydrates(0), kcal(0), money(0) {}
	Ingredient(const string name, const double fat, const double protein, const double carbohydrates, const int kcal, const double money)
		:Base(++ingredietnid)
	{
		setName(name);
		setFat(fat);
		setProtein(protein);
		setCarbohydrates(carbohydrates);
		setKcal(kcal);
		setMoney(money);
	}
	static int getID() {
		return ingredietnid;
	}
	string getName()const {
		return name;
	}
	double getFat()const {
		return fat;
	}
	double getProtein()const {
		return protein;
	}
	double getCarbohydrates()const {
		return carbohydrates;
	}
	double getMoney()const {
		return money;
	}
	double getKcal()const {
		return kcal;
	}
	void setName(const string name) {
		if (!name.empty())
		{
			this->name = name;
		}
	}
	void setMoney(const double money) {
		if (money >= 0) {
			this->money = money;
		}
	}
	void setFat(const double fat) {
		if (fat > 0)
		{
			this->fat = fat;
		}
	}
	void setProtein(const double protein) {
		if (protein > 0)
		{
			this->protein = protein;
		}
	}
	void setCarbohydrates(const double carbohydrates) {
		if (carbohydrates > 0)
		{
			this->carbohydrates = carbohydrates;
		}
	}
	void setKcal(const double kcal) {
		if (kcal > 0)
		{
			this->kcal = kcal;
		}
	}
	void showDetail() const {
		cout << "_________Ingredient_________" << endl;
		cout << "Id: " << getId() << endl;
		cout << "Name : " << getName() << endl;
		cout << "Price: " << getMoney() << endl;
		cout << "Fats : " << getFat() << endl;
		cout << "Protein : " << getProtein() << endl;
		cout << "Carbohydrats : " << getCarbohydrates() << endl;
		cout << "Kcal : " << getKcal() << endl << endl;
	}
	void show()const {
		cout << "Name : " << getName() << endl;
	}
};
