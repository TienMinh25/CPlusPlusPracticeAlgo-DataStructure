#include<iostream>
#include<vector>

/*
    @params:
    n: Tổng của đề bài cho
    vector<int> a: mảng lưu cấu hình
    ok: kiểm tra xem đã là cấu hình cuối cùng chưa
    cnt: đếm số lượng số hạng trong tổng 
    d: tính số phần bù còn thiếu để cộng thành tổng n 
*/
using namespace std;

int n, ok, cnt;
vector<int> a(100);

void ktao() {
    cnt = 1;
    a[1] = n;
}

void sinh() {
    int i = cnt;
    while (i >= 1 && a[i] == 1) {
        --i;
    }

    if (i == 0) ok = 0;
    else {
        a[i]--;
        int d = cnt - i + 1; 
        cnt = i; // luc nay xem phan phan tich chi co i thang thoi, phan con thieu chua bieu dien vao
        int q = d / a[i]; // xem d gap may lan thang a[i] de bieu dien d qua a[i]
        int r = d % a[i]; // kiem tra xem co du ko
        if (q) {
            for (int j = 1; j <= q; j++) {
                ++cnt;
                a[cnt] = a[i];
            } 
        }

        if (r) {
            ++cnt;
            a[cnt] = r;
        }
    }
}

int main(){
    int t; cin >> t;
    while (t--) {
        ok = 1;
        cin >> n;
        ktao();

        while (ok) {
            cout << "( ";
            for (int i = 1; i <= cnt; ++i) {
                cout<< a[i] << " ";
            }
            cout << ") ";
            sinh();
        }
        cout<<endl;
    }
    
}