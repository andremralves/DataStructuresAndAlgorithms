#include <iostream>

int main (int argc, char *argv[])
{

    // store the lambda func
    auto func = [](int a, int b) {
        return a*b;
    };

    // Call the lambda func and store the result
    auto result = [](int a, int b) {
        return a*b;
    }(5, 7);

    // specify the return type
    auto boolResult = [](int a, int b)->bool {
        return (a*b)>10 ? true : false;
    }(5, 7);

    std::cout << func(10, 15) << std::endl;
    std::cout << result << std::endl;
    std::cout << boolResult << std::endl;

    return 0;
}

