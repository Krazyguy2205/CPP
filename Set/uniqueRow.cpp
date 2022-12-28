#include<iostream>
#include<set>
#include<vector>

using namespace std;

vector<vector<int>>uniqueRow(vector<vector<int>>matrix)
{
    set<vector<int>>s;  // set<set<int>>s sẽ không nhận các giá trị giống nhau, nên phải khai báo set<vector<int>>s
    vector<vector<int>>result;
    // p = matrix.begin() là trỏ đến dòng đầu tiên
    for(vector<vector<int>>::iterator p = matrix.begin();p !=matrix.end(); p++)
    {
        if( !s.count(*p) )  // s.count(*p) dùng để kiểm tra từng dòng, nếu có trong set s thì trả về 1, không có thì trả về 0
        {                   // !1 là 0    !0 là 1     trả về 1 tức là true thì thực hiện
            s.insert(*p);
            result.push_back(*p);
        }
    }
    return result;
}

int main()
{
    int row = 3, column = 4;


    vector<vector<int>>matrix; // có thể hiểu matrix lúc này giống như mảng 2 chiều

    matrix.resize(row);        // khởi tạo  matrix 3 dòng


    for(int i=0; i<matrix.size(); i++)
    {
        matrix[i].resize(column);          // 3 dòng, mỗi dòng khởi tạo 4 phần tử
    }


    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)      //nhập ví dụ ở đề bài    1 1 0 1
        {                                //                       1 0 0 1
            cin >> matrix[i][j];         //                       1 1 0 1
        }
    }


    cout << "________________________________________________________" << endl;


    // vì hàm uniqueRow(matrix) trả về vector result nên có thể gán cho 1 vector khác
    vector<vector<int>>run = uniqueRow(matrix);    // ở đây là gán result cho vector run

    for(int i=0; i<run.size(); i++)
    {
        for(int j=0; j<run[i].size(); j++)
        {
            cout << run[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    system("pause");
}