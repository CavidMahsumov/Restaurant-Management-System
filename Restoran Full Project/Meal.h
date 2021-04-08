#pragma once
#include"RecipeItem.h"
#include"Exception.h"
#include"Base.h"
using namespace std;
using namespace Exception;
class Meal :public Base {
	ReciepeItem** ingredients;
	int ingredientCount;
	string name;
public:
	static int id;
	Meal() :ingredients(nullptr), ingredientCount(0), name("") {}
	Meal(ReciepeItem** ingredients, const int ingredientCount, const string name) :Base(++id)
	{
		setIngredientCount(ingredientCount);
		setIngredient(ingredients);
		setName(name);
	}
	static int getID() {
		return id;
	}
	ReciepeItem** getIngredient()const {
		return ingredients;
	}
	int getIngredientCount()const {
		return ingredientCount;
	}
	string getName()const {
		return name;
	}
	void setIngredient(ReciepeItem** ingredients) {
		if (ingredients != nullptr)
		{
			this->ingredients = new ReciepeItem * [ingredientCount];
			for (size_t i = 0; i < ingredientCount; i++)
			{
				this->ingredients[i] = ingredients[i];
			}
		}
	}
	void setIngredientCount(const int ingredientCount) {
		if (ingredientCount > 0)
		{
			this->ingredientCount = ingredientCount;
		}
		else {
			throw InvalidArgumentException("Count<0", __LINE__, "Exception.txt");
		}
	}
	void setName(const string name) {
		if (!name.empty())
		{
			this->name = name;
		}
		else {
			throw InvalidArgumentException("Name is Empty", __LINE__, "Exception.txt");

		}
	}
	void show()const {
		cout << "========Meal Info========" << endl;
		cout << "Meal name : " << getName() << endl;
		for (size_t i = 0; i < getIngredientCount(); i++)
		{
			ingredients[i]->show();
		}
		cout << "Meal Price: " << sumPrice << endl;
		sumPrice = 0;
		cout << "Meal ingredient count : " << getIngredientCount() << endl;
	}
	void addIngredient(ReciepeItem* ingredient) {
		auto newIngredient = new ReciepeItem * [ingredientCount + 1]{};
		for (int i = 0; i < ingredientCount; i++)
		{
			newIngredient[i] = ingredients[i];
		}
		newIngredient[ingredientCount] = ingredient;
		++ingredientCount;
		ingredients = newIngredient;
		newIngredient = nullptr;
	}
	void showDetail()const {
		cout << "========Meal Detail Info========" << endl;
		cout << "Meal id: " << getId() << endl;
		cout << "Meal name : " << getName() << endl;
		cout << "Meal ingredient count : " << getIngredientCount() << endl;
		for (size_t i = 0; i < ingredientCount; i++)
		{
			ingredients[i]->showDetail();
		}
		cout << "Meal Price: " << sumPrice << endl;
		sum = 0;
		sumPrice = 0;
	}
};