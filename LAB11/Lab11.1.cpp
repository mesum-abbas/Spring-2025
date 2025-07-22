#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class InvalidPasswordException {
private:
    char message[100];
public:
    InvalidPasswordException() {
        strcpy(message, "Password must be at least 6 characters long and contain at least one digit");
    }
    
    const char* what() {
        return message;
    }
};

bool isValidPassword(const string& password) {
    if (password.length() < 6) 
        return false;
    
    bool hasDigit = false;
    for (int i = 0; i < password.length(); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = true;
            break;
        }
    }
    
    return hasDigit;
}

void login() {
    string username, password;
    
    cout << "Enter username: ";
    cin >> username;
    
    cout << "Enter password: ";
    cin >> password;
    
    if (!isValidPassword(password)) {
        throw InvalidPasswordException();
    }
    
    cout << "Login successful!" << endl;
}

int main() {
	cout << " The code is written by MESUM ABBAS CT-238" << endl;
    try {
        login();
    }
    catch (InvalidPasswordException& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
