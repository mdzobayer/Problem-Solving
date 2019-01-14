#include <iostream>
#include <string>

using namespace std;
#include <string.h>

int main() {

    char* mystring = new char[255]; // allocate 255 bytes for the string
    strcpy_s(mystring, 255, "Simon"); // copy "Simon\0" into mystring
                                      // the size of the memory at the mystring pointer is 255
                                      // bytes, the size of the string is 5 bytes + the
                                      // null terminator
    cout << mystring << endl;

    char* tenchars = new char[10];
    char* sixchars = new char[6];
    char* bigchars = new char[255];

    // copy / concatenate strings
    strcpy(sixchars, "Simon");  // exactly fills sixchars
    strcpy_s(sixchars, 6, "Simon"); // exactly fills sixchars

    strcpy(tenchars, sixchars); // fills tenchars with 4 spare
    strcpy_s(tenchars, 10, sixchars); // fills tenchars with 4 spare

    strcat(tenchars, sixchars); // no error but overwriting memory by 1 char
    strcat_s(tenchars, 10, sixchars);   // Error!

    // copy / concatenate n chars from one string to another
    strcpy(bigchars, sixchars, 3);  // copy 3 chars from sixchars to bigchars
    strcpy_s(bigchars, 255, sixchars, 3); // copy 3 chars from sixchars to bigchars safely

    // concatenate n chars from one string to another
    strncat(bigchars, sixchars, 3); // concatenate 3 chars
    strncat_s(bigchars, 255, sixchars, 3); // concatenate 3 chars safely

    //copy / concatenate n chars from one string to another
    strncpy(bigchars, sixchars, 3);         // copy 3 chars from sixchars to bigchars
    strncpy_s(bigchars, 255, sixchars, 3);  // copy 3 chars from sixchars to bigchars safely

    // Concatenate n chars from one string to another
    strncat(bigchars, sixchars, 3);        // concatenate 3 chars
    strncat_s(bigchars, 255, sixchars, 3); // concatenate 3 chars safely

    int x = strcmp(sixchars, tenchars);     // compare whole string
    int y = strncmp(sixchars, tenchars, 3); // compare ist 3 chars of string only
                                            // result comparison
                                            // -1 sixchars < tenchars
                                            // 0 sixchars == tenchars
                                            // 1 sixchars > tenchars
    // get number of chars in a string - not including the null terminator
    int z = strlen(bigchars);               // returns length not including null terminator

    // std::string compatibility
    string name = "Simon";
    strcpy(bigchars, name.date());        // std:: string.date() returns const char*
    strcpy_s(bigchars, 255, name.date()); // std:: string.date() returns const char*

    return (0);
}
