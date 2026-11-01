//
//  utilities.cpp
//  Courier Managementt
//
//  Created by Krishna Nahak on 30/10/26.
//

#include <iostream>
#include "../include/customer.h"
#include "../include/courier.h"
#include "../include/employee.h"

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[H";
    cout.flush();
}

void line() {
    cout << "============================================================\n";
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void saveAllData() {
    
    CustomerManager customerManager;
    EmployeeManager employeeManager;
    CourierManager courierManager;
    
    customerManager.saveCustomers();
    employeeManager.saveEmployees();
    courierManager.saveCouriers();
}
