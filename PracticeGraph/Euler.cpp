//Điều kiện để đồ thị có chu trình, đường đi euler
//1. Đồ thị vô hướng
//Đồ thị vô huowngs có chu trình euler nếu:
//  -> Các đỉnh có bậc khác 0 liên thông
//  -> Tất cả các đỉnh có bậc chẵn
//Đồ thị vô hướng có đường đi euler nếu:
//  -> Các đỉnh có bậc khác 0 liên thông
//  -> Đồ thị có 0 hặc 2 đỉnh bậc lẻ, trong truownghf hợp có 2 đỉnh bậc lẻ thì đường đi sẽ bắt đầu ở đỉnh bậc lẻ tứ 1 và kết thúc ở đỉnh ậc lẻ thứ 2

//2. Đồ thị có hướng
//Đồ thị có hướng có chu trình euler nếu:
//  -> Các đỉnh có bậc khác 0 thuộc cùng 1 thành phần liên thông
//  -> Mọi đỉnh thuộc đồ thị có bán bậc ra = bán bậc vào
//Đồ thị có hướng có đường đi euler nếu:
//  -> Các đỉnh có bậc khác 0 thuộc cùng một thành phần liên thông
//  -> tồn tại 2 đỉnh u, v mà deg+(u) - deg-(u) = 1 và deg-(v) - deg+(v) = 1
//  -> mọi đỉnh còn lại cáo bán bậc ra = bán bậc vào
//  -> khi đó đường đi sẽ bắt đầu ở u và kết thúc ở v

#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> adj[1001];
int degree[1001];

void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++;
        degree[y]++;
    }
}

void Euler(int v) {
    stack<int> st;
    vector<int> euler; // luu chu trinh
    st.push(v);
    while(!st.empty()) {
        int x = st.top();
        if(!adj[x].empty()) {
            st.push(*adj[x].begin());
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        } else {
            st.pop();
            euler.push_back(x);
        }
    }
    reverse(begin(euler), end(euler));
    for(int x : euler) {
        cout << x << " ";
    }
}

int main() {
    input();
    Euler(1);
}





















