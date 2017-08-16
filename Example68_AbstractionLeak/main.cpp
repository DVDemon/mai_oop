#include <iostream>
#include "tuple.h"

class Circle {
protected:
    const double R;
public:

    Circle(double r) : R(r) {
    };

    double Square() {
        return 3.14 * R * R;
    };

    virtual ~Circle() {
    };

};

class Sphere {
protected:
    const double R;
public:

    Sphere(double r) : R(r) {
    };

    double Volume() {
       return 3.14 * R*R * R*4/3;
    };

    virtual ~Sphere() {
    };
};

template <class T> class Array {
private:
    static const size_t SIZE = 10;
    T* array[SIZE];
public:

    Array() {
    }

    T*& operator[](size_t index) {
        return array[index];
    }

    size_t size() {
        return SIZE;
    }

    virtual ~Array() {
        for (int i = 0; i < SIZE; i++) delete array[i];
    }
};

int main(int argc, char** argv) {
    tuple<Circle, Circle, Sphere, Sphere> 
      t(Circle(1), Circle(2), Sphere(1), Sphere(2));

    std::cout << "Square:" << get<0>(t).Square() << std::endl;
    std::cout << "Volume:" << get<3>(t).Volume() << std::endl;

    Array<Circle> array_circle;
    array_circle[0] = new Circle(1);
    array_circle[1] = new Circle(2);
    for (int i = 0; i < array_circle.size(); i++)
        if (array_circle[i] != nullptr)
            std::cout << "Square:" << array_circle[i]->Square() << std::endl;

    Array<Sphere> array_sphere;
    array_sphere[0] = new Sphere(1);
    array_sphere[1] = new Sphere(2);
    for (int i = 0; i < array_sphere.size(); i++)
        if (array_sphere[i] != nullptr)
            std::cout << "Volume:" << array_sphere[i]->Volume() << std::endl;

    return 0;
}

