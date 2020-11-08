/*
 * checkIsbn
 * This app checks if the ISBN number introduced
 * is valid or not taking into account the
 * verification code at the end of it,
 * which must be the result of mod 11 of
 * the sum-product of each digit by its
 * position (starting at index 1).
 *
 * Using: ./checkIsbn 9708170003
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    // Main code of application
    // 1. Take value from argv[1],
    // pass it to a string (isbnCode)
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " [ISBNNumber]" << endl;
        return 1;
    }
    string isbnCode = argv[1];
    cout << "ISBN Code introduced is equal to " <<
         isbnCode << endl;
    // 2. Perform the sumproduct of
    // isbnCode numbers by its
    // positions (starting at index 1)
    // Except for the last one.
    int sumProduct = 0;
    for (int pos=0; pos<9; pos++) {
        //string currentChar = string(1, isbnCode.at(pos));
        char currentChar[2] = { isbnCode.at(pos), 0x00 };
        //sumProduct += (pos+1)*atoi(currentChar.c_str());
        sumProduct += (pos+1)*atoi(currentChar);
    }
    cout << "Sum product: " << sumProduct << endl;
    // 3. Calc the mod 11 of the sumProduct
    int calcVerification = sumProduct % 11;
    // 4. Check if calcVerification is
    // equal to the last item at isbnCode.
    // 4.a. Extract the integer from the .at(9) of isbnCode
    int inputVerification = atoi(&isbnCode.c_str()[9]);
    //if (calcVerification == /*...*/) {
    //    cout << "The ISBN is Korract!" << endl;
    //} else {
    //    cout << "b4d ISBN! The last digit " <<
    //         "should be equal to " << calcVerification
    //         << endl;
    //}
    return 0;
}
