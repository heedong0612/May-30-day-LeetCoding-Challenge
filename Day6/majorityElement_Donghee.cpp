// Donghee Lee
// 05/06/2020

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums.size() / 2;
        unordered_map<int, int> m;
        for (int n: nums) {
             m[n]++;
            if(m[n] > major )
                return n;
        }
        
        return -1;
    }
};