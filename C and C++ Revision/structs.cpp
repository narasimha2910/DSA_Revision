#include <iostream>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    struct Rectangle r, r1={21, 22};
    r.length = 10;
    r.breadth = 20;

    printf("Area: %d\n", r1.breadth*r1.length);
    return 0;
}