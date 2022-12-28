//Huyền có một cái điện thoại, màn hình điện thoại của Huyền chỉ hiển thị được tối đa k tin nhắn
//Màn hình của Huyền hiện thị như sau
  //Không hiện thị 2 tin nhắn của cùng một số điện thoại (SĐT) trên cùng một khung hình
  //nếu SĐT a gửi tin nhắn đến mà trên màn hình đã có tin nhắn của SĐT a thì màn hình không thay đổi gì
  //Khi SĐT a gửi tin nhắn đến mà trên màn hình chưa có tin nhắn của SĐT a thì
    //Nếu màn hình chưa đủ k tin nhắn thì tin nhắn của SĐT a sẽ được chèn vào cuối màn hình
    //Nếu màn hình đã có đủ k tin nhắn thì thì màn hình sẽ đẩy tin nhắn trên cùng ra và sau đó chèn tin nhắn của SĐT a vào cuối màn hình
//Cho dãy a là các SĐT sẽ gửi tin nhắn cho Huyền
//sau khi nhận được tin nhắn cuối cùng thì màn hình của Huyền đang hiển thì tin nhắn của các SĐT nào
// đưa ra theo thứ tự từ trên xuống dưới của màn hình
#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    bool b[1001];
    int a[1001];
    int n, k;
    cin >> n;

    for(bool & i : b) {
        i = false;
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> k;
    for(int i = 0; i < n; i++) {
        if(!b[a[i]]) {
            if(q.size() < k) {
                b[a[i]] = true;
                q.push(a[i]);
            } else {
                b[q.front()] = false;
                b[a[i]] = true;
                q.push(a[i]);
                q.pop();
            }
        }
    }

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}