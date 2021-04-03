// Define all the functions and operators
#include "header.h"
//---------------------------------------------------------------------------------------------------------
// Member functions and support functions
bool Punct_stream::is_whitespace (char c) {
    for (char w: white) { // Compare char c with all chars in white
        if (c == w) {
            return true;
        }
    }
    return false;
}

// Reture true if the operation on Punct_stream succeeded
Punct_stream::operator bool() {
    return !(source.fail() || source.bad()) && buffer.good();
}

Punct_stream& Punct_stream::operator>>(string& s) {
    // The while loop will only run if there is no char in buffer to read to string s
    // namely when "buffer >> s" fails
    while (!(buffer >> s)) {
        if (buffer.bad() || !source.good()) {
            return *this; // Return the current object
        }
        buffer.clear(); // clear the status of buffer

        string line;
        // get a line from source and save in string line
        // format: getline(istream, string s)
        getline(source, line);

        // replace the whitespace characters
        for (char& ch: line) { // Check all characters in the string line one by one
            if (is_whitespace(ch)) { // if thie char ch is one of the whitespace char
                ch = ' ';
            }
            else if (!sensitive) { // Case sensitive or not
                ch = tolower(ch);
            }
        }

         buffer.str(line); // istringstream.str(string s), assing string s to istringstream
    }
    return *this; // Return the current object
}

//---------------------------------------------------------------------------------------------------------
// Function to open input file
ifstream open_ifile (string address) {
    ifstream ist {address};
    // If fail to open the target input file
    if (!ist) {
        error("Can not open input file");
    }
    return ist;
}

// Function to open output file
ofstream open_ofile (string address) {
    ofstream ost {address};
    // If fail to open the target input file
    if (!ost) {
        error("Can not open output file");
    }
    return ost;
}

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
