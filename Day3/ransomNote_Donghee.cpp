// Donghee Lee
// 05/03/2020

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> r(26*2);        
        
        for (char c: magazine) {
           // cout << "1: " << c << endl;
            r[c -'a']++;
        }
        
        for (char c: ransomNote) {
         //    cout << "2: " << c << endl;
            r[c-'a']--;
            if (r[c-'a'] < 0) return false;
        }
        return true;
        
    }
};