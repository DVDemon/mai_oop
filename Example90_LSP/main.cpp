#include <iostream>
#include <memory>

class Rectangle {
protected:
    int width;
    int height;
public:

    Rectangle(int w, int h) : width(w), height(h) {
    };

    virtual void SetWidth(int value) {
        width = value;
    }

    virtual void SetHeight(int value) {
        height = value;
    }

    virtual int GetSquare() {
        return width * height;
    }
};

class Square : public Rectangle {
public:

    Square(int w, int h) : Rectangle(w, w) {
    };

    void SetWidth(int value) override {
        width = value;
        height = value;
    }

    void SetHeight(int value) override {
        width = value;
        height = value;
    }

};

int main() {
    std::shared_ptr<Rectangle> rec = 
            std::make_shared<Square>(2, 2);

    rec->SetWidth(3);
    rec->SetHeight(4);

    if (rec->GetSquare() != 12) std::cout << "Oops!" << std::endl;

    
    return 0;
}