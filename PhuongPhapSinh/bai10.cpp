#include<iostream>
#include<vector>

using namespace std; 
/* 
    Ý tưởng: 
    - Bài này có thể hiểu rằng ta sẽ sinh 1 dãy con gồm k phần tử trong dãy ban đầu gồm n phần tử
    - Sinh ra 1 cấu hình mới
    - Sinh theo thứ tự
*/
int n, k, maxEle = INT_MIN, check = 1;

void nhap(vector<int>& a) {
    for (int i = 1; i <= k; i++) {
        cin>>a[i];
        if (maxEle < a[i]) maxEle = a[i];
    }
}

void sinh(vector<int>& a) {
    int i = k;
    
    while (i > 0 && a[i] == n - k + i) { // tim phan tu ma a[i] < n - k + 1
        i--;
    }

    if (i == 0) {
        check = 0;
    }
    else {
        a[i] = a[i] + 1;
        for (int j = i + 1; j <= k; j++) { // cap nhat lai cho cac ptu tu [i + 1, k]
            a[j] = a[j-1] + 1;
        }
    }
}

int main() {
    int T; cout<<"Nhap so luong test case: ";
    cin>>T;

    while (T) {
        cin >> n >> k;
        vector<int> a(k + 1);
        int prevEle = 0;
        
        nhap(a);
        vector<int> count(maxEle + 1, 0);
        
        for (int i = 1; i <= k; i++) { // khoi tao ra mang dem
            count[a[i]]++;
        }


        sinh(a); // sinh cau hinh tiep theo

        if (check) { // kiem tra xem do da la nhom cuoi cung chua
            for (int i = 1; i <= k; i++) { // cap nhat lai mang dem
                count[a[i]]++;
            }

            for (int i = 1; i <= k; i++) {
                if (count[a[i]] == 2) prevEle++;
            }
            
        }
        cout<<k - prevEle<<endl; // in ra ket qua nhung nguoi cu dc nghi
        check = 1; // cap nhat lai bien check cho cac truong hop o sau
        T--;
    }
    
    return 0;
}