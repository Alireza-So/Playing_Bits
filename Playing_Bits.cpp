// Coded by Alireza Sohrabi
// Coded for Linux/Unix
#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

int main(){
    
    system("clear"); // Clearing the output before showing the result
    cout << endl; // Making one line 
    cout << right; // Justifying the result to the right
    unsigned short int value{0xffffu}; // Storing 0XFFFF to the value (As unsigned value)
    cout << "The value in Decimal is: " << setw(19) << showbase << dec << value << endl; // Showing the result in decimal and making the result
    //use 19 characters to justify it to the same column as other results and also showing the base system of the decimal number


    cout << "The value in Hexadecimal is: " << setw(16) << showbase << hex << value << endl << endl; //Showing the value in Hexadecimal and making the result use 
    //16 characters it to the same column as other results

    cout << noshowbase; // Disabling the showbase result to not disturb the justification (Also binary base doesn't need to show the base)
    cout << "The base value in bits is: " << setw(28) << bitset<16>(value) << endl; // Showing the number in binary
    
    cout << left; // Justifying the result to the left
    unsigned short int result[16]; // An array for storing the modified value for further expriments
    // Shifting one bit to the right using for statement
    for(int index = 0; index <= 15; index++){
        value = static_cast<unsigned short int>(value >> 1); // Converting explicitly to store the result ,which is in integer base and is 4 byte, to unsigned short (which is 2 byte)
        result[index] = static_cast<unsigned short int>(value); // Storing the modified value to the related index for futhur expriments
        cout << "The value afer " << setw(2) << dec << noshowbase << index << " bit to the right is: " << bitset<16>(value); // Showing the result in bits
        cout << " , and the decimal equivalence is: " << setw(5) << dec << value; // Showing the result in decimal
        cout << " , which is equvalent to: " << setw(6) << showbase << hex << value << " in Hexadecimal" << endl; // Showing the result in Hexadecimal
    }
    cout << endl << endl;
    // Xor'ing the first index of array with the last one (Each value's couterpart) using for statemenr for repetition
    unsigned short int modified_result{}; // A variable for storing the Xor result each time
    for(int index = 0; index <=15; index++){
        modified_result = static_cast<unsigned short int>(result[index] ^ result[15 - index]); // Xor'ing the couterparts
        cout << "The result of xor'ing each value with its counterpart is: " << bitset<16>(modified_result); // Printing the result as bits
        cout << " , and the decimal equivalence is: " << setw(5) << dec << modified_result; // Printing the result in decimal
        cout << " , which is equivalent to: " << setw(6) << showbase << hex << modified_result << " in Hexadecimal" << endl; // Printing the result in hexadecimal
    }

    return 0;
}