// Donghee Lee
// 05/05/2020

class Solution {
public:
    
    int firstUniqChar(string s) {
        // 1st iteration: make a vector of counts of all chars
        // 2nd iteration: find the first char with count 1
        
        vector<int> count(26*2);
        
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;    
        }
        
        for (int i = 0; i < s.length(); i++) {
            if(count[s[i]-'a'] == 1) return i;
        }
        
        return -1;
    }
};