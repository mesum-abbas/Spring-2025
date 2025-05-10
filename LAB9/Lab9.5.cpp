#include <iostream>
#include <string>
using namespace std;

class Encryption {
public:
    virtual string encrypt(string msg) = 0;
    virtual string decrypt(string msg) = 0;
};

class SimpleEncrypt : public Encryption {
public:
    string encrypt(string msg) {
        string result;
        for(int i=0; i<msg.length(); i++) {
            int num = msg[i];
            result += to_string(num);
        }
        return result;
    }
    
    string decrypt(string msg) {
        string result;
        for(int i=0; i<msg.length(); i+=2) {
            string part = msg.substr(i, 2);
            int num = stoi(part);
            result += char(num);
        }
        return result;
    }
};

class ShiftEncrypt : public Encryption {
public:
    string encrypt(string msg) {
        string result;
        for(int i=0; i<msg.length(); i++) {
            int num = msg[i] + 2;
            result += to_string(num);
        }
        return result;
    }
    
    string decrypt(string msg) {
        string result;
        for(int i=0; i<msg.length(); i+=2) {
            string part = msg.substr(i, 2);
            int num = stoi(part) - 2;
            result += char(num);
        }
        return result;
    }
};

int main() {
    string input;
    cout << "Enter message: ";
    cin >> input;

    SimpleEncrypt simple;
    ShiftEncrypt shift;

    string e1 = simple.encrypt(input);
    string d1 = simple.decrypt(e1);

    string e2 = shift.encrypt(input);
    string d2 = shift.decrypt(e2);

    cout << "\nSimple Encryption:" << endl;
    cout << "Encrypted: " << e1 << endl;
    cout << "Decrypted: " << d1 << endl;

    cout << "\nShift Encryption:" << endl;
    cout << "Encrypted: " << e2 << endl;
    cout << "Decrypted: " << d2 << endl;

    return 0;
}
