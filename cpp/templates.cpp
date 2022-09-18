#include <iostream>
#include <string>
#include <cstring>

template <typename T> T maximum(T a, T b);
template <typename T> T multiply(T a, T b);
// Especialization to compare char pointers
template <> const char * maximum<const char *> (const char *a, const char *b);

int main (int argc, char *argv[])
{

    int ia = 5, ib = 10;
    double da = 5, db = 10;
    std::string sa = "andre", sb = "pedro";
    const char *ca = "bob";
    const char *cb = "Mike";

    std::cout << maximum(ia, ib) << std::endl;
    std::cout << maximum(da, db) << std::endl;
    std::cout << maximum(sa, sb) << std::endl;
    std::cout << maximum(ca, cb) << std::endl;
        
    return 0;
}


template <typename T> T maximum(T a, T b) {
    return (a>b) ? a : b;
}

template <>
const char * maximum<const char *> (const char *a, const char *b) {
    return (std::strcmp(a, b) > 0) ? a : b;
}

template <typename T> T multiply(T a, T b) {
    return a * b;
}
