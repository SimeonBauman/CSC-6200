#include <iostream>
using namespace std;

int* getIndexes(int num[], int target, int arraySize);

int main()
{
    int num[] = { 2,11,15,7 };
    int target = 9;
    int* final = getIndexes(num, target, sizeof(num) / sizeof(num[0]));
    cout << final[0] << "," << final[1];
}

int* getIndexes(int num[], int target, int arraySize) {
    int* final = new int[2];
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = i + 1; j < arraySize; j++) {
            if (num[i] + num[j] == target) {
                final[0] = i; final[1] = j;
                return final;
            }
        }
    }

}

