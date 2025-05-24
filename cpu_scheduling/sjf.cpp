#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, arrival, burst, start, finish, waiting, turnaround;
};

bool cmp(Process a, Process b) {
    return a.arrival < b.arrival;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> p[i].arrival >> p[i].burst;
    }

    sort(p.begin(), p.end(), cmp);
    vector<bool> done(n, false);

    int time = 0, completed = 0;
    float total_wait = 0, total_turnaround = 0;

    while (completed < n) {
        int idx = -1, min_burst = 1e9;
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival <= time && p[i].burst < min_burst) {
                min_burst = p[i].burst;
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

    cout << "\nPID\tArrival\tBurst\tStart\tFinish\tWaiting\tTurnaround\n";
    for (auto &pr : p) {
        cout << pr.pid << "\t" << pr.arrival << "\t" << pr.burst << "\t"
             << pr.start << "\t" << pr.finish << "\t" << pr.waiting << "\t" << pr.turnaround << '\n';
    }

    cout << "\nAverage Waiting Time: " << total_wait / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround / n << '\n';

    return 0;
}
