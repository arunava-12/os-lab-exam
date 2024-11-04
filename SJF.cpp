#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id, arrival, burst, waiting, turnaround;
};

void sjf(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](Process a, Process b) { return a.burst < b.burst; });
    int time = 0;
    for (auto& p : processes) {
        if (time < p.arrival) time = p.arrival;
        p.waiting = time - p.arrival;
        p.turnaround = p.waiting + p.burst;
        time += p.burst;
    }
}

int main() {
    vector<Process> processes = {{1, 0, 6}, {2, 2, 8}, {3, 4, 7}, {4, 5, 3}};
    sjf(processes);

    for (auto& p : processes)
        cout << "Process " << p.id << ": Waiting Time = " << p.waiting << ", Turnaround Time = " << p.turnaround << "\n";
    return 0;
}
