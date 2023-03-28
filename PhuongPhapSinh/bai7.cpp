#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> & A, int n) {
    for (int i = 1; i <= n; i++) {
        cout<<A[i];
    }
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

bool checkValid(vector<int>& A, int n, int k) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 1) cnt++;
    }
    if (cnt == k) return true;
    return false;
}

void listConfig(vector<int>& A, int n, int k) {
    A.clear(); // xoa mang 
    // khoi tao
    khoitao(A, n);
    bool check = true;

    while (check) {
        if(checkValid(A, n, k)) {
            print(A, n);    
            cout<<"  ";
        }
        nextConfig(A, n, check); // in ra cau hinh tiep theo
    }
    cout<<endl;
}

int main() {
    int T;
    cout<<"Nhap so luong test case: "<<endl;
    cin>>T;
    while (T) {
        int n, k; cin >> n >> k;
        vector<int> A(n+1);

        listConfig(A, n, k);
        T--;
    }
    

    return 0;
}