#include <iostream>

class Figure {
public:
    virtual double Square() = 0;

    virtual ~Figure() {
    };
};

class Circle : public Figure {
protected:
    const double R;
public:

    Circle(double r) : R(r) {
    };

    double Square() override {
        return 3.14 * R * R;
    };

};

class Sphere : public Circle {
public:

    Sphere(double r) : Circle(r) {
    };

    double Volume() {
        return 3.14 * R*R * R*4/3;
    };
};

class Array {
private:
    static const size_t SIZE = 10;
    Figure* array[SIZE];
public:

    Array() {
    }

    Figure*& operator[](size_t index) {
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

    Array array;
    array[0] = new Circle(1);
    array[1] = new Circle(2);
    array[2] = new Sphere(1);

    for (int i = 0; i < array.size(); i++)
        if (array[i] != nullptr) {
            std::cout << "Square:" << array[i]->Square() << std::endl;
            // abstraction leak
            Sphere *sphere = dynamic_cast<Sphere*> (array[i]);
            if (sphere != nullptr)
                std::cout << "Volume:" << sphere->Volume() << std::endl;
        }



    return 0;
}

