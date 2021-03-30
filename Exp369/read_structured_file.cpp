// Define all the functions and operators
#include "read_structured_file.h"

//---------------------------------------------------------------------------------------------------------
// Some supporting functions
// Possible inputs of month name
vector <string> month_input_tbl = {
    "jan", "feb", "mar", "apr", "may", "jun", "jul",
    "aug", "sep", "oct", "nov", "dec"
};

// Convert string month to int month
int month_to_int (string s) {
    for (int i = 0; i < 12; ++i) {
        if (month_input_tbl[i] == s) {
            return i;
        }
    }
    return not_a_month;
}

// Possible outputs of month name
vector <string> month_output_tbl = {
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};

// Convert int month to string month
string int_to_month (int i) {
    if (i<0 || i>11) {
        error("Bad month Index!");
    }
    return month_output_tbl[i];
}

// Function to check if Reading is valid
constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

bool is_valid (const Reading& r) {
    if (r.day < 1 || r.day > 31) {
        return false;
    }
    if (r.hour < 0 || r.hour > 23) {
        return false;
    }
    if (r.temperature < implausible_min || r.temperature > implausible_max) {
        return false;
    }
    return true;
}

// Function "end_of_loop"
void end_of_loop(istream& ist, char term, const string& message) {
    if (ist.fail()) { // use term as terminator or separator
        ist.clear();
        char ch;
        if (ist >> ch && ch == term) return;
        error(message);
    }
}

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

//---------------------------------------------------------------------------------------------------------
// Define istream >> for Reading
// read a temperature reading from is into r, format: ( 3 4 9.7 )
// check format, but don’t bother with data validity
istream& operator >> (istream& is, Reading& r) {
    char ch1;
    if (is>>ch1 && ch1 != '(') { // Wrong format
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d, h; // day, hour
    double t; // temperature
    is >> d >> h >> t >> ch2;
    if (!is || ch2 != ')') { // Wrong input type or wrong format
        error("Bad Reading!");
    }
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

// Define istream >> for Month, format: {month feb ... }
istream& operator >> (istream& is, Month& m) {
    char ch;
    if (is>>ch && ch != '{') { // Wrong format
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    string month_marker; // For the title text "month"
    string mm; // For the reading of month, e.g. jan or feb
    is >> month_marker >> mm;
    if (!is || month_marker != "month") { // Wrong input type or wrong format
        error("Bad start of month");
    }
    m.month = month_to_int(mm);

    int duplicates = 0;
    int invalids = 0;
    // Start to read (day, hour, temp) after read the month number
    for (Reading r; is >> r;) {
        if (is_valid(r)) { // Check if Reading r is valid
            if (m.day[r.day].hour[r.hour] != not_a_reading) {
                // m is type Month with .day and .month
                // m.day is vector<Day>
                // m.day[r.day] is type Day
                // m.day[r.day].hour is vector<double>
                // m.day[r.day].hour[r.hour] is double for temperature reading
                ++duplicates;
                // if ++duplicates, then it means the same r.day and r.hour pair appears the second time
                // if the pair never appears before
                // they should have the default value = not_a_reading before being updated
            }
            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else {
            ++invalids;
        }
    }
    if (invalids) { // if (int c) is true if c != 0, if (! int c) is true if c == 0
        error("Invalid readings in month ", m.month+1);
    }
    if (duplicates) {
        error("duplicate readings in month", m.month+1);
    }
    end_of_loop (is, '}', "Bad end of month");
    return is;
}

// Define istream >> for Year, format: {year 1972 ... }
istream& operator >> (istream& is, Year& y) {
    char ch;
    is >> ch;
    if (ch != '{') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    string year_maker;
    int yy;
    is >> year_maker >> yy;
    if (!is || year_maker != "year") { // Wrong input type or wrong format
        error("Bad start of year!");
    }
    y.year = yy;

    while (true) { // while (true) is kind of infinite loop and need break scheme
        Month m;
        if (!(is>>m)) { // Continue until the read of Month fail
            break;
        }
        // during the is >> m (reading month), we will know m.month (the number of month)
        // hence, we know which element [m.month] in the vector y.month to update
        // The reading of month actuall happend here
        // y.month is a vector<Month>
        // y.month[m.month] is a type Month
        y.month[m.month] = m;
    }

    end_of_loop(is, '}', "Bad end of year");
    return is;
}

//---------------------------------------------------------------------------------------------------------
ostream& print (ostream& os,  vector <Year>& ys) {
    for (int i=0; i<ys.size(); ++i) {
        os << "Year " << ys[i].year << endl;
        for (int j=0; j<ys[i].month.size(); ++j) {
            // ys[i].month is vector<Month>
            if (ys[i].month[j].month != not_a_month) {
                os << "Month " << int_to_month(ys[i].month[j].month) << endl;
            }
            // ys[i].month[j].month is int month
            for (int k=0; k < ys[i].month[j].day.size(); ++k) {
                // ys[i].month[j].day is vector<Day>
                for (int l=0; l < ys[i].month[j].day[k].hour.size(); ++l)
                    // ys[i].month[j].day[k].hour is vector<double>
                    if (ys[i].month[j].day[k].hour[l] != not_a_reading) {
                        os << "day: " << k << " " << "hour: " << l << " "
                             << "Temperature: " << ys[i].month[j].day[k].hour[l] << endl;
                    }
            }
        }
    }
    return os;
}

// Define ostream >> for Month
ostream& operator << (ostream& os, Month& m) {
    os << "Month: " << m.month << endl;
    for (int i=0; i<m.day.size(); ++i) {
        for (int j=0; j<m.day[i].hour.size(); ++j) {
            if (m.day[i].hour[j] != not_a_reading) {
                os << "day: " << i << " " << "hour: " << j << " "
                   << "Temperature: " << m.day[i].hour[j] << endl;
            }
        }
    }
    return os;
}

// Define ostream >> for Year
ostream& operator << (ostream& os, Year& y) {
    os << "Year: " << y.year << endl;
    for (int i=0; i<y.month.size(); ++i) {
        if (y.month[i].month != not_a_month) { // Only print the month updated with real data
            os << y.month[i] << endl; // y.month[i] is type Month
        }
    }
    return os;
}




