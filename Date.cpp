#include "Date.h"

/**
 * Creates a date object.
 * @param dateString The string date with format MM/DD/YYYY
 */
Date::Date(string dateString) {
    parse(dateString);
}

 /**
  * Parses a string date with format MM/DD/YYYY, into an object date
  * @param dateString
  */
void Date::parse(string dateString) {

    int delimiterCount = 0;
    string day, month, year;

    // 1.Iterates over the string
    for(char c : dateString) {
        // 1.1.If the delimiter is found, skips the current iteration.
        if(c == DATE_DELIMITER) {
            delimiterCount++;
            continue;
        }
        // 1.2.Before the first delimiter is found, the month is captured
        if(delimiterCount == 0) month+=c;
        // 1.3.Before the second delimiter is found, the day is captured
        else if (delimiterCount == 1) day+=c;
        // 1.4.Year is captured
        else year+=c;
    }

    date = {};
    date.tm_year = stoi(year)-1900;
    date.tm_mon  = stoi(month)-1;
    date.tm_mday = stoi(day);
    mktime(&date);
}

/**
 * Add days to the current date.
 * @param days The days to add
 */
void Date::addDays(int days) {
    date.tm_mday += days;
};

/**
 * Returns a string date with format MM/DD/YYYY.
 * @return A string date with format MM/DD/YYYY
 */
string Date::getDateString() const {

    return to_string(date.tm_mon+1) +
           DATE_DELIMITER +
           to_string(date.tm_mday) +
           DATE_DELIMITER +
           to_string(date.tm_year+1900);
}

/**
 * Checks and returns whether dateA is bigger than dateB or not.
 * @param dateA
 * @param dateB
 * @return Whether dateA is bigger than dateB or not
 */
bool operator> (Date& dateA, Date& dateB) {

    time_t secondsA = mktime(&dateA.date);
    time_t secondsB = mktime(&dateB.date);

    return (secondsA > secondsB);
}

/**
 * Checks and returns whether dateA is smaller than dateB or not.
 * @param dateA
 * @param dateB
 * @return Whether dateA is smaller than dateB or not
 */
bool operator< (Date& dateA, Date& dateB) {

    time_t secondsA = mktime(&dateA.date);
    time_t secondsB = mktime(&dateB.date);

    return (secondsA < secondsB);
}