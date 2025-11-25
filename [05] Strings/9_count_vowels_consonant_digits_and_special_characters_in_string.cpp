#include <iostream>
using namespace std;

// Time Complexity: O(n)

bool isVowel(char ch) {
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    ch = tolower(ch);

    for(int i = 0; i < 5; i++) {
        if(ch == vowels[i])
            return 1;
    }

    return 0;
}

void countAll(string str) {
    int vowel = 0, consonant = 0, digits = 0, specChar = 0;

    for(int i = 0; i < str.length(); i++) {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            if(isVowel(str[i]))
                vowel++;
            else 
                consonant++;
        } else if(str[i] >= '0' && str[i] <= '9') {
            digits++;
        } else {
            specChar++;
        }
    }

    cout << "Vowels: " << vowel << "\nConsonants: " << consonant << "\nDigits: " << digits << "\nSpecial Characters: " << specChar << endl;
}

int main() {
    string str = " A1 B@ d  adc";

    countAll(str);
    cout << endl;

    return 0;
}