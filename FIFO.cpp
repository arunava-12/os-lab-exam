#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int fifoPageReplacement(vector<int> pages, int frames) {
    unordered_set<int> s;
    queue<int> q;
    int pageFaults = 0;

    for (int page : pages) {
        if (s.size() < frames) {
            if (s.find(page) == s.end()) {
                s.insert(page);
                q.push(page);
                pageFaults++;
            }
        } else {
            if (s.find(page) == s.end()) {
                int front = q.front();
                q.pop();
                s.erase(front);
                s.insert(page);
                q.push(page);
                pageFaults++;
            }
        }
    }
    return pageFaults;
}

int main() {
    vector<int> pages = {1, 3, 0, 3, 5, 6};
    int frames = 3;
    cout << "FIFO Page Faults: " << fifoPageReplacement(pages, frames) << "\n";
    return 0;
}
