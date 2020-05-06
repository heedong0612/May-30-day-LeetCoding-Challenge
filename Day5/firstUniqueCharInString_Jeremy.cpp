#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/*
Runtime : 56 ms
With boost : 32 ms
*/
int firstUniqChar(string s) {
    // init lowercase ascii vector
    vector<char> v = {};
    for (int i = 97; i < 97 + 26; i++) {
        v.push_back(i);
    }

    // init ans 
    int ans = s.size();

    for (char c : v) {
        // find first instance of char
        size_t left = s.find(c);

        if (left != string::npos && left == s.rfind(c)) {
            if (ans > left)
                ans = left;
        }
    }

    if (ans != s.size()) 
        return ans;
    else 
        return -1;
    
}

int main() {
    int ret = firstUniqChar("leetcode");
    cout << "ret : " << ret << endl;
    return 0;
}