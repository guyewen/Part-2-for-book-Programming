// Chapter 11, Exp393
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "std_lib_facilities.h"
using namespace std; // for cout & cin
//#include "header.h"

//---------------------------------------------------------------------------------------------------------
// Function to open file for both input and output
fstream open_iofile (string address) {
    fstream iost {address};
    // If fail to open the target input file
    if (!iost) {
        error("Can not open file");
    }
    return iost;
}

//---------------------------------------------------------------------------------------------------------

int main()
try
{
    fstream iost = open_iofile("C:/Git/Repository/Part-2-for-book-Programming/Exp393/input.txt"); // Update address

    iost.seekg(2); // move reading position (g for “get”) to 5 (the 6th character)
    char ch1;
    iost >> ch1; // read and increment reading position
    cout << "character[3] is " << ch1 << " (" << int(ch1) << ")\n";
    char ch2;
    iost >> ch2;
    cout << "character[4] is " << ch2 << " (" << int(ch2) << ")\n";

    iost.seekp(13); // move writing position (p for “put”) to 1
    iost << '*'; // write and increment writing position, the original char will be replaced

}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << e.what() << '\n';
    keep_window_open("~");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
cout << "exiting\n";
keep_window_open("~");	// For some Windows(tm) setups
}
