#pragma once
#include"ItemBaseh.h"
#include"Meal.h"
using namespace std;
class MealItem :public ItemBase {
	Meal* meal;
public:
	MealItem() :meal(nullptr) {}
	MealItem(Meal* meals, int count) :ItemBase(count)
	{
		setMeals(meals);
	}
	Meal* getMeals()const {
		return meal;
	}
	void setMeals(Meal* meals) {
		this->meal = meals;
	}
	int length = ItemBase::getCount();
	void show()const {
		for (int i = 0; i < length; i++)
		{
			meal[i].show();
		}
	}
	void showDetailMealsWithId(int id) {
		for (int i = 0; i < length; i++)
		{
			if (id == meal[i].getID()) {
				meal[i].showDetail();
			}
		}
	}
};
