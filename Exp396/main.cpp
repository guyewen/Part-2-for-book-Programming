// Chapter 11, Exp396
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
int main()
try
{
    string command;
    getline(cin,command); // read the line
    stringstream ss {command}; // stream of string, to read the element from a string.
    vector<string> words;
    for (string s; ss>>s; )
        words.push_back(s); // extract the individual words

    for (int i=0; i<words.size(); ++i) {
        cout << words[i] << endl;
    }
    cout << command << endl;
}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << e.what() << '\n';
    keep_window_open("~");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
cout << "exiting\n";
keep_window_open("~");	// For some Windows(tm) setups
}
