// Chapter 10, Drill10 - Point
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "std_lib_facilities.h"
using namespace std; // for cout & cin
#include "drill10.h"

//---------------------------------------------------------------------------------------------------------

int main()
try
{
    ifstream ist = open_ifile("C:/Qt/Code/QTTest/Test/input.txt"); // Update the address
    ofstream ost = open_ofile("C:/Qt/Code/QTTest/Test/output.txt"); // Update the address
    //somewhere: make ist throw an exception if it goes bad:
    ist.exceptions(ist.exceptions()|ios_base::badbit);

    // test Point class, >> and << for Point
    // Point p;
    // cout << "Create a Point" << endl;
    // cin >> p;
    // cout << p;

    vector <Point> points;

    // Test read from file
    while (true) {

        Point p;
        if (!(ist >> p)) {
            break;
        }

        points.push_back(p);
    }

    // Test print out to file
    for (int i=0; i<points.size(); ++i) {
        ost << points[i];
    }

}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << e.what() << '\n';
    keep_window_open("~");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
cout << "exiting\n";
keep_window_open("~");	// For some Windows(tm) setups
}
