#pragma once
#include"RecipeItem.h"
#include"Stock.h"
#include"Order.h"
#include"Meal.h"
#include"Notfication.h"
class Kitchen {
	Stock* stock;
	ReciepeItem** recipeitem;
	Order** orders;
	Meal** meals;
	Notfication** notifications;
	int ordercount;
	int itemcount;
	int mealcount;
	int notificationCount;
public:
	static int id;
	Kitchen() = default;
	Kitchen(ReciepeItem** items, int itemcount, Meal** meals, int mealcount)
	{
		setItems(items);
		setItemCount(itemcount);
		setMealCount(mealcount);
		setMeals(meals);
	}
	int getMealCount()const {
		return mealcount;
	}
	Stock* getStock()const {
		return stock;
	}
	ReciepeItem** getRecipe()const {
		return recipeitem;
	}
	Order** getOrders()const {
		return orders;
	}
	Meal** getMeals()const {
		return meals;
	}
	static int getİd() {
		return id;
	}
	Notfication** getNotification() const {
		return notifications;
	}
	int getNotificationCount()const {
		return notificationCount;
	}
	int getOrderCount()const {
		return ordercount;
	}
	int getItemCount()const {
		return itemcount;
	}
	void setMealCount(const int count) {
		if (count >= 0) {
			this->mealcount = count;
		}
	}
	void setNotifiacationCount(const int notificationCount) {
		if (notificationCount > 0)
		{
			this->notificationCount = notificationCount;
		}
	}
	void setNotification(Notfication** notification) {
		this->notifications = new Notfication * [notificationCount] {};
		for (size_t i = 0; i < notificationCount; i++)
		{
			this->notifications = notification;
		}
	}
	void setMeals(Meal** meals) {
		this->meals = new Meal * [mealcount] {};
		for (size_t i = 0; i < mealcount; i++)
		{
			this->meals[i] = meals[i];
		}
	}
	void setItems(ReciepeItem** items) {
		this->recipeitem = new ReciepeItem * [itemcount] {};
		for (int i = 0; i < itemcount; i++)
		{
			this->recipeitem[i] = items[i];
		}
	}
	void setOrder(Order** orders) {
		this->orders = new Order * [ordercount] {};
		for (int i = 0; i < ordercount; i++)
		{
			this->orders[i] = orders[i];
		}
	}
	void setOrderCount(int ordercount) {
		if (ordercount >= 0) {
			this->ordercount = ordercount;
		}
	}
	void setItemCount(int itemcount) {
		if (itemcount >= 0) {
			this->itemcount = itemcount;
		}
	}
	void addNotfication(Notfication* notification) {
		auto newNotfications = new Notfication * [notificationCount + 1]{};
		for (size_t i = 0; i < notificationCount; i++)
		{
			newNotfications[i] = this->notifications[i];
		}
		newNotfications[notificationCount] = notification;
		++notificationCount;
		notifications = newNotfications;
		newNotfications = nullptr;
	}
	void searchMeal(const string& name) {
		for (size_t i = 0; i < mealcount; i++)
		{
			if (name == meals[i]->getName())
			{
				meals[i]->showDetail();
				return;
			}
		}
		cout << "Name is incorrect!" << endl;
	}
	void addOrders(Order* order) {
		auto newOrders = new Order * [ordercount + 1]{};
		for (size_t i = 0; i < ordercount; i++)
		{
			newOrders[i] = orders[i];
		}
		newOrders[ordercount] = order;
		++ordercount;
		orders = newOrders;
		newOrders = nullptr;
	}
	void deleteOrder(int id) {
		auto newOrders = new Order * [ordercount - 1]{};
		for (size_t i = 0; i < id; i++)
		{
			newOrders[i] = orders[i];
		}
		for (int i = id, i2 = id + 1; i < ordercount - 1; i++)
		{
			newOrders[i] = orders[i2];
		}
		--ordercount;
		orders = newOrders;
		newOrders = nullptr;
	}
	void accaptedOrder(int id) {
		for (int i = 0; i < ordercount; i++)
		{
			if (id == orders[i]->getId()) {
				cout << "Meal is accapted: " << endl;
				deleteOrder(id);
				Order::id = 0;
			}
			else {
				cout << "Id is incorrect" << endl;
			}
		}
	}
	void cancelOrder(int id) {
		for (int i = 0; i < ordercount; i++)
		{
			if (id == orders[i]->getId()) {
				cout << "Meal is Cancel" << endl;
				deleteOrder(id);
				Order::id = 0;

			}
			else {
				cout << "Id is incorrect" << endl;
			}
		}
	}

	void addMeals(Meal* meal) {
		auto newMeal = new Meal * [mealcount + 1]{};
		for (size_t i = 0; i < mealcount; i++)
		{
			newMeal[i] = meals[i];
		}
		newMeal[mealcount] = meal;
		++mealcount;
		meals = newMeal;
		newMeal = nullptr;
	}
	void deleteMeal(int id) {
		auto newMeal = new Meal * [mealcount - 1]{};
		for (int i = 0; i < id; i++)
		{
			newMeal[i] = meals[i];
		}
		for (int i = id, i2 = id + 1; i < mealcount - 1; i++, i2++)
		{
			newMeal[i] = meals[i2];
		}
		--mealcount;
		meals = newMeal;
		newMeal = nullptr;
	}
	void UpdateMeal(int id) {
		string name;
		cout << "Input Name: " << endl;
		cin >> name;

		for (size_t i = 0; i < mealcount; i++)
		{
			if (id == meals[i]->getId()) {
				meals[i]->setName(name);
				break;
			}
			else {
				cout << "InCorrect id " << endl;
			}
		}
	}
	void showOrders()const {
		if (ordercount != 0) {
			cout << "Order Count: " << getOrderCount() << endl;

			for (int i = 0; i < ordercount; i++)
			{
				orders[i]->show();
			}
		}
		else {
			cout << "Order Not Found:" << endl;
			Sleep(1200);
			system("cls");
		}
	}
	void showAllMeals()const {
		cout << "Meals Count: " << getMealCount() << endl;
		for (size_t i = 0; i < mealcount; i++)
		{
			meals[i]->showDetail();
		}
	}
	void showNotifiactions()const {
		for (size_t i = 0; i < notificationCount; i++)
		{
			notifications[i]->show();
		}
	}
};
