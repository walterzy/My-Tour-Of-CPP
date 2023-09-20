//
// Created by walterzy on 2023-07-27.
//
#include <vector>
#include <iostream>

class Point {
private:
    int x_;
    int y_;

public:
    Point() : x_{0}, y_{0} {}
    
    Point(int xin, int yin) : x_{xin}, y_{yin} {}
    
    // 'elegant' setters
    void x(int xin) { x_ = xin; }
    void y(int yin) { y_ = yin; }
    
    // 'elegant' getters
    // ### const Member Functions (text excerpted from: Scott Meyers, "Effective C++ (2005)", Itens 3)
    // The purpose of 'const' on member functions is to identify which member functions may be invoked on `const objects`
    // These functions cannot modify an object (its member data).
    // They are important for two reasons:
    // 1. It is important to know which functions may modify an object and which may not.
    // 2. They make it possible to work with 'const' objects, which is a critical aspect in effective C++ code
    // when passing objects by reference-to-const. This technique is viable only if there are `const member functions`
    // with which to manipulate the resulting const-qualified objects.
    
    // Rule of Thumb: for any member function that does not modify the object, USE const.
    int x() const { return x_; }
    int y() const { return y_; }
    
    void print() const {
        cout << "x, y = " << x_ << ", " << y_ << endl;
    }
};


class Shape {
public:
    virtual Point center() const = 0; // pure virtual
    virtual void move(Point to) = 0;
    virtual void draw() const = 0; // draw on current "Canvas"
    virtual void rotate(int angle) = 0;
    virtual ~Shape() {} // destructor
    // ...
};


class Circle : public Shape {
public:
    Circle(Point p, int rad) : x{p}, r{rad} {} // constructor
    Point center() const override { return x; }
    void move(Point to) override { x = to; }
    void draw() const override;
    void rotate(int) override {} // nice simple algorithm

private:
    Point x; // center
    int r; // radius
};


class Smiley : public Circle { // use the circle as the base for a face
public:
    Smiley(Point p, int rad) : Circle{p,rad}, mouth{nullptr} { }
    ~Smiley();

    void move(Point to) override;
    void draw() const override;
    void rotate(int) override;

    void add_eye(Shape* s)
    {
        eyes.push_back(s);
    }

    void set_mouth(Shape* s);
    virtual void wink(int i); // wink eye number i
    // ...

private:
    vector<unique_ptr<Shape>> eyes; // usually two eyes
    unique_ptr<Shape> mouth;
};


void Smiley::draw() const
{
    Circle::draw();

    for (auto p : eyes)
        p->draw();

    mouth->draw();
}


enum class Kind { circle, triangle, smiley };

Shape* read_shape(istream& is) // read shape descriptions from input stream is
{
    // ... read shape header from is and find its Kind k ...
    switch (k) {
        case Kind::circle:
            // ... read circle data {Point,int} into p and r ...
            return unique_ptr<Shape>{new Circle{p, r}};

        case Kind::triangle:
            // ... read triangle data {Point,Point,Point} into p1, p2, and p3 ...
            return unique_ptr<Shape>{new Triangle{p1, p2, p3}};

        case Kind::smiley:
            // ... read smiley data {Point,int,Shape,Shape,Shape} into p, r, e1, e2, and m .
            Smiley * ps = unique_ptr<Shape>{new Smiley{p, r}};
            ps->add_eye(e1);
            ps->add_eye(e2);
            ps->set_mouth(m);
            return ps;
    }
}


void user()
{
    std::vector<unique_ptr<Shape>> v;

    while (cin)
        v.push_back(read_shape(cin));

    draw_all(v); // call draw() for each element
    rotate_all(v,45); // call rotate(45) for each element

    for (auto p : v) // remember to delete elements
        delete p;
}


void draw_all(vector<Shape *> & v)
{
    for_each(v.begin(), v.end(), [](Shape * p) { p->draw(); });
}


void draw_all(vector<Shape *> & v)
{
    for_each(v.begin(), v.end(), mem_fn(&Shape::draw));
}

