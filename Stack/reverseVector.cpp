#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> popMin(vector<int> arr) {
    stack<int> st_min;
    vector<int> res;
    st_min.push(arr[0]);
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] >= st_min.top()) {
            st_min.push(st_min.top());
        } else {
            st_min.push(arr[i]);
        }
    }

    while(!st_min.empty()) {
        res.push_back(st_min.top());
        st_min.pop();
    }
    return res;
}

int main() {
    vector<int> arr = {4,2,6,7,8,1};
    vector<int> res = popMin(arr);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}