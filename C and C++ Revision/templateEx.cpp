#include <iostream>

using namespace std;

template <class T>
class Arithmetic {
    private:
        T a, b;
    public:
        Arithmetic(T a, T b);
        T add();
        T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b){
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add() {
    return a+b;
} 

template <class T>
T Arithmetic<T>::sub() {
    return a-b;
} 

int main() {
    Arithmetic<int> a(10, 20);
    Arithmetic<float> b(10.1, 20);

    cout<<a.add()<<endl;
    cout<<b.sub()<<endl;

    return 0;
}