// Donghee Lee
// 05/02/2020

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        vector<bool> check(26*2);

        for (char c : J) {
            check[c - 'A'] = true;
        }
        
        int count = 0;
        for (char c : S) {
            if(check[c - 'A']) count++;
        }
        return count;
    }
};