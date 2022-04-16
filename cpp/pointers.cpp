#include <iostream>
using namespace std;

int main (int argc, char *argv[])
{
    int a = 5;
    int *ptr = &a; 
    int **ptr1 = &ptr; 

    // printing pointers 
    cout << "Printing pointers\n";
    cout << ptr1 << "\n";
    cout << *ptr1 << "\n";
    cout << **ptr1 << "\n";
    printf("%d\n", **ptr1);

    // Array
    int arr[] = {1, 2, 3, 4, 5};

    cout << "Printing Array\n\n";
    // print using []
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
    }
    cout << "\n";

    // print using pointers
    for (int i = 0; i < 5; i++) {
        cout << *(arr+i);
    }
    cout << "\n\n";

    // 2D Array
    int twoDarray[5][5] = {
        {1, 2, 3, 4, 5}, 
        {2, 7, 87, 1, 50},
        {19, 28, 31, 42, 54},
        {18, 2, 30, 84, 15},
        {71, 2, 93, 24, 55},
    };

    cout << "Printing 2D Array\n\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << twoDarray[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << *(*(twoDarray+i)+j) << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}
