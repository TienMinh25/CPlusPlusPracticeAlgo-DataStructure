#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> a(1000);

void next(string s) {
    int i = s.length() - 2;
    while (i >= 0 && s[i] >= s[i + 1]) {
        --i;
    }

    if (i == -1) {
        cout<<"BIGGEST \n";
    }
    else {
        int j = s.length() - 1;
        while (s[i] >= s[j]) {
            --j;
        }
        swap(s[i], s[j]); // doi cho 2 ptu a[i] va a[j]
        reverse(s.begin() + i + 1, s.end()); // dao nguoc day tu i + 1 den s.length() - 1
        cout<< s <<endl;
    }
}

int main() {
    int T; cin>>T;
    while (T--) {
        int TC; cin>>TC;
        string s; cin>>s;
        cout<< "---------" << endl;
        cout<<TC << " ";
        next(s);
    }
    return 0;

}