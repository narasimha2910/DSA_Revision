#include <iostream>

using namespace std;

int glo = 0;

int fun(int n){
    if(n>0){
        return fun(n-1) + n;
    }
    return 0;
}

int fun1(int n){
    static int x = 0;
    if(n>0){
        x++;
        return fun1(n-1) + x;
    }
    return 0;
}

int fun2(int n){
    if(n>0){
        glo++;
        return fun2(n-1) + glo;
    }
    return 0;
}

int main() {
    int r = 5;
    cout<<fun(r)<<endl;
    cout<<fun1(r)<<endl;
    cout<<fun2(r)<<endl;
    cout<<fun2(r)<<endl;
    return 0;
}