#include <iostream>
using namespace std;

int getSize(int array[][5]);

int main()
{
    int array[4][5] = {
        {0,0,3,0,4},
        {0,0,5,7,0},
        {0,0,0,0,0},
        {0,2,6,0,0}
    };

    int sparseMatrix[3][6];
    int index = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++) {
            if (array[i][j] != 0) {
                sparseMatrix[0][index] = i;
                sparseMatrix[1][index] = j;
                sparseMatrix[2][index] = array[i][j];
                index++;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        cout << sparseMatrix[2][i] << ", ";
    }
}
