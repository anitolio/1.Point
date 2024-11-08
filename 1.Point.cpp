#include <iostream>  
using namespace std;

class Point {
    int x;
    int y;
public:
    Point() {
        cout << "Construct\n";
        x = y = 0;
    }
    Point(int x1, int y1) {
        cout << "Construct by 2 param\n";
        x = x1;
        y = y1;
    }

    void Output() {
        cout << "X: " << x << "\tY: " << y << endl;
    }

    Point operator+(const Point& b) {
        return Point(this->x + b.x, this->y + b.y);
    }
    Point operator+(int a) {
        return Point(x + a, y + a);
    }
    friend Point operator+(int a, const Point& b) {
        return Point(b.x + a, b.y + a);
    }

    Point& operator+=(const Point& b) {
        this->x += b.x;
        this->y += b.y;
        return *this;
    }
    Point& operator+=(int a) {
        this->x += a;
        this->y += a;
        return *this;
    }

    Point operator++() {   
        this->x += 10;
        this->y += 10;
        return *this;
    }
    Point operator++(int) {  
        Point temp = *this;
        this->x += 10;
        this->y += 10;
        return temp;
    }

    Point operator*(int a) {
        return Point(this->x * a, this->y * a);
    }

    Point operator-(const Point& b) {
        return Point(this->x - b.x, this->y - b.y);
    }

    Point operator/(int scalar) {
        if (scalar == 0) {
            throw runtime_error("Division by zero");
        }
        return Point(this->x / scalar, this->y / scalar);
    }

    int GetX() {
        return x;
    }
    int GetY() {
        return y;
    }
    void SetX(int a) {
        x = a;
    }
    void SetY(int a) {
        y = a;
    }
};

int main() {
    Point a(1, 2);
    Point b(3, 4);

    Point c = a + b;
    c.Output(); 

    c = a + 10;   
    c.Output();   

    c = 10 + a;   
    c.Output(); 

    Point d = a - b;  
    d.Output(); 

    Point e = a * 10; 
    e.Output(); 

    try {
        Point f = a / 0; 
        f.Output();
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl; 
    }

    a += 10;
    a.Output();  

    a += b;   
    a.Output(); 

    Point preInc = ++a;  
    preInc.Output();   

    Point postInc = a++; 
    postInc.Output();   
    a.Output(); 

}