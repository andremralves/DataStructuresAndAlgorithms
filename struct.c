#include <stdio.h>

/*
struct [structure tag] {

   member definition;
   member definition;
   ...
   member definition;
} [one or more structure variables];  
 */

//basic struct
struct Struct1{
    int a; 
};

// creates an alias
typedef struct {
    int a; 
}Struct2;

//anonymous struct
struct {
    int a; 
}Struct3;//create a variable


int main ()
{
    struct Struct1 s1; 
    Struct2 s2; 
    Struct3.a = 15;
    s1.a = 5;
    s2.a = 10;
    printf("%d\n", s1.a);
    printf("%d\n", s2.a);
    printf("%d\n", Struct3.a);
    return 0;
}

