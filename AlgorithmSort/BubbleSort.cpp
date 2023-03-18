#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int>& a, int n) { // sap xep tang dan
    bool checkSwap;
    for (int i = 0 ; i < n; i++) {
        checkSwap = false; // dat lai trang thai cho bien kiem tra
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {   // sap xep tang dan
                swap(a[j], a[j+1]); 
                checkSwap = true;
            }
        }

        if (!checkSwap) { // neu checkSwap = false, nghia la day khong can phai sap xep lai, ta ket thuc chuong trinh
            break;
        }
    }
}

void printResult(vector<int>& a, int n) {
    cout<<"Ham sau khi sap xep la: "<<endl;
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}

int main(){
    int n; cin>>n;
    vector<int> A(n);

    srand(time(NULL));
    for (int i = 0; i < n; i++) { // sinh ngau nhien cac phan tu trong mang
        A[i] = rand() % 1000;
    }
    cout<<"Ham truoc khi sap xep la :" <<endl;
    printResult(A,n);
    bubbleSort(A,n);
    printResult(A,n);
}