#include <iostream>
using namespace std;

int main()

{
    int Array[7] = {10,5,3,9,6,1,4};
      int panjang = sizeof(Array)/sizeof(Array[0]);

    int i,j,imaks,temp;
    for(i = panjang ; i >= 2 ; i--){
        imaks = 1;
        for(j= 2; j <i ; j++){
            if(Array[j] > Array[imaks]){
                imaks = j;
            }
        }
        temp = Array[i];
        Array[i] = Array[imaks];
        Array[imaks] = temp;
    }
    for(int x = 0 ; x<= panjang; x++){
            cout<<Array[x]<<endl;

    }

}