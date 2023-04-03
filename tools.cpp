#include "tools.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

// Define function to print elements of a vector
void print(vector<int> const &input) {
std::copy(input.begin(),
        input.end(),
        std::ostream_iterator<int>(std::cout, " "));
}

// Function to get the size of a file in bytes
// Open the file in binary mode and set the stream position to the end of the file
ifstream::pos_type filesize(const char* filename)
{
    ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    ifstream::pos_type ret =  in.tellg();
    return ret;
}

// Function to write a vector of integers to a binary file
void write_vect(vector<int> vect, string name){
    fstream f;
    int* arr = &vect[0];
    f.open(name, ios::out|ios::binary);
    if (f){
        f.write(reinterpret_cast<char*>(arr), vect.size() * 4);
        f.close();
    } else {
        cout << "Error" << endl;
    }
}

// Function to read a vector of integers from a binary file
vector<int> read_vect(const char *name){
    fstream f;
    string loc = name;
    f.open(loc, ios::in|ios::binary);
    int fsize = filesize(loc.c_str());
    vector<int> vect(fsize/4);
    int* arr = &vect[0];
    if(f){
        f.read(reinterpret_cast<char*>(arr), fsize);
        f.close();
    }
    return vect;
}
