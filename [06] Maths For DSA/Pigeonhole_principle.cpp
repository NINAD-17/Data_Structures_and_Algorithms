#include <iostream>
#include <vector>
using namespace std;

void pigeonholePrinciple(vector<int> &totalPigeons, int totalHoles) {
    vector<int> pigeonholes(totalHoles, 0);

    for(int pigeonNo = 0; pigeonNo < totalPigeons.size(); pigeonNo++)
        pigeonholes[totalPigeons[pigeonNo] % totalHoles]++;
    
    for(int i = 0; i < totalHoles; i++) {
        if(pigeonholes[i] > 1) 
            cout << "Hole " << i << " contains " << pigeonholes[i] << " pigeons." << endl;
    }
}

int main() {
    vector<int> pigeons = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Each item is a pigeon's number/ID
    int pigeonholes = 8;

    pigeonholePrinciple(pigeons, pigeonholes);
    return 0;
}