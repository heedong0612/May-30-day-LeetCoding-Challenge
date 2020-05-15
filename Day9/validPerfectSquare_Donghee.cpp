// Donghee Lee 
// 05/09/2020

class Solution {
public:
    bool isPerfectSquare(int num) {
        long i = 1;

        while (i * i <= num) {
            if (i * i == num) return true;
            i++;
        }
        return false;
    }
};