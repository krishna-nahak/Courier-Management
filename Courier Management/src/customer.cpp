//
//  customer.cpp
//  Courier Managementt
//
//  Created by Krishna Nahak on 30/10/26.
//

#include "../include/customer.h"
#include "../utilities/utilities.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Customer::Customer() : Person(), customerId(0), email("") {}

Customer::Customer(int id, string n, string p, string a, string e) : Person(n, p, a), customerId(id), email(e) {}

void Customer::display() {
    cout << left << setw(10) << customerId
         << setw(20) << name
         << setw(15) << phone
         << setw(25) << email
         << endl;
}

int Customer::getId() {
    return customerId;
}

string Customer::getEmail() {
    return email;
}

bool CustomerManager::verifyCustomerLogin(int id, string phone) {
    for (Customer c : customers) {
        if (c.getId() == id && c.getPhone() == phone) {
            return true;
        }
    }

    return false;
}

void CustomerManager::displayCustomers() {
    cout << "\n---------------- CUSTOMERS ----------------\n";
    if (customers.empty()) {
        cout << "No customers found.\n";
        return;
    }
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Phone"
         << setw(25) << "Email" << endl;
    line();
    for (Customer c : customers)
        c.display();
}

void CustomerManager::searchCustomer() {
    int id;
    cout << "\nEnter Customer ID: ";
    cin >> id;
    cin.ignore();
    for (Customer c : customers) {
        if (c.getId() == id) {
            cout << "\nCustomer Found\n";
            c.display();
            return;
        }
    }
    cout << "Customer not found.\n";
}

void CustomerManager::addCustomer() {
    int id = (int)customers.size() + 1;
    string name, phone, address, email;
    cout << "\n------------- ADD CUSTOMER -------------\n";
    cout << "Enter Name    : ";
    getline(cin, name);
    cout << "Enter Phone   : ";
    getline(cin, phone);
    cout << "Enter Address : ";
    getline(cin, address);
    cout << "Enter Email   : ";
    getline(cin, email);
    customers.push_back(Customer(id, name, phone, address, email));
    cout << "\nCustomer added successfully.\n";
    cout << "Customer ID: " << id << endl;
}

void CustomerManager::saveCustomers() {
    ofstream file("/data/customers.txt");
    for (Customer c : customers) {
        file << c.getId() << "|"
             << c.getName() << "|"
             << c.getPhone() << "|"
             << c.getEmail() << endl;
    }
    file.close();
}
