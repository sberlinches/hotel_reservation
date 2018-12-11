#include <iostream>
#include <fstream>

#include "Date.h"
#include "Hotel.h"
#include "Customer.h"

void parseAndReserve(string, Hotel*);

/**
 * A2 Hotel reservation
 * Sergio Berlinches
 * 100291288
 * 06/11/18
 *
 * You are asked to write an application for hotel management that assigns roomList
 * automatically to customers. This application will be used in many different
 * hotels with different setting such as number of roomList, number of beds in each
 * room, etc.
 * At this assignment we are interested in hotel reservation process as part of
 * whole application. Consider you have information such as number of roomList,
 * number of beds in each room, and a list of customers requesting roomList.
 * Customers ask for roomList with different number of beds.
 *
 * @return
 */
int main() {

    string line;
    ifstream inputFileStream;
    inputFileStream.open("test.txt");

    if (!inputFileStream) {
        cout << "Unable to open file";
        exit(1);
    }

    /*
     * A. Consider a given hotel has 100 roomList with only one bed, 50 roomList with
     * 2 beds and 30 roomList with 3 beds. Develop above classes and new classes if
     * you need to program hotel reservation task as explained in the following
     * parts.
     */
    int size = 3;
    int rooms[size] = {
        100, //1 bed room
        50, //2 beds room
        30, //3 beds room
    };
    Hotel* hotel = new Hotel(rooms, size);
    //hotel->print();

    /*
     * B. Write a main program that given number of customers and a single
     * hotel, slots as many customers into the hotel according to the following
     * conditions:
     * - Assign roomList to the customer based on their requested number of beds.
     * - If room with requested number of beds is not available, but a room with
     * more beds is available, then assign the available room with the lowest
     * beds to the customer. For example, if customer requested a room with one
     * bed, but only roomList with two and three beds are available, then assign
     * the room with two beds to the customer. Notes: you cannot change the
     * assigned room later.
     * - If a customer is not placed into a room, notify it by printing out the
     * name and the first time that there is an available room. However, your
     * program is only responsible to allocate room to the customer right now if
     * it is available; otherwise, no more action should be taken except
     * notifying the customer.
     */
    while(getline(inputFileStream, line))
        parseAndReserve(line, hotel);

    inputFileStream.close();
    //hotel->print();

    cout << "---------------------------------------------------------" << endl;
    cout << "Number of comparisons: " << hotel->count << endl;
    cout << "---------------------------------------------------------" << endl;

    return 0;
}

/**
 *
 * @param line
 * @param hotel
 */
void parseAndReserve(string line, Hotel* hotel) {

    const char DELIMITER = ',';
    const char WHITESPACE = ' ';
    string customerId, checkIn, checkOut, numberOfBeds, durationOfStay;
    int delimiterFound = 0;

    for(char c : line) {

        if(c == DELIMITER) {
            delimiterFound++;
            continue; //Jumps the current iteration
        }
        if(c == WHITESPACE) continue;

        if(delimiterFound == 0) checkIn += c;
        else if (delimiterFound == 1) customerId += c;
        else if (delimiterFound == 2) numberOfBeds += c;
        else durationOfStay += c;
    }

    Date test(checkIn);
    test.addDays(stoi(durationOfStay));
    checkOut = test.getDateString();

    hotel->reserveRoom(new Customer(customerId, stoi(numberOfBeds), checkIn, checkOut));
}

