#include <iostream>
#include "dummy.h"

int main() {
    dummy one;
    one.print();
    std::cout<<one.add(5)<<endl;
    return 0;
}
