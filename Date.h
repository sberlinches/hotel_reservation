#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>

using namespace std;

const char DATE_DELIMITER = '/';

class Date {
private:
    struct tm date;
    void parse(string);
public:
    Date(string);
    void addDays(int);
    string getDateString() const;
    friend bool operator> (Date& dateA, Date& dateB);
    friend bool operator< (Date& dateA, Date& dateB);
};

#endif
