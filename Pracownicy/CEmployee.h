#pragma once
#include "commonHeader.h"
class CEmployee
{
	private:
		string fullName;
		float workTime;
		float hourlySalary;
		string idNumber;
		float paycheck;

	public:
		CEmployee();
		CEmployee(vector<string> row);
		string getFullName();
		void setFullName(string fullNameNew);
		float getWorkTime();
		void setWorkTime(float workTimeNew);
		float getHourlySalary();
		void setHourltSalary(float hourlySalaryNew);
		string getIdNumber();
		void setIdNumber(string idNumberNew);
		void calculatePaycheck();
		float getPaycheck();
		~CEmployee();
};

