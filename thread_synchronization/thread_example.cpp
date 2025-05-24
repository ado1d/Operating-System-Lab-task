#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

int counter = 0;

void* increment(void* arg) {
    for (int i = 0; i < 1000000; ++i) {
        counter++;
    }
    return nullptr;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, nullptr, increment, nullptr);
    pthread_create(&t2, nullptr, increment, nullptr);

    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    cout << "counter value (unsynchronized): " << counter << '\n';

    return 0;
}
