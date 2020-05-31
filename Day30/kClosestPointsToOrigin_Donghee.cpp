class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        /*
        Uses priority queeu with min heap 
        */
        
        
        priority_queue<pair<double, vector<int>>, vector<pair<double,vector<int>>>, greater<pair<double,vector<int>>>> pq; 

        double dist;

        for (vector<int>& pt: points) {
            dist = sqrt(pt[0] * pt[0] + pt[1] * pt[1]);
            pq.push(make_pair(dist, pt));
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};

/* TIME LIMIT EXCEEDED: 

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        /*
        
        Algorithms:
        1) make a map of key(distance) and value(vector of points)
        2) as filling in the map, keeping the min and max value of distance
        3) iterate through all keys from min to max, add to a result points keeping counts of added points so far
        
        */
        
        
        unordered_map<int, vector<vector<int>>> mp;

        int dist;
        int maxd = INT_MIN;
        int mind = INT_MAX;

        for (vector<int>& pt: points) {
            dist = pt[0] * pt[0] + pt[1] * pt[1]; // not taking sqrt to keep it as an int rather than double
            maxd = max(maxd, dist);
            mind = min(mind, dist);
            mp[dist].push_back(pt);
        }
        
        vector<vector<int>> res;
        int count = 0;
        for (int i = mind; i <= maxd; i++) {
            if (count == k) return res;
            if (mp.find(i) != mp.end()) {
                for (vector<int>& pt: mp[i]) {
                    count++;
                    res.push_back(pt);
                    if (count == k) return res;
                }
            }
        }
        
        return res;
    }
*/