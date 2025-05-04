#include<iostream>
#include<string>
using namespace std;

class payroll;  //friend class


class employee{
    private :
    string name ;
    int id ;
    string designation;
    double salary;


 friend class payroll;
    public :

    employee(string n, int i, string des, double sal) : name(n) , id(i) ,designation(des), salary(sal){}


    void diplaydetails(){
        cout<<"Employee ID :"<<id<<endl;
        cout<<"Name :"<<name<<endl;
        cout<<"Designation :"<<designation<<endl;
        cout<<"Salary :"<<salary<<endl;
        cout<<"-----------------"<<endl;
    }
};

class payroll{
    public:
    void updatesalary(employee &emp , double newsalary){
        cout<<"Updating salary of Employee :"<<emp.name<<endl;
        cout<<"Old salary :"<<emp.salary<<endl;

        emp.salary = newsalary ;

        cout<<"New salary :"<<emp.salary<<endl;
        
    }

    void raisesalary(employee &emp , double percentage){
        if(percentage <= 0){
            cout<<"Invalid"<<endl;
            return ;
        }

        double raiseamount = emp.salary * (percentage /100);
        double newsalary = emp.salary + raiseamount ;


        cout<<"Giving a :"<<percentage << "% raise to"<< emp.name<<endl;
        cout<<"Old salary is  :"<<emp.salary <<endl;

        emp.salary = newsalary ;

        cout<<"New salary is  :"<<emp.salary<<endl;
    }
};

int main () {
    cout<<"The code is written bu MESUM ABBAS CT-238 :"<<endl;
    employee emp1("MESUM",1002,"Developer",300000);
    employee emp2("ABBAS",1002,"Worker",800000);
    employee emp3("ALI",1002,"Engineer",1000000);


    cout << "INITIAL EMPLOYEE DETAILS:" << endl;
    cout << "------------------------" << endl;
    emp1.diplaydetails();
    emp2.diplaydetails();
    emp3.diplaydetails();


    payroll pay;
    cout << "SALARY UPDATES:" << endl;
    pay.updatesalary(emp1,5000000);
    pay.raisesalary(emp2,10);
    pay.raisesalary(emp3,19);


    cout << "UPDATES DETAILS :"  << endl;
    emp1.diplaydetails();
    emp2.diplaydetails();
    emp3.diplaydetails();


    


    return 0;
}
