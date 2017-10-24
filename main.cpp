#include <iostream>
using namespace std;

class A {
public:
    A() {cout << "A ctor" << endl;}
    A(A& a) {cout << "A copy ctor" << endl;}
    virtual ~A() {cout << "A dtor" << endl;}
    virtual void f() {cout << "A f" << endl;}
};

class B : public A {
public:
    B() {cout << "B ctor" << endl;}
    ~B() {cout << "B dtor" << endl;}
    void f() {cout << "B f" << endl;}
};

class C : public B {
public:
    C() {cout << "C ctor" << endl;}
    ~C() {cout << "C dtor" << endl;}
    void f() {cout << "C f" << endl;}
};

class X {
public:
    X() {cout << "X ctor" << endl;}
    X(X& x) {cout << "X copy ctor" << endl;}
    ~X() {cout << "X dtor" << endl;}
    void f() {cout << "X f" << endl;}
};

X foo(A& a, X x) {
    cout << "*** in foo" << endl;
    A aa;
    aa = a;
    X xx(x);
    cout << "*** leaving foo" << endl;
    return xx;
}

int main() {
    cout << "*** starting main" << endl;
    A* a_ptr_to_a = new A;
    B* b_ptr_to_b = new B;
    C* c_ptr_to_c = new C;
    X x1;

    X* x_ptr_to_x = &x1;
    A* a_ptr_to_b = b_ptr_to_b;
    A* a_ptr_to_c = c_ptr_to_c;
    B* b_ptr_to_c = c_ptr_to_c;

    cout << "*** calls of f #1:" << endl;
    a_ptr_to_a->f();
    b_ptr_to_b->f();
    c_ptr_to_c->f();
    x_ptr_to_x->f();

    cout << "*** calls of f #2:" << endl;
    a_ptr_to_b->f();
    a_ptr_to_c->f();
    b_ptr_to_c->f();
    X x2;

    cout << "*** calling foo" << endl;
    x2 = foo(*a_ptr_to_a, x1);

    cout << "*** back in main" << endl;
    cout << "*** delete a_ptr_to_a:" << endl;
    delete a_ptr_to_a;

    cout << "*** delete b_ptr_to_b:" << endl;
    delete b_ptr_to_b;

    cout << "*** delete b_ptr_to_c:" << endl;
    delete b_ptr_to_c;

    cout << "*** leaving main" << endl;
    return 0;
}