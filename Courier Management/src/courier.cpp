//
//  courier.cpp
//  Courier Managementt
//
//  Created by Krishna Nahak on 31/10/26.
//

#include "../include/courier.h"
#include "../utilities/utilities.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Courier::Courier() : courierId(0), sender(""), receiver(""), source(""), destination(""), weight(0), type(""), charges(0), status("") {}

Courier::Courier(int id, string s, string r, string src, string dest, double w, string t, double c, string st)
    : courierId(id), sender(s), receiver(r), source(src), destination(dest), weight(w), type(t), charges(c), status(st) {}

void Courier::display() {
    cout << left << setw(10) << courierId
         << setw(18) << sender
         << setw(18) << receiver
         << setw(18) << destination
         << setw(10) << weight
         << setw(13) << type
         << setw(12) << charges
         << setw(18) << status
         << endl;
}

void Courier::tracking() {
    cout << "\n------------- COURIER DETAILS -------------\n";
    cout << "Courier ID  : " << courierId << endl;
    cout << "Sender      : " << sender << endl;
    cout << "Receiver    : " << receiver << endl;
    cout << "Source      : " << source << endl;
    cout << "Destination : " << destination << endl;
    cout << "Weight      : " << weight << " KG" << endl;
    cout << "Type        : " << type << endl;
    cout << "Charges     : Rs. " << charges << endl;
    cout << "Status      : " << status << endl;
    cout << "--------------------------------------------\n";
}

int Courier::getId() {
    return courierId;
}

string Courier::getSender() {
    return sender;
}

string Courier::getReceiver() {
    return receiver;
}

string Courier::getDestination() {
    return destination;
}

string Courier::getStatus() {
    return status;
}

double Courier::getCharges() {
    return charges;
}

void Courier::setStatus(string s) {
    status = s;
}

void Courier::save(ofstream& file) {
    file << courierId << "|"
         << sender << "|"
         << receiver << "|"
         << source << "|"
         << destination << "|"
         << weight << "|"
         << type << "|"
         << charges << "|"
         << status << endl;
}

int CourierManager::getNextCourierId() {
    if (couriers.empty())
        return 1001;
    return couriers.back().getId() + 1;
}

double CourierManager::calculateCharge(double w) {
    return 50 + (w * 30);
}

double CourierManager::calculateCharge(double w, string t) {
    double amount = 50 + (w * 30);
    if (t == "Express")
        amount += 50;
    else if (t == "Same Day")
        amount += 100;
    return amount;
}

void CourierManager::addCourier() {
    int id = getNextCourierId();
    string sender, receiver, source, destination, type;
    double weight;

    cout << "\n------------- REGISTER COURIER -------------\n";
    cout << "Sender Name       : ";
    getline(cin, sender);

    cout << "Receiver Name     : ";
    getline(cin, receiver);

    cout << "Source            : ";
    getline(cin, source);

    cout << "Destination       : ";
    getline(cin, destination);

    cout << "Weight (KG)       : ";
    cin >> weight;

    cin.ignore();
    cout << "\nCourier Type\n";
    cout << "1. Normal\n";
    cout << "2. Express\n";
    cout << "3. Same Day\n";

    int choice;
    cout << "Enter Choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 2)
        type = "Express";
    else if (choice == 3)
        type = "Same Day";
    else
        type = "Normal";

    double charges = calculateCharge(weight, type);
    Courier c(id, sender, receiver, source, destination, weight, type, charges, "Booked");

    couriers.push_back(c);
    cout << "\nCourier registered successfully.\n";
    cout << "Courier ID : " << id << endl;
    cout << "Charges    : Rs. " << charges << endl;
}

void CourierManager::trackCourier() {
    int id;
    cout << "\nEnter Courier ID: ";
    cin >> id;
    cin.ignore();
    for (Courier c : couriers) {
        if (c.getId() == id) {
            c.tracking();
            return;
        }
    }
    cout << "Courier not found.\n";
}

void CourierManager::searchCourier() {
    int choice;
    cout << "\n------------- SEARCH COURIER -------------\n";
    cout << "1. Search by Courier ID\n";
    cout << "2. Search by Sender\n";
    cout << "3. Search by Receiver\n";
    cout << "4. Search by Destination\n";
    cout << "5. Search by Status\n";
    cout << "Enter Choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        int id;
        cout << "Courier ID: ";
        cin >> id;
        cin.ignore();
        for (Courier c : couriers) {
            if (c.getId() == id) {
                c.tracking();
                return;
            }
        }
    } else if (choice == 2) {
        string name;
        cout << "Sender Name: ";
        getline(cin, name);
        for (Courier c : couriers) {
            if (c.getSender() == name)
                c.tracking();
        }
    } else if (choice == 3) {
        string name;
        cout << "Receiver Name: ";
        getline(cin, name);
        for (Courier c : couriers) {
            if (c.getReceiver() == name)
                c.tracking();
        }
    } else if (choice == 4) {
        string destination;
        cout << "Destination: ";
        getline(cin, destination);
        for (Courier c : couriers) {
            if (c.getDestination() == destination)
                c.tracking();
        }
    } else if (choice == 5) {
        string status;
        cout << "Status: ";
        getline(cin, status);
        for (Courier c : couriers) {
            if (c.getStatus() == status)
                c.tracking();
        }
    } else {
        cout << "Invalid choice.\n";
    }
}

void CourierManager::displayCouriers() {
    cout << "\n---------------- ALL COURIERS ----------------\n";
    if (couriers.empty()) {
        cout << "No courier records found.\n";
        return;
    }

    cout << left << setw(10) << "ID"
         << setw(18) << "Sender"
         << setw(18) << "Receiver"
         << setw(18) << "Destination"
         << setw(10) << "Weight"
         << setw(13) << "Type"
         << setw(12) << "Charges"
         << setw(18) << "Status"
         << endl;
    line();

    for (Courier c : couriers)
        c.display();
}

void CourierManager::updateStatus() {
    int id;
    cout << "\nEnter Courier ID: ";
    cin >> id;
    cin.ignore();
    for (Courier& c : couriers) {
        if (c.getId() == id) {
            int choice;
            cout << "\n1. Booked\n";
            cout << "2. Picked Up\n";
            cout << "3. In Transit\n";
            cout << "4. At Local Hub\n";
            cout << "5. Out for Delivery\n";
            cout << "6. Delivered\n";
            cout << "7. Cancelled\n";
            cout << "Select Status: ";
            cin >> choice;
            cin.ignore();
            string status;
            if (choice == 1) status = "Booked";
            else if (choice == 2) status = "Picked Up";
            else if (choice == 3) status = "In Transit";
            else if (choice == 4) status = "At Local Hub";
            else if (choice == 5) status = "Out for Delivery";
            else if (choice == 6) status = "Delivered";
            else if (choice == 7) status = "Cancelled";
            else {
                cout << "Invalid status.\n";
                return;
            }
            c.setStatus(status);
            cout << "Status updated successfully.\n";
            return;
        }
    }
    cout << "Courier not found.\n";
}

void CourierManager::sortCouriers() {
    if (couriers.empty()) {
        cout << "No couriers available.\n";
        return;
    }

    for (int i = 0; i < (int)couriers.size() - 1; i++) {
        for (int j = 0; j < (int)couriers.size() - i - 1; j++) {
            if (couriers[j].getCharges() > couriers[j + 1].getCharges())
                swap(couriers[j], couriers[j + 1]);
        }
    }

    cout << "\nCouriers sorted by charges.\n";
    displayCouriers();
}

void CourierManager::saveCouriers() {
    ofstream file("/data/couriers.txt");
    for (Courier c : couriers)
        c.save(file);
    file.close();
}

void CourierManager::report() {
    int delivered = 0;
    int cancelled = 0;
    double revenue = 0;
    for (Courier c : couriers) {
        if (c.getStatus() == "Delivered")
            delivered++;
        if (c.getStatus() == "Cancelled")
            cancelled++;
        if (c.getStatus() != "Cancelled")
            revenue += c.getCharges();
    }

    int pending = (int)couriers.size() - delivered - cancelled;
    cout << "\n------------- COURIER REPORT -------------\n";
    cout << "Total Couriers     : " << couriers.size() << endl;
    cout << "Delivered          : " << delivered << endl;
    cout << "Pending            : " << pending << endl;
    cout << "Cancelled          : " << cancelled << endl;
    cout << "Total Revenue      : Rs. " << revenue << endl;
}
