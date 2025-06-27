class Solution {
public:
    int k;

    // Check if t appears in s as a subsequence at least k times
    bool isKSubsequence(const string &s, const string &t, int k) {
        int cnt = 0;
        int n = s.length(), m = t.length();
        for (int i = 0; i < n; ) {
            int j = 0;
            while (i < n && j < m) {
                if (s[i] == t[j]) j++;
                i++;
            }
            if (j == m) cnt++;
            if (cnt >= k) return true;
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        this->k = k;
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string chars = "";
        for (int i = 0; i < 26; ++i) {
            if (freq[i] >= k) {
                int repeat = min(freq[i] / k, 2); // limit repetition
                chars += string(repeat, 'a' + i);
            }
        }

        string best = "";
        queue<string> q;
        q.push("");

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            for (char c : chars) {
                string next = cur + c;
                if (isKSubsequence(s, next, k)) {
                    if (next.length() > best.length() ||
                        (next.length() == best.length() && next > best)) {
                        best = next;
                    }
                    q.push(next);
                }
            }
        }
        return best;
    }
};
