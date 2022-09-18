#include <iostream>
    
int main (int argc, char *argv[])
{
    int val = 5;    
    int& ref = val;
    int *pointer = &val;
    ref = 10;
    std::cout << "val: " << val << std::endl;
    std::cout << "ref: "<< ref << std::endl;
    std::cout << "pointer: "<< *pointer << std::endl;
    return 0;
}
