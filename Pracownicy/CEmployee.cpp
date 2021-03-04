#include "CEmployee.h"


CEmployee::CEmployee() 
{
	this->fullName = "";
	this->workTime = 0;
	this->hourlySalary = 0;
	this->idNumber = "";
	this->paycheck = 0;
}

CEmployee::CEmployee(vector<string> row)
{
	this->fullName = row[0];
	this->workTime = stof(row[1]);
	this->hourlySalary = stof(row[2]);
	this->idNumber = row[3];
	this->paycheck = 0;
}

string CEmployee::getFullName()
{
	return this->fullName;
}

void CEmployee::setFullName(string fullNameNew)
{
	this->fullName = fullNameNew;
}

float CEmployee::getWorkTime()
{
	return this->workTime;
}

void CEmployee::setWorkTime(float workTimeNew)
{
	this->workTime = workTimeNew;
}

float CEmployee::getHourlySalary()
{
	return this->hourlySalary;
}

void CEmployee::setHourltSalary(float hourlySalaryNew)
{
	this->hourlySalary = hourlySalaryNew;
}

string CEmployee::getIdNumber()
{
	return this->idNumber;
}

void CEmployee::setIdNumber(string idNumberNew)
{
	this->idNumber = idNumberNew;
}

void CEmployee::calculatePaycheck()
{
	this->paycheck = this->workTime * this->hourlySalary;
}

float CEmployee::getPaycheck()
{
	return this->paycheck;
}

CEmployee::~CEmployee()
{
}
