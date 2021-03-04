#pragma once
#include "commonHeader.h"
#include "CEmployee.h"

list<CEmployee> readEmployeesCSV(string fileName);
vector<string> splitByCommas(stringstream& lineStream);
vector<vector<string>> readlines(fstream& fin);
list<CEmployee> turnRowsToEmployees(vector<vector<string>> rows);
void saveProgressToCSV(list<CEmployee> employees);
