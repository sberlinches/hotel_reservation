#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
//#include "Room.h"

using namespace std;

class Customer {
private:
    string customerId;
    int numOfRequestedBeds;
    string checkIn;
    string checkOut;
    //Room* room; // the assigned room
public:
    Customer();
    Customer(string, int, string, string);
    friend class Hotel;
    //friend class Room;
};


#endif
