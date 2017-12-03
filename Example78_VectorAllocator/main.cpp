#include <cstdlib>
#include <vector>
#include <iostream>
#include <iterator>

template<typename T>
class Allocator {
public:
    //    typedefs
    typedef T value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

public:
    //    convert an allocator<T> to allocator<U>

    template<typename U>
    struct rebind {
        typedef Allocator<U> other;
    };

public:
    // inline - подстановочная функция (ни каких вызовов на стеке))

    inline explicit Allocator() {
    }

    inline ~Allocator() {
    }

    inline explicit Allocator(Allocator const&) {
    }

    template<typename U>
    inline explicit Allocator(Allocator<U> const&) {
    }

    //    address

    inline pointer address(reference r) {
        return &r;
    }

    inline const_pointer address(const_reference r) {
        return &r;
    }

    //    memory allocation

    inline pointer allocate(size_type cnt,
            typename std::allocator<void>::const_pointer = 0) {
        std::cout << "Allocate" << std::endl;
        return reinterpret_cast<pointer> (::operator new(cnt * sizeof (T)));
    }

    inline void deallocate(pointer p, size_type) {
        std::cout << "DeAllocate" << std::endl;
        ::operator delete(p);
    }

    //    size

    inline size_type max_size() const {
        return std::numeric_limits<size_type>::max() / sizeof (T);
    }

    //    construction/destruction

    inline void construct(pointer p, const T& t) {
        new(p) T(t);
    }

    inline void destroy(pointer p) {
        p->~T();
    }

    inline bool operator==(Allocator const&) {
        return true;
    }

    inline bool operator!=(Allocator const& a) {
        return !operator==(a);
    }
}; //    end of class Allocator 

class Foo {
private:
    int number;
public:

    Foo() : Foo(0) {
    };

    Foo(int n) : number(n) {
        std::cout << "Construct" << std::endl;
    };

    Foo(const Foo & other) : number(other.number) {
        std::cout << "Copy" << std::endl;

    };

    friend std::istream & operator>>(std::istream &is, Foo& foo);
    friend std::ostream & operator<<(std::ostream &os, const Foo& foo);
};

std::istream & operator>>(std::istream &is, Foo& foo) {
    is >> foo.number;
    return is;
};

std::ostream & operator<<(std::ostream &os, const Foo& foo) {
    os << foo.number;
    return os;
};

int main(int argc, char** argv) {
    typedef std::vector<Foo, Allocator < Foo>> vec;
    vec vector;

    // явное выделение памяти
    vector.reserve(10);


    std::istream_iterator<Foo> iter(std::cin);
    std::istream_iterator<Foo> eos;
    std::insert_iterator<vec> insert_iter(vector, vector.begin());
    std::copy(iter, eos, insert_iter);


    //std::ostream_iterator<Foo> out(std::cout, " ");
    //std::copy(vector.begin(), vector.end(), out);


    return 0;
}

