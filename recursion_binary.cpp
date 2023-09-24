#include <iostream>

using namespace std;

int binarySearch(int list[], int key, int lo, int hi){
    if(lo>hi) {return -1;}
    int mi=(lo+hi)/2;
    if(key==list[mi]) return mi;
    if(key<list[mi]){
        return binarySearch(list, key, lo, mi-1);
    }
    else{
        return binarySearch(list, key, mi+1, hi);
    }
}

int main(){
    int list[]={2,5,8,9,16,23,31,56,62,71};
    int index;
    index=binarySearch(list, 23, 0, 9);

    cout<<index<<endl;
}