#pragma once
#include<iostream>
#include"Base.h"
#include<string>
#include"Exception.h"
using namespace Exception;
using namespace std;
class Notfication :public Base {
	string from;
	string date;
	string message;
	string tableNo;
public:
	Notfication(const string from, string date, const string message, const string tableNo)
	{
		setFrom(from);
		setDate(date);
		setMessage(message);
		setTableNo(tableNo);
	}
	string getFrom()const {
		return from;
	}
	string getDate()const {
		return date;
	}
	string getMessage()const {
		return message;
	}
	string getTbaleNo()const {
		return tableNo;
	}
	void setFrom(const string from) {
		if (!from.empty()) {
			this->from = from;
		}
		else {
			throw InvalidArgumentException("From is Empty", __LINE__, "Exception.txt");
		}
	}
	void setDate(const string date) {
		if (!date.empty()) {
			this->date = date;
		}
		else {
			throw InvalidArgumentException("Date is Empty", __LINE__, "Exception.txt");

		}
	}
	void setMessage(const string message) {
		if (!message.empty()) {
			this->message = message;
		}
		else {
			throw InvalidArgumentException("Message is Empty", __LINE__, "Exception.txt");
		}

	}
	void setTableNo(const string tableNo) {
		if (!tableNo.empty())
		{
			this->tableNo = tableNo;
		}
		else {
			throw InvalidArgumentException("Table No is Empty", __LINE__, "Exception.txt");

		}
	}
	void show()const {
		cout << "Table no :" << getTbaleNo() << endl;
		cout << "From: " << getFrom() << endl;
		cout << "Date: " << getDate() << endl;
		cout << "Message: " << getMessage() << endl;
	}
};