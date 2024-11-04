#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id, arrival, burst, waiting, turnaround;
};

void fcfs(vector<Process>& processes) {
    int time = 0;
    for (auto& p : processes) {
        if (time < p.arrival) time = p.arrival;
        p.waiting = time - p.arrival;
        p.turnaround = p.waiting + p.burst;
        time += p.burst;
    }
}

int main() {
    vector<Process> processes = {{1, 0, 4}, {2, 1, 3}, {3, 2, 1}};
    fcfs(processes);

    for (auto& p : processes)
        cout << "Process " << p.id << ": Waiting Time = " << p.waiting << ", Turnaround Time = " << p.turnaround << "\n";
    return 0;
}
