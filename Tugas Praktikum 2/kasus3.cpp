#include <iostream>
using namespace std;

int main()
{
    int Array[10] = {1,2,3,4,5,6,7,8,9,10};
    int i , j , mid;
    bool found;
    int idx;
    int y = 5;

    i = 1;
    j = sizeof(Array)/sizeof(Array[0]);
    found = false;
    while(!found && i <= j){
        mid  = (i + j)/2;
        if(Array[mid] == y){
            found = true;
        }
        else if(Array[mid]< y){
                i = mid + 1;
        }
        else{
            j = mid - 1;
        }
    }
    if(found == true){
        idx = mid;
    }
    else{
        idx = 0;
    }
    cout<<idx;
    return 0;
}