//Danh sach canh -> ma tran ke
#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int dinh, canh;
int a[MAX][MAX];

int main() {
    cin >> dinh >> canh;
    for(int i = 0; i < canh; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for(int i = 1; i <= dinh; i++) {
        for(int j = 1; i <= dinh; i++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}