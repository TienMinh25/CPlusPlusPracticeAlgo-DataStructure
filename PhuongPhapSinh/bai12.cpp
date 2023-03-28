#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
    De y ket qua thi thay:
        1 3 2
row:    1 2 3  
col:    1 3 2
    se thay cac hang i chay tu tu 1 den 3
    con cac chi muc in ra se la cac cot
    => ta se sinh hoan vi n hang
    va kiem tra xem cau hinh do co thoa man bang tong k da cho hay khong
    bieu dien moi so se la mt[i][a[i]];
    a[i]: luu lai index cua cot
*/
int main() {
    vector<vector<int> > mt(100, vector<int>(100)); // mang ma tran nhap vao
    vector<int> a(1005); // luu cau hinh hien tai

    vector<vector<int> > result; // luu cac cau hinh thoa man yeu cau bai toan
    int n, k;
    cin >> n >> k;

    // nhap ma tran
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)    
            cin>>mt[i][j];

    // khoi tao cau hinh
    for (int i = 1; i <= n; i++) a[i] = i; 
    do {
        int sum = 0;
        for (int i = 1; i <= n; i++) sum += mt[i][a[i]];

        if (sum == k) { // kiem tra xem cau hinh co thoa man khong
            vector<int> tmp(a.begin() + 1, a.begin() + n + 1); // sao chep lai cau hinh thoa man;
            result.push_back(tmp);
        }
    }
    while (next_permutation(a.begin() + 1, a.begin() + n + 1)); // ham co san trong thu vien

    // in ket qua ra man hinh
    cout<<result.size()<<endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout<< result[i][j] << " ";
        }
        cout<<endl;
    }
}