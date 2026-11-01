//
//  customer.h
//  Courier Managementt
//
//  Created by Krishna Nahak on 30/10/26.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"
#include <string>
#include <vector>

using namespace std;

class Customer : public Person {
private:
    int customerId;
    string email;

public:
    Customer();
    Customer(int id, string n, string p, string a, string e);

    void display() override;
    int getId();
    string getEmail();
};

class CustomerManager {
    vector<Customer> customers;

public:
    bool verifyCustomerLogin(int id, string phone);
    void displayCustomers();
    void searchCustomer();
    void addCustomer();
    void saveCustomers();
};

#endif
