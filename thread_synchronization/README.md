# Thread Synchronization

## Objective
thread creation and synchronization using `pthread`.

## Code Files:
- `thread_example.cpp`: Without mutex
- `thread_mutex.cpp`: With mutex for synchronization

## How to Compile and Run

```bash
g++ thread_example.cpp -o thread_example -lpthread
./thread_example

g++ thread_mutex.cpp -o thread_mutex -lpthread
./thread_mutex