//
// Created by wadeh on 22/03/2021.
//

#include<iostream>
#include<string>

using namespace std;

int main() {
    string rows[8];
    for (int i = 0; i < 8; i++) {
        cin >> rows[i];
    }

    int blackColumns = 0;
    int blackRows = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (rows[i][j] != 'B') {
                break;
            } else if (j == 7) {
                blackColumns += 1;
            }
        }
        for (int j = 0; j < 8; j++) {
            if (rows[j][i] != 'B') {
                break;
            } else if (j == 7) {
                blackRows += 1;
            }
        }
    }

    if (blackColumns + blackRows == 16) {
        cout << "8";
    } else {
        cout << blackColumns + blackRows;
    }
};