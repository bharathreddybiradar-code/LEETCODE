
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int N = n + 1;

        vector<int> s = nums;
        s.push_back(0);

        vector<int> p(N), c(N);

        int mx = max(N, *max_element(s.begin(), s.end()) + 1);
        vector<int> cnt(mx, 0);

        for (int x : s) cnt[x]++;

        for (int i = 1; i < mx; i++)
            cnt[i] += cnt[i - 1];

        for (int i = N - 1; i >= 0; i--)
            p[--cnt[s[i]]] = i;

        int classes = 1;
        c[p[0]] = 0;

        for (int i = 1; i < N; i++) {
            if (s[p[i]] != s[p[i - 1]])
                classes++;
            c[p[i]] = classes - 1;
        }

        vector<int> pn(N), cn(N);

        for (int h = 0; (1 << h) < N; h++) {
            int len = 1 << h;

            for (int i = 0; i < N; i++) {
                pn[i] = p[i] - len;
                if (pn[i] < 0) pn[i] += N;
            }

            fill(cnt.begin(), cnt.begin() + classes, 0);

            for (int x : pn)
                cnt[c[x]]++;

            for (int i = 1; i < classes; i++)
                cnt[i] += cnt[i - 1];

            for (int i = N - 1; i >= 0; i--)
                p[--cnt[c[pn[i]]]] = pn[i];

            cn[p[0]] = 0;
            int newClasses = 1;

            for (int i = 1; i < N; i++) {
                pair<int,int> cur = {
                    c[p[i]], c[(p[i] + len) % N]
                };

                pair<int,int> prev = {
                    c[p[i - 1]], c[(p[i - 1] + len) % N]
                };

                if (cur != prev)
                    newClasses++;

                cn[p[i]] = newClasses - 1;
            }

            c.swap(cn);
            classes = newClasses;
        }

        vector<int> sa;
        for (int x : p) {
            if (x != n)
                sa.push_back(x);
        }

        vector<int> rank(n), lcp(n, 0);

        for (int i = 0; i < n; i++)
            rank[sa[i]] = i;

        int k = 0;

        for (int i = 0; i < n; i++) {
            int r = rank[i];

            if (r == 0) continue;

            int j = sa[r - 1];

            while (i + k < n && j + k < n &&
                   nums[i + k] == nums[j + k])
                k++;

            lcp[r] = k;

            if (k > 0) k--;
        }

        int ans = n;

        for (int r = 0; r < n; r++) {
            int i = sa[r];

            int longest = lcp[r];

            if (r + 1 < n)
                longest = max(longest, lcp[r + 1]);

            if (longest < n - i)
                ans = min(ans, longest + 1);
        }

        return ans;
    }
};
