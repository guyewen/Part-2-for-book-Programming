// Chapter 11, Exp400 - Punct_stream class to read strings and ignore certain chars, e.g. ",;:"
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "std_lib_facilities.h"
using namespace std; // for cout & cin
#include "header.h"

//---------------------------------------------------------------------------------------------------------
int main()
try
{
    // given text input, produce a sorted list of all words in that text
    // ignore punctuation and case differences
    // eliminate duplicates from the output

    ifstream ist = open_ifile("C:/Qt/Code/QTTest/Test/input.txt"); // Update the address
    ofstream ost = open_ofile("C:/Qt/Code/QTTest/Test/output.txt"); // Update the address
    //somewhere: make ist throw an exception if it goes bad:
    ist.exceptions(ist.exceptions()|ios_base::badbit);

    // Enter string from keyboard for source
    // Punct_stream ps {cin};

    // Enter string from file for source
    Punct_stream ps {ist};

    // Set whitespace chars
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~"); // note \“ means ” in string
    ps.add_white('[');
    ps.add_white(']');
    // Set case sensitive
    ps.case_sensitive(false);

    cout << "please enter words\n";

    vector<string> vs;

    for (string word; ps>>word;) {
        vs.push_back(word); // read words
    }
    sort(vs.begin(),vs.end()); // sort in lexicographical order

    // Print on screem
    for (int i=0; i<vs.size(); ++i) { // write dictionary
        if (i==0 || vs[i]!=vs[i-1]){ // Only print non-repeat words
            cout << vs[i] << '\n'; // Print to screen
            ost << vs[i] << '\n';  // Print to file
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
