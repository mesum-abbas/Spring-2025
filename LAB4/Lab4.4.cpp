#include <iostream>
#include <string>
using namespace std;

class HotelRent {
private:
    string customerName;
    int days;
    const double dailyRent;  

public:
    
    HotelRent(string name, int stay) : customerName(name), days(stay), dailyRent(1000.85) {}
    double calculateRent() const {
        if (days > 7) {
            return (days - 1) * dailyRent;  
        }
        return days * dailyRent;
    }
    void displayDetails() const {
        cout << "Customer Name: " << customerName << endl;
        cout << "Days Stayed: " << days << endl;
        cout << "Total Rent: " << calculateRent() << endl;
    }
};

int main() {
	cout <<"THE CODE IS WRITTEN BY MESUM ABBAS CT-238"<<endl;
    string name;
    int stayDays;

    cout << "Enter Customer Name: ";
    getline(cin, name);
    cout << "Enter Number of Days Stayed: ";
    cin >> stayDays;

    HotelRent customer(name, stayDays);
    cout << "\nRent Details";
    customer.displayDetails();

    return 0;
}
