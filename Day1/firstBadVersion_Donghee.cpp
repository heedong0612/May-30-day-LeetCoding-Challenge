// Donghee Lee
// 05/01/20
// 
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n, mid;
        
        while (i < j) {
            mid = i + (j-i+1)/2;

            if (isBadVersion(mid)) {
                if (i == 0) return 0;
                if (!isBadVersion(mid-1)) return mid;
                j = mid - 1;
            } else {
                i = mid;
            }
        }
         return i;
    }
};