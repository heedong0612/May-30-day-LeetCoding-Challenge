// Donghee Lee
// 5/19/2020

class StockSpanner {
private: 
    stack<pair<int, int>> stk;      // keeps track of the current number 
                                    // and the counts up until that number
    
public:  
    StockSpanner() {
        
    }
    
    int next(int price) {
       if (stk.empty()) {
           stk.push(make_pair(price, 1));
           return 1;
       }
        
       if (price < stk.top().first) {
           stk.push(make_pair(price, 1));
           return 1;
       } else {
           int count = 1;
           
           while (!stk.empty() && stk.top().first <= price) {
               // pop, adding the cumul count
               count += stk.top().second;
               stk.pop();
           }
           
           // push to the stack
           stk.push(make_pair(price, count));

           return count;
       }
    }
};

// Jumping to the previous numbers using DP array

// class StockSpanner {
// public:
//     vector<int> ps;
//     vector<int> dp;
    
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//         ps.push_back(price);
//         dp.push_back(1);
        
//         if (ps.size() == 1) 
//             return 1;
        
//         if (price < ps[ps.size() - 2]) {
//             return 1;
//         } else {
//             // jump around by that much
//             int count = 0;
//             int i = ps.size() - 1;
//             while (i >= 0) {
//                 if (price >= ps[i]) {
//                     count += dp[i];
//                 }
                
//                 i -= dp[i];
//             }
            
//             dp[ps.size() - 1] = count;
//             return count;
//         }
//     }
// };

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */