#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int solveProblemBySet(vector<int> &a)
{
    set<int> st;
    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }
    return st.size();
}

int solveProblemByMap(vector<int> &a)
{
    map<int, int> mp;
    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]] = 1;
    }
    return mp.size();
}

int main()
{
    int n;
    cout << "Nhap so luong so can kiem tra: " << endl;
    cin >> n;
    vector<int> test(n);

    for (int i = 0; i < n; i++)
    {
        cin >> test[i];
    }

    cout << "Xu li bang set: " << solveProblemBySet(test) << endl;
    cout << "Xu li bang map: " << solveProblemByMap(test) << endl;
    return 0;
}