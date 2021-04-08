#pragma once

class Base {
	int id;
public:
	Base() :id(0) {}
	Base(const int id)
	{
		setId(id);
	}
	int getId()const {
		return id;
	}
	void setId(const int id) {
		if (id > 0)
		{
			this->id = id;
		}
	}
	virtual ~Base() = 0 {};
};