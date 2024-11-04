#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int lruPageReplacement(vector<int> pages, int frames) {
    unordered_map<int, list<int>::iterator> mp;
    list<int> lru;
    int pageFaults = 0;

    for (int page : pages) {
        if (mp.find(page) == mp.end()) {
            if (lru.size() == frames) {
                int last = lru.back();
                lru.pop_back();
                mp.erase(last);
            }
            pageFaults++;
        } else {
            lru.erase(mp[page]);
        }
        lru.push_front(page);
        mp[page] = lru.begin();
    }
    return pageFaults;
}

int main() {
    vector<int> pages = {1, 3, 0, 3, 5, 6};
    int frames = 3;
    cout << "LRU Page Faults: " << lruPageReplacement(pages, frames) << "\n";
    return 0;
}
