#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <cstdlib>
#include "conio.h"
#include "Exception.h"
#include"Base.h"
#include"AdminSide.h"
#include"ItemBaseh.h"
#include"IngredientClass.h"
#include"Ingredients.h"
#include"RecipeItem.h"
#include"GlobalVariable.h"
#include"Meal.h"
#include"Order.h"
#include"Notfication.h"
#include"Table.h"
#include"DataBase.h"
#include"Restourant.h"
#include"Stock.h"
#include"Kitchen.h"
#include"FileHelper.h"

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128


using namespace std;

void unsolvedWord(string phrase);
string phrase;



using namespace Exception;
using namespace AdminSide;
int Ingredient::ingredietnid = 0;
int Meal::id = 0;
int Admin::adminId = 0;
int Order::id = 0;
class Console {
public:
	//Admin
	Admin* admin1 = new Admin("admin", "admin");
	Admin* admin2 = new Admin("Cavid", "123");
	Admin* admin3 = new Admin("Raul", "123");
	Admin** admins = new Admin * [3]{ admin1,admin2,admin3 };
	//Ingredients
	Ingredient* tomato = new Tomatoes("Pomidor", 0.1, 8, 3, 1, 5.10);
	Ingredient* spice = new Spices("Solt", 2, 5, 3, 1, 1.30);
	Ingredient* meat = new Meat("Toyug Eti", 10, 25, 10, 10, 2.10);
	Ingredient* mushroom = new Mushrooms("Gobeley", 0.1, 15, 3, 2, 3.50);
	Ingredient* cheese = new Cheese("Ag Pendir", 1, 8, 3, 5, 2.20);
	Ingredient** ing = new Ingredient * [5]{ mushroom,meat,spice,cheese,tomato };
	//RecipeItem
	ReciepeItem* reciep = new ReciepeItem(mushroom, 13);
	ReciepeItem* reciep1 = new ReciepeItem(meat, 1);
	ReciepeItem* reciep2 = new ReciepeItem(spice, 1);
	ReciepeItem* reciep3 = new ReciepeItem(cheese, 1);
	ReciepeItem* reciep4 = new ReciepeItem(tomato, 1);
	ReciepeItem** items = new ReciepeItem * [5]{ reciep,reciep1,reciep2,reciep3,reciep4 };
	ReciepeItem** items1 = new ReciepeItem * [4]{ reciep,reciep1,reciep2,reciep3 };
	ReciepeItem** items2 = new ReciepeItem * [3]{ reciep,reciep1,reciep2 };
	//Meals
	Meal* meal = new Meal(items, 5, "Pizza");
	Meal* meal1 = new Meal(items1, 4, "Kabab");
	Meal* meal2 = new Meal(items2, 3, "As");
	Meal** meals = new Meal * [3]{ meal,meal1,meal2 };
	//tables
	Table* table1 = new Table("1)T-1", false);
	Table* table2 = new  Table("2)T-2", false);
	Table* table3 = new Table("3)T-3", true);
	Table* table4 = new Table("4)T-4", false);
	Table** tables = new Table * [4]{ table1,table2,table3,table4 };
	//Restoran
	Restourant* restourant = new Restourant("Cavid Restoran", "Genclik", "Baku", 5000, admins, tables);
	//Stock
	Stock* stock = new Stock(items, 5);
	//Kitchen
	Kitchen* kitchen = new Kitchen(items, 5, meals, 3);
	//Datebase
	DateBase* datebase = new DateBase(admins, tables, meals);
	short choose = 0;
	short selectTable = 0;
	short chooseadmin;
	short chooseMenu;
	short chooseBack;
	short chooseBack1;
	short chooseBack2;
	short chooseBack3;
	short chooseBack4;
	short kitchenchoose = 0;
	string addchoose;
	int selectin = 0;

	void adminSide() {

		if (choose == 1) {
			system("color 20");
			string username;
			string password;
			cout << "Input username : ";
			cin >> username;
			cout << "Input Password : ";
			cin >> password;
			if (restourant->AdminCheck(username, password)) {

				FileHelper::Append_file_in_text_format("error.log", "Admin succesufuly loged in\n");
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
				cout << "Password is correct! " << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				Sleep(2300);
				system("cls");
				system("color 20");//21

				cout << "1)Stock" << endl;
				cout << "2)Kitchen" << endl;
				cout << "3)Exit" << endl << endl;
				cout << "Select : " << endl;
				cin >> chooseadmin;
				system("cls");
				stockMenu();
				kitchenMenu();
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				cout << "Incorrect Password" << endl;
				FileHelper::Append_file_in_text_format("error.log", "Admin entered incorrect password\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				Sleep(1000);
				system("cls");
				adminSide();
			}
		}
	}


	void kitchenMenu() {
		if (chooseadmin == 2) {
			system("color 20");//21

			cout << "1)Show all orders" << endl;
			cout << "2)Accept Orders" << endl;
			cout << "3)Cancel Orders" << endl;
			cout << "4)Show All Meals" << endl;
			cout << "5)Add Meals" << endl;
			cout << "6)Delete Meal" << endl;
			cout << "7)Update Meal" << endl;
			cout << "8)Stock" << endl;
			cout << "9)Show all notifications" << endl;
			cout << "10)Back" << endl;
			int choosekitchen = 0;
			cout << "Your Selection : \n";
			cin >> choosekitchen;
			if (choosekitchen == 1) {
				system("color 20");//21

				kitchen->showOrders();
				FileHelper::Append_file_in_text_format("error.log", "Admin saw order\n");
				cout << "1)Back: " << endl;
				cin >> kitchenchoose;
				while (1) {
					if (kitchenchoose == 1) {
						system("cls");
						kitchenMenu();
					}
					else {
						cout << "Wrong choose" << endl;
						cin >> kitchenchoose;
					}

				}


			}
			else if (choosekitchen == 2) {
				system("color 20");//21
				if (kitchen->getOrderCount() != 0) {
					cout << "++++++++++Orders:+++++++++++++" << endl;
					kitchen->showOrders();
					int id;
					cout << "Input ID : ";
					cin >> id;
					kitchen->accaptedOrder(id);
					Notfication* notification = new Notfication("Kitchen", __DATE__, "Accepted order", tables[selectTable - 1]->getNo());
					tables[selectTable - 1]->addNotfication(notification);
					FileHelper::Append_file_in_text_format("error.log", "Accapted Order\n");
					cout << "If you want back to menu?" << endl;
					string answer;
					cout << "Your Select : " << endl;
					cin >> answer;
					if (answer == "Yes") {
						Start();
					}
				}
				else {
					cout << "Order Not Found" << endl;
					Sleep(1200);
					system("cls");
					kitchenMenu();
				}
			}

			else if (choosekitchen == 3) {
				system("color 20");//21
				if (kitchen->getOrderCount() != 0) {
					cout << "++++++++++Orders:+++++++++++" << endl;
					kitchen->showOrders();
					int id;
					cout << "Input ID: ";
					cin >> id;
					kitchen->cancelOrder(id);
					FileHelper::Append_file_in_text_format("error.log", "Canceled Order\n");
					Notfication* notification = new Notfication("Kitchen", __DATE__, "Order Canceled", tables[selectTable - 1]->getNo());
					tables[selectTable - 1]->addNotfication(notification);


					cout << "If you want back to menu?" << endl;
					string answer;
					cout << "Your Select : " << endl;
					cin >> answer;
					if (answer == "Yes") {
						Start();
					}
				}
				else {
					cout << "Order Not Found" << endl;
					Sleep(1200);
					system("cls");
					kitchenMenu();
				}
			}
			else if (choosekitchen == 4) {
				system("color 20");//21

				cout << "++++++Meals Info++++++++++++" << endl;
				kitchen->showAllMeals();
				FileHelper::Append_file_in_text_format("error.log", "Admin saw dishes\n");
				cout << "1)Back" << endl;
				cout << "Your Select : " << endl;
				cin >> kitchenchoose;
				while (1) {
					if (kitchenchoose == 1) {
						system("cls");
						kitchenMenu();
					}
					else {
						cout << "Wrong Choice: " << endl;
						cin >> kitchenchoose;
					}
				}
			}
			else if (choosekitchen == 5) {
				system("color 20");//21

				stock->showDetail();
				string name;
				cout << "Input Meal Name: " << endl;
				cin >> name;
				short id;
				int count = 0;
				cout << "How Many Ingredietn Add Your Meals?" << endl;
				cin >> count;
				for (size_t i = 0; i < count; i++)
				{
					cout << "Input ID : " << endl;
					cin >> id;
					ReciepeItem** items1 = new ReciepeItem * [count] {items[id - 1]};

				}
				Meal* meal = new Meal(items1, count, name);
				kitchen->addMeals(meal);
				FileHelper::Append_file_in_text_format("error.log", "Meals added\n");
				cout << "++++++++++ALL Meals+++++++++++" << endl;
				kitchen->showAllMeals();
				cout << "1)Back" << endl;
				cout << "Your Select : " << endl;
				cin >> kitchenchoose;
				while (1) {
					if (kitchenchoose == 1) {
						system("cls");
						kitchenMenu();
					}
					else {
						cout << "Wrong Choice: " << endl;
						cout << "Please Input Again!" << endl;
						cin >> kitchenchoose;
					}
				}
			}
			else if (choosekitchen == 6) {
				system("color 20");//21

				kitchen->showAllMeals();
				short id;
				cout << "Input Id: " << endl;
				cin >> id;
				kitchen->deleteMeal(id - 1);
				FileHelper::Append_file_in_text_format("error.log", "Meals deleted\n");
				system("cls");
				cout << "++++++++++After Deleted+++++++++" << endl;
				kitchen->showAllMeals();
				cout << "1)Back" << endl;
				cout << "Your Select : " << endl;
				cin >> kitchenchoose;
				while (1) {
					if (kitchenchoose == 1) {
						system("cls");
						kitchenMenu();
					}
					else {
						cout << "Wrong Choice: " << endl;
						cout << "Please Input Again!" << endl;
						cin >> kitchenchoose;
					}
				}
			}
			else if (choosekitchen == 7) {
				system("color 20");//21

				kitchen->showAllMeals();
				cout << "Enter The Id: " << endl;
				short id;
				cin >> id;
				kitchen->UpdateMeal(id);
				FileHelper::Append_file_in_text_format("error.log", "Meals updated\n");
				cout << "+++++++++After Update+++++++++" << endl;
				kitchen->showAllMeals();
				cout << "1)Back" << endl;
				cout << "Your Select : " << endl;
				cin >> kitchenchoose;
				while (1) {
					if (kitchenchoose == 1) {
						system("cls");
						kitchenMenu();
					}
					else {
						cout << "Wrong Choice: " << endl;
						cout << "Please Input Again!" << endl;
						cin >> kitchenchoose;
					}
				}
			}
			else if (choosekitchen == 8) {
				system("color 20");//21

				cout << "+++++++++++++Detail Show+++++++++++" << endl;
				stock->showDetail();
				FileHelper::Append_file_in_text_format("error.log", "Admin saw meals detailed\n");
				cout << "1)Back" << endl;
				cout << "Your Select : " << endl;
				cin >> kitchenchoose;
				while (1) {
					if (kitchenchoose == 1) {
						system("cls");
						kitchenMenu();
					}
					else {
						cout << "Wrong Choice: " << endl;
						cout << "Please Input Again!" << endl;
						cin >> kitchenchoose;
					}
				}
			}
			else if (choosekitchen == 9)
			{
				if (kitchen->getNotificationCount() != 0) {
					system("color 20");//21
					kitchen->showNotifiactions();
					cout << "1)Back" << endl;
					cout << "Your Select : " << endl;
					cin >> kitchenchoose;
					while (1) {
						if (kitchenchoose == 1) {
							system("cls");
							kitchenMenu();
						}
						else {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
							cout << "Wrong Choice: " << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
							cout << "Please Input Again!" << endl;
							cin >> kitchenchoose;
						}
					}
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					cout << "Notfication Not Found" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					Sleep(1200);
					system("cls");
					kitchenMenu();
				}
			}
			else if (choosekitchen == 10) {
				system("cls");
				Start();

			}
		}
	}
	void wrongIncreaseChoice() {
		if (chooseBack2 == 1)
		{
			stockMenu();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "Wrong choice!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			cin >> chooseBack2;
		}
	}
	void wrongDecreaseChoice() {
		if (chooseBack3 == 1)
		{
			stockMenu();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "Wrong choice!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			cin >> chooseBack3;
		}
	}
	void wrongShowChoice() {
		if (chooseMenu == 1)
		{
			stockMenu();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "Wrong choice!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			cin >> chooseMenu;
		}
	}
	void wrongDeleteChoice() {
		if (chooseBack4 == 1)
		{
			stockMenu();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "Wrong choice!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			cin >> chooseBack4;
		}
	}
	void addAgain() {
		system("color 20");//21

		cout << "If you add ingredient again?(Yes/No)" << endl;
		cin >> addchoose;
		if (addchoose == "YES" || addchoose == "yes") {
			while (true) {
				stock->addIngredientinStock();
				cout << "1)Back to Stock" << endl;
				cout << "2)Add again" << endl;
				cout << "Select : ";
				cin >> chooseBack1;
				system("cls");
				if (chooseBack1 == 1)
				{
					stockMenu();
				}
				else if (chooseBack1 == 2)
				{
					addAgain();
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					cout << "Wrong choice!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					Sleep(1000);
					system("cls");
					cout << "1)Back to Stock" << endl;
					cin >> chooseBack1;
					if (chooseBack1 == 1)
					{
						stockMenu();
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
						cout << "Wrong choice!" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
						cin >> chooseBack1;
					}
				}
			}
		}
		else if (addchoose == "NO" || addchoose == "no"||addchoose=="No") {
			cout << "1)Back to Stock" << endl;
			cout << "Select : ";
			cin >> chooseBack;
			system("cls");
			if (chooseBack == 1)
			{
				stockMenu();
			}
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "Wrong choiche!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			addAgain();
		}
	}
	void stockMenu() {
		system("color 20");//21

		if (chooseadmin == 1) {
			cout << "1)Show All Ingredients" << endl;
			cout << "2)Add Ingredients" << endl;
			cout << "3)Increase ingredient amount" << endl;
			cout << "4)Decrease ingredient amount" << endl;
			cout << "5)Delete Ingredient" << endl;
			cout << "6)Exit" << endl << endl;
			int admin1s;
			cout << "Select : ";
			cin >> admin1s;
			if (admin1s == 1) {
				system("cls");
				stock->show();
				FileHelper::Append_file_in_text_format("error.log", "Admin saw all ingredient\n");
				cout << "1)Back to Stock" << endl;
				cout << "Select : ";
				cin >> chooseMenu;
				system("cls");
				while (true)
				{
					if (chooseMenu == 1)
					{
						stockMenu();
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
						cout << "Wrong choice!" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
						cout << "Select : " << endl;
						cin >> chooseMenu;
						wrongShowChoice();
					}
				}
			}
			else if (admin1s == 2) {
				int admin2s = 0;
				for (int i = 0; i < 5; i++)
				{
					items[i]->showDetail();
				}
				system("cls");
				stock->addIngredientinStock();
				FileHelper::Append_file_in_text_format("error.log", "Admin added new ingredient\n");
				addAgain();
			}
			else if (admin1s == 6) {
				exit(-1);
			}
			else if (admin1s == 5) {
				int id2 = 0;
				system("cls");
				stock->showDetail();
				cout << "Input Id: " << endl;
				cin >> id2;
				stock->deleteIngredient(id2 - 1);
				FileHelper::Append_file_in_text_format("error.log", "Admin delete ingredient\n");
				cout << "1)Back to stock" << endl;
				cout << "Select : ";
				cin >> chooseBack4;
				system("cls");
				while (true)
				{
					if (chooseBack4 == 1)
					{
						stockMenu();
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
						cout << "Wrong choice!" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
						cout << "Select  : ";
						cin >> chooseBack4;
						wrongDeleteChoice();
					}
				}
			}
			else if (admin1s == 3)
			{
				int id3;
				system("cls");
				cout << "What kind of ingredient ?" << endl;
				stock->showDetail();
				cout << "Input ID : ";
				cin >> id3;
				int increase = 0;
				cout << "Input amount : ";
				cin >> increase;
				stock->increaseIngredientCount(items[id3 - 1], increase);
				FileHelper::Append_file_in_text_format("error.log", "Admin increased ingredient count\n");
				cout << "1)Back to stock" << endl;
				cout << "Select : ";
				cin >> chooseBack2;
				system("cls");
				while (true)
				{
					if (chooseBack2 == 1)
					{
						stockMenu();
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
						cout << "Wrong choice!" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
						cout << "Select  : ";
						cin >> chooseBack2;
						wrongIncreaseChoice();
					}
				}
			}
			else if (admin1s == 4)
			{
				int id3;
				cout << "What kind of ingredient ?" << endl;
				stock->showDetail();
				cout << "Input ID : " << endl;
				cin >> id3;
				int decrease = 0;
				cout << "Input amount : " << endl;
				cin >> decrease;
				stock->decreaseIngredientCount(items[id3 - 1], decrease);
				FileHelper::Append_file_in_text_format("error.log", "Admin decreased ingredient count\n");
				cout << "1)Back to stock" << endl;
				cout << "Select : ";
				cin >> chooseBack3;
				system("cls");
				while (true)
				{
					if (chooseBack3 == 1)
					{
						stockMenu();
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
						cout << "Wrong choice!" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
						cout << "Select  : ";
						cin >> chooseBack3;
						wrongDecreaseChoice();
					}
				}
			}
		}
	};

	void clientMenu() {
		int ss = 0;
		cout << "1)Show Menu" << endl;
		cout << "2)Order" << endl;
		cout << "3)Exit Restoran" << endl;
		cout << "4)Show Detail Meal" << endl;
		cout << "5)Back:" << endl;
		cout << "6)Search meal" << endl;
		cout << "7)Show notifications" << endl;
		cout << "Select: ";
		cin >> ss;
		int choose;
		if (ss == 1) {
			kitchen->showAllMeals();
		}
		else if (ss == 2) {
			cout << "Input meals ID : " << endl;
			cin >> choose;
			cout << "Do You Want Add Ingredient?(Yes/No)" << endl;
			string add;
			cin >> add;
			if (add == "YES") {
				int ig = 0;
				for (int i = 0; i < 5; i++)
				{
					items[i]->showDetail();
				}
				cout << "Input ID : ";
				cin >> ig;
				meals[choose - 1]->addIngredient(items[ig - 1]);
				cout << meals[choose - 1]->getName() << "is Cooked" << endl;
				FileHelper::Append_file_in_text_format("error.log", "Client meal order\n");
				Notfication* notification = new Notfication("Client side", __DATE__, meals[choose - 1]->getName(), tables[selectTable - 1]->getNo());
				kitchen->addNotfication(notification);
				double rating;
				cout << "Please rate the food[1-5]" << endl;
				cin >> rating;
				cout << "Thank For Order" << endl;
				system("cls");
				Start();
			}
			else {
				cout << meals[choose - 1]->getName() << "is Cooked" << endl;
				system("cls");
				Order* order = new Order(tables[selectTable - 1]->getNo(), meals[choose - 1], 1);
				kitchen->addOrders(order);
				FileHelper::Append_file_in_text_format("error.log", "Client ordered meal\n");
				Notfication* notification = new Notfication("Client side", __DATE__, meals[choose - 1]->getName(), tables[selectTable - 1]->getNo());
				int ingAmount = meal[choose - 1].getIngredientCount();
				kitchen->addNotfication(notification);
				double rating;
				cout << "Please rate the food[1-5]" << endl;
				cin >> rating;
				cout << "Thank For Order" << endl;
				system("cls");
				Start();
			}
		}
		else if (ss == 3) {
			system("cls");
			exit(-1);
		}
		else if (ss == 4) {
			int id;
			cout << "Enter ID : ";
			cin >> id;
			for (int i = 0; i < 3; i++)
			{
				datebase->showDetailMealsWithId(id);
				FileHelper::Append_file_in_text_format("error.log", "Client saw meal detailed\n");
			}
			int choose5;
			cout << "1)Back to Menu" << endl;
			cout << "Select : ";
			cin >> choose5;
			system("cls");
			if (choose5 == 1)
			{
				tables[selectTable - 1]->setIsEmpty(false);
				clientSide();
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				cout << "Wrong choice!" << endl;
				cout << "Backing menu..." << endl;
				Sleep(1500);
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				clientSide();
			}
		}
		else if (ss == 5) {
			system("cls");
			tables[selectTable - 1]->setIsEmpty(false);
			clientMenu();
		}
		else if (ss == 6)
		{
			string name;
			cout << "Enter name : " << endl;
			cin >> name;
			kitchen->searchMeal(name);
			int choose5;
			cout << "1)Back to Menu" << endl;
			cout << "Select : ";
			cin >> choose5;
			system("cls");
			if (choose5 == 1)
			{
				tables[selectTable - 1]->setIsEmpty(false);
				clientMenu();
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				cout << "Wrong choice!" << endl;
				cout << "Backing menu..." << endl;
				Sleep(1500);
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				clientSide();
			}

		}
		else if (ss == 7)
		{
			if (tables[selectTable - 1]->getNotificationCount() != 0) {
				tables[selectTable - 1]->showNotification();
				int choose5;
				cout << "1)Back to Menu" << endl;
				cout << "Select : ";
				cin >> choose5;
				system("cls");
				if (choose5 == 1)
				{
					tables[selectTable - 1]->setIsEmpty(false);
					clientMenu();
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					cout << "Wrong choice!" << endl;
					cout << "Backing menu..." << endl;
					Sleep(1500);
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					clientMenu();
				}
			}
			else {
				cout << "Notfiaction Not Found" << endl;
				Sleep(1200);
				system("cls");
				clientMenu();
			}
		}
	}
	void clientSide() {
		if (choose == 2) {
			cout << "Please Choose Table" << endl;
			system("cls");
			for (int i = 0; i < 4; i++)
			{
				tables[i]->showTable();
			}
			cout << "Your Selection: ";
			cin >> selectTable;
			if (selectTable <= 4) {
				if (tables[selectTable - 1]->checkTable(tables[selectTable - 1]) == false) {
					FileHelper::Append_file_in_text_format("error.log", "Client choosed table\n");
					system("cls");
					tables[selectTable - 1]->setIsEmpty(true);
					tables[selectTable - 1]->getIsEmpty() == true;
					int ss = 0;
					cout << "1)Show Menu" << endl;
					cout << "2)Order" << endl;
					cout << "3)Exit Restoran" << endl;
					cout << "4)Show Detail Meal" << endl;
					cout << "5)Back:" << endl;
					cout << "6)Search meal" << endl;
					cout << "7)Show notifications" << endl;
					cout << "Select: ";
					cin >> ss;
					int choose;
					if (ss == 1) {
						kitchen->showAllMeals();
						int choose5;
						cout << "1)Back to Menu" << endl;
						cout << "Select : ";
						cin >> choose5;
						system("cls");
						while (1) {
							if (choose5 == 1)
							{
								tables[selectTable - 1]->setIsEmpty(false);
								clientMenu();
							}
							else {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
								cout << "Wrong Input Again!" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
								cin >> choose5;
							}
						}

					}
					else if (ss == 2) {
						kitchen->showAllMeals();

						cout << "Input meals ID : " << endl;
						cin >> choose;
						cout << "Do You Want Add Ingredient?(Yes/No)" << endl;
						string add;
						cin >> add;
						if (add == "YES") {
							int ig = 0;
							for (int i = 0; i < 5; i++)
							{
								items[i]->showDetail();
							}
							cout << "Input ID : ";
							cin >> ig;
							meals[choose - 1]->addIngredient(items[ig - 1]);
							cout << meals[choose - 1]->getName() << "is Cooked" << endl;
							FileHelper::Append_file_in_text_format("error.log", "Client meal order\n");
							Notfication* notification = new Notfication("Client side", __DATE__, meals[choose - 1]->getName(), tables[selectTable - 1]->getNo());
							kitchen->addNotfication(notification);
							double rating;
							cout << "Please rate the food[1-5]" << endl;
							cin >> rating;
							cout << "Thank For Order" << endl;
							system("cls");
							Start();
						}
						else {
							cout << meals[choose - 1]->getName() << "is Cooked" << endl;
							system("cls");
							Order* order = new Order(tables[selectTable - 1]->getNo(), meals[choose - 1], 1);
							kitchen->addOrders(order);
							FileHelper::Append_file_in_text_format("error.log", "Client ordered meal\n");
							Notfication* notification = new Notfication("Client side", __DATE__, meals[choose - 1]->getName(), tables[selectTable - 1]->getNo());
							int ingAmount = meal[choose - 1].getIngredientCount();
							kitchen->addNotfication(notification);
							double rating;
							cout << "Please rate the food[1-5]" << endl;
							cin >> rating;
							cout << "Thank For Order" << endl;
							system("cls");
							Start();
						}
					}
					else if (ss == 3) {
						system("cls");
						exit(-1);
					}
					else if (ss == 4) {
						stock->showDetail();
						int id;
						cout << "Enter ID : ";
						cin >> id;
						for (int i = 0; i < 3; i++)
						{
							datebase->showDetailMealsWithId(id);
							FileHelper::Append_file_in_text_format("error.log", "Client saw meal detailed\n");
						}
						int choose5;
						cout << "1)Back to Menu" << endl;
						cout << "Select : ";
						cin >> choose5;
						system("cls");
						while (1) {
							if (choose5 == 1)
							{
								tables[selectTable - 1]->setIsEmpty(false);
								clientMenu();
							}
							else {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
								cout << "Wrong Input Again!" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
								cin >> choose5;
							}
						}

					}
					else if (ss == 5) {
						system("cls");
						tables[selectTable - 1]->setIsEmpty(false);
						clientSide();
					}
					else if (ss == 6)
					{
						string name;
						cout << "Enter name : " << endl;
						cin >> name;
						kitchen->searchMeal(name);
						int choose5;
						cout << "1)Back to Menu" << endl;
						cout << "Select : ";
						cin >> choose5;
						system("cls");
						while (1) {
							if (choose5 == 1)
							{
								tables[selectTable - 1]->setIsEmpty(false);
								clientMenu();
							}
							else {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
								cout << "Wrong Input Again!" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
								cin >> choose5;
							}
						}

					}
					else if (ss == 7)
					{
						if (tables[selectTable - 1]->getNotificationCount() != 0) {
							tables[selectTable - 1]->showNotification();
							int choose5;
							cout << "1)Back to Menu" << endl;
							cout << "Select : ";
							cin >> choose5;
							system("cls");
							while (1) {
								if (choose5 == 1)
								{
									tables[selectTable - 1]->setIsEmpty(false);
									clientMenu();
								}
								else {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
									cout << "Wrong Input Again!" << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
									cin >> choose5;
								}
							}
						}
						else {
							while (1) {
								cout << "Notifaction Not Found" << endl;
								Sleep(1200);
								system("cls");
								clientMenu();
							}

						}
					}
				}

				else if (selectin == 2) {
					system("cls");
					cout << "Cox sagolun Birde Gozleyirik!" << endl;
					exit(-1);
				}
				else {
					while (1) {
						tables[selectTable - 1]->setIsEmpty(false);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
						cout << "Wrong Choice!Please Input Again" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
						cin >> selectin;
						clientMenu();

					}
				}
			}
			else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				cout << "Wrong Choose!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				FileHelper::Append_file_in_text_format("error.log", "Client choosed table is full\n");
				clientSide();
			}
		}

	}
	void Exit() {
		if (choose == 3) {
			system("cls");
			system("color 20");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			FileHelper::Append_file_in_text_format("error.log", "Client exit restourant\n");
			cout << "Exiting...." << endl;
			exit(-1);
		}
	}
	void Start() {
		system("color 20");//21
		cout << "\t\t\t\t\tWelcome My Restourant" << endl;
		cout << "\t\t\t\t1)Admin" << endl;
		cout << "\t\t\t\t2)Client" << endl;
		cout << "\t\t\t\t3)Exit" << endl;
		cout << "\t\t\t\t4)Info Restoran: " << endl;
		cout << "\t\t\t\tSelect :";
		cin >> choose;
		system("cls");
		adminSide();
		clientSide();
		if (choose == 3) {
			Exit();
		}
		if (choose == 4) {
			restourant->show();
			cout << "1)Back " << endl;
			int back;
			cout << "Select: ";
			cin >> back;
			if (back == 1) {
				system("cls");
				Start();
			}
			
		}
		else {
			Start();
		}
	}

};

void main()
{
	Console c;
	try {
		HWND hwnd = GetConsoleWindow();
		HMENU hmenu = GetSystemMenu(hwnd, FALSE);
		EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
		system("color 21");
		c.Start();
	}
	catch (...) {
		cout << "Exception Occured" << endl;
	}

	//Cixmaqi qadagan etmek
}