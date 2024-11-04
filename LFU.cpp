#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int lfuPageReplacement(vector<int> pages, int frames) {
    unordered_map<int, int> freq, pos;
    set<pair<int, int>> s;
    int pageFaults = 0, index = 0;

    for (int page : pages) {
        if (freq.find(page) == freq.end() || freq[page] == 0) {
            if (s.size() == frames) {
                auto it = s.begin();
                int lfuPage = it->second;
                s.erase(it);
                freq[lfuPage] = 0;
            }
            pageFaults++;
        } else {
            s.erase({freq[page], pos[page]});
        }

        freq[page]++;
        pos[page] = index++;
        s.insert({freq[page], pos[page]});
    }

    return pageFaults;
}

int main() {
    vector<int> pages = {1, 3, 0, 3, 5, 6};
    int frames = 3;
    cout << "LFU Page Faults: " << lfuPageReplacement(pages, frames) << "\n";
    return 0;
}
