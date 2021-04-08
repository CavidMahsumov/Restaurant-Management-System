#pragma once
class ItemBase {
	int count;
public:
	ItemBase() :count(0) {}
	ItemBase(const int count)
	{
		setCount(count);
	}
	int getCount()const {
		return count;
	}
	void setCount(const int count) {
		if (count > 0)
		{
			this->count = count;
		}
	}
};
