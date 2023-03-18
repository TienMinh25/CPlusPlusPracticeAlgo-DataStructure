#include<iostream>
#include<vector>

using namespace std;

void printResult(vector<int>& a, int n) {
    cout<<"Ham sau khi sap xep la: "<<endl;
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}

void Merge(vector<int>& a, int l, int m, int r) {
    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);

    int i = 0, j = 0;

    while(i < left.size() && j < right.size()) { // sap xep tang dan
        if (left[i] <= right[j]) {
            a[l] = left[i];
            i++;
            l++;
        }
        else {
            a[l] = right[j];
            j++;
            l++;
        }
    }

    while (i < left.size()) {
        a[l] = left[i];
        l++;
        i++;
    }

    while (j < right.size()) {
        a[l] = right[j];
        l++;
        j++;
    }
}

void MergeSort(vector<int>& a, int l, int r) {
    if (l>=r) return;
    int m = (l+r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m+1, r);
    Merge(a, l, m, r);
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
    MergeSort(A, 0, n - 1); // dung ham sap xep
    printResult(A,n); // in ket qua ra man hinh
}