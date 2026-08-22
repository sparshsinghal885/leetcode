#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vpll = vector<pll>;
using vpii = vector<pii>;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define b2e(v) v.begin(), v.end()
#define loop(i, a, b) for (ll i = (a); i <= (b); i++)
#define rloop(i, a, b) for (ll i = (a); i >= (b); i--)

const ll MOD = 1e9 + 7;
const ll INF = 1e15;

class SegmentTree{
public:
    vi tree;

    SegmentTree(int n){
        tree.resize(4*n+10);
    }

    void update(int node, int start, int end, int idx){
        if(start == end){
            tree[node]++;
            return;
        }
        int mid = start + (end - start)/2;
        if(idx <= mid) update(2*node+1, start, mid, idx);
        else update(2*node+2, mid+1, end, idx);

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    int query(int node, int start, int end, int left, int right){
        if(start > right || end < left) return 0;
        if(start <= left and end <= right) return tree[node];

        int mid = start + (end - start)/2;
        int l = query(2*node+1, start, mid, left, right);
        int r = query(2*node+2, mid+1, end, left, right);

        return l + r;
    }
};
class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size();
        if(n < 2) return 0;

        vi left(n, 0), right(n);

        int j=0;
        loop(i, 0, n-1){
            while(skill[i] != station[j]) j++;

            left[i] = j;
            j++;
        }

        j=m-1;
        rloop(i, n-1, 0){
            while(skill[i] != station[j]) j--;
            right[i] = j;
            j--;
        }

        int ans = 0;
        loop(i, 1, n-1){
            int temp = right[i] - left[i-1];
            ans = max(ans, temp);
        }
        return ans;
    }
};
static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();