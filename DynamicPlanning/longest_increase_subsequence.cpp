//Cho mảng A gồm N phần tử, tìm dãy con tăng chặt dài nhất
//constraints:
//1 <= N <= 1000 || 1 <= A[i] <= 1000
//sample input:
//14
//128 104 53 876 660 961 754 290 231  224 915 392 994
//sample output:
//6
#include <bits/stdc++.h>
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //O(n^2)
    //L[i]: độ dài dãy con tăng dài nhất kết thức ở chỉ số i
    //L[i] = max{L[i], L[j] + 1} : a[i] > a[j]
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> L(n, 1);
    for(int i = 0; i < n; i++) {
        //duyệt qua từng ptu đứng trước chỉ số i
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                L[i] = std::max(L[i], L[j] + 1);
            }
        }
    }
    std::cout << *std::max_element(L.begin(), L.end()) << std::endl;
}