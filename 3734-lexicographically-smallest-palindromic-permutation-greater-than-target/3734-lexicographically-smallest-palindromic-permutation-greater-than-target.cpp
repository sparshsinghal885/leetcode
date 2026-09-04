class Solution {
public:
    string res = "";
    
    bool solve(string& curr, string& target, vector<int>& count, int i, bool isGreater, char odd_char, int n){
        if(i == n / 2){
            string palin = curr;
            if(n % 2 != 0) palin.push_back(odd_char);
            
            string rev = curr;
            reverse(rev.begin(), rev.end());
            palin += rev;
            
            if(palin > target) {
                res = palin;
                return true;
            }
            return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(count[ch - 'a'] <= 0) continue;
            
            if(!isGreater && ch < target[i]) continue;

            curr.push_back(ch);
            count[ch - 'a']--;
            
            if(solve(curr, target, count, i + 1, isGreater || ch > target[i], odd_char, n)){
                return true;
            }

            curr.pop_back();
            count[ch - 'a']++;
        }
        return false;
    }
    
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);

        for(auto& c : s){
            count[c - 'a']++;
        }        

        int odds = 0;
        char odd_char = '\0';

        for(int i = 0; i < 26; i++){
            if(count[i] % 2 == 1){
                if(n % 2 == 0 || odds > 0)
                    return "";

                odd_char = 'a' + i;
                odds++;
            }

            count[i] /= 2;
        }

        string curr = "";
        solve(curr, target, count, 0, false, odd_char, n);
        
        return res;
    }
};