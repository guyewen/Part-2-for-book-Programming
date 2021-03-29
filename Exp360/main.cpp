// Chapter 10, Exp 362, 10.7
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

//---------------------------------------------------------------------------------------------------------

int main()
try
{
    cout << "Please enter an integer in the range 1 to 10 (inclusive):\n";
    int n = 0;
    while (true) {
        if (cin >> n) {
            if (1 <= n && n <= 10) {
                cout << "Succeed!" << endl;
                break;
            }
            cout << "Sorry " << n
                 << " is not in the [1:10] range; please try again\n";
        }
        else {
            cout << "Sorry, that was not a number; please try again\n";
            skip_to_int();
        }

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
