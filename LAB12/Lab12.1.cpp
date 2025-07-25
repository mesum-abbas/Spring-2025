#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main (){

    string input;
    cout << "Enter the string " << endl;
    getline(cin,input);
    cout << "You entered" << input << endl;

    int length = input.length();
    cout << "length of your string " << length <<  "character" << endl;


    string fname = "my_string.txt";
    ofstream outFile(fname);

    if(outFile.is_open()){
        outFile << input ;
        outFile.close();
        cout << "Successfully stored in string "<< fname << endl;

    }
    else {
        cout << "Unable to open file  "<< fname << endl;
        return 1;
    }

    string storedstring ;
    ifstream inFile(fname);
    if(inFile.is_open()){
        getline(inFile,storedstring);
        inFile.close();
        cout << "Reverted fron file " << endl;
    }
    else {
        cout << "Error" << endl;
        return 1;
    }

    return 0;

}
