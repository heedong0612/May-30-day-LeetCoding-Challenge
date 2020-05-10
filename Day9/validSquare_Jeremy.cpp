#include <iostream>
#include <vector>

using namespace std;

/*
We don't need the eyeball test cus the bruteforce solution is fast enough #bruh
Do some eyeball test based on characteristics
of perfect square numbers

Then do binary search
*/
bool isPerfectSquare(int num) {
    if (num == 0 || num == 1) return true;

    vector<int> digitalRoot {1, 4, 7, 9};
    vector<int> squareOneth {0, 1, 4, 5, 6, 9};
    int oneth = num % 10;
    int tenth = num / 10 % 10;
    int modEight = num % 8;

    // not in square oneth
    if (find(squareOneth.begin(), squareOneth.end(), oneth) == squareOneth.end())
        return false; 
    
    // even oneth
    else if (oneth % 2 == 0) {
        if (oneth == 0) 
            if (tenth % 2!= 0) return false;

        else if (oneth == 4)
            if (tenth % 2 != 0) return false;
        
        else if (oneth == 6)
            if (tenth % 2 == 0) return false;
        
        if (modEight != 0 && modEight != 4) return false;
    } else if {
        if (oneth == 1) 
            if (tenth %2 != 0) return false;

        else if (oneth == 4)
            if (tenth != 2) return false;
        
        else if (oneth == 6)
            if (tenth % 2 != 0) return false;
        
        if (modEight != 1) return false;
    }
 

    int number = num; 
    int sumDigit = getSumDigit(num);

    while (sumDigit > 9) 
        sumDigit = getSumDigit(sumDigit);
    
    if (find(digitalRoot.begin(), digitalRoot.end(), sumDigit) == digitalRoot.end())
        return false;

    int l = 0;
    int r = num;

    while (l <= r) {
        int mid = (l + r)/2;
        int maybe = mid * mid;
        if (maybe == num) return true;
        else if (maybe > num) r = mid - 1;
        else if (maybe < num) l = mid + 1;
    }

    return false;
}

/*
Get the sum of each digit of a number
*/
int getSumDigit(int num) {
    int n = num;
    int sum = 0;
    while (num > 0) {
        int rem = num % 10;
        sum += rem;
        n /= 10;
    }
    return sum;
}

int main() {
    return 0;
}