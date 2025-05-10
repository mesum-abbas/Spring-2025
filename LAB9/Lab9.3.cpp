#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string carId;
    string brand;
    string model;
    bool available;
public:
    Vehicle(string id, string b, string m) : carId(id), brand(b), model(m), available(true) {}
    virtual bool isAvailable() = 0;
    virtual void rent() = 0;
    virtual void returnVehicle() = 0;
    virtual ~Vehicle() {}
    string getBrand() { return brand; }
    string getModel() { return model; }
};

class Car : public Vehicle {
public:
    Car(string id, string b, string m) : Vehicle(id, b, m) {}
    bool isAvailable() override { return available; }
    void rent() override { available = false; }
    void returnVehicle() override { available = true; }
};

class RentalSystem {
private:
    vector<Vehicle*> vehicles;
public:
    void addVehicle(Vehicle* v) { vehicles.push_back(v); }
    bool rentVehicle(Vehicle* v) {
        if (v->isAvailable()) {
            v->rent();
            return true;
        }
        return false;
    }
    void returnVehicle(Vehicle* v) {
        v->returnVehicle();
    }
    void displayAvailable() {
        cout << "Available Vehicles:\n";
        for (auto v : vehicles) {
            if (v->isAvailable()) {
                cout << v->getBrand() << " " << v->getModel() << endl;
            }
        }
    }
};

class Customer {
private:
    string name;
    RentalSystem* rentalSystem;
public:
    Customer(string n, RentalSystem* rs) : name(n), rentalSystem(rs) {}
    bool rentVehicle(Vehicle* v) {
        return rentalSystem->rentVehicle(v);
    }
    void returnVehicle(Vehicle* v) {
        rentalSystem->returnVehicle(v);
    }
};

int main() {
    RentalSystem rentalSystem;
    
    Vehicle* car1 = new Car("C001", "Toyota", "Corolla");
    Vehicle* car2 = new Car("C002", "Honda", "Civic");
    Vehicle* car3 = new Car("C003", "Ford", "Mustang");
    
    rentalSystem.addVehicle(car1);
    rentalSystem.addVehicle(car2);
    rentalSystem.addVehicle(car3);
    
    Customer customer("John", &rentalSystem);
    
    rentalSystem.displayAvailable();
    
    if (customer.rentVehicle(car1)) {
        cout << "Toyota Corolla rented successfully\n";
    } else {
        cout << "Toyota Corolla not available\n";
    }
    
    rentalSystem.displayAvailable();
    
    customer.returnVehicle(car1);
    
    rentalSystem.displayAvailable();
    
    delete car1;
    delete car2;
    delete car3;
    
    return 0;
}
