#include "manageCSV.h"
#include "CEmployee.h"

list<CEmployee> readEmployeesCSV(string fileName)
{
	list<CEmployee> csvemployees;
	fstream fin;
	fin.open(fileName, ios::in);
	auto rows = readlines(fin);
	fin.close();
	csvemployees = turnRowsToEmployees(rows);
	return csvemployees;
}

vector<vector<string>> readlines(fstream& fin)
{
	vector<vector<string>> rows;
	vector<string> row;
	string line;
	while (getline(fin, line))
	{
		row.clear();
		stringstream lineStream(line);
		rows.push_back(splitByCommas(lineStream));
	}
	rows.erase(rows.begin());
	return rows;
}
list<CEmployee> turnRowsToEmployees(vector<vector<string>> rows)
{
	list<CEmployee> employees;
	for (auto row : rows)
	{
		CEmployee employee(row);
		employees.push_back(employee);
	}
	return employees;
}
void saveProgressToCSV(list<CEmployee> employees)
{
	ofstream fout;
	fout.open("out.csv", ios::out);
	fout << "Full Name,Work Time,Hourly Salary,Id" << endl;
	for (auto employee : employees)
	{
		fout << employee.getFullName() << ',' << employee.getHourlySalary() << ',';
		fout << employee.getWorkTime() << ',' << employee.getIdNumber() << ',';
		fout << employee.getPaycheck() << endl;
	}
	fout.close();
}
vector<string> splitByCommas(stringstream& lineStream)
{
	vector<string> row;
	string word;
	while (getline(lineStream, word, ','))
		row.push_back(word);
	return row;
}