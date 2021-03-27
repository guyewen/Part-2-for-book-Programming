// Chapter 10, Exp 354, 10.5
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "std_lib_facilities.h"
using namespace std; // for cout & cin

//---------------------------------------------------------------------------------------------------------
struct Reading {
    int hour;
    double temperature;
};

//---------------------------------------------------------------------------------------------------------

int main()
try
{
    /*cout << "Please enter the input file name: " << endl;
    string iname;
    cin >> iname;*/
    // define an istream "ist" reads from the file named saved in string iname
    // You need the path of the file location
    ifstream ist {"C:/Qt/Code/QTTest/Test/input.txt"};
    // If fail to open the target input file
    if (!ist) {
        error("Can not open input file");
    }

    /*string oname;
    cout << endl << "Please enter name of output file: " << endl;
    cin >> oname;*/
    // If fail to open the target output file
    ofstream ost {"C:/Qt/Code/QTTest/Test/output.txt"}; // define an ostream "ost" writes to the file named saved in string oname
    if (!ost) {
        error("Can not open output file");
    }

    vector <Reading> temps;
    int hour;
    double temp;
    while (ist >> hour >> temp) {
        if (hour < 0 || hour > 23) {
            error("Invalid hour!");
        }
        Reading data;
        data.hour = hour;
        data.temperature = temp;
        temps.push_back(data);
    }

    for (int i=0; i<temps.size(); ++i) {
        ost << '(' << temps[i].hour << ", " << temps[i].temperature << ')' << endl;
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
