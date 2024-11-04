#include <iostream>
#include <vector>

using namespace std;

struct Process {
    int id, burst, waiting, remaining;
};

void round_robin(vector<Process>& processes, int quantum) {
    int time = 0;
    bool done;
    do {
        done = true;
        for (auto& p : processes) {
            if (p.remaining > 0) {
                done = false;
                if (p.remaining > quantum) {
                    time += quantum;
                    p.remaining -= quantum;
                } else {
                    time += p.remaining;
                    p.waiting = time - p.burst;
                    p.remaining = 0;
                }
            }
        }
    } while (!done);
}

int main() {
    vector<Process> processes = {{1, 5, 0, 5}, {2, 4, 0, 4}, {3, 2, 0, 2}};
    int quantum = 2;
    round_robin(processes, quantum);

    for (auto& p : processes)
        cout << "Process " << p.id << ": Waiting Time = " << p.waiting << "\n";
    return 0;
}
