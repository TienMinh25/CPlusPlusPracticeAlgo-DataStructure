#include<vector>
#include<iostream>

using namespace std;

void inputArray(vector<int>&A, int k) {
    A.clear(); // xoa mang truoc khi nhap
    for (int i = 1; i <= k; i++) {
        cin>>A[i];
    }
}

void nextConfig(vector<int>& A, int k, int n ) {
    // n - k + i
    int i = k;
    while (i >= 1 && A[i] == n - k + i) {
        i--;
    }

    if (i != 0) {
        A[i]++;
        for (int j = i + 1; j <= k; j++) A[j] = A[j-1] + 1;
    }
    else {
        for (int j = 1; j <= k; j++) {
            A[j] = j;
        }
    }
}

int main() {

    int T; 
    cout<<"Nhap so luong test case: "<<endl;
    cin>>T;

    while(T) {
        int n; cin>>n;
        int k; cin>>k;
        vector<int> A(k+1);

        inputArray(A, k);
        nextConfig(A, k, n);
        cout<<"Cau hinh tiep theo la: ";
        //in ra man hinh sau khi sinh ra tap con ke tiep
        for (int i = 1; i <= k; i++) cout<<A[i] << " "; 
        cout<<endl;
        T--;
    }

    return 0;
}