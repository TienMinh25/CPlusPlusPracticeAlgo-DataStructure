#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void printResult(vector<int>& a, int n) {
    cout<<"Ham sau khi sap xep la: "<<endl;
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}

void Heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    if (right < n && a[right] > a[largest]){
        largest = right;
    }

    if (largest != i) {
        swap(a[largest], a[i]);
        Heapify(a, n, largest);
    }
}

void HeapSort(vector<int>& a, int n) { // sap xep mang giam dan
    //xay dung min-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(a[i], a[0]);
        Heapify(a, i, 0);
    }
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
    HeapSort(A, n); // dung ham sap xep
    printResult(A,n); // in ket qua ra man hinh
}