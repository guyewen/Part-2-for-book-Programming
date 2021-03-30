#ifndef READ_STRUCTURED_FILE_H
#define READ_STRUCTURED_FILE_H
#include "std_lib_facilities.h"

//---------------------------------------------------------------------------------------------------------
class Point {
public:
    Point ();
    Point (double x, double y);
    double get_x () const {return x;};
    double get_y () const {return y;};
private:
    double x;
    double y;
};

//---------------------------------------------------------------------------------------------------------
// Declear all the istream and ostream operators
istream& operator >> (istream& is, Point& p);
ostream& operator << (ostream& os, Point& p);

ifstream open_ifile (string address);
ofstream open_ofile (string address);

//---------------------------------------------------------------------------------------------------------
#endif // READ_STRUCTURED_FILE_H
