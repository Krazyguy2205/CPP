#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k, value;
    queue<int> q;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    cin >> k;
    for(int i = 0; i < k; i++) {
        int x = q.front();
        q.pop();
        q.push(x);
    }

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}