#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

int counter = 0;
pthread_mutex_t lockk;

void* increment(void* arg) {
    for (int i = 0; i < 1000000; ++i) {
        pthread_mutex_lock(&lockk);
        counter++;
        pthread_mutex_unlock(&lockk);
    }
    return nullptr;
}

int main() {
    pthread_t t1, t2;

     pthread_mutex_init(&lockk, nullptr);

    pthread_create(&t1, nullptr, increment, nullptr);
    pthread_create(&t2, nullptr, increment, nullptr);

    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    pthread_mutex_destroy(&lockk);

    cout << "counter value : " << counter << '\n';

    return 0;
}
