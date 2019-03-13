#include <iostream>
using namespace std;

int main()
{

  int Array[5] = {1,2,11,8,10};
  int i = 1;
  int y = 10;
  int idx;
  int found = false;

  while(i <= (sizeof(Array)/sizeof(Array[0])) && !found){
    if(Array[i] == y){
        found = true;
    }

    else{
        i++;
    }
  }
  if(found == true){
    idx = i;
  }
  else{
    idx = 0;
  }
  cout<<idx;
  return 0;
}
