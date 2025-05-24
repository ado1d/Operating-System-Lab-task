#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, arrival, burst, priority;
    int start, finish, waiting, turnaround;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter arrival time, burst time and priority (lower = higher) for process " << i + 1 << ": ";
        cin >> p[i].arrival >> p[i].burst >> p[i].priority;
    }

    vector<bool> done(n, false);
    int time = 0, completed = 0;
    float total_wait = 0, total_turnaround = 0;

    while (completed < n) {
        int idx = -1, min_priority = 1e9;
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival <= time && p[i].priority < min_priority) {
                min_priority = p[i].priority;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
        } else {
            p[idx].start = time;
            p[idx].finish = time + p[idx].burst;
            p[idx].turnaround = p[idx].finish - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;

            total_wait += p[idx].waiting;
            total_turnaround += p[idx].turnaround;

            done[idx] = true;
            time = p[idx].finish;
            completed++;
        }
    }

    cout << "\nPID\tArrival\tBurst\tPriority\tStart\tFinish\tWaiting\tTurnaround\n";
    for (auto &pr : p) {
        cout << pr.pid << "\t" << pr.arrival << "\t" << pr.burst << "\t" << pr.priority << "\t\t"
             << pr.start << "\t" << pr.finish << "\t" << pr.waiting << "\t" << pr.turnaround << endl;
    }

    cout << "\nAverage Waiting Time: " << total_wait / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround / n << endl;

    return 0;
}
