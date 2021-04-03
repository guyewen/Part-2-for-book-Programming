#ifndef HEADER_H
#define HEADER_H
#include "std_lib_facilities.h"

//---------------------------------------------------------------------------------------------------------
// Define the Punct_stream class
class Punct_stream {
public:
    Punct_stream(istream& is) // Constructor
        :source{is}, sensitive{true} {} // Initializer

    void whitespace (const string& s) {white = s;} // make s the whitespace set
    void add_white (char c) {white += c;} // add to the whitespace set
    bool is_whitespace (char c); // is c in the whitespace set?
    void case_sensitive (bool b) {sensitive = b;}

    Punct_stream& operator >> (string& s);
    operator bool();
private:
    istream& source; // Source of input
    istringstream buffer; // To save to after replace the chars to whitespace and sort on it
    string white; // Save all chars that are considered as whitespace
    bool sensitive; // Is the stream case-sensitive
};

//---------------------------------------------------------------------------------------------------------
// Member functions and other support functions

ifstream open_ifile (string address);
ofstream open_ofile (string address);
fstream open_iofile (string address);



//---------------------------------------------------------------------------------------------------------

#endif // HEADER_H
