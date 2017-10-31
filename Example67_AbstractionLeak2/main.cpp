#include <iostream>

class Figure {
public:
    virtual double Square() = 0;
    virtual double Volume() = 0;

    virtual ~Figure() {
    };
};

class Circle : public Figure {
protected:
    const double R;
public:

    Circle(double r) : R(r) {
    };

    double Volume() override {
        return 0.0;
    };

    double Square() override {
        return 3.14 * R * R;
    };

};

class Sphere : public Figure {
protected:
    const double R;
public:

    Sphere(double r) : R(r) {
    };

    double Volume() override {
        return 3.14 * R*R * R*4/3;
    };

    double Square() override {
        return 0;
    };
};

class Array {
private:
    static const size_t SIZE = 10;
    Figure* array[SIZE];
public:

    Array() {
        for (int i = 0; i < SIZE; i++) array[i]=nullptr;
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
            if(array[i]->Square()) std::cout << "Square:" << array[i]->Square() << std::endl;
            if(array[i]->Volume()) std::cout << "Volume:" << array[i]->Volume() << std::endl;
        }


    return 0;
}

