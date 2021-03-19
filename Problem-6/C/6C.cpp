//
// Created by wadeh on 19/03/2021.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int barsOnTable;
    cin >> barsOnTable;
    auto timeToConsume = vector<int>();

    int sum = 0;
    for (int i = 0; i < barsOnTable; i++) {
        int val;
        cin >> val;
        timeToConsume.push_back(val);
        sum += timeToConsume[i];
    }

    int aliceCurrentBar = 0;
    int bobCurrentBar = barsOnTable - 1;

    int barBob = 0;
    int barAlice = 0;

    while (true) {
        if ((barBob + barAlice) == barsOnTable) {
            break;
        }
        if (timeToConsume[aliceCurrentBar] > timeToConsume[bobCurrentBar]) {
            timeToConsume[aliceCurrentBar] = timeToConsume[aliceCurrentBar] - timeToConsume[bobCurrentBar];
            barBob += 1;
            bobCurrentBar -= 1;
            if (((barBob + barAlice + 1) == (barsOnTable))) {
                if (aliceCurrentBar != bobCurrentBar) {
                    barBob += 1;
                    break;
                } else {
                    barAlice += 1;
                    break;
                }
            }
        } else if (timeToConsume[aliceCurrentBar] < timeToConsume[bobCurrentBar]) {
            timeToConsume[bobCurrentBar] = timeToConsume[bobCurrentBar] - timeToConsume[aliceCurrentBar];
            barAlice += 1;
            aliceCurrentBar += 1;
            if (((barBob + barAlice + 1) == (barsOnTable))) {
                if (aliceCurrentBar != bobCurrentBar) {
                    barAlice += 1;
                    break;
                } else {
                    barBob += 1;
                    break;
                }
            }
        } else {
            if (((barBob + barAlice + 1) == (barsOnTable))) {
                barAlice += 1;
                break;
            }
            barAlice += 1;
            barBob += 1;
            aliceCurrentBar += 1;
            bobCurrentBar -= 1;
        }
    }
    cout << barAlice << " " << barBob;
}
