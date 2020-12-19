#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
   public:
    vector<double> medianSlidingWindow(vector<int>& A, int K) {
        ordered_set st;
        vector<double> ans;
        long long N = A.size();
        for (long long i = 0; i < K; i++) {
            st.insert(A[i]);
        }
        if (K & 1) {
            ans.push_back(*st.find_by_order(K / 2));
            for (long long i = 0; i < N - K; i++) {
                st.erase(st.find_by_order(st.order_of_key(A[i])));
                st.insert(A[i + K]);
                ans.push_back(*st.find_by_order(K / 2));
            }
        } else {
            ans.push_back(((long long)*st.find_by_order(((K + 1) / 2) - 1) + (long long)*st.find_by_order(K / 2)) / 2.0);
            for (long long i = 0; i < N - K; i++) {
                st.erase(st.find_by_order(st.order_of_key(A[i])));
                st.insert(A[i + K]);
                ans.push_back(((long long)*st.find_by_order(((K + 1) / 2) - 1) + (long long)*st.find_by_order(K / 2)) / 2.0);
            }
        }
        return ans;
    }
};