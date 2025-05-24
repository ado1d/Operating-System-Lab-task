#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, arrival, burst, remaining, waiting = 0, turnaround = 0, finish = 0;
};

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> tq;

    vector<Process> p(n);
    queue<int> q;
    vector<bool> inQueue(n, false);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter arrival and burst time for process " << i + 1 << ": ";
        cin >> p[i].arrival >> p[i].burst;
        p[i].remaining = p[i].burst;
    }

    int time = 0, completed = 0;
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && !inQueue[i] && p[i].remaining > 0) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (!q.empty()) {
            int i = q.front(); q.pop();

            int exec_time = min(tq, p[i].remaining);
            time += exec_time;
            p[i].remaining -= exec_time;

            for (int j = 0; j < n; j++) {
                if (j != i && p[j].arrival <= time && p[j].remaining > 0) {
                    if (!inQueue[j]) {
                        q.push(j);
                        inQueue[j] = true;
                    }
                }
            }

            if (p[i].remaining == 0) {
                p[i].finish = time;
                p[i].turnaround = p[i].finish - p[i].arrival;
                p[i].waiting = p[i].turnaround - p[i].burst;
                completed++;
            } else {
                q.push(i);  // still remaining
            }
        } else {
            time++;
        }
    }

    float total_wait = 0, total_turnaround = 0;

    cout << "\nPID\tArrival\tBurst\tFinish\tWaiting\tTurnaround\n";
    for (auto &pr : p) {
        cout << pr.pid << "\t" << pr.arrival << "\t" << pr.burst << "\t"
             << pr.finish << "\t" << pr.waiting << "\t" << pr.turnaround << '\n';

        total_wait += pr.waiting;
        total_turnaround += pr.turnaround;
    }

    cout << "\nAverage Waiting Time: " << total_wait / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround / n << '\n';

    return 0;
}
