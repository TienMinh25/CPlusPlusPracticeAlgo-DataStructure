#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool check = true;

void khoitao(vector<char>& A, int n) {
    for (int i = 1; i <= n; i++) {
        A[i] = 'A';
    }
}

void sinh(vector<char>& A, int n){ 
    int i = n;

    while (i > 0 && A[i] == 'B') {
        A[i] = 'A';
        i--;
    }

    if (i != 0) {
        A[i] = 'B';
    }
    else check = false;

}

bool checkValid(vector<char> &A, int n, int k) {
    int dem = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 'A') {
            ++dem;
        }
        else {
            dem = 0; // nếu gặp dãy bị break thì cập nhật lại biến đếm
        }
        if (dem > k) { // nếu biến dem > k, nghĩa là dãy con ko chỉ gồm k ptu
            return false;
        }
        if (dem == k) { // neu biến dem > k thì tăng biến kết quả để đếm số dãy có k phần tử
            ++res;
        }
    }

    return res == 1; // so sánh xem mảng đó chỉ có duy nhất 1 dãy gồm k phần tử liên tiếp phần tử 'A'
}


int main() {
    int n, k; 
    cin>>n>>k;
    vector<char> A(n+1);

    khoitao(A, n);

    while (check) {
        if (checkValid(A, n, k)) {
            for (int i = 1; i <= n; i++) {
                cout<<A[i];
            }

            cout<<endl;
        }
        
        sinh(A, n);
    }
       

    return 0;
}