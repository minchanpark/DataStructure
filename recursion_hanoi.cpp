#include <iostream>
#include <cstdlib>

void hanoi(int n, char source, char end, char spare){
    if(n==1){
        printf("disk 1 from %c to %c\n", source, end);
    }
    else{
        hanoi(n-1, source, spare, end);
        printf("disk %d from %c to %c\n", n, source, end);
        hanoi(n-1, spare, end, source);
    } 
}

int main(){
    hanoi(3, 'A', 'B', 'C');
}