#include <bits/stdc++.h>

std::vector<int> stickSpan(std::vector<int> arr) {
    std::stack<int> st;
    std::vector<int> res;
    st.push(0);
    res.push_back(1);

    for(int i = 1; i < arr.size(); i++) {
        while(!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }

        res.push_back((st.empty()) ? (i + 1) : (i - st.top()));
        st.push(i);
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int & i : arr) {
        std::cin >> i;
    }
    for(auto x : stickSpan(arr)) {
        std::cout << x << " ";
    }
    return 0;
}