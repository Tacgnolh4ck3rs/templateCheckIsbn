#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    // Main code of application
    // 1. take value from argv[1]
    // pass it to a string (isbnCode)
    if(argc !=2){
        cout<< "Usage: " << argv[0] << " [ISBNNumber]" <<endl; 
        return 1;   
    }
    string isbnCode = argv[1];
    cout<< "2 ISBN Code introduced is equal to " <<
        isbnCode<< endl;
    int sumProduct= 0;
    for(int pos=1; pos<10;pos++){
       // string currentChar =string(1,isbnCode.at(pos));
         char currentChar[2] = {isbnCode.at(pos-1), 0x00};// the end of string 0x00
      //  sumProduct += (pos)*atoi(currentChar.c_str());
         sumProduct += (pos)*atoi(currentChar);
    }
    cout<< "The ISBN:  " << sumProduct << endl;
    int calcVerification= sumProduct % 11;
    cout<< "The number verification:  " << calcVerification << endl;
    
    int inputVerification = atoi(&isbnCode.c_str()[9]); 
    if( inputVerification == calcVerification){
        cout<< "The number ISBN is correct" << endl;
        }
        else{
        cout<< "The number ISBN is incorrect" << endl;
        }
 return 0;
}
