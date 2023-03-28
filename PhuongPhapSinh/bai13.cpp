#include<iostream>
#include<vector>

using namespace std;
/*
    - Ý tưởng:
    - Sinh hết tất cả các xâu nhị phân có bit 0 và bit 9
    - Duyệt qua các xâu nhị phân và check xem xâu nhị phân đó có chia hết cho i ( 1 <= i <= 500)
    - Nếu chia hết thì đẩy vào mảng kết quả là a
    - Sau đó ta chỉ việc lấy ra khi cần
*/
vector<long long> a(505);
vector<long long> res;
int ok;

void next(string& s) {
    int i = s.length() - 1;
    while( i >= 0 && s[i] == '9') {
        s[i] = '0';
        --i;
    }

    if (i == -1) {
        ok = 0;
    }
    else {
        s[i] = '9';
    }
}

int main() {
    string s(13, '0'); // khoi tao xau nhi phan gom 13 bit
    ok = 1;
    next(s); // de qua cai so 0, vi so 0 chia cho so nao cx bang 0
    
    while (ok) {
        res.push_back(stoll(s));
        next(s);
    }
    
    for (int i = 1; i <= 500; i++) {
        for(int j = 0; j < res.size(); j++) {
            if (a[i] == 0 && res[j] % i == 0) { // kiem tra xem neu a[i] chua co boi va bien res[j] chia het cho i
                a[i] = res[j];
            }
        }
    }

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        cout << a[n] <<endl;
    }

    return 0;
}