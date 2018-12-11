#include "Customer.h"

/**
 * Creates a customer.
 * @param customerId The customer identification
 * @param numOfRequestedBeds The number of beds requested by customer
 * @param checkIn The customer's check-in date
 * @param checkOut The customer's check-out date
 */
Customer::Customer(string customerId, int numOfRequestedBeds, string checkIn, string checkOut) {
    this->customerId = customerId;
    this->numOfRequestedBeds = numOfRequestedBeds;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
}