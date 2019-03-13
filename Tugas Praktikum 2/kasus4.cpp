#include <iostream>
using namespace std;

int main()
{
	int Array[7] = {1, 3, 4, 8, 10, 13, 17};

	int i, j, insert;

	for (i = 2; i < (sizeof(Array)/sizeof(Array[0])); i++){
		insert = Array[i];
		j = i;

		while (j < i && Array[j - 1] > insert){
			Array[j] = Array[j - 1];
			j = j - 1;
		}

		Array[j] = insert;
		cout<<insert;
	}

    return 0;
}