//
// Created by Walter on 19/03/2021.
//

#include <iostream>

using namespace std;

int main() {
    int input[4];
    for (int i = 0; i < 4; i++) {
        cin >> input[i];
    }

    for (int i = 0; i < 4; i++) {
        int a = input[i];
        int b = input[((i + 1 >= 4) ? (i + 1) - 4 : i + 1)];
        int c = input[((i + 2 >= 4) ? (i + 2) - 4 : i + 2)];

        if ((a + b > c && a + c > b && b + c > a)) {
            cout << "TRIANGLE";
            return 0;
        }
    }

    for (int i = 0; i < 4; i++) {
        int a = input[i];
        int b = input[((i + 1 >= 4) ? (i + 1) - 4 : i + 1)];
        int c = input[((i + 2 >= 4) ? (i + 2) - 4 : i + 2)];

        if ((a + b == c) ||
            (a + c == b) ||
            (b + c == a)) {
            cout << "SEGMENT";
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
