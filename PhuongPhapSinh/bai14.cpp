#include<iostream>
#include<vector>

using namespace std;
int n, k, ok;
vector<int> a(1000);

void ktao() {
    for (int i = 1; i <= n; i++) a[i] = 0;
}

void next() {
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }

    if (i == 0) {
        ok = 0;
    }
    else {
        a[i] = 1;
    }
}

bool check() {
    if (a[1] == 0 || a[n] == 1) return false; // xem 'H' la bit 0, A la bit '1'
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] == 1 && a[i+1] == 1)
            return false;
    }

    return true;
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin>>n;
        ktao();
        ok = 1;
        while(ok) {
            if (check()){
                for (int i = 1; i <= n; i++) 
                    if(a[i] == 0) cout<<"A";
                    else cout<<"H";
                cout<<endl;
            }
            next();
        }
    }
    return 0;
}