class Solution {
public:
    typedef long long ll;

    // Helper to count pairs with product <= mid
    ll countPairs(vector<int>& nums1, vector<int>& nums2, ll mid) {
        ll count = 0;
        int n = nums2.size();

        for (int a : nums1) {
            if (a > 0) {
                // count elements in nums2 where a * nums2[j] <= mid
                int l = 0, r = n - 1, pos = -1;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if ((ll)a * nums2[m] <= mid) {
                        pos = m;
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
                count += (pos + 1);
            } 
            else if (a < 0) {
                // count elements in nums2 where a * nums2[j] <= mid
                int l = 0, r = n - 1, pos = n;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if ((ll)a * nums2[m] <= mid) {
                        pos = m;
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                count += (n - pos);
            } 
            else {
                if (mid >= 0) count += n;
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        ll low = -1e10, high = 1e10, ans = 0;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll cnt = countPairs(nums1, nums2, mid);
            if (cnt >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
