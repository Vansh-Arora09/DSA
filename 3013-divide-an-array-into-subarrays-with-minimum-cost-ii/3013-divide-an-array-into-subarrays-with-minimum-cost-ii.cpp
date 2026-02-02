
#include <bits/extc++.h>
#define ST first

using namespace __gnu_pbds;

template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class Solution
{
public:
    long long minimumCost(const vector<int> &nums, int k, int dist)
    {
       const auto nums_indexed = views::zip(nums | views::drop(1), views::iota(0));

        _tree<pair<int, int>> t;
        for (const auto i : nums_indexed | views::take(dist + 1))
            t.insert(i);
        
        const auto itr = t.find_by_order(k - 1);
        int64_t sum = 0;
        for (const auto jtr : views::iota(t.begin(), itr))
            sum += jtr->ST;

        int64_t mn = sum;
        for (const auto sliding_window : nums_indexed | views::slide(dist + 2))
        {
            if (t.order_of_key(sliding_window.front()) < k - 1)
            {
                sum -= get<0>(sliding_window.front());
                sum += t.find_by_order(k - 1)->ST;
            }
            t.erase(sliding_window.front());

            t.insert(sliding_window.back());
            if (t.order_of_key(sliding_window.back()) < k - 1)
            {
                sum += get<0>(sliding_window.back());
                sum -= t.find_by_order(k - 1)->ST;
            }

            mn = min(mn, sum);
        }

        return nums.front() + mn;
    }
};