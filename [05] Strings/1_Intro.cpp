#include <iostream>
#include <istream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {

    /***************** Character Arrays ********************/
    char name[10];

    // take input
    cout << "Enter your name: ";
    cin >> name;
    cout << "Your name is " << name << endl;

    // Add Null char in between 
    name[2] = '\0'; // Because of this output will be print only 1st two characters only.

    // print output
    cout << "Your name is " << name << endl;
    cout << "***********************************" << endl << endl;

    /************ String **************/
    string s; 

    cout << "Enter a string: ";
    cin >> s;

    cout << "Your string is " << s << endl;
    cout << "Lenght of your string is " << s.length() << endl;
    cout << "***********************************" << endl << endl;


    /*************** Difference between string and character array ******************/
    string str = "ab\0cd\0";
    char str2[10] = "ab\0cd\0";

    cout << "String: " << str << "\tChar Array: " << str2 << endl;
    cout << "***********************************" << endl << endl;

    /************************* String Operations *****************************/
    string fname = "Taehyung";
    string lname = "Kim";

    lname.append(" " + fname);
    cout << "Lname: " << lname << endl;

    cout << "char at pos 4: " << lname.at(4) << endl; // lname = "Kim Taehyung"

    if(lname.empty())
        cout << "last name is empty." << endl;
    else 
        cout << "last name isn't empty -> " << lname << endl;

    // find -> returns index of first letter
    cout << "find kim: " << lname.find("Tae") << endl;

    // insert
    fname.insert(3, "-");
    cout << "First name: " << fname << endl;

    // Size/ length:
    cout << "Size: " << fname.size() << endl;
    cout << "Length: " << fname.length() << endl;

    string num = "17";
    cout << stoi(num) + 1 << endl; // stoi() converts string to int

    int numStr = 17;
    cout << to_string(numStr) + "1" << endl; // To convert int to string


    // Assign
    string a;
    string base = "The quick brown fox jumps over a lazy dog.";

    a.assign(base);
    cout << a << endl; // The quick brown fox jumps over a lazy dog.

    a.assign(base, 32, 40);
    cout << a << endl; // lazy dog

    a.assign("pangrams are cool", 7);
    cout << a << endl; // panagram

    a.assign(10, '*');
    cout << a << endl; // "**********"

    a.assign(base.begin() + 16, base.end() - 12);
    cout << a << endl; // fox jumps over

    a.assign(10, 0x2D);
    cout << a << endl; // "----------"


    // Erase
    a = "This is an example sentence.";
    a.erase(10, 8); // This is an sentence.
    cout << "Size: " << fname.size() << endl;
    cout << "Length: " << fname.length() << endl;

    // replace
    base = "this is a test string.";
    string b1 = "n example";
    string b2 = "sample phrase";
    string b3 = "useful.";
    str = base;

    str.replace(9, 5, b1);
    cout << str << endl; // this is an example string.

    str.replace(19, 6, b2, 7, 6);
    cout << str << endl;

    str.replace(8, 6, "a shorty", 7);
    cout << str << endl;


    // Swap
    string buyer = "Money";
    string seller = "Goods";
    cout << "Before the swap, buyer has " << buyer << " and seller has " << seller << endl;
    buyer.swap(seller);
    cout << "After the swap, buyer has " << buyer << " and seller has " << seller << endl;

    // Upper lower case
    transform(fname.begin(), fname.end(), fname.begin(), ::toupper); // from algorithm file
    cout << "Uppercase fname: " << fname << endl;


    // getline(cin, str, '...') know more about delimeter char from readme.md file
    cout << "------Getline--------" << endl;
    string getStr;
    cout << "Enter any string and when you want to end enter ',': ";
    getline(cin, getStr, ','); // It only reads input till ,
    cout << getStr << endl;

    return 0;
}