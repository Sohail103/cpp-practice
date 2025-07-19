# OOP Notes for C++

If you create a dynamically allocated inherited class object using a pointer for the base class, then call delete on the base class pointer pointing to the inherited object - only the destructor for the base class part of the object will be called - this is why we need virtual destructors

destructors are called in the order of most inherited->base class
constructors are called in the order of base class->inherited classes

marking an inherited class as final - no other classes can inherit from it
marking a virtual function as final - no more overriding in inheriting classes
marking a virtual function as override - explicitly stating that the virtual function is an override 

default arguments in virtual functions are dangerous because - 
default arguments are statically resolved by the compiler whereas virtual functions (polymorphism) are dynamically resolved during run time
suppose you make an object of a derived class using a pointer for a base class - the default arguments used will be of the base class but the virtual function used will be of the derived class
therefore - default arguments depend on the pointer type (base class pointer or derived class pointer) whereas which virtual function to use is resolved at run time

copy constructors are called even when you try to make a collection (array) of objects of a class - also when passing an object to a function as a parameter

if you use a base class pointer to represent an inherited class object - you can only use polymorphic or virtual functions
to use all the functions of the derived class object, use a dynamic cast

if you use a base class pointer to represent an inherited class object - calling delete *baseclassptr will only call the destructor for the base class if your destructors are not marked as virtual - may lead to memory leaks if constructors for your objects dynamically allocate memory

can cast a base class pointer to a derived class pointer using the ```dynamic_cast<derived_class_type*>(base_class_ptr);``` - always check if cast was successful before using the pointer - the dynamic_cast returns a nullptr if it failed
- this can be used to call non-virtual functions of inherited classes through a base class pointer

no such thing as a null reference - cant do pointer checks like in previous case - gives undefined behavior

can dynamic cast references the same way (Eg: Feline& feline_ref {dynamic_cast<Feline&>(animal_ref)};) - only issue being that you can't check for null references to see if the dynamic cast passed or failed - therefore prefer pointers

can dynamically cast a base class reference to an inherited class pointer also - best way to do it if you have a reference - this way you can even check if the cast was successful or not

calling virtual functions from constructors or destructors gives static binding results - this is because the base constructor is called first before the inherited part of the object is built so it calls whatever version of the virtual function is available (the base class object method which therefore leads to static binding)
- instead - first build the object, then call the virtual method on the object if the virtual method was supposed to act as a constructor and set up some values - dynamic binding results
- instead of calling virtual functions from the destructor - call the virtual function before the destructor is called for the object - dynamic binding results

pure virtual functions - example shape-> circle
                                      |-> rectangle
and you have functions to calculate area and perimeter in the base shape class - but no implementation to find the area and perimeter in the base class - the functions are meant to be overriden by the base class - called a purely virtual method 
- dont have to put in implementations for these functions in the base class - compiler will not look for the base class implementation 
To declare pure virtual functions: ```virtual double perimeter() const = 0;```
If you're inheriting from an abstract class make sure you explicitly override every single pure virtual method even if youre not using it in that specific inherited class otherwise the inherited class will become an abstract class

once you set up even 1 purely virtual function in the class - the class becomes an abstract class - cant create objects of this class anymore - dont have to put in implementations for the inheriting downstream classes
- can still use base pointers to manage derived objects
- derived classes must explicitly override all the pure virtual functions from the abstract parent class - otherwise the derived classes themselves become abstract
- cant call the pure virtual functions from the constructor of the abstract class

```typeid(*base_class_ptr).name()``` returns the name of the inherited class (dynamically)

Abstract classes as interfaces:
- an interface can be modelled as an abstract class with pure virtual functions and no member variables
- an interface is a specification of something that will be fully implemented in a derived class but the specification itself resides in the abstract class

Useful interfaces:
- StreamInsertable Interface - inserts data into std::cout streams 
- StreamInsertable is an abstract class with virtual function specified like this:
```
class StreamInsertable{
    friend std::ostream& operator<<(std::ostream& out, const StreamInsertable& operand) {
        operand.stream_insert(out);
        return out;
    }
  public:
    virtual void stream_insert(std::ostream& out) const = 0;
};
```
- all other classes inherit from class StreamInsertable and define their implementation of the ```virtual void stream_insert(std::ostream& out)``` function

- Example Point class that inherits from he interface StreamInsertable:
```
class Point: public StreamInsertable{
  public:
    Point() = default;
    Point(double x, double y): m_x(x), x_y(y) {}
    virtual void stream_insert (std::ostream& out) const override {
    out << "Point = " << m_x << ", " << m_y << "\n";
    }
  private:
    double m_x;
    double m_y;
};
```

In a complete inheritance hierarchy, the base class (eg: animals) can inherit from the interface StreamInsertable and then all inherited classes from animals can define their implementation of the ```stream_insert``` function and makes all objects printable to cout - good because now we dont have to define overloads for operator<< everytime

```#include <memory>``` to use smart pointers

unique pointers - scoped pointers - memory is freed when the pointer goes out of scope - called unique pointers because you cant have two unique pointers
- this is because if you have 2 unique pointers and both are pointing to the same memory location and one goes out of scope, it frees that allocated memory and now the 2nd unique pointer is not pointing to valid memory

```std::unique_ptr<Entity> entity = std::make_unique<Entity>();``` - to declare a unique pointers
but ```std::unique_ptr<Entity> entity(new Entity());``` will also compile correctly - main reason not to do this is exception safety

```std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();``` - to declare a shared pointer - implemented using reference counting - delete memory when reference count becomes 0
but ```std::shared_ptr<Entity> sharedEntity (new Entity());``` would also compile correctly - dont do this because the shared pointer has to allocate another block of memory called the control block where it stores the reference count. If you do new Entity() yourself and then the shared pointer separately allocated the control block it is less efficient than just letting it allocate both blocks together
can copy a shared pointer by doing: ```std::shared_ptr<Entity> e0 = sharedEntity;```

a weak pointer can take on a value from a shared pointer without increasing the reference count.
can be declared like ```std::weak_ptr<Entity> weakEntity = sharedEntity;``` - good for cases where you dont want to take ownership of the data - lets you check whether a memory location is still valid without trying to keep it valid

Can call object functions on this pointer like how you would with a regular pointer, eg: ```entity->Print();```
