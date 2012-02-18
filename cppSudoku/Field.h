#pragma once
class Field
{
private:
	int number;
	bool changeable;
public:
	Field(void);
	Field(int number, bool changeable);

	~Field(void);

	void setNumber(int number);
	int getNumber();

	bool isChangeable();
};

