#include<iostream>

using namespace std;

int power(int base, int expo){
    if (expo == 0 )
        return 1;
    return power(base, expo-1) * base;
}

int optim(int base, int expo){
    if(expo == 0)
        return 1;
    if(base%2==0)
        return power(base*base, expo/2);
    return base * power(base*base, (expo-1)/2);
}

int main() {
    cout<<power(10,0)<<endl;
    cout<<optim(10,0)<<endl;
    return 0;
}