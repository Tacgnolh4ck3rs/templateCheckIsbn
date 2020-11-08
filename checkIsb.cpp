#include <iostream>
#include <cstdlib>
using namespace std;

//9708170003
int main (int argc, char **argv) {
    string isbnCode= argv[1];
    int ac=0;
    if(argc !=2) {
        cout<<"ISBN introduced is equal to "<<isbnCode<<endl;
    }

    for(int i=0; i<9; i++) {
        //string currentChar=string(1,isbnCode.at(i));
        char currentChar[2] = {isbnCode.at(i),0x00};
        //ac += atoi(currentChar.c_str()) *(i+1);
        ac += atoi(currentChar)*(i+1);
    }
    int calcVerification=ac%11;
    int inputVerification=atoi(&isbnCode.c_str()[9]);
    if(calcVerification ==inputVerification) {
        cout<<"the ISB is correct"<<endl;
    } else {
        cout<<"the ISB is incorrect"<<endl;
    }


    //cout<<"the value of the sum product "<<ac<<endl;
    return 0;
}
