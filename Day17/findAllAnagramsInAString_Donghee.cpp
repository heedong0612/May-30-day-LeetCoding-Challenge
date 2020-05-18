// Donghee Lee
// 5/17/2020

class Solution {
public:
    
    /* Algorithm O(n*m):
     - keep a "needed" map to keep track of the chars and its counts missing
     - if needed has size 0, then count++
     - if not, add the char at startingIndex to needed, and -- the count of the added char if it was in the map
     - ... 
    */
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() == 0 || s.length() < p.length()) return result;

        unordered_map<char, int> needed;            // needed chars in current window
        unordered_map<char, int> actual;            // actual chars we have in the window -- unnecessary?
        unordered_map<char, int> originalNeeded;    // in string p , we don't touch this
        
        for (char c: p) {
            needed[c]++;
            originalNeeded[c]++;
        }
        
        /*** initializing with only the first p.length() of chars in string s ***/
        int start = 0; // start index
        for (int i = 0; i < p.length(); i++) {
            actual[s[i]]++;
            if (needed.find(s[i]) != needed.end()) { // there is the char in map
                needed[s[i]]--;
            } 
            if (needed[s[i]] == 0) needed.erase(s[i]);
        }
        // if needed map is empty, window has all chars
        if (needed.size() == 0) result.push_back(start);
        

        /*** regular iteration ***/
        for (int i = p.length(); i < s.length(); i++, start++) {
            actual[s[i]]++;     // add new char
            actual[s[start]]--; // delete one char
            
            if (needed.find(s[i]) != needed.end()) { // there is the char in map
                needed[s[i]]--;
            }
            if (originalNeeded.find(s[start]) != originalNeeded.end()) { 
                // we are getting rid of s[start] that we might need, which means we will need to check it
                if (originalNeeded[s[start]] > actual[s[start]]) {
                    needed[s[start]]++;
                }  
            }
            
            if (needed[s[i]] == 0) needed.erase(s[i]);
            if (needed.size() == 0) result.push_back(start + 1);  // adding the index
        }
        
        return result;
    }
};