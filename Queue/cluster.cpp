#include <bits/stdc++.h>

int cluster(std::vector<std::vector<int>> arr) {
    std::queue<std::pair<int, int>> q;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 1) { //Duyệt các phần tử trong ma trận nếu phần tử nào bằng 1 thì chuyển thành 0
                //để khi dịch chuyển lên xuống trái phải không quay lại giá trị đó
                arr[i][j] = 0;
                ++ans;
                q.push({i, j}); //thêm vị trí của phần tử có giá trị bằng 1
            }

            while(!q.empty()) {
                int dx[] = {0, 1, 0, -1};
                int dy[] = {1, 0, -1, 0};
                for(int k = 0; k < 4; k++) {
                    int x = q.front().first + dx[k];
                    int y = q.front().second + dy[k];
                    //nếu khi dịch nó còn ở trong ma trận và thỏa mãn giá trị của nó bằng 1 thì
                    //lại chuyển về 0
                    //Và thêm địa chỉ đó vào
                    if(x >= 0 && x < arr.size() && y >= 0 && y < arr[i].size() && arr[x][y] == 1) {
                        arr[x][y] = 0;
                        ans++;
                        q.push({x, y});
                    }
                }
                q.pop(); //Xóa địa chỉ hiện tại mà đã lan xung quanh xong
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> ma;
    for(int i = 0; i < n; i++) {
        std::vector<int> arr1;
        for(int j = 0; i < m; j++) {
            int temp;
            std::cin >> temp;
            arr1.push_back(temp);
        }
        ma.push_back(arr1);
    }
    std::cout << cluster(ma);
    return 0;
}