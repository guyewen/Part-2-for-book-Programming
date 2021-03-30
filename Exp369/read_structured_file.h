#ifndef READ_STRUCTURED_FILE_H
#define READ_STRUCTURED_FILE_H
#include "std_lib_facilities.h"

//---------------------------------------------------------------------------------------------------------
// Declear all the structs

const int not_a_reading = -777;
const int not_a_month = -1;

// Structure for Day, a vector with 24 elements saving temperatures
struct Day {
    vector <double> hour {vector <double> (24, not_a_reading)};
};

// Structure for Month, two members - month number and Day
struct Month {
    int month {not_a_month}; // From 0 t0 11
    vector <Day> day {32}; // Since from 1 to 31, you need put 32 here
                           // day 0 is possible, but will be excluded in the later is_valid function
};

// Structure of Year, two members - year and Month
struct Year {
    int year;
    vector <Month> month {12}; // From 0 to 11
};

// Structure of reading for the detailed data (day, hour, temp)
struct Reading {
    int day;
    int hour;
    double temperature;
};

//---------------------------------------------------------------------------------------------------------
// Declear all the istream and ostream operators
istream& operator >> (istream& is, Reading& r);
istream& operator >> (istream& is, Month& m);
istream& operator >> (istream& is, Year& y);

ostream& operator << (ostream& os, Reading& r);
ostream& operator << (ostream& os, Month& m);
ostream& operator << (ostream& os, Year& y);

bool is_valid (const Reading& r);

ifstream open_ifile (string address);
ofstream open_ofile (string address);

ostream& print (ostream& os, vector <Year>& ys);
//---------------------------------------------------------------------------------------------------------
#endif // READ_STRUCTURED_FILE_H
