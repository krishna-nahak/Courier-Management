//
//  courier.h
//  Courier Managementt
//
//  Created by Krishna Nahak on 31/10/26.
//


#ifndef COURIER_H
#define COURIER_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Courier {
private:
    int courierId;
    string sender;
    string receiver;
    string source;
    string destination;
    double weight;
    string type;
    double charges;
    string status;

public:
    Courier();
    Courier(int id, string s, string r, string src, string dest, double w, string t, double c, string st);

    double calculateCharge(double w);
    double calculateCharge(double w, string t);

    void display();
    void tracking();
    int getId();

    string getSender();
    string getReceiver();
    string getDestination();
    string getStatus();

    double getCharges();
    void setStatus(string s);
    void save(ofstream& file);
};

class CourierManager {
    vector<Courier> couriers;

public:
    int getNextCourierId();
    double calculateCharge(double w);
    double calculateCharge(double w, string t);
    void addCourier();
    void trackCourier();
    void searchCourier();
    void displayCouriers();
    void updateStatus();
    void sortCouriers();
    void saveCouriers();
    void report();
};

#endif
