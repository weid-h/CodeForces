//
// Created by wadeh on 22/03/2021.
//

#include<iostream>
#include<string>
#include<vector>

using namespace std;

void alloc(int memory[], int memorySize, int bytes, int &blockIdentifier) {
    if (memorySize >= bytes) {
        for (int i = 0; i < memorySize; i++) {
            if (i + bytes > memorySize) {
                break;
            }
            for (int j = i; j < bytes + i; j++) {
                if (memory[j] != 0) {
                    break;
                } else if (j - i + 1 == bytes) {
                    for (int x = 0; x < bytes; x++) {
                        memory[i + x] = blockIdentifier;
                    }
                    cout << blockIdentifier << endl;
                    blockIdentifier += 1;
                    return;
                }
            }
        }
    }
    cout << "NULL" << endl;
}

void erase(int memory[], int memorySize, int blockIdentifier) {
    bool found = false;
    for (int i = 0; i < memorySize; i++) {
        if (memory[i] == blockIdentifier) {
            found = true;
            memory[i] = 0;
        }
    }
    if (!found || blockIdentifier == 0) {
        cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
    }
}

void defragment(int memory[], int memorySize) {
    bool swapped = false;
    for (int i = 0; i < memorySize - 1; i++) {
        if (memory[i] == 0 && memory[i + 1] != 0) {
            memory[i] = memory[i + 1];
            memory[i + 1] = 0;
            swapped = true;
        }
    }
    if (swapped) {
        defragment(memory, memorySize);
    }
}

int main() {
    int operations, memorySize;
    int blockIdentifier = 1;

    cin >> operations >> memorySize;

    int *memory = new int[memorySize];

    for (int i = 0; i < memorySize; i++) {
        memory[i] = 0;
    }

    for (int i = 0; i < operations; i++) {
        string instruction;
        int instructionArgument;

        cin >> instruction;

        if (instruction == "alloc") {
            cin >> instructionArgument;
            alloc(memory, memorySize, instructionArgument, blockIdentifier);
        } else if (instruction == "erase") {
            cin >> instructionArgument;
            erase(memory, memorySize, instructionArgument);
        } else {
            defragment(memory, memorySize);
        }
    }
};