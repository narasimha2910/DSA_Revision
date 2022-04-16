#include <iostream>

using namespace std;

int main() {
    int A[5];
    for (int i=0; i<5; i++)
        A[i] = i;

    for (int i:A)
    {
        cout<< i <<endl;
    }
    

    cout << sizeof(int);
}