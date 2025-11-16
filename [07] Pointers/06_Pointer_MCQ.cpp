#include <iostream>
using namespace std;

int main () {

    /*
    int first = 8;
    int second = 19;
    int *ptr = &second;
    *ptr = 9;
    cout << "first = " << first << " second = " << second << endl;
    */

    /*
    int first = 6;
    int *p = &first;
    int *q = p;
    (*q)++;
    cout << "first = " << first << endl;
    */

    /*
    int first = 8;
    int *p = &first;
    cout << (*p)++ << " ";
    cout << first << endl;
    */

    /*
    int *p = 0;
    int first = 110;
    *p = first; // ANS: Segmentetion Fault (Because while declaring ptr & not written on 'first');
    cout << *p << endl; //*p = 0; p = &first;
    */

    /*
    int first = 8;
    int second = 11;
    int *third = &second;
    first = *third;
    *third = *third + 2;
    cout << first << " " << second << endl;
    */

    /*
    float f = 12.5;
    float p = 21.5;
    float* ptr = &f;
    (*ptr++);
    *ptr = p; //ANS: 21.5 21.5 21.5
    cout << *ptr << " " << f << " " << p << endl;
    */

    /*
    int arr[5]; // int = 4 (therefore, 4 * 5 = 20);
    int *ptr; // ptr size: 8 (address size is always 8 for every datatype);
    cout << sizeof(arr) << " " << sizeof(ptr) << endl;
    */

    /*
    int arr[] = {11, 21, 13, 14};
    cout << *(arr) << " " << *(arr + 1) << endl;
    */

    /*
    int arr[6] = {11, 12, 31};
    cout << arr << " " << &arr << endl;
    */

    /*
    int arr[6] = {11, 21, 13};
    cout << (arr + 1) << endl;
    */

    /*
    int arr[6] = {11, 22, 13};
    int *p = arr;
    cout << p[2] << endl;
    */

    /*
    int arr[] = {11, 12, 13, 14, 15};
    cout << *arr << " " << *(arr + 3) << endl;
    */  

    /*
    int arr[] = {11, 21, 31, 41};
    int *ptr = arr++; // we not able to do 'arr = arr + 1';
    cout << *ptr << endl; //but we can do 'ptr = ptr + 1';
    */

    /*
    char ch = 'a';
    char* ptr = &ch;
    ch++;
    cout << *ptr << endl; // This will output correctly but if you use cout << ptr then it'll run till '\0' character
    */

    /*
    char arr[] = "abcde";
    char* p = &arr[0];
    cout << p << endl;
    */

    /*
    char arr[] = "abcde";
    char *p = &arr[0];
    p++; 
    cout << p << endl; //start from (arr + 1) i.e arr[1];
    */

    /*
    char str[] = "babbar";
    char *p = str;
    cout << str[0] << " " << p[0] << endl;
    */

   //watch all MCQ's on Codehelp by Love babber
   //after time stamp 45:15
   //May or may not be continued
}