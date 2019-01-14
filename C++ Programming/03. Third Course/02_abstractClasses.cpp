#include <iostream>

using namespace std;

/*An Abstract class is a class that has function
declaration but not executable code in them.*/

class Shape {
    //---Pure virtual functions----
    virtual void setX(int xcor) = 0;
    virtual void setY(int ycor) = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual void draw() const = 0;
};
class Circle : public Shape {
private:
    int x, y, radius;
public:
    Circle(int xcor, int ycor, int r) {
        x = xcor;
        y = ycor;
        radius = r;
    }
    virtual void setX(int xcor) {
        x = xcor;
    }
    virtual void setY(int ycor) {
        y = ycor;
    }
    void setRadius(int r) {
        radius = r;
    }
    virtual int getX() const {
        return x;
    }
    virtual int getY() const {
        return y;
    }
    virtual int getRadius() const {
        return radius;
    }
    virtual void draw() const {
        cout << "Drawing Circle at: " <<
        getX() << ", " << getY() <<
        " with a radius of: " << getRadius() << endl;
    }
};
int main() {

    Circle c(2,3,5);
    c.draw();
    return (0);
}
