class Solution {
public:
    string res = "";
    int n;

    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        n = s.size();
        for(auto& ch : s){
            count[ch-'a']++;
        }
        solve("", s, target, 0, false, count);
        return res;
    }

    bool solve(string curr, string& s, string& target, int i, bool greater, vector<int>& count){
        if(i == n){
            if(greater){
                res = curr;
                return true;
            }
            return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(count[ch-'a'] <= 0) continue;
            if(greater == false && ch < target[i]) continue;

            curr.push_back(ch);
            count[ch - 'a']--;
            bool isGreater = greater || ch > target[i];

            if(solve(curr, s, target, i+1, isGreater, count)) return true;

            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
};