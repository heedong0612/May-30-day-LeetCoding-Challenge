// Donghee Lee
// 5/13/20

class Solution {
public:
    string removeKdigits(string num, int k) { 
        if (num.length() == 0) return "0";
        if (k == 0) return num;
        
        stack<char> stk;
        stk.push(num[0]);
        
        for (int i = 1; i < num.length(); i++) {
            while (k > 0 && !stk.empty() && stk.top() > num[i]) {
                // pop 
                stk.pop();
                k--; 
            } 
             stk.push(num[i]);
        }
        
        if (k > 0) {
            if (stk.size() <= k) return "0";
            for (int i = 0; i < k; i++) stk.pop();
        }
        
        string ans = "";
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        
        
         // delete leading zeroes
        while (ans.length() > 1 && ans[0] == '0'){ 
            ans = ans.substr(1);
        }
        
        return ans;

    }
};
