// Donghee Lee
// 05/12/2020

/*
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. Find this single element that appears only once.

Example 1:

Input: [1,1,2,3,3,4,4,8,8]

1
1

Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10

*/

/*  bruteforce 
    - O(n)
    - not considering every element appears twice (except for the answer)
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int prev = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (prev == nums[i]) {
                count++;
            } else {
                if (count == 1) return prev;
                prev = nums[i];
                count = 1;
            }
        }
        return prev;
    }
};

// half the range by taking advantage of the fact that all elements have count of 2 besidse the answer
// O(log n)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, j = nums.size() -1, mid = (j - i + 1) / 2; // I set that mid is included on the left side

        while (i < j) {
            if (nums[mid] != nums[mid +1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }
            if (nums[mid] == nums[mid + 1]) {
                mid--;
            } 
            if ((mid-i+1) % 2 == 0) { // size of left part is even => answer is on the right => check right side
                if (nums[j] != nums[j-1]) return nums[j];
                
                // change the range to right side
                i = mid + 1;
                mid = i + (j - i) / 2;

            } else { // check left side
                if (nums[i] != nums[i+1]) return nums[i];

                // change the range to left side
                j = mid;
                mid = i + (j - i) / 2;

            }
        }
        cout << "out the loop" << endl;
        return nums[0];
        
    }
};