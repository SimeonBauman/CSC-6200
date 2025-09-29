#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonSubstring(const string& firstStr, const string& secondStr) {
    int lenFirst = firstStr.length();
    int lenSecond = secondStr.length();

    vector<vector<int>> suffixTable(lenFirst + 1, vector<int>(lenSecond + 1, 0));

    int maxLength = 0;
    int endPosFirst = 0;

    for (int i = 1; i <= lenFirst; i++) {
        for (int j = 1; j <= lenSecond; j++) {
            if (firstStr[i - 1] == secondStr[j - 1]) {
                suffixTable[i][j] = suffixTable[i - 1][j - 1] + 1;

                if (suffixTable[i][j] > maxLength) {
                    maxLength = suffixTable[i][j];
                    endPosFirst = i - 1;
                }
            }
            else {
                suffixTable[i][j] = 0;
            }
            cout << suffixTable[i][j] << ", ";
        }
        cout << endl;
    }
    return firstStr.substr(endPosFirst - maxLength + 1, maxLength);
}

int main() {
    string firstStr;
    string secondStr;
    cin >> firstStr;
    cin >> secondStr;

    cout << longestCommonSubstring(firstStr, secondStr) << endl;

    return 0;
}
