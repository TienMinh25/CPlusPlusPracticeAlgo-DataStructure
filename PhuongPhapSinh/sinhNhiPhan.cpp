#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> & A, int n) {
    for (int i = 1; i <= n; i++) {
        cout<<A[i];
    }
    cout<<endl;
}

void khoitao(vector<int> &A, int n) {
    for (int i = 1; i <= n; i++) {
        A.push_back(0);
    }
}

void nextConfig(vector<int>& A, int n, bool& check) {
    int i = n;

    while (i >= 1 && A[i] == 1) { // tim bit 0 dau tien
        A[i] = 0;
        i--;
    }

    if (i == 0) {
        check = false; // day la cau hinh cuoi cung
    }
    else {
        A[i] = 1;
    }

}

void listConfig(int n) {
    vector<int> A(n+1);
    // khoi tao
    khoitao(A, n);
    bool check = true;

    while (check) {
        print(A, n);
        nextConfig(A, n, check);
    }
}

int main() {
    int n; cin >> n;
    listConfig(n);

    return 0;
}