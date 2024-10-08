//
// Created by Carlos Lopez on 2/13/24.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <bitset>

using namespace std;



int main(int argc, char* argv[]) {
    //the file name will be the last argument passed
    string filename = argv[argc-1];
    //base 16 for hex by default unless -b is passed
    unsigned base = 16;
    //if -b is passed then argc is >2
    if (argc > 2) {
        base = 2;
    }

    //variable to store each char read from the file
    char c;
    //variable to track the number of bytes read
    int byte_counter = 0;
    //variable to store address to be incremented with each line read
    int address = 0000000;
    //variable for readable-form output at end of line
    string line;
    //initialize and construct an ifstream object from given file in binary mode
    ifstream in(filename.c_str(), ios::binary);

    //
    cout << setw(7) << setfill ('0') << hex << address << ": ";

    if (base == 2) {
        while (in.get(c)) {
            //determine if current char is printable, if not replace w/ '.'
            if (!isprint(c)) {
                line += '.';
            }
            else {
                line += c;
            }
            // output char in binary
            cout << bitset<8>(c).to_string() << " ";
            // increment bytes read counter
            byte_counter++;

            //end of line once 6 bytes have been printed
            if (byte_counter%6 == 0 ){
                //output readable-form line followed by a new line
                cout << " " << line << '\n';
                // reset readable-form line variable
                line = "";
                // increment by 6 for 6 bytes read per line
                address += 6;
                //output new address
                cout << setw(7) << setfill ('0') << hex << address << ": ";

            }
        }
        cout << " " << line << "\n";
        return 0;
    }

    //default: converting and outputting file bytes to hex
    while (in.get(c)) {
        //determine if current char is printable, if not replace w/ '.'
        if (!isprint(c)) {
            line += '.';
        }
        else {
            //if it is printable, then char will be appended to output line string
            line += c;
        }
        //output char in hex
        cout << setw(2) << hex << (int)c;
        // increment byte read counter
        byte_counter++;
        //condition to print a space between every two bytes
        if (byte_counter%2 == 0) {
            cout << " ";
        }
        //end of line once 16 bytes have been printed
        if (byte_counter%16 == 0){
            //output readable-form line followed by a new line
            cout << " " << line << '\n';
            // reset readable-form line variable
            line = "";
            // increment by 16 for 16 bytes read per line
            address += 16;
            //output new address
            cout << setw(7) << setfill ('0') << hex << address << ": ";

        }
    }

    cout << " " << line << "\n";

    return 0;
}