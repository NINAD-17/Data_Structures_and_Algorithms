#include <iostream>
#include <vector>
using namespace std;

// Optimized isPrime()
// Time complexity: O(sqrt(n))
bool isPrime_2(int num) {
    int count = 0;

    for(int i = 1; i * i <= num; i++) { 
        if((num % i) == 0) {
            count++;

            if((num / i) != i)
                count++;
        }
    }

    if(count == 2)
        return true;
    else    
        return false;
}

// Unoptimized -> Time complexity: O(n)
bool isPrime(int num) {
    for(int i = 2; i < num; i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

// Brute Force Approach
// Time complexity:
// if we used isPrime(i) ==> O(n^2) because we're calculating isPrime function for each number between 2 and num
// if we used isPrime_2(i) ==> O(n * (sqrt(n)))
int countPrimes(int num) {
    int count = 0;
    
    for(int i = 2; i < num; i++) {
        if(isPrime_2(i))
            count++;
    }

    return count;
}

int main() {
    int num;
    cin >> num;

    int totalPrimeNumbers = countPrimes(num);
    cout << "Number of prime numbers which are strictly less than " << num << " is " << totalPrimeNumbers << endl;

    return 0;
}