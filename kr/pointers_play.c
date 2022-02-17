/*
Interesting explanation on names and addresses of pointers:


https://stackoverflow.com/questions/2528318/how-come-an-arrays-address-is-equal-to-its-value-in-c#2528328
The name of an array usually evaluates to the address of the first element of the array, so array and &array have the same value. but different types, ...


https://stackoverflow.com/questions/15177420/what-does-sizeofarray-return/15177499#15177499
According to pointer mathematics rules when you add 1 to pointer variable it start points to next element of its own type that is the reason 10 byte differences because &str2 is array address.. 


*/

#include <stdio.h>


int main(void)
{
    int i, *pi;
    i = 7;
    pi = &i;
    printf(" i: %14d \t  &i: %p\n", i, &i);
    printf("pi: %p \t &pi: %p \t *pi: %14d\n", pi, &pi, *pi);

   char str2[10]  = {"Hello"};
   
   //According to pointer mathematics rules when you add 1 to pointer variable it start points to *next element of its own type*
   // str2 is a pointer to char - type is char, char is 1 byte, so str2+1 will increment by 1 byte
   // &str2 is the address of an array[10] of pointers to char - type is 10*char, so &str2+1 will increment by 10 bytes 
   
   printf("\n %p, %p\n",str2, str2+1);
   printf("\n %p, %p\n",(&str2), (&str2+1));

   printf("\n%p %c, %p %c\n",str2, *(str2), *(&str2), **(&str2));
   
    return 0;
}
