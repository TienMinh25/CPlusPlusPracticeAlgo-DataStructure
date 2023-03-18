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

int Partition(vector<int> &a, int l, int r, int pivot) { // theo Lomuto
    int low = l;
    int high = r - 1;
    // sap xep tang dan
    while (true) {
        while (low <= high && a[low] <= pivot) low++; // tim phan tu dau tien tu trai sang phai lon hon hoac bang pivot
        while (low <= high && a[high] >= pivot) high--; // tim phan tu dau tien tu phai sang trai be hon hoac bang pivot

        if (low >= high) break; // neu duyet xong roi thi thoat khoi vong lap
        swap(a[low], a[high]); // doi vi tri cua 2 phan tu 
        low++; // vi low hien tai da xet, tang low de xet tiep
        high--; // vi high hien tai da xet, giam high de xet tiep
    }

    swap(a[r], a[low]); // doi vi tri cua phan tu pivot va phan tu dang tro vao low, luc nay low dang tro vao cho ma 1 ptu bat ki lon hon hoac bang no
    return low; // tra ve vi tri cua pivot, se dung de chia doi mang
}

void QuickSort(vector<int>& a, int l, int r) {
    if (l >= r) return;

    int pivot = a[r];
    int mid = Partition(a, l, r, pivot);

    QuickSort(a, l, mid - 1);
    QuickSort(a, mid + 1, r);
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
    QuickSort(A, 0, n - 1); // dung ham sap xep
    printResult(A,n); // in ket qua ra man hinh
}