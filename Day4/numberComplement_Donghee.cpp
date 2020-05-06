// Donghee Lee
// 05/04/2020

class Solution {
public:
    int findComplement(int num) {
        // 101 -> 010 = 2 
        
        int binDigits = 0;
        int temp = num;
        
        while (temp != 0) {
            temp = temp/2;    
            binDigits++;
        }
        
        int mask = pow(2, binDigits) - 1;
        
        return mask ^ num;
    }
};