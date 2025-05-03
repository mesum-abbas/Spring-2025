#include <iostream>
using namespace std;

class Shape {
	protected :
		int numof_sides;
		float area;
    public :
		Shape(int no_sides , float ar) : numof_sides(no_sides) ,area(ar) {}

        int getnoof_sides(){
            return numof_sides;
        }

        float getarea(){
            return area;
        }

        void setnumof_sides(int sides){
            numof_sides = sides;
        }

        void setarea(float a){
            area = a;
        }

};

class Rectangle : public Shape {
	protected :
		double length;
		double width;
    public :
		Rectangle(double len , double wid) : Shape(4 , 0) , length(len) ,width(wid) {}

        void generatearea(){
             area = length * width ;
        }
};

class Circle : public  Shape  {
	protected :
		double radius;
        public :
		Circle(double rad ) : Shape (0, 0) , radius(rad) {}

        void generatearea(){
            area = 3.142 * radius * radius  ;
       }
};

class Triangle : public Shape  {
	protected :
		double base;
		double height;
        public :
        	Triangle(double ba , double ht) : Shape (3,0), height(ht) , base(ba) {}

            void generatearea(){
                area = (base * height)/2;
           }
};

class Square  : public Rectangle  {
	public :
        	Square(float side) : Rectangle (side ,side ) {
                numof_sides = 4 ;
            }

            void checkside(){
                if(length == width ){
                    cout << " its Square " <<endl;
                }
                else {
                    cout << " Its not Squre " << endl;
                }
           }
           void generatearea() {
            area = length * width ;
       }
};



int main(int argc, char** argv) {
    cout << " The code is written by MESUM ABBAS CT-238" << endl ;
    Rectangle rect(5,5);
    rect.generatearea();
    cout << " Rectangle area " << rect.getarea() << endl ;
    
    Circle crl(4);
    crl.generatearea();
    cout << "Circle area " << crl.getarea() << endl ;

    Square sq(4);
    sq.checkside();
    sq.generatearea();
    cout << " Square area " << sq.getarea() << endl ;

	return 0;
}
