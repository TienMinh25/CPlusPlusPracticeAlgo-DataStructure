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

int main() {
    int T;
    cout<<"Nhap vao so luong test case: "<<endl;
    cin>>T;

    while (T) {
        int n; 
        cin>>n;
        vector<char> A(n+1);

        khoitao(A, n);

        while (check) {
            for (int i = 1; i <= n; i++) {
                cout<<A[i];
            }
            cout<<" ";
            sinh(A, n);
        }
        cout<<endl;
        check = true; // cap nhat lai bien check (vi bien check dang o pham vi global)
        T--;
    }

    return 0;
}