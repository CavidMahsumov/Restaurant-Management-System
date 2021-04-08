#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class FileHelper
{
public:
	static void Append_file_in_text_format(const std::string& file_name, const string& text) {
		std::ofstream fout(file_name, std::ios_base::app);
		if (fout.is_open())
			fout << text;
		else
			cout << "File could not be opened!\n";
		fout.close();
	};

};
