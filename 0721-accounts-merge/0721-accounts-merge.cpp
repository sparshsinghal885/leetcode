class UnionFind {
private:
    vector<int> parent;
    
public:
    UnionFind(int N) {
        parent.resize(N);
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x]); 
        return parent[x];
    }
    
    void unify(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx < ry) {
            parent[ry] = parent[rx];
        } else {
            parent[rx] = parent[ry];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int N = accounts.size();
        UnionFind uf(N);
        
        unordered_map<string, int> emails;
        unordered_map<int, string> name;  
        unordered_map<string, int> seen;  
        
        for (int id = 0; id < N; id++) {
            name[id] = accounts[id][0];
            for (int i = 1; i < accounts[id].size(); i++) {
                string email = accounts[id][i];
                emails[email] = id;
                if (seen.count(email)) {
                    uf.unify(id, seen[email]);
                } else {
                    seen[email] = id;
                }
            }
        }
        
        unordered_map<int, set<string>> filtered;
        for (auto& [email, id] : emails) {
            int root = uf.find(id);
            filtered[root].insert(email);
        }
        
        vector<vector<string>> res;
        for (auto& [k, v] : filtered) {
            vector<string> cur;
            cur.push_back(name[k]);
            for (const string& email : v) {
                cur.push_back(email);
            }
            res.push_back(cur);
        }
        
        return res;
    }
};