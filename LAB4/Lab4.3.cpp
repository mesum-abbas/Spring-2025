	#include <iostream>
using namespace std;

class Car {
private:
    const int maxSpeed;  
    int currentSpeed;

public:
    Car(int speed) : maxSpeed(speed), currentSpeed(0) {}

    void accelerate(int increase) {
        if (currentSpeed + increase > maxSpeed) {
            currentSpeed = maxSpeed; 
        } else {
            currentSpeed += increase;
        }
        cout << "Current Speed: " << currentSpeed << endl;
    }
    void displayMaxSpeed() const {
        cout << "Max Speed: " << maxSpeed << endl;
    }
};

int main() {
	cout <<"THE CODE IS WRITTEN BY MESUM ABBAS CT-238"<<endl;
    Car myCar(180);  
    myCar.displayMaxSpeed();
    myCar.accelerate(50);
    myCar.accelerate(150);  

    return 0;
}
