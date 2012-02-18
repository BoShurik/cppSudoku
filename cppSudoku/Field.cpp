#include "StdAfx.h"
#include "Field.h"


Field::Field(void)
{
	this->number = 0;
	this->changeable = true;
}

Field::Field(int number, bool changeable)
{
	this->number = number;
	this->changeable = changeable;
}

Field::~Field(void)
{
}

void Field::setNumber(int number)
{
	this->number = number;
}

int Field::getNumber()
{
	return this->number;
}

bool Field::isChangeable()
{
	return this->changeable;
}
