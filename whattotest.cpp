#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <bitset>

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
