#pragma once
#include"IngredientClass.h"
class Mushrooms :public Ingredient {
public:
	Mushrooms(string name, const double fat, const double protein, const double carbohydrates, const int kcal, const double money)
		:Ingredient(name, fat, protein, carbohydrates, kcal, money)
	{
	}
	void show()const {
		Ingredient::show();
	}
};
class Meat :public Ingredient {
public:
	Meat(string name, const double fat, const double protein, const double carbohydrates, const int kcal, const double money)
		:Ingredient(name, fat, protein, carbohydrates, kcal, money)
	{
	}
	void show()const {
		Ingredient::show();
	}
};
class Spices :public Ingredient {
public:
	Spices(string name, const double fat, const double protein, const double carbohydrates, const int kcal, const double money)
		:Ingredient(name, fat, protein, carbohydrates, kcal, money)
	{
	}
	void show()const {
		Ingredient::show();
	}
};
class Cheese :public Ingredient {
public:
	Cheese(string name, const double fat, const double protein, const double carbohydrates, const int kcal, const double money)
		:Ingredient(name, fat, protein, carbohydrates, kcal, money) {}
};
class Tomatoes :public Ingredient {
public:
	Tomatoes(string name, const double fat, const double protein, const double carbohydrates, const int kcal, const double money)
		:Ingredient(name, fat, protein, carbohydrates, kcal, money) {}
};
