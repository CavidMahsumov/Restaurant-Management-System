#pragma once
#include<string>
using namespace std;
namespace Exception {
	class Exception
	{

	private:
		string text;
		int line;
		string file_name;

	public:

		Exception(const std::string& text, const int& line, const std::string& file_name) {
			setText(text);
			setLine(line);
			setFilename(file_name);
		};

		void setText(const std::string& text) {
			this->text = text;
		};
		std::string getText() const {
			return text;
		};

		void setLine(const int& line) {
			if (line >= 0) {
				this->line = line;
			}

		};
		int getLine() const {
			return line;
		};

		void setFilename(const std::string& file_name) {
			if (!file_name.empty()) {
				this->file_name = file_name;
			}

		};
		string getFilename() const {
			return file_name;

		};



		friend std::ostream& operator << (std::ostream& out, const Exception& exception);

	};

	class DataBaseException : public Exception
	{
	public:

		DataBaseException(const std::string& text, const int& line, const std::string& file_name)
			:Exception(text, line, file_name) {};

	};

	class InvalidArgumentException : public Exception
	{
	public:

		InvalidArgumentException(const std::string& text, const int& line, const std::string& file_name)
			:Exception(text, line, file_name) {};

	};
	ostream& operator << (std::ostream& out, const Exception& exception) {
		out << "Error Text: " << exception.getText() << endl;
		out << "Error Line: " << exception.getLine() << endl;
		out << "File Name: " << exception.getFilename() << endl;
		return out;

	}
}