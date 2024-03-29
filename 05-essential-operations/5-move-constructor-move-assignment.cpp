
#include <iostream>     // std::cerr
#include <stdexcept>    // std::length_error
#include <algorithm>    // std::copy


class Vector {
private:
    // default member initialization
    long size_ = 0;
    double *elem_ = nullptr;

public:
    Vector() {
        std::cout << "default constructor for Vector\n";
    }
    
    // constructor: establish invariant (pre-conditions), 
    // acquire resources (e.g., allocations on heap)
    explicit Vector(long size) {
        std::cout << "ordinary constructor for Vector\n";
        
        if (size < 0) {
            throw std::length_error{"Vector constructor: negative size"};
        }
        
        size_ = size;
        elem_ = new double[size];
        for (long i = 0; i < size_; i++)
            elem_[i] = 0;
    }
    
    
    Vector(std::initializer_list<double> lst)
            : elem_{new double[lst.size()]}, size_{static_cast<int>(lst.size())} {
        std::cout << "initializer-list constructor for Vector\n";
        
        std::copy(lst.begin(), lst.end(), elem_); // copy from lst into elem (§12.6)
    }
    
    
    // destructor: release resources
    ~Vector() {
        std::cout << "Vector destructor\n";
        delete[] elem_;
    }
    
    
    long size() const {
        return size_;
    }
    
    void print() const {
        std::cout << "size = " << size() << std::endl;
        for (long i = 0; i < size(); i++)
            std::cout << "[" << i << "] = " << elem_[i] << std::endl;
        std::cout << "\n";
    }
    
    
    // copy constructor
    Vector(const Vector& v) : elem_{new double[v.size_]}, size_{v.size_} {
        std::cout << "Copy Constructor for Vector\n";
        
        for (int i = 0; i != v.size_; i++) // copy elements
            elem_[i] = v.elem_[i];
    }
    
    
    // copy assignment
    Vector& operator=(const Vector& v) {
        std::cout << "Copy Assignment for Vector\n";
        
        double* p = new double[v.size_];
        
        for (int i = 0; i != v.size_; i++) // copy elements
            p[i] = v.elem_[i];
        
        delete[] elem_; // delete the object data
        
        elem_ = p;
        size_ = v.size_;
        
        return *this;
    }
    
        
    Vector operator+(const Vector& v) const {
        std::cout << "operator+\n";
    
        if (size_ != v.size_)
            std::cout << "Throw a given exception\n";
        
        Vector res(size_); // it calls the ordinary constructor
        for (int i = 0; i < size_; i++)
            res.elem_[i] = elem_[i] + v.elem_[i];
    
        // since we defined a Move Assignment, 
        // the compiler know that it will be returned a temporary object,
        // then the Move Assignment is called automatically 
        // afterwards, it is destroyed
        return res;
    }
    
    
    // Move Constructor
    // it does not take a const argument: after all, a move constructor is supposed to 
    // remove the value from its argument.
    Vector(Vector&& v) :
            elem_{v.elem_}, // "grab the elements" from v: elem_ now points to v.elem_
            size_{v.size_}
    {
        std::cout << "Move Constructor for Vector\n";
    
        v.elem_ = nullptr; // now v has no elements
        v.size_ = 0;
    }
    
    
    // Move Assignment
    Vector& operator=(Vector&& v) {
        std::cout << "Move Assignment for Vector\n";
    
        // if the object isn't being called on itself
        if (this != &v) {
            delete[] elem_; // delete the object data
            
            // "Move" v's data into the current object
            elem_ = v.elem_;
            size_ = v.size_;
            
            // Mark the v object as "empty"
            v.elem_ = nullptr; // now v has no elements
            v.size_ = 0;
        }

        return *this;
    }
};


Vector foo() {
    // since we defined a Move Assignment, the compiler know that it will be returned 
    // a temporary object, then the Move Assignment is called automatically
    // afterwards, it is destroyed
    return Vector{-1, -1, -1};
}


int main() {
    std::cout << "x\n";
    Vector x{1, 2, 3};
    x.print();
    
    std::cout << "y\n";
    Vector y = {10, 20, 30};
    y.print();
    
    std::cout << "z\n";
    Vector z = {100, 200, 300};
    z.print();
    
    Vector r;
    std::cout << "r = x + y + z\n";
    r = x + y + z; // it calls the Move Assigment
    r.print();

    std::cout << "foo()\n";
    foo(); // it calls the initializer-list constructor

    std::cout << "\ns = foo()\n";
    Vector s = foo(); // there is a compilation optimization; the values are put directly in s;
                      // there is no calls for constructor, move/copy assigment, destroyer 
                      // (for the temp object inside foo())
    s.print();
    
    std::cout << "t = foo()\n";
    Vector t; // it calls the default constructor
    t = foo(); // it calls the Move Assignment lastly
    t.print();
    
    std::cout << "Vector a = std::move(x)\n";
    Vector a = std::move(x); // it calls the Move Constructor
    a.print();
    
    std::cout << "x after std::move\n";
    x.print();
    
    std::cout << "b = std::move(y)\n";
    Vector b; // it calls the default constructor
    b = std::move(y); // it calls the Move Assigment
    b.print();
    
    std::cout << "y after std::move\n";
    y.print();
    
    return 0;
}
