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

bool checkValid(vector<int>& A) {
    int l = 1, r = A.size();

    while (l < r) {
        if (A[l] != A[r]) return false;
        l++;
        r--;
    }

    return true;
}

void listConfig(vector<int>& A, int n) {
    A.clear(); // xoa mang 
    // khoi tao
    khoitao(A, n);
    bool check = true;

    while (check) {
        if(checkValid(A)) {
            print(A, n);
            cout<<"    ";
        }
        nextConfig(A, n, check); // in ra cau hinh tiep theo
    }
    cout<<endl;
}

int main() {
    int T;
    cout<<"Nhap so luong test case: "<<endl;
    cin>>T;
    while (T--) {
        int n; cin >> n;
        vector<int> A(n+1);

        listConfig(A, n);
    }
    

    return 0;
}