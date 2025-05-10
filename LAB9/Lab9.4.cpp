#include <iostream>
#include <string>
using namespace std;

class EncryptionTechnique {
public:
    virtual string encrypt(string message) = 0;
    virtual ~EncryptionTechnique() {}
};

class EncryptionTechnique1 : public EncryptionTechnique {
public:
    string encrypt(string message) override {
        string result;
        for(char c : message) {
            result += to_string((int)c);
        }
        return result;
    }
};

class EncryptionTechnique2 : public EncryptionTechnique {
public:
    string encrypt(string message) override {
        string result;
        for(char c : message) {
            result += to_string((int)c + 2);
        }
        return result;
    }
};

int main() {
    string message;
    cout << "Enter message to encrypt: ";
    getline(cin, message);

    EncryptionTechnique1 tech1;
    EncryptionTechnique2 tech2;

    string encrypted1 = tech1.encrypt(message);
    string encrypted2 = tech2.encrypt(message);

    cout << "Technique 1: " << encrypted1 << endl;
    cout << "Technique 2: " << encrypted2 << endl;

    return 0;
}
