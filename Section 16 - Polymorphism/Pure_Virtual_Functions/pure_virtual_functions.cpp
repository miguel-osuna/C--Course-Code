/*
	Purpose: Demonstrating Pure Virtual Functions. 
	Author: Miguel Osuna
	Date: 5/29/2019
*/

#include <iostream>
#include <vector>
using namespace std;

// Abstracted Class
class Shape
{
public:
    virtual void draw() = 0; // Pure Virtual Function
    virtual void rotate() = 0; // Pure Virtual Function
    virtual ~Shape() {} // Virtual Shape Destructor
};

// Abstracted Class
class Open_Shape: public Shape
{
public: 
    virtual ~Open_Shape() { } // Virtual Open_Shape Destructor
};

// Abstracted Class
class Closed_Shape: public Shape
{
public:
    virtual ~Closed_Shape() { } // Virtual Close_Shape Destructor
};

class Line: public Open_Shape
{
public:
    // We need to specify the function override so the class can be Concrete
    virtual void draw() override
    {
        cout << "Draw a Line" << endl;
    }

    virtual void rotate() override
    {
        cout << "Rotate a Line" << endl;
    }
};

class Circle: public Closed_Shape
{
public:
    // We need to specify the function override so the class can be Concrete
    virtual void draw() override
    {
        cout << "Draw a Circle" << endl;
    }

    virtual void rotate() override
    {
        cout << "Rotate a Circle" << endl;
    }
    virtual ~Circle() { } // Virtual Circle Destructor
};

class Square: public Closed_Shape
{
public:
    // We need to specify the function override so the class can be Concrete
    virtual void draw() override
    {
        cout << "Draw a Square" << endl;
    }

    virtual void rotate() override
    {
        cout << "Rotate a Square" << endl;
    }
    virtual ~Square() { } // Virtual Square Destructor
};

int main()
{
    /*
    cout << "-----Shape-----" << endl;
    Shape s; // Compiler ERROR
    Shape *shape_ptr = new Shape(); // Compiler ERROR

    cout << "-----Open Shape-----" << endl;
    Open_Shape o; // Compiler ERROR
    Open_Shape *op_ptr = new Open_Shape();

    cout << "-----Closed Shape-----" << endl;
    Closed_Shape o; // Compiler ERROR
    Closed_Shape *op_ptr = new Closed_Shape(); // Compiler ERROR
    */

    // We can still use 'Shape' class pointers to point to Derived clases instances
    // Using 'Shape' class pointers let's us apply dynamic binding, so we can call 
    // functions on run-time
    cout << "\n-----Shape Pointers-----" << endl;
    Shape *p1 = new Line();
    Shape *p2 = new Circle();
    Shape *p3 = new Square();

    vector<Shape *> pointers;
    pointers.push_back(p1);
    pointers.push_back(p2);
    pointers.push_back(p3);

    for(const auto &pointer: pointers)
    {
        pointer->draw();
        pointer->rotate();
        cout << endl;
    }

    return 0;
}