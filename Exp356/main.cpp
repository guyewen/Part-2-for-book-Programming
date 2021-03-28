// Chapter 10, Exp 356, 10.6
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "std_lib_facilities.h"
using namespace std; // for cout & cin

//---------------------------------------------------------------------------------------------------------
void fill_vector(istream& ist, vector<int>& v, char terminator) {
    for (int i; ist >> i;) {
        v.push_back(i);
    }
    // fine: we found the end of file
    if (ist.eof()) {
        return;
    }
    // stream corrupted; let’s get out of here!
    // Can be removed if ist.exceptions(ist.exceptions() | ios_base::badbit) is added
    /*if (ist.bad()) {
        error("ist is bad");
    }*/
    // clean up the mess as best we can and report the problem
    if (ist.fail()) {
        ist.clear(); // clear stream state, so that we can look for terminator
        char c;
        ist>>c; // read a character, hopefully terminator
        if (c != terminator) { // unexpected character
            ist.unget(); // put that character back
            ist.clear(ios_base::failbit); // set the state to fail()
        }
    }
}

//---------------------------------------------------------------------------------------------------------

int main()
try
{
    ifstream ist {"C:/Qt/Code/QTTest/Test/input.txt"};
    // If fail to open the target input file
    if (!ist) {
        error("Can not open input file");
    }

    ofstream ost {"C:/Qt/Code/QTTest/Test/output.txt"}; // define an ostream "ost" writes to the file named saved in string oname
    if (!ost) {
        error("Can not open output file");
    }

    // make ist throw if it goes bad, p.357
    ist.exceptions(ist.exceptions() | ios_base::badbit);

    vector<int> num;
    char stop = '*';
    fill_vector(ist, num, stop);

    for (int i=0; i<num.size(); ++i) {
        ost << '(' << num[i] << ')' << endl;
    }

    cout << "Input and Output finished!" << endl;

}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << e.what() << '\n';
    keep_window_open("~");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
cout << "exiting\n";
keep_window_open("~");	// For some Windows(tm) setups
}
