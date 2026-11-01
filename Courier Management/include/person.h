//
//  person.h
//  Courier Managementt
//
//  Created by Krishna Nahak on 30/10/26.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    string phone;
    string address;

public:
    Person();
    Person(string n, string p, string a);
    virtual void display();
    string getName();
    string getPhone();
};

#endif
