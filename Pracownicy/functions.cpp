#include "functions.h"

list<CEmployee> employees;

void menu() 
{
	char choice = '\0';
	cout << "Welcome to employees manegement system!" << endl;
	while (tolower(choice) != 'x')
	{
		printMenu(); 
		choice = _getch();
		system("CLS");
		menuSwitch(choice);
	}
}

void printMenu()
{
	system("CLS");
	cout << "Number of employees: " << employees.size() << endl;
	cout << "Choose option:" << endl;
	cout << "1. Hire new employee" << endl;
	cout << "2. Fire an employee" << endl;
	cout << "3. Calculate paychecks" << endl;
	cout << "4. Save progress" << endl;
	cout << "X. End" << endl;
}

void menuSwitch(char choice)
{
	switch (choice)
	{
	case '1':
	{
		pushEmployee();
		break;
	}
	case '2':
	{
		eraseEmployee();
		break;
	}
	case '3':
		calculate_paychecks();
		break;
	case '4':
		saveProgressToCSV(employees);
		break;
	default:
		break;
	}
}

void pushEmployee()
{
	auto row = colectNewEmployeeData();
	CEmployee employee(row);
	employees.push_back(employee);
}

void eraseEmployee()
{
	string idToBeFound;
	cout << "Enter Id of employee who is to be fired: ";
	getline(cin, idToBeFound);
	for (auto listIterator = begin(employees); listIterator != end(employees); listIterator++)
	{
		if (!listIterator->getIdNumber().compare(idToBeFound))
		{
			employees.erase(listIterator);
			break;
		}
	}
}

void calculate_paychecks()
{
	for (auto&& employee : employees)
	{
		employee.calculatePaycheck();
	}
}

vector<string> colectNewEmployeeData()
{
	vector<string> row;
	cout << "Enter full name of new employee: ";
	addArgumentToRow(row);
	cout << "Enter current work time: ";
	addArgumentToRow(row);
	cout << "Enter hourly salary: ";
	addArgumentToRow(row);
	cout << "Enter Id: ";
	addArgumentToRow(row);
	return row;
}

void addArgumentToRow(vector<string>& row)
{
	string line;
	getline(cin, line);
	row.push_back(line);
}
