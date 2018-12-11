#ifndef HOTEL_H
#define HOTEL_H

#include "Queue.h"
#include "Customer.h"
#include "Room.h"

/**
 *
 */
class NodeHotel {
private:
    int numOfBeds;
    Queue<Room*>* groupByNumOfBeds;
    NodeHotel* next;
public:
    NodeHotel();
    void enqueueCheckOutPriority(Customer*);
    friend class Hotel;
};

/**
 * Hotel Class
 */
class Hotel {
private:
    NodeHotel* rooms;
    void parseRooms(int[], int);
    void assignRoom(NodeHotel*, Customer*, bool);
    void assignRoom(NodeHotel*, Customer*);
    bool isAvailable(Room*, Customer*);
public:
    Hotel(int[], int);
    void print();
    void reserveRoom(Customer*);
    static long count;
};


#endif
