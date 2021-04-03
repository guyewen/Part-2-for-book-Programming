// Chapter 11, Exp400 - Punct_stream class to read strings and ignore certain chars, e.g. ",;:"
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "std_lib_facilities.h"
using namespace std; // for cout & cin

//---------------------------------------------------------------------------------------------------------
int main()
try
{
    /*
    // Drill 01
    int birth_year = 1986;

    // Drill 02 & 03 & 04 & 07
    cout << showbase;
    cout << "Decimal:\t" << dec << birth_year << endl;
    cout << "Hexadecimal:\t" << hex << birth_year << endl;
    cout << "Octal:\t\t" << oct << birth_year << endl;

    // Drill 05 & 06
    int age = 34;
    cout << "Age:\t\t" << dec << age << endl;

    // Drill 08
    int a, b, c, d;
    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
    */

    // Drill 09
    const float f = 1234567.89;
    cout << "Standard:\t" << f << endl;
    cout << "DefaultFloat:\t" << defaultfloat << f << endl;
    cout << "Fixed:\t\t" << fixed << f << endl;
    cout << "Scientific:\t" << scientific << f << endl;
    cout << endl;

    const double d = 1234567.89;
    cout << "Standard:\t" << d << endl;
    cout << "DefaultFloat:\t" << defaultfloat << d << endl;
    cout << "Fixed:\t\t" << fixed << d << endl;
    cout << "Scientific:\t" << scientific << d << endl;
    cout << endl;

    cout << "Standard:\t" << 1234567.89 << endl;
    cout << "DefaultFloat:\t" << defaultfloat << 1234567.89 << endl;
    cout << "Fixed:\t\t" << fixed << 1234567.89 << endl;
    cout << "Scientific:\t" << scientific << 1234567.89 << endl;
    cout << endl;

    // Drill 10


}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << e.what() << '\n';
    keep_window_open("~");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
cout << "exiting\n";
keep_window_open("~");	// For some Windows(tm) setups
}
