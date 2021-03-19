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

    auto CheckAddDeputy = [&presidentColor, &deputies](char neighbor) {
        if (neighbor != '.' && neighbor != presidentColor) {
            deputies.insert(neighbor);
        };
    };

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            if (matrix[i][j] == presidentColor) {
                if (i - 1 >= 0) {
                    CheckAddDeputy(matrix[i - 1][j]);
                }
                if (i + 1 < length) {
                    CheckAddDeputy(matrix[i + 1][j]);
                }
                if (j - 1 >= 0) {
                    CheckAddDeputy(matrix[i][j - 1]);
                }
                if (j + 1 < width) {
                    CheckAddDeputy(matrix[i][j + 1]);
                }
            }
        }
    }

    cout << deputies.size();
    return 0;
}
