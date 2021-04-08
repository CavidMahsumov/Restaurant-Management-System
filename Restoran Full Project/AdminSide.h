#pragma once
#include<string>
#include"Base.h"
using namespace std;
namespace AdminSide {
	class Admin :public Base {
		string username;
		string password;
	public:
		static int adminId;
		Admin() :username(""), password("") {}
		Admin(const string username, const string password) :Base(++adminId)
		{
			setUsername(username);
			setPassword(password);
		}
		string getUsername()const {
			return username;
		}
		string getPassword()const {
			return password;
		}
		void setUsername(const string username) {
			if (!username.empty())
			{
				this->username = username;
			}
		}
		void setPassword(const string password) {
			if (!password.empty())
			{
				this->password = password;
			}
		}
		void show()const {
			cout << "=======Admin Info=======" << endl;
			cout << "Admin id : " << getId() << endl;
			cout << "Admin username : " << getUsername() << endl;
			cout << "Admin password : " << getPassword() << endl;
		}
	};
}