#include <stdio.h>
int main()
{
    int  a,b=10, c=100;
    printf("Please enter your number: ");

    scanf("%d", &a);

    if( a > b && a < c){
        printf("in the interval \n");
    }else {
        printf("not in the interval \n");
    }
    return 0;
}