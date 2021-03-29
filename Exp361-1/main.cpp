// Chapter 10, Exp 361-1, 10.7, read from files
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "std_lib_facilities.h"
using namespace std; // for cout & cin

//---------------------------------------------------------------------------------------------------------
ifstream open_ifile (string address) {
    ifstream ist {address};
    // If fail to open the target input file
    if (!ist) {
        error("Can not open input file");
    }
    return ist;
}

ofstream open_ofile (string address) {
    ofstream ost {address};
    // If fail to open the target input file
    if (!ost) {
        error("Can not open output file");
    }
    return ost;
}

void skip_to_int(ifstream& ist) {
    if (ist.fail()) { // we found something that wasn’t an integer
        ist.clear();  // we’d like to look at the characters
        // throw away non-digits
        for (char ch; ist >> ch;) {
            if (isdigit(ch) || ch == '-' || ch == '+') {
                ist.unget(); // put the digit back, so that we can read the number
                return;
            }
        }
    }
    error("no input"); // eof or bad: give up
}

int get_int(ifstream& ist, int low, int high) {
    cout << "Please enter an integer in the range "
         << low << " to " << high << " (inclusive):\n";
    while (true) {
        int n = 0;
        if (ist >> n) {
            if (n >= low && n <= high) {
                return n;
            }
            cout << "Sorry "
             << n << " is not in the [" << low << ':' << high
             << "] range; please try again\n";
        }
        cout << "Sorry, that was not a number, please try again!" << endl;
        skip_to_int(ist);
    }
}

//---------------------------------------------------------------------------------------------------------

int main()
try
{
    ifstream ist = open_ifile("C:/Qt/Code/QTTest/Test/input.txt");
    ofstream ost = open_ofile("C:/Qt/Code/QTTest/Test/output.txt");

    int n = get_int(ist, 1, 10);
    ost << n;

}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << e.what() << '\n';
    keep_window_open("~");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
cout << "exiting\n";
keep_window_open("~");	// For some Windows(tm) setups
}
