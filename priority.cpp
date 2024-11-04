#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id, burst, priority, waiting, turnaround;
};

void priority_scheduling(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](Process a, Process b) { return a.priority < b.priority; });
    int time = 0;
    for (auto& p : processes) {
        p.waiting = time;
        p.turnaround = p.waiting + p.burst;
        time += p.burst;
    }
}

int main() {
    vector<Process> processes = {{1, 10, 1}, {2, 1, 3}, {3, 2, 2}};
    priority_scheduling(processes);

    for (auto& p : processes)
        cout << "Process " << p.id << ": Waiting Time = " << p.waiting << ", Turnaround Time = " << p.turnaround << "\n";
    return 0;
}
