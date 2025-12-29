#include <iostream>
#include <vector>
using namespace std;

// Using Sieve of Eratosthenes
// time complexity: O(n log (log n)). This is because the Sieve of Eratosthenes algorithm runs in this time complexity. The outer loop runs n times and the inner loop runs approximately n / i times, where i is the current prime number. The sum of n / i for all i from 2 to n is approximately n log log n.
// Space complexity: O(n)
int countPrimesUsingSOE(int num) {
    int count = 0;
    vector<bool> prime(num + 1, true); // num + 1 because in arr/vector indexing starts from 0. if we take it as `num` then 50 - 1 = 49 means it can't take 50 in it (0 to 49).

    prime[0] = prime[1] = false; // As 0 and 1 are none prime number

    for(int i = 2; i * i < num; i++) { // i*i because not need to go beyond squareroot of num. Otherwise in inner loop j will unncesary calculate i*i each time.
        if(prime[i]) { // only process if 'i' is prime
            for (int j = i * i; j < num; j += i) 
                prime[j] = false;
        }
    }

    cout << "Printing all prime numbers: ";
    for(int i = 2; i < num; i++) {
        if(prime[i] == true) {
            cout << i << " ";
            count++;
        }
    }
    cout << endl;

    return count;
}


int main() {
    int num;
    cin >> num;

    int totalPrimeNumbers = countPrimesUsingSOE(num);
    cout << "Number of prime numbers which are strictly less than " << num << " is " << totalPrimeNumbers << endl;

    return 0;
}