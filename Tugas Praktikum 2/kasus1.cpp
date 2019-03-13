#include <iostream>
using namespace std;

int main()
{
    int Array[5] = {10, 11, 5, 27, 1};
    int max = Array[0];
    int i = 2;
    while(i < (sizeof(Array)/sizeof(Array[0]))){
        if(Array[i] > max){
            max = Array[i];
        }
        i++;
    }
    cout<<max;
}