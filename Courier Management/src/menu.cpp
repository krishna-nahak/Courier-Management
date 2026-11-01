//
//  menu.cpp
//  Courier Managementt
//
//  Created by Krishna Nahak on 31/10/26.
//

#include "../include/menu.h"
#include "../include/courier.h"
#include "../include/customer.h"
#include "../include/employee.h"
#include "../utilities/utilities.h"
#include <iomanip>
#include <iostream>

using namespace std;

void MenuManager::adminMenu() {
    string username, password;

    cout << "\n------------- ADMIN LOGIN -------------\n";
    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;
    cin.ignore();

    if (username != "admin" || password != "admin123") {
        cout << "Invalid login.\n";
        return;
    }

    int choice;

    do {
        cout << "\n================ ADMIN MENU ================\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Display Customers\n";
        cout << "5. Display Couriers\n";
        cout << "6. Search Courier\n";
        cout << "7. Update Courier Status\n";
        cout << "8. Sort Couriers\n";
        cout << "9. Courier Report\n";
        cout << "10. Logout\n";
        cout << "Enter Choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                employeeManager.addEmployee();
                break;

            case 2:
                employeeManager.displayEmployees();
                break;

            case 3:
                employeeManager.searchEmployee();
                break;

            case 4:
                customerManager.displayCustomers();
                break;

            case 5:
                courierManager.displayCouriers();
                break;

            case 6:
                courierManager.searchCourier();
                break;

            case 7:
                courierManager.updateStatus();
                break;

            case 8:
                courierManager.sortCouriers();
                break;

            case 9:
                courierManager.report();
                break;

            case 10:
                cout << "Admin logged out.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 10);
}

void MenuManager::employeeMenu() {
    int id;
    string phone;

    cout << "\n========== EMPLOYEE LOGIN ==========";
    cout << "Employee ID: ";
    cin >> id;

    cout << "Phone Number: ";
    cin >> phone;

    if (!employeeManager.verifyEmployeeLogin(id, phone)) {
        cout << "Invalid Employee ID or Phone Number.\n";
        return;
    }

    cout << "\nLogin successful.\n";

    int choice;

    do {
        cout << "\n========== EMPLOYEE DASHBOARD ==========";
        cout << "1. Display All Couriers\n";
        cout << "2. Search Courier\n";
        cout << "3. Track Courier\n";
        cout << "4. Update Courier Status\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                courierManager.displayCouriers();
                clearScreen();
                break;

            case 2:
                courierManager.searchCourier();
                break;

            case 3:
                courierManager.trackCourier();
                break;

            case 4:
                courierManager.updateStatus();
                break;

            case 5:
                cout << "Employee logged out.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);
}

void MenuManager::mainMenu() {
    int choice;

    do {
        cout << "\n";
        line();
        cout << "             COURIER MANAGEMENT SYSTEM\n";
        line();

        cout << "1. Track a Courier\n";
        cout << "2. Register as a Customer\n";
        cout << "3. Customer Login\n";
        cout << "4. Employee Login\n";
        cout << "5. Admin Login\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(10000, '\n');

        switch (choice) {
            case 1:
                clearScreen();
                courierManager.trackCourier();
                break;

            case 2:
                clearScreen();
                customerManager.addCustomer();
                saveAllData();
                break;

            case 3:
                clearScreen();
                customerMenu();
                break;

            case 4:
                clearScreen();
                employeeMenu();
                break;

            case 5:
                clearScreen();
                adminMenu();
                break;

            case 6:
                clearScreen();
                saveAllData();
                cout << "Thank you for using our service.\n";
                break;

            default:
                cout << "Invalid choice. Please select 1 to 6.\n";
        }
    } while (choice != 6);
}

void MenuManager::customerMenu() {
    int id;
    string phone;

    cout << "\n========== CUSTOMER LOGIN ==========\n";
    cout << "Customer ID: ";
    cin >> id;

    cout << "Phone Number: ";
    cin >> phone;

    if (!customerManager.verifyCustomerLogin(id, phone)) {
        cout << "Invalid Customer ID or Phone Number.\n";
        return;
    }

    cout << "\nLogin successful.\n";

    int choice;

    do {
        cout << "\n========== CUSTOMER DASHBOARD ==========\n";
        cout << "1. Register Courier\n";
        cout << "2. Track Courier\n";
        cout << "3. Search Courier\n";
        cout << "4. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                courierManager.addCourier();
                break;

            case 2:
                courierManager.trackCourier();
                break;

            case 3:
                courierManager.searchCourier();
                break;

            case 4:
                cout << "Customer logged out.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);
}
