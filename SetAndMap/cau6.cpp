#include<iostream>
#include<set>
 
using namespace std;

int main() {
    int t; cin>>t;
    cin.ignore();

    while(t--) {
        string s;
        getline(cin, s);
        set<char> st;
        for (int i = 0; i < s.size(); i++) {
            st.insert(tolower(s[i]));
        }
        if(st.size() == 26) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}