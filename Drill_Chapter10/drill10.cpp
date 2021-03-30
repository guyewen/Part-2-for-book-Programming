// Define all the functions and operators
#include "drill10.h"

//---------------------------------------------------------------------------------------------------------
Point::Point() {
    x=0;
    y=0;
}

Point::Point(double x, double y) {
    Point::x = x;
    Point::y = y;
}

//---------------------------------------------------------------------------------------------------------
// Function "end_of_loop"
istream& operator >> (istream& is, Point& p) { // format (x, y)
    char ch1, ch2, ch3;
    double x, y;

    is >> ch1 >> x >> ch2 >> y >> ch3;

    // For manual input
    /*while (!is || ch1 != '(' || ch2 != ',' || ch3 != ')') {
        is.clear();
        is.ignore(100, '\n');
        cout << "Wrong input, please try again with the right format (x, y)!" << endl;
        is >> ch1 >> x >> ch2 >> y >> ch3;
    }*/

    if (ch1 == '*') { // check the terminal symbol
        return is;
    }
    if (!is || ch1 != '(' || ch2 != ',' || ch3 != ')') {
        error("Baid format!");
    }

    p = Point(x, y);
    return is;
}

ostream& operator << (ostream& os, Point& p) {
    return os << '(' << p.get_x() << ", " << p.get_y() << ')' << endl;
}

//---------------------------------------------------------------------------------------------------------
// Function to open input file
ifstream open_ifile (string address) {
    ifstream ist {address};
    // If fail to open the target input file
    if (!ist) {
        error("Can not open input file");
    }
    return ist;
}

// Function to open output file
ofstream open_ofile (string address) {
    ofstream ost {address};
    // If fail to open the target input file
    if (!ost) {
        error("Can not open output file");
    }
    return ost;
}
