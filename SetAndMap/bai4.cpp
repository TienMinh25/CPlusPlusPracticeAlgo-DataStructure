#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

void solveProblem(int t) {
    map<int, int> mp;
    while (t--) {
        int n; cin>>n;
        int result, resultLength = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            mp[x]++;
        }

        for (map<int,int>::iterator a = mp.begin(); a != mp.end(); a++) {
            if ((*a).second > resultLength) {
                resultLength = (*a).second;
                result = (*a).first;
            }
        }

        cout<<result<<"  "<<resultLength<<endl;
        mp.clear();
    }
}

int main() {
    int t; cin >> t;
    solveProblem(t);
    return 0;
}