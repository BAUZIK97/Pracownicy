#pragma once
#include "commonHeader.h"
#include "CEmployee.h"
#include "manageCSV.h"

extern list<CEmployee> employees;

void menu(); 
void printMenu();
void menuSwitch(char choice);
void pushEmployee();
void eraseEmployee();
void calculate_paychecks();
void addArgumentToRow(vector<string>& row);
