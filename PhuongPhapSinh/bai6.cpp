#include<vector>
#include<iostream>

using namespace std;

bool check = true;

void khoitao(vector<int>& A, int n) {
    for (int i = 1; i <= n; i++) 
        A[i] = n - i + 1;
}

void sinh(vector<int>& A, int n) {
    int i = n - 1;
    
    while (i > 0 && A[i] < A[i + 1]){
        i--;
    }

    if (i == 0) { // khong sinh duoc cau hinh nao nua
        check = false;
    }   
    else {
        int prevResult = i + 1; // tim chi muc 
        // tim chi muc thang lon nhat va nho hon A[i] trong day [i+1, n]
        for (int j = i+1; j <= n; j++) {
            if (A[i] > A[j]) {
                if (A[j] > A[prevResult]) {
                    prevResult = j;
                }
            }
        }

        swap(A[i], A[prevResult]);

        // sap xep lai cac phan tu theo thu tu giam dan
        // luc nay mang tu [i+1, n] la day tang dan
        int left = i+1, right = n;
        while (left < right) {
            swap(A[left], A[right]);
            left++;
            right--;
        }
    }
}

int main(){
    int T;
    cout<<"Nhap vao so luong test case: "<<endl;
    cin>>T;

    while (T) {
        int n; cin>>n;
        vector<int> A(n+1);
        khoitao(A, n);

        while(check) {
            for (int i = 1; i <= n; i++) { // in ra man hinh
                cout<<A[i];
            }
            cout<<"  ";
            sinh(A, n);
        }
        cout<<endl;
        check = true; // cap nhat lai bien check
        T--;
    }

    return 0;
}