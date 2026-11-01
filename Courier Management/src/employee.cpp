//
//  employee.cpp
//  Courier Managementt
//
//  Created by Krishna Nahak on 30/10/26.
//

#include "../include/employee.h"
#include "../utilities/utilities.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

Employee::Employee() : Person(), employeeId(0), designation("") {}

Employee::Employee(int id, string n, string p, string a, string d) : Person(n, p, a), employeeId(id), designation(d) {}

void Employee::display() {
    cout << left << setw(10) << employeeId
         << setw(20) << name
         << setw(15) << phone
         << setw(20) << designation
         << endl;
}

int Employee::getId() {
    return employeeId;
}

bool EmployeeManager::verifyEmployeeLogin(int id, string phone) {
    for (Employee e : employees) {
        if (e.getId() == id && e.getPhone() == phone) {
            return true;
        }
    }

    return false;
}

void EmployeeManager::addEmployee() {
    int id = (int)employees.size() + 1;
    string name, phone, address, designation;
    cout << "\n------------- ADD EMPLOYEE -------------\n";
    cout << "Enter Name        : ";
    getline(cin, name);
    cout << "Enter Phone       : ";
    getline(cin, phone);
    cout << "Enter Address     : ";
    getline(cin, address);
    cout << "Enter Designation : ";
    getline(cin, designation);
    employees.push_back(Employee(id, name, phone, address, designation));
    cout << "\nEmployee added successfully.\n";
    cout << "Employee ID: " << id << endl;
}

void EmployeeManager::saveEmployees() {
    ofstream file("/data/employees.txt");
    for (Employee e : employees) {
        file << e.getId() << "|"
             << e.getName() << "|"
             << e.getPhone() << endl;
    }
    file.close();
}

void EmployeeManager::searchEmployee() {
    int id;
    cout << "\nEnter Employee ID: ";
    cin >> id;
    cin.ignore();
    for (Employee e : employees) {
        if (e.getId() == id) {
            cout << "\nEmployee Found\n";
            e.display();
            return;
        }
    }
    cout << "Employee not found.\n";
}

void EmployeeManager::displayEmployees() {
    cout << "\n---------------- EMPLOYEES ----------------\n";
    if (employees.empty()) {
        cout << "No employees found.\n";
        return;
    }
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Phone"
         << setw(20) << "Designation" << endl;
    line();
    for (Employee e : employees)
        e.display();
}
