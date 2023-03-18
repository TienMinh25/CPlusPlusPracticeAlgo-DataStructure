#include<vector>
#include<iostream>
#include<math.h>

using namespace std;

void InsertionSort(vector<int>& a, int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1; 
        int key = a[i];

        while (j >= 0 && a[j] > key )  { // sap xep tang dan
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void printResult(vector<int>& a, int n) {
    cout<<"Ham sau khi sap xep la: "<<endl;
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}

int main() {
    int n; cin>>n;
    vector<int> A(n);

    srand(time(NULL));
    for (int i = 0; i < n; i++) { // sinh ngau nhien cac phan tu trong mang
        A[i] = rand() % 1000;
    }

    cout<<"Ham truoc khi sap xep la :" <<endl;
    printResult(A,n);
    InsertionSort(A,n); // dung ham sap xep
    printResult(A,n); // in ket qua ra man hinh
}