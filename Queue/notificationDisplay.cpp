#include <bits/stdc++.h>

using namespace std;

vector<int> messagesPhone(vector<int>& arr, int k)
{
    queue<int> q;
    set<int> se;
    for (auto x : arr)//Duyệt tất cả các phần tử trong arr
    {
        if (!se.count(x))//nếu như x không có trong set
        {
            if (se.size() == k)//và size==k thì xóa bỏ phần tử đầu tiên trong  q
            //và phần tử vừa thêm vào trong set
            {
                se.erase(q.front());
                q.pop();
            }
            //nếu như size<k thì thêm hết vào
            q.push(x);
            se.insert(x);
        }
        //nếu như x có trong set thì bỏ qua set và tiếp tục vòng lặp
        else
        {
            continue;
        }
    }
    vector<int> res;
    while (!q.empty())
    {
        res.push_back(q.front());
        q.pop();
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
    {
        cin >> x;
    }
    int k;
    cin >> k;
    for (int x : messagesPhone(arr, k))
    {
        cout << x << " ";
    }
    return 0;
}
