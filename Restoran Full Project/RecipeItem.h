#pragma once
#include<iostream>
#include"ItemBaseh.h"
#include"GlobalVariable.h"
#include"IngredientClass.h"

using namespace std;
class ReciepeItem :public ItemBase {
	Ingredient* ingredient;
public:
	ReciepeItem() = default;
	ReciepeItem(Ingredient* ingredient, const int count) :ItemBase(count)
	{
		setIngredient(ingredient);
	}
	Ingredient* getIngredient()const {
		return ingredient;
	}
	void setIngredient(Ingredient* ingredient) {
		if (ingredient != nullptr)
		{
			this->ingredient = ingredient;
		}
	}
	int count = ItemBase::getCount();
	void show()const {
		ingredient->show();
		for (int i = 0; i < ItemBase::getCount(); i++)
		{
			sumPrice += ingredient->getMoney();
		}
	}
	void showDetail()const {
		ingredient->showDetail();
		cout << "Count : " << ItemBase::getCount() << endl;
		for (size_t i = 0; i < ItemBase::getCount(); i++)
		{
			sum += ingredient->getKcal();
			sumPrice += ingredient->getMoney();
		}
		cout << "Total Kcal : " << sum << endl;
	}
};
