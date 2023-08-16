#include <stdio.h>


int d2h (int y){
    return ("%X", y);
}
int main(){

    int x;
    x = d2h(26);

    printf("%d", x);
}