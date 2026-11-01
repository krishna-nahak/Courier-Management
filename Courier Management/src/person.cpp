//
//  person.cpp
//  Courier Managementt
//
//  Created by Krishna Nahak on 30/10/26.
//

#include "../include/person.h"
#include <iostream>

using namespace std;

Person::Person() : name(""), phone(""), address("") {}

Person::Person(string n, string p, string a) : name(n), phone(p), address(a) {}

void Person::display() {
    cout << "Name    : " << name << endl;
    cout << "Phone   : " << phone << endl;
    cout << "Address : " << address << endl;
}

string Person::getName() {
    return name;
}

string Person::getPhone() {
    return phone;
}
