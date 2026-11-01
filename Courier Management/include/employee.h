//
//  employee.h
//  Courier Managementt
//
//  Created by Krishna Nahak on 30/10/26.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"
#include <string>
#include <vector>

using namespace std;

class Employee : public Person {
private:
    int employeeId;
    string designation;

public:
    Employee();
    Employee(int empId, string n, string p, string a, string d);
    void display() override;
    int getId();
};

class EmployeeManager {
    vector<Employee> employees;

public:
    bool verifyEmployeeLogin(int id, string phone);
    void saveEmployees();
    void searchEmployee();
    void displayEmployees();
    void addEmployee();
};

#endif
