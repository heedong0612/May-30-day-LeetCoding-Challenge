// Donghee Lee 
// 05/10/2020
//
// runtime analysis: O(n) + O(n) = O(n)

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<bool> candidates(N + 1, true); // list of boolean that keeps track of candidates so far
        vector<int> trusted(N + 1);           // keeps track of counts of how many people trusts i-th person
        
        for (vector<int>& v : trust) {
            candidates[v[0]] = false; // if you trust someone, you are never a town judge 
            trusted[v[1]]++;          // increase the count of trust received
        }
        
        // iterate and find the town judge
        for (int i = 1; i < N + 1; i++) {
            if (candidates[i] && trusted[i] == N - 1) return i; 
        }

        return -1;
    }
};

