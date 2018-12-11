#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "Queue.h"
#include "Customer.h"

using namespace std;

/**
 * Room class
 */
class Room {
private:
    string roomId;
    int numberOfBeds;
    Queue<Customer*>* customers;
public:
    Room(string, int);
    friend class NodeHotel;
    friend class Hotel;
};


#endif
