#include <iostream> 
#include <climits>
using namespace std;

// Problem Link: https://www.codingninjas.com/studio/library/book-allocation-problem

// Time complexity: O(totalPages * numOfBooks)
bool isPossible(int *bookPages, int numOfBooks, int numOfStud, int numOfPages) {
    int cntStud = 1;
    int currSum = 0;

    for(int i = 0; i < numOfBooks; i++) {
        if(bookPages[i] > numOfPages)
            return false;
        
        if(currSum + bookPages[i] > numOfPages) {
            cntStud++;
            currSum += bookPages[i];

            if(cntStud > numOfStud)
                return false;
        } else {
            currSum += bookPages[i];
        }
    }
    return true;
}

// Brute Force
int bookAllocation(int *books, int numOfBooks, int numOfStud) {
    // If num of students are greater than total num of books
    if(numOfStud > numOfBooks)
        return -1;

    int totalPages = 0;
    // Count Total pages
    for(int i = 0; i < numOfBooks; i++)
        totalPages += books[i];
    
    // Check every possible value
    for(int numPages = 1; numPages <= totalPages; numPages++) {
        if(isPossible(books, numOfBooks, numOfStud, numPages)) 
            return numPages;
    }
    return -1;
}

// Brute Force Solution
// Time Complexity: O(n^2)
// In this logic we're assuming that there are only two students
int bookAllocation_bruteForce(int *books, int noOfBooks) {
    int ans = INT_MAX, sum1 = 0; // `sum1` is the sum of pages for 1st student and `ans` is final answer (minimum of max pages allocated)
    
    for(int i = 0; i < noOfBooks - 1; i++) {
        sum1 += books[i]; // add current book to first student's allocation
        int sum2 = 0; // sum of pages for second student
        int currAns = 0; // max pages allocated in this split. Ex - sum1 = 30 and sum2 = 70 then it's 70

        for(int j = i + 1; j < noOfBooks; j++)
            sum2 += books[j];

        // Debug print
        cout << "• Split at index " << i 
             << " | Student1 sum = " << sum1 
             << " | Student2 sum = " << sum2 << endl;

        // Find Max Book Pages Allocation among two students
        if(sum1 > sum2) 
            currAns = sum1;
        else    
            currAns = sum2;

        // Debug print: show current max allocation
        cout << "\t- Max allocation at this split = " << currAns << endl;

        // Update Actual Ans
        if(currAns < ans) {
            ans = currAns;
            cout << "\t- Updated answer = " << ans << endl;
        }
    }

    cout << "-----------------------------" << endl << endl;
    return ans;
}

int main() {
    // int books[10], numOfBooks, studNum;

    // cout << "Enter total number of books: ";
    // cin >> numOfBooks;

    // cout << "Enter total pages of each book: ";
    // for(int i = 0; i < numOfBooks; i++)
    //     cin >> books[i];

    // cout << "Enter total number of students: ";
    // cin >> studNum;

    int books[10] = {10, 20, 30, 40}; // pages of each book
    int numOfBooks = 4;
    int studNum = 2;

    cout << "The minimum of the maximum number of pages assigned to only 2 students is " << bookAllocation_bruteForce(books, numOfBooks) << endl;
    cout << "The minimum of the maximum number of pages assigned to " << studNum << " students is " << bookAllocation(books, numOfBooks, studNum) << endl;
    return 0;
}