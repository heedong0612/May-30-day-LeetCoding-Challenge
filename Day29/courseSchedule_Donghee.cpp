/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& preqs) {
        vector<int> visited(nc); // 0: unvisited, 1: viisted, 2: processing
        vector<vector<int>> adj(nc);
        
        // make a adjacency list    
        for (vector<int>& pr: preqs) {
            adj[pr[0]].push_back(pr[1]);
        }

        // check if there's a cycle
        for (int i = 0; i < nc; i++) {
            if (visited[i] == 0) {
                 visited[i] = 2; // processing
                
                if (!coloringGraph(i , visited, adj)) 
                    return false;
                
            } else if (visited[i] == 2) 
                return false;
        }
        return true;
    }
    
    bool coloringGraph(int curr, vector<int>& visited, vector<vector<int>>& adj) {
        for (int i = 0; i < adj[curr].size(); i++) { // for going through the adjacency matrix of the node i     
            if (visited[adj[curr][i]] == 2) 
                return false;
            
            if (visited[adj[curr][i]] == 0) {     
                visited[adj[curr][i]] = 2;
                
                if (!coloringGraph(adj[curr][i], visited, adj)) 
                    return false;
                
            }
        } 
        
        visited[curr] = 1;
        return true;
    }
};