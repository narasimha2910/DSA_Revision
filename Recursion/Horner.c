#include<stdio.h>

double e(int x, int n){
    static double s=1;
    if(n==0)
        return s;
    s = 1 + (double)x/(double)n *s; //type cast to double
    return e(x, n-1);
}

double forE(int x, int n){
    double s = 1;
    for (;n>0;n--)
    {
        s = 1 + (double)x/(double)n *s;
    }
    return s;
}

int main() {
    printf("%lf\n", e(1,10));
    printf("%lf\n", forE(1,10));
    return 0;
}