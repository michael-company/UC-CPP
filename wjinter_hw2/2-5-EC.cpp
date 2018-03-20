//Below is mostly from cppreference
//I pin-pointed the cases work and listed case doesn't work
//I demonstrated a few backgrounds which I am not sure if required

//a pure virtual method is declared but never define, so it has no body
struct a { virtual void f() = 0; };

struct Abstract {
    virtual void F() = 0; // pure virtual
    virtual void G() {}; // non-pure virtual
    ~Abstract() {
        G(); // okay, calls Abstract::g()
        // f(); // undefined behavior!
        Abstract::F(); // okay, non-virtual call
    }
};

//definition of the pure virtual function with nothing inside.
void Abstract::F() {}

struct Concrete : Abstract {
    void F() override {
        Abstract::F(); // OK: calls pure virtual function
    }
    void G() override {}
    ~Concrete() {
        G(); // okay, calls Concrete::g()
        F(); // okay, calls Concrete::f()
    }
};

struct Abstract2 : Concrete {
    void G() override = 0; // pure virtual overrider
}; // "Abstract2" is abstract

int main()
{
    //this doesn't compile and work
    //a::f();

    // Abstract a; // Error: abstract class
    Concrete b; // OK
    Abstract& A = b; // OK to reference abstract base

    //this compiles and works
    A.F(); // virtual dispatch to Concrete::f()
}