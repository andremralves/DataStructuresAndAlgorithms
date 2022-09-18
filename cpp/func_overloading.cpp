#include <iostream>

int max(int a, int b) {
    return (a>b) ? a : b;
}

// changing the parameters cretates a function overload
double  max(double a, double b) {
    return (a>b) ? a : b;
}

std::string max(std::string a, std::string b) {
    return (a>b) ? a : b;
}

int main (int argc, char *argv[])
{
    int ia = 5, ib = 10; 
    double da = 7.5, db = 3.25;
    std::string sa = "andre", sb = "pedro"; 
    
    std::cout << max(ia, ib) << "\n";
    std::cout << max(da, db) << "\n";
    std::cout << max(sa, sb) << "\n";

    return 0;
}
