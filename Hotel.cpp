#include "Hotel.h"
#include "Date.h"

long Hotel::count = 0;

/**
 * Creates a NodeHotel
 */
NodeHotel::NodeHotel() {
    this->numOfBeds = 0;
    this->groupByNumOfBeds = nullptr;
    this->next = nullptr;
}

/**
 * Creates an Hotel.
 * @param rooms The list of rooms
 * @param size The size of the list
 */
Hotel::Hotel(int rooms[], int size) {
    this->rooms = nullptr;
    parseRooms(rooms, size);
};

/**
 * Prints the hotel room list.
 */
void Hotel::print() {

    NodeHotel* head = rooms;

    cout << "---------------------------------------------------------" << endl;
    while (head) {
        cout << head->numOfBeds << " bed rooms: ";
        for (int i = 0; i < head->groupByNumOfBeds->getSize(); ++i) {
            cout << head->groupByNumOfBeds->front()->roomId
                 << "("
                 << head->groupByNumOfBeds->front()->customers->getSize()
                 << "),";
            head->groupByNumOfBeds->moveForward();
        }
        cout << endl << endl;
        head = head->next;
    }
    cout << "---------------------------------------------------------" << endl;
}

/**
 * Parses the list of rooms into a list of queues.
 * @param rooms The list of rooms
 * @param size The size of the list
 */
void Hotel::parseRooms(int rooms[], int size) {

    NodeHotel* head = nullptr;
    Queue<Room*>* groupByNumOfBeds;

    for (int i = 0; i < size; ++i) {

        groupByNumOfBeds = new Queue<Room*>();

        for (int j = 1; j <= rooms[i]; ++j)
            groupByNumOfBeds->enqueue(new Room(
                    to_string(i+1) + to_string(j),
                    i+1
            ));

        if(head == nullptr) {
            head = new NodeHotel();
            this->rooms = head; //roomList keeps the pointer to the head
        }

        head->numOfBeds = i+1;
        head->groupByNumOfBeds = groupByNumOfBeds;
        head->next = (i == size-1)? nullptr: new NodeHotel();
        head = head->next;
    }
}

/**
 *
 * @param customer
 */
void Hotel::reserveRoom(Customer* customer) {
    NodeHotel* head = rooms;
    /*cout <<  "Customer "
         << customer->customerId
         << ": "
         << customer->numOfRequestedBeds
         << " beds ("
         << customer->checkIn
         << "-"
         << customer->checkOut
         << ")"
         << endl;*/
    assignRoom(head, customer, false);
}

/**
 * Checks all the rooms from the same group (same number of beds), if there's a
 * room available is assigned to the customer, otherwise the customer is
 * upgraded to a room with more beds.
 *
 * @param rooms The rooms of each group
 * @param customer The customer object
 * @param roomUpgrade If the customer has got a room upgrade due availability
 * issues or not
 */
void Hotel::assignRoom(NodeHotel* rooms, Customer* customer, bool roomUpgrade) {

    if(!rooms)
        cout << customer->customerId << " no rooms available at that period." << endl;

    while (rooms) {
        // 1.Skips the group with no rooms assigned (4 beds room, 0 rooms)
        if(rooms->groupByNumOfBeds->isEmpty())
            break;
        // 2.If this is the number of beds requested OR an is a room upgrade
        if(rooms->numOfBeds == customer->numOfRequestedBeds || roomUpgrade) {
            assignRoom(rooms, customer);
            break;
        }
        rooms = rooms->next;
    }
}

/**
 * Checks all the rooms from the same group (same number of beds), if there's a
 * room available is assigned to the customer, otherwise the customer is
 * upgraded to a room with more beds.
 *
 * @param rooms The rooms of each group
 * @param customer The customer object
 */
void Hotel::assignRoom(NodeHotel *rooms, Customer *customer) {

    // 1.Iterate over the rooms of the same group (same number of beds)
    for (int i = 1; i <= rooms->groupByNumOfBeds->getSize(); ++i) {

        // 1.1.If there's a room available, the customer gets the room
        if(isAvailable(rooms->groupByNumOfBeds->front(), customer)) {
            rooms->groupByNumOfBeds->front()->customers->enqueue(customer);
            /*cout << "- Room "
                 << rooms->groupByNumOfBeds->front()->roomId
                 << " reserved."
                 << endl;*/
            // Once the user got the reservation, ends the loop
            break;
        }

        // 1.2.If there's no rooms available of the requested group, the
        // customer gets upgraded
        else if(i == rooms->groupByNumOfBeds->getSize()) {
            /*cout << "- No "
                 << rooms->groupByNumOfBeds->front()->numberOfBeds
                 << " beds room available. Customer gets an upgrade."
                 << endl;*/
            assignRoom(rooms->next, customer, true);
            break;
        }

        rooms->groupByNumOfBeds->moveForward();
    }
}

/**
 * Checks and returns whether the room is available or not.
 * Checks the check-in with the first expected check-out.
 * E.g.:
 * Room check-out 6/17/2018
 * Customer check-in 6/18/2018
 * The customer can reserve
 *
 * Room check-out 6/17/2018
 * Customer check-in 6/17/2018
 * The customer cannot reserve
 *
 * @param room The room to check the availability
 * @param customer The customer
 * @return Whether the room is available or not.
 */
bool Hotel::isAvailable(Room* room, Customer* customer) {

    // 1.If the room doesn't have any reservation
    if(room->customers->isEmpty())
        return true;
    // 2.If the room has previous reservations
    else {
        Date customerCheckIn(customer->checkIn);
        Date customerCheckOut(customer->checkOut);

        for (int i = 0; i < room->customers->getSize(); ++i) {

            // Count the number of comparisons
            this->count++;

            /*cout << "reservations: "
                 << room->customers->front()->checkIn
                 << " - "
                 << room->customers->front()->checkOut
                 << endl;*/

            Date roomCheckOut(room->customers->front()->checkOut);
            Date roomCheckIn(room->customers->front()->checkIn);

            if(customerCheckIn > roomCheckOut || customerCheckOut < roomCheckIn)
                return true;

            room->customers->moveForward();
        }

        return false;
    }
};