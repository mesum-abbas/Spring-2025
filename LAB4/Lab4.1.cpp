#include <iostream>
#include <cstring>
using namespace std;

class employee {
private:
    char employeename[50]; 
    const int employeeid;  

public:
    employee(const char* name, int id) : employeeid(id) {
        strcpy(employeename, name);
    }

    void setemployeename(const char* name) {
        strcpy(employeename, name);
    }

    const char* getemployeename() const {
        return employeename;
    }

    int getemployeeid() const {
        return employeeid;
    }

    void display() const {
        cout << "Name is " << employeename << endl;
        cout << "ID is " << employeeid << endl;
    }
};

int main() {
	cout<<"THE CODE IS WRITTEN BY MESUM ABBAS CT-238\n"<<endl;
    employee E1("MESUM", 56);
  	employee E2("HUSAIN",43);
	employee E3("MUHAMMAD",90);
    
    E1.display();
    E2.display();
    E3.display();

	E1.setemployeename("ALI");
    E3.setemployeename("ABBAS");
    cout << "\nAfter Name Change:\n";
    E1.display();
    E3.display();

    return 0;
}
