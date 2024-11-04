#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void firstFit(vector<int> blockSize, int m, vector<int> processSize, int n) {
    cout << "\nFirst Fit Allocation:\n";
    vector<int> allocation(n, -1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " allocated to block " << allocation[i] + 1 << "\n";
        else
            cout << "Process " << i + 1 << " not allocated\n";
    }
}

void bestFit(vector<int> blockSize, int m, vector<int> processSize, int n) {
    cout << "\nBest Fit Allocation:\n";
    vector<int> allocation(n, -1);
    
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " allocated to block " << allocation[i] + 1 << "\n";
        else
            cout << "Process " << i + 1 << " not allocated\n";
    }
}

void worstFit(vector<int> blockSize, int m, vector<int> processSize, int n) {
    cout << "\nWorst Fit Allocation:\n";
    vector<int> allocation(n, -1);
    
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " allocated to block " << allocation[i] + 1 << "\n";
        else
            cout << "Process " << i + 1 << " not allocated\n";
    }
}

int main() {
    vector<int> blockSize = {100, 500, 200, 300, 600};
    vector<int> processSize = {212, 417, 112, 426};
    int m = blockSize.size();
    int n = processSize.size();

    firstFit(blockSize, m, processSize, n);
    bestFit(blockSize, m, processSize, n);
    worstFit(blockSize, m, processSize, n);
    
    return 0;
}
