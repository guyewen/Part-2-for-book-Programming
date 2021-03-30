// Chapter 10, Exp 369, 10.11, reading structured file, reading temp in year, month, day, hour
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "std_lib_facilities.h"
using namespace std; // for cout & cin
#include "read_structured_file.h"

//---------------------------------------------------------------------------------------------------------

int main()
try
{
    ifstream ist = open_ifile("C:/Qt/Code/QTTest/Test/input.txt"); // Update the address
    ofstream ost = open_ofile("C:/Qt/Code/QTTest/Test/output.txt"); // Update the address
    //somewhere: make ist throw an exception if it goes bad:
    ist.exceptions(ist.exceptions()|ios_base::badbit);

    vector <Year> ys;
    while (true) {
        Year y;
        // Directly or indirectly uses all istream operator >> here
        // read from ifstream ist
        if (!(ist >> y)) {
            break;
        }
        ys.push_back(y);
    }
    cout << "Read " << ys.size() << " years of readings." << endl;

    // Print out everthing in Year ys on screen
    for (int i=0; i<ys.size(); ++i) {
        cout << "Year " << ys[i].year << endl;
        for (int j=0; j<ys[i].month.size(); ++j) {
            // ys[i].month is vector<Month>
            if (ys[i].month[j].month != not_a_month) {
            cout << "Month " << ys[i].month[j].month << endl;
            }
            // ys[i].month[j].month is int month
            for (int k=0; k < ys[i].month[j].day.size(); ++k) {
                // ys[i].month[j].day is vector<Day>
                for (int l=0; l < ys[i].month[j].day[k].hour.size(); ++l)
                    // ys[i].month[j].day[k].hour is vector<double>
                    if (ys[i].month[j].day[k].hour[l] != not_a_reading) {
                        cout << "day: " << k << " " << "hour: " << l << " "
                             << "Temperature: " << ys[i].month[j].day[k].hour[l] << endl;
                    }
            }
        }
    }

    // Test operator for ostream <<
    cout << endl;
    for (int i=0; i<ys.size(); ++i) {
        cout << ys[i] << endl;
    }

    // Print to file function with ofstream ost
    print(ost, ys);
}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << e.what() << '\n';
    keep_window_open("~");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
cout << "exiting\n";
keep_window_open("~");	// For some Windows(tm) setups
}
