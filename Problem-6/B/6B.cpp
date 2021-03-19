//
// Created by wadeh on 19/03/2021.
//


#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    int length, width;
    char presidentColor;
    cin >> length >> width >> presidentColor;

    auto matrix = vector<vector<char>>();

    for (int i = 0; i < length; i++) {
        matrix.push_back(vector<char>());
        string officeRow;
        cin >> officeRow;
        for (int j = 0; j < width; j++) {
            matrix[i].push_back(officeRow[j]);
        }
    }

    auto deputies = set<char>();

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            if (matrix[i][j] == presidentColor) {
                if (i - 1 >= 0) {
                    if (matrix[i - 1][j] != '.' && matrix[i - 1][j] != presidentColor) {
                        deputies.insert(matrix[i - 1][j]);
                    }
                }
                if (i + 1 < length) {
                    if (matrix[i + 1][j] != '.' && matrix[i + 1][j] != presidentColor) {
                        deputies.insert(matrix[i + 1][j]);
                    }
                }
                if (j - 1 >= 0) {
                    if (matrix[i][j - 1] != '.' && matrix[i][j - 1] != presidentColor) {
                        deputies.insert(matrix[i][j - 1]);
                    }
                }
                if (j + 1 < width) {
                    if (matrix[i][j + 1] != '.' && matrix[i][j + 1] != presidentColor) {
                        deputies.insert(matrix[i][j + 1]);
                    }
                }
            }
        }
    }

    cout << deputies.size();
    return 0;
}
