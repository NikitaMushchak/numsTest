#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <bitset>
#include <future>
#include <thread>
#include <queue>
#include <atomic>

#include <algorithm>

typedef  std::vector<int> vint;


bool isPrime(const int number) {
    if (number <= 1) {
        return false;
    }
    double num_double = (double)number;
    double max_number = sqrt(num_double);
    int max_int = int(max_number);
    for (int i = 2; i <= max_int; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

vint primesToArray(const int N) {
    vint array;
    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) {
            array.push_back(i);
        }
    }
    return array;
}
vint primesToArrayEratosfen(const int N) {
    std::vector<bool> sieve(sqrt(N));
    vint primes;

    for (int i = 2; i <= N; ++i) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j+=i) {
                sieve[j] = 1;
            }
        
        }
    }
    return primes;
}

bool ftask(int taskID) {
    static std::mutex task;
    task.lock();

    std::cout << "thread id : " << std::this_thread::get_id() << " task : " << taskID << std::endl;

    task.unlock();

    size_t sleep = std::rand() % 1000;
    std::this_thread::sleep_for(std::chrono::microseconds(sleep));
    return true;
}

class Item {
public:
    void start() {
        std::cout << "start():" << std::endl;
        std::cout << "thread id : " << std::this_thread::get_id() << std::endl;
    }
};


struct ListNode {


    int val;
    int size = 0;
    ListNode* head;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    void Push_Back(int number) {

        if (head == nullptr) {
            head = new ListNode(number);

        }
        else {
            ListNode* current = this->head;
            if (current->next != nullptr) {
                current = current->next;
            }
            current->next = new ListNode(number);
        }
        size++;
    }
};
