#include <stdio.h>
#include <stdlib.h>

int maxRec(int *);


int main(){
    int arr[]= {7,6,1,3,23,8,11,-3,4,19};
    printf("\n\n%d",maxRec(arr));

    return 0;
}

int maxRec(int *arr){
    int static i=0, max= 0, num;
    printf("%d ",*arr);

    if(i==9){
        i=0;
        return (*arr);
    }
    i++;
    
    num= maxRec(arr+1);
    if(max < num)
        max= num;
    return *arr;
}
