#include<iostream>

using namespace std;

int fact(int n){
    if(n==0)
        return 1;
    return fact(n-1) * n;
}

int C(int n, int r){
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);
    return t1 / (t2*t3);
}

int Crec(int n, int r){
    if(r==0 || n==r)
        return 1;
    return Crec(n-1, r-1) + Crec(n-1, r);
}

int main() {

    cout<<C(2,1)<<endl;
    cout<<Crec(2,1)<<endl;

    return 0;
}