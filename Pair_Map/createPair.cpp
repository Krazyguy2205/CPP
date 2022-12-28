#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> ip = {100, 200};
    cout << ip.first << endl;
    cout << ip.second << endl;

    tuple<int, int, int> t = {1, 2, 3};
    cout << get<0>(t);
}