#include <iostream>

// We add the proper libraries for the 'sizeof' operator for the different data types
#include <climits>
#include <cfloat>

using namespace std;

int main()
{
    cout << "\'sizeof\' operator information" << endl;
    cout << "===============================" << endl;

    cout << "char: " << sizeof(char) << " bytes." << endl;
    cout << "int: " << sizeof(int) << " bytes." << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes." << endl;
    cout << "short: " << sizeof(short) << " bytes." << endl;
    cout << "long: " << sizeof(long) << " bytes." << endl;
    cout << "long long: " << sizeof(long long) << " bytes.\n" << endl;

    cout << "\'sizeof\' operator information in cfloat" << endl;
    cout << "=========================================" << endl;

    cout << "float: " << sizeof(float) << " bytes." << endl;
    cout << "double: " << sizeof(double) << " bytes." << endl;
    cout << "long double: " << sizeof(long double) << " bytes." <<endl;


    // This specifies the value that can be stored in a variable
    cout << "\'sizeof\' operator information in climits" << endl;
    cout << "==========================================" << endl;

    cout << "For MINIMUM values" << endl;
    cout << "char: " << CHAR_MIN << endl; // In this case, we have signed character, so we have the 2-s complement (1 bit for the sign): 2^7 = 128
                                          // -128 to 127
    cout << "int: " << INT_MIN << endl;
    cout << "short: " << SHRT_MIN << endl;
    cout << "long: " << LONG_MIN << endl;
    cout << "long long: " << LLONG_MIN << endl;

    cout << "\nFor MINIMUM values" << endl;
    cout << "char: " << CHAR_MAX << endl;
    cout << "int: " << INT_MAX << endl;
    cout << "short: " << SHRT_MAX << endl;
    cout << "long: " << LONG_MAX << endl;
    cout << "long long: " << LLONG_MAX << endl;

    return 0;
}

