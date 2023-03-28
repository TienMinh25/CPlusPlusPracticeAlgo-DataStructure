#include<iostream>
#include<vector>

using namespace std;

void nhapXau(string& A) {
    cin.ignore(); // xoa bo nho dem
    cin>> A;
}

void nextConfig(string& A) {
    int n = A.size();
    int i = n - 1;

    while (i >= 0 && A[i] == '1') { // dich tung bit sang trai, den bit 0 thi dung lai
        A[i] = '0';
        i--;
    }

    if (i != -1) A[i] = '1';
}

int main() {
    int T;
    string A;
    cin >> T;
    while (T--) {
        nhapXau(A);
        nextConfig(A);
        cout<<"Cau hinh moi: "<< A;
        cout<<endl;
    }
}
