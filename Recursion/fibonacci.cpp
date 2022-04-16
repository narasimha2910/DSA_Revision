#include <iostream>

using namespace std;

int M[11];

int fib(int n){
    if(n<=1)
        return n;
return fib(n-2) + fib(n-1);
}

int fibIter(int n){
    int t0=0, t1=1, s, i;
    if(n<=1)
        return n;
    for(i=2;i<=n;i++){
        s = t0 + t1;
        t0=t1;
        t1=s; 
    }
    return s;
}

int fibMem(int n){
    if(n<=1)
    {
        M[n] = n;
        return n;
    }
    else{
        if(M[n-2] == -1)
            M[n-2] = fibMem(n-2);
        if(M[n-1] == -1)
            M[n-1] = fibMem(n-1);
        M[n] = M[n-1] + M[n-2];
        return M[n-2] + M[n-1];
    }
}

int main() {
    for(int i=0; i<10; i++)
        M[i] = -1;
    cout<<fib(10)<<endl;
    cout<<fibIter(10)<<endl;
    cout<<fibMem(10)<<endl;
    cout<<M[10]<<endl;
    return 0;
}