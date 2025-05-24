#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;


// code for creating 2 child process of a parent process


int main() {
    cout << "Parent PID: " << getpid() << '\n';
    pid_t pid1 = fork();

    if (pid1 == 0) {
        cout << "Child 1 PID: " << getpid() << ", Parent PID: " << getppid() << '\n';
        sleep(10); 
    } else {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            cout << "Child 2 PID: " << getpid() << ", Parent PID: " << getppid() << '\n';
            sleep(10); 

            exit(0);        //end process
        } else {
            sleep(10);
        }
    }
    

    return 0;
}
