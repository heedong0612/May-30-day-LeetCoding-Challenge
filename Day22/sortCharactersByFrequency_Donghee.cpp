// Donghee Lee
// 5/22/2020

class Solution {
public:
    // For this algo, Credits to the sample code!! 
    
    // using a map of <int, char>
    string frequencySort(string s) {
      
        int counts[256] = {0};
        
        for (char c : s) {
            counts[c]++;
        }
        
        unordered_map<int, string> mp;
        int maxCount = 0;
        int minCount = INT_MAX;
        
        for (int i = 0; i < 256; i++) {
            if (counts[i] > 0) {
                // appending the char to the string if they have the same counts
                mp[counts[i]] += i;
                 
                // finds the max count
                maxCount = max(maxCount, counts[i]);
                
                // find the min count
                minCount = min(minCount, counts[i]);
            }
        }

        string ans = "";
        
        for (int i = maxCount; i >= minCount; i--) {
            if (mp.find(i) != mp.end()) {
                for (char & c : mp[i]) {
                    for (int j = 0; j < i; j++) {
                        ans += c;
                    }
                }
            }
        }
        
        return ans;
    }
};

// class Solution {
// public:
    
//     // using a priority queue (max heap)
//     string frequencySort(string s) {
//       //  cout << (int)'a' << ", " << (int)'A' << endl;
//         // make a vector for counts for each chars
//         int counts[256] = {0};
        
//         for (char c : s) {
//             counts[(int)c]++;
//         }
        
//         // put elements in the prioity queue to be sorted by their counts
//         priority_queue<pair<int, char>> pq;
//         for (int i = 0; i < 256; i++) {
//             if (counts[i] > 0) {
//                  pq.push(make_pair(counts[i], (char)i));
//             }
//         }

//         string ans = "";
//         while (!pq.empty()) {
//             for (int i = 0; i < pq.top().first; i++) {
//                 ans += pq.top().second;
//             }
//             pq.pop();
//         }
        
//         return ans;
//     }
// };