// 5/28/2020
// Donghee Lee

class Solution {
public:
    vector<int> countBits(int num) {
        /****** algorithm ********/
        // runtime: O(n)

        // counts of 1 digits have a pattern of repeatance with +1 every time the number hits multiples of 2.
        // (whenever we encounter 2^n, it is just adding +1 to previous corresponding number, curr - n)
        // curr from 2 - 4 is 1 because of 2^1, curr from 4 - 8 is 2 because of 2^2, curr from 8 - 16 is 3 because of 2^3, and so on ...
        // 
        // for example, in the array, arr[6] = 1 + arr[6 - curr] 
        
        vector<int> arr(num + 1);
        
        // base case
        arr[0] = 0;
        if (num == 0) return arr;
        
        arr[1] = 1;
        if (num == 1) return arr;
        
        
        int currNum = 2, nextNum = currNum * 2, i = currNum;
        
        while (i <= num) {
            arr[i] = 1 + arr[i - currNum];
            i++;
            
            if (i == nextNum) {
                currNum = nextNum;
                nextNum *= 2;
            }
        }
        
        return arr;
        
    }
};