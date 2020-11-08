/*This program checks ISBN Numbers*/

#include<iostream>
#include<string>
#include <cstdlib>

using namespace std;
int main (int argc, char **argv){
	string isbnCode;
	int sum=0;
	int verificationMod;
	if (argc!=2){
		cout<<"Write the ISBN-Code"<<endl;
		return 1;
	}

	isbnCode= argv[1];

	cout<<"ISBN Code ti verify is"<< argv[0]<<endl;

	for(int k=0; k<9;k++){
	//string currentChar= string(1,isbnCode.at(k));
	char currentChar[2]={isbnCode.at(k),0x00};
	sum=sum+ (k+1)*atoi(currentChar);
	
	}
	cout<<"The sum result is "<< sum <<endl;
	
	verificationMod=sum % 11;

	int verificationISBN=stoi(&isbnCode.c_str()[9]);
	
	if(verificationISBN==verificationMod){
		cout<<"The ISBN-Code is correct"<<endl;
	}
	else {
		cout<<"The ISBB-Code is wrong"<<endl;
	}
	
}


