#include <iostream>
#include <set>

using namespace std;

set<int> creatSet(int n)
{
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    set<int> s = creatSet(n);
    cout << s.size() << endl;
    return 0;
}