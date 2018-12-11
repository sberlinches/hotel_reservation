#include "Room.h"

/**
 * Creates a room.
 * @param roomId The room identification
 * @param numberOfBeds The number of beds in the room
 */
Room::Room(string roomId, int numberOfBeds) {
    this->roomId = roomId;
    this->numberOfBeds = numberOfBeds;
    this->customers = new Queue<Customer*>();
}
