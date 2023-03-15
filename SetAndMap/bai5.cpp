#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

void solveProblem(int t) {
    map<char, int> mp;
    while (t--){
        string s;
        cin.ignore();
        getline(cin, s);
        int maxLengthString = 0;
        int result;
        for (int i = 0; i <s.size(); i++) {
            mp[s[i]]++;
        }

        for (map<char,int>::iterator a = mp.begin(); a!=mp.end(); a++) {
            if ((*a).second > maxLengthString) {
                maxLengthString = (*a).second;
                result = (*a).first;
            }
        }
        cout<<(char)result<<endl;
        mp.clear();
    }
}

int main() {
    int t; cin>>t;
    solveProblem(t);
    return 0;
}