#include <iostream>
#include <vector>

using namespace std;

const int PROCESSES = 5;
const int RESOURCES = 3;

bool is_safe(int processes[], int avail[], int max[][RESOURCES], int allot[][RESOURCES]) {
    int need[PROCESSES][RESOURCES];
    int work[RESOURCES];
    bool finish[PROCESSES] = {false};

    for (int i = 0; i < RESOURCES; i++)
        work[i] = avail[i];

    for (int i = 0; i < PROCESSES; i++)
        for (int j = 0; j < RESOURCES; j++)
            need[i][j] = max[i][j] - allot[i][j];

    while (true) {
        bool found = false;
        for (int p = 0; p < PROCESSES; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < RESOURCES; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == RESOURCES) {
                    for (int k = 0; k < RESOURCES; k++)
                        work[k] += allot[p][k];
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) break;
    }

    for (int i = 0; i < PROCESSES; i++)
        if (!finish[i])
            return false;

    return true;
}

int main() {
    int processes[] = {0, 1, 2, 3, 4};
    int avail[] = {3, 3, 2};
    int max[PROCESSES][RESOURCES] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int allot[PROCESSES][RESOURCES] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};

    if (is_safe(processes, avail, max, allot))
        cout << "System is in a safe state.\n";
    else
        cout << "System is not in a safe state.\n";

    return 0;
}
