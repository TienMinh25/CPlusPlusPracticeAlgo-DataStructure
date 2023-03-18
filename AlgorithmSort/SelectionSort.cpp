#include<vector>
#include<iostream>
#include<math.h>

using namespace std;

void SelectionSort(vector<int>& a, int n) {
    for (int i = 0; i < n - 1; i++) { // sap xep tang dan
        int indMin = i;

        for (int j = i + 1; j < n; j++) {  
            if (a[j] < a[indMin]) { // tim kiem vi tri cua phan tu nho hon
                indMin = j;
            }
        }

        swap(a[indMin], a[i]); // doi cho cua phan tu thu i va phan tu nho nhat co index la indMin
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
    SelectionSort(A,n);
    printResult(A,n);
}