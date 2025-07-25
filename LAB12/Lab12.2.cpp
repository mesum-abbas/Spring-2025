#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string sourceFile, destFile;
    
    cout << "Enter the source file name: ";
    cin >> sourceFile;
    
    cout << "Enter the destination file name: ";
    cin >> destFile;
    
    ifstream source(sourceFile);
    
    if (!source.is_open()) {
        cout << "Error: Unable to open source file: " << sourceFile << endl;
        return 1;
    }
    
    ofstream destination(destFile);
    
    if (!destination.is_open()) {
        cout << "Error: Unable to open destination file: " << destFile << endl;
        source.close();
        return 1;
    }
    
    char ch;
    int count = 0;
    
    while (source.get(ch)) {
        destination.put(ch);
        count++;
    }
    
    source.close();
    destination.close();
    
    cout << "File copied successfully!" << endl;
    cout << "Total " << count << " characters copied from '" << sourceFile 
         << "' to '" << destFile << "'" << endl;
    
    return 0;
}
