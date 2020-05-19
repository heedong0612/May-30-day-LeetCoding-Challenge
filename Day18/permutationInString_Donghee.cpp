// Donghee Lee
// 5/18/2020

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int needed[26] = {0};
        int actual[26] = {0};
        int constNeeded[26] = {0};
        int allCharsNeededCount = 0; // shortcut of checking if all chars are in the substring
        
        for (char c : s1) {
            needed[c - 'a']++;
            constNeeded[c - 'a']++;
            allCharsNeededCount++;
        }
        
        // initialization by length of s1
        for (int i = 0; i < s1.length(); i++) {
            actual[s2[i] - 'a']++;
            if (needed[s2[i] - 'a'] > 0) {
                needed[s2[i] - 'a']--;
                allCharsNeededCount--;
            }
        }
        if (allCharsNeededCount == 0) return true;
        
        int start = 0; // starting index of the substring 
        // regular iteration as we add one char and subtract one char
        for (int i = s1.length(); i < s2.length(); i++, start++) {
            actual[s2[i] -'a']++;
            
            if (needed[s2[i] -'a'] > 0) {
                needed[s2[i] - 'a']--;
                allCharsNeededCount--;
            }
            
            if (actual[s2[start] -'a'] <= constNeeded[s2[start] -'a']){
                needed[s2[start] -'a']++;
                allCharsNeededCount++;
            }
            actual[s2[start] -'a']--;
            
            if (allCharsNeededCount == 0) return true;
        }
        
        return false;
    }
};