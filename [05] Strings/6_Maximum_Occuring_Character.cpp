#include <iostream>
#include <unordered_map>
using namespace std;

// Problem: https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1

// Using hashmaps
// time complexity: O(n); space compleixty: O(n)
char maxOccChar_usingHashmap(string &str) {
    unordered_map<char, int> characters;

    // for(int i = 0; i < str.length(); i++)
    //     characters[str[i]]++;

    for(char c : str) {
        if(isalpha(c)) {   // only count letters (a-z && A-Z)
            characters[c]++;
        }
    }
    
    int max = -1;
    char ansChar = '~'; // start with a high ASCII value: 126
    for(auto value: characters) { // total characters can be at max 52 (26 + 26) O(1) in case if all characters in string are distinct
        if(value.second > max || (value.second == max && value.first < ansChar)) { // if there're multiple element with same max number then take lexicographically smallest one.
            max = value.second;
            ansChar = value.first;
        }
    }

    return ansChar;
}

// (B) same solution as (A) but with space complexity: O(1)
char maxOccChar_b(string str) {
    // to store total occurances of uppercase and lowercase characters
    int uppercase[26] = {0}; // constant space: O(1)
    int lowercase[26] = {0}; // constant space: O(1)
    
    // update frequencies of lowercase and uppercase characters
    int charNum = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            charNum = str[i] - 'a';
            lowercase[charNum]++;
        } else {
            charNum = str[i] - 'A';
            uppercase[charNum]++;
        }
    }

    int max = -1; // maximum frequency
    int ansChar = -1;
    bool isUpperCase = false;

    // Check lowercase array
    for(int i = 0; i < 26; i++) {
        if(lowercase[i] > max || (lowercase[i] == max && i < ansChar)) {
            max = lowercase[i];
            ansChar = i;
            isUpperCase = false;
        }
        cout << i << ". Char: " << char(i + 'a') << "\tFreq: " << lowercase[i] << endl;
    }

    // Check uppercase array
    for(int i = 0; i < 26; i++) {
        if(uppercase[i] > max || (uppercase[i] == max && i < ansChar)) {
            max = uppercase[i];
            ansChar = i;
            isUpperCase = true;
        }
        cout << i << ". Char: " << char(i + 'A') << "\tFreq: " << uppercase[i] << endl;
    }

    return isUpperCase ? ansChar + 'A' : ansChar + 'a';
}

// (A) time complexity: O(n) and Space complexity: O(n)
char maxOccChar(string str) {
    // to store total occurances of uppercase and lowercase characters
    int uppercase[26] = {0}; // constant space: O(1)
    int lowercase[26] = {0}; // constant space: O(1)
    
    // exclude special characters and spaces
    string cleanStr = "";
    for(int i = 0; i < str.length(); i++) {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            cleanStr += str[i];
    }

    int charNum = 0;
    
    // update frequencies of lowercase and uppercase characters
    for(int i = 0; i < cleanStr.length(); i++) {
        if(cleanStr[i] >= 'a' && cleanStr[i] <= 'z') {
            charNum = cleanStr[i] - 'a';
            lowercase[charNum]++;
        } else {
            charNum = cleanStr[i] - 'A';
            uppercase[charNum]++;
        }
    }

    int max = -1; // maximum frequency
    int ansChar = -1;
    bool isUpperCase = false;

    for(int i = 0; i < cleanStr.length(); i++) {
        if(cleanStr[i] >= 'a' && cleanStr[i] <= 'z') {
            charNum = cleanStr[i] - 'a';

            // if max frequency is smaller than current char OR if it's equal and current char is lexicographically smaller then only change.
            if(max < lowercase[charNum] || (max == lowercase[charNum] && charNum < ansChar)) {
                max = lowercase[charNum];
                ansChar = charNum;
                isUpperCase = false;
            }
            cout << i << ". Char: " << char(charNum + 'a') << "\tFreq: " << lowercase[charNum] << endl;
            continue;
        } else {
            charNum = cleanStr[i] - 'A';
            if(max < uppercase[charNum] || (max == uppercase[charNum] && charNum < ansChar)) {
                max = uppercase[charNum];
                ansChar = charNum;
                isUpperCase = true;
            }
            cout << i << ". Char: " << char(charNum + 'A') << "\tFreq: " << uppercase[charNum] << endl;
            continue;
        }    
    }

    return isUpperCase? ansChar + 'A': ansChar + 'a';
}

int main() {
    string str = "Galaxy AI is Here!";
    
    // cout << "Enter a string: ";
    // getline(cin, str);

    cout << "Maximum Occuring character: " << maxOccChar_b(str) << endl;
    cout << "Maximum Occuring character using Hashmap: " << maxOccChar_usingHashmap(str);
    return 0;
}