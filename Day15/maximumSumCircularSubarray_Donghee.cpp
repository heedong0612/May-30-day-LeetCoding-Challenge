// Donghee Lee
// 5/15/2020

// finds maximum subarray sum using Kadane algorithm
// since this is a circular array, there can be 2 cases: 
// case 1   [ ......... maximum sum subarray .........]
// case 2   [ part of subarray ...... part of subarray]
// For case 1, we can use Kadane's algorithm and treat it like a normal array
// For case 2, we can find the maximum sum of subarray by calculating (TotalSum - minimum sum)
// since it is actually [ part of subarray | minimum sum subarray| part of subarray]

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
       
        int maxSum = A[0];
        int currSum_max = A[0];
        int minSum = A[0];
        int currSum_min = A[0];
        
        int startIndex = 0; // for case 2. we want to avoid when the total sum of array is the minimum sum array;
                            // we need at least one element
        int totalSum = A[0];
        
    
        for (int i = 1; i < A.size(); i++) {
            totalSum += A[i];
            
            // case 1 -- finds maximum sum subarrays
            if (A[i] + currSum_max > 0) {
                 if (A[i] >= A[i] + currSum_max) {
                    currSum_max = A[i];
                } else {
                    currSum_max = A[i] + currSum_max;
                }                
                maxSum = max(maxSum, currSum_max); 

            } else {
                currSum_max = A[i];
                maxSum = max(maxSum, currSum_max); 
               
            }
            
            // case 2 -- finds minimum sum subarray
            if (A[i] + currSum_min < 0) {
                if (A[i] <= A[i] + currSum_min) {
                    startIndex = i;
                    currSum_min = A[i];
                } else {
                    currSum_min = A[i] + currSum_min;
                }
                
                minSum = min(minSum, currSum_min); 

            } else {
                currSum_min = A[i];
                startIndex = i;
                minSum = min(minSum, currSum_min); 
            }
        }
        
        return (startIndex == 0) ? maxSum : max(maxSum, totalSum - minSum);
    }
};