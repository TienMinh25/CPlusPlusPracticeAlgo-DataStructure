#include<iostream>
#include<vector>

using namespace std;

vector<int> A(10000); // khai bao 10000 ptu
int n;
bool check = true;

void khoitao() {
    for (int i = 1; i <= n; i++) {
        A[i] = i;
    }
}

void sinh() {
    int i = n - 1;
    while ( i >= 1 && A[i] > A[i+1]) {
        i--;
    }

    if (i == 0) {
        check = false;
    }
    else {
        // di tim thang be nhat lon hon A[i]
        int f = n;
        while (f > i && A[i] > A[f]) f--;
        swap(A[i], A[f]); // doi cho 2 thang de ra cau hinh moi

        int j = i+1, k = n;
        while (j < k) {
            swap(A[j], A[k]);
            j++; k--;
        }
    }
}

int main() {
    cin >> n;

    khoitao();
    while (check) {
        for (int i = 1; i <= n; i++) {
            cout<<A[i];
        }
        cout<<endl;

        sinh();
    }
    return 0;
}