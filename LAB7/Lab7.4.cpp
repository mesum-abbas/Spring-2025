#include<iostream>
#include<string>
using namespace std;

class employee;
void updatesalary(employee &emp, double newsalary);
void raisesalary(employee &emp, double percentage);

class employee {
    private:
        string name;
        int id;
        string designation;
        double salary;

        friend void updatesalary(employee &emp, double newsalary);
        friend void raisesalary(employee &emp, double percentage);

    public:
        employee(string n, int i, string des, double sal) : name(n), id(i), designation(des), salary(sal) {}

        void displaydetails() {
            cout << "Employee ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Designation: " << designation << endl;
            cout << "Salary: $" << salary << endl;
            cout << "-----------------" << endl;
        }
};

void updatesalary(employee &emp, double newsalary) {
    cout << "Updating salary for employee: " << emp.name << endl;
    cout << "Old salary: $" << emp.salary << endl;
    emp.salary = newsalary;
    cout << "New salary: $" << emp.salary << endl;
    cout << "------------------------" << endl;
}

void raisesalary(employee &emp, double percentage) {
    if (percentage <= 0) {
        cout << "Invalid percentage for raise!" << endl;
        return;
    }
    
    double raiseAmount = emp.salary * (percentage / 100);
    double newSalary = emp.salary + raiseAmount;
    
    cout << "Giving a " << percentage << "% raise to: " << emp.name << endl;
    cout << "Old salary: $" << emp.salary << endl;
    emp.salary = newSalary;
    cout << "New salary: $" << emp.salary << endl;
    cout << "------------------------" << endl;
}

class payroll {
    public:
        void processupdatesalary(employee &emp, double newsalary) {
            cout << "Payroll system processing salary update..." << endl;
            updatesalary(emp, newsalary);
        }

        void processraisesalary(employee &emp, double percentage) {
            cout << "Payroll system processing salary raise..." << endl;
            raisesalary(emp, percentage);
        }
};

int main() {
    cout << "The code is written by MESUM ABBAS CT-238:" << endl;
    
    employee emp1("MESUM", 1001, "Developer", 300000);
    employee emp2("ABBAS", 1002, "Worker", 800000);
    employee emp3("ALI", 1003, "Engineer", 1000000);

    cout << "INITIAL EMPLOYEE DETAILS:" << endl;
    cout << "------------------------" << endl;
    emp1.displaydetails();
    emp2.displaydetails();
    emp3.displaydetails();

    payroll pay;
    cout << "SALARY UPDATES:" << endl;
    cout << "------------------------" << endl;
    pay.processupdatesalary(emp1, 5000000);
    pay.processraisesalary(emp2, 10);
    pay.processraisesalary(emp3, 19);

    cout << "UPDATED DETAILS:" << endl;
    cout << "------------------------" << endl;
    emp1.displaydetails();
    emp2.displaydetails();
    emp3.displaydetails();

    return 0;
}
