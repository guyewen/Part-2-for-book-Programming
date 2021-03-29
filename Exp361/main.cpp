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
void skip_to_int() {
    if (cin.fail()) { // we found something that wasn’t an integer
        cin.clear();  // we’d like to look at the characters
        // throw away non-digits
        for (char ch; cin >> ch;) {
            if (isdigit(ch) || ch == '-' || ch == '+') {
                cin.unget(); // put the digit back, so that we can read the number
                return;
            }
        }
    }
    error("no input"); // eof or bad: give up
}

int get_int() {
    int n = 0;
    while (true) {
        if (cin >> n) {
            return n;
        }
        cout << "Sorry, that was not a number, please try again!" << endl;
        skip_to_int();
    }
}

int get_int(int low, int high) {
    cout << "Please enter an integer in the range "
         << low << " to " << high << " (inclusive):\n";
    while (true) {
        int n = get_int();
        if (n >= low && n <= high) {
            return n;
        }
        cout << "Sorry "
             << n << " is not in the [" << low << ':' << high
             << "] range; please try again\n";
    }
}

//---------------------------------------------------------------------------------------------------------

int main()
try
{
    int n = get_int(1, 10);
    cout << "n: " << n << endl;

    int m = get_int(2,300);
    cout << "m: " << m << '\n';
}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << e.what() << '\n';
    keep_window_open("~");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
cout << "exiting\n";
keep_window_open("~");	// For some Windows(tm) setups
}
