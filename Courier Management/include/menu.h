//
//  menu.h
//  Courier Managementt
//
//  Created by Krishna Nahak on 31/10/26.
//

#ifndef MENU_H
#define MENU_H

#include "courier.h"
#include "customer.h"
#include "employee.h"

class MenuManager {
private:
    EmployeeManager employeeManager;
    CustomerManager customerManager;
    CourierManager courierManager;

public:
    void adminMenu();
    void employeeMenu();
    void mainMenu();
    void customerMenu();
};

#endif
