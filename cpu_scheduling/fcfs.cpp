#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, arrival, burst;
};

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

    vector<int> start(n), finish(n), waiting(n), turnaround(n);
    int time = 0;
    float total_wait = 0, total_turnaround = 0;

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival) time = p[i].arrival;
        
        start[i] = time;
        finish[i] = time + p[i].burst;
        turnaround[i] = finish[i] - p[i].arrival;
        waiting[i] = turnaround[i] - p[i].burst;

        total_wait += waiting[i];
        total_turnaround += turnaround[i];

        time = finish[i];
    }
    cout << "\nPID\tArrival\tBurst\tStart\tFinish\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t" << p[i].arrival << "\t" << p[i].burst << "\t"
             << start[i] << "\t" << finish[i] << "\t" << waiting[i] << "\t" << turnaround[i] << '\n';
    }

    cout << "\nAverage Waiting Time: " << total_wait / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround / n << '\n';

    return 0;
}
