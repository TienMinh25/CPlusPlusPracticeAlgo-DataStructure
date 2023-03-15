#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

void solveBySet(int t)
{
    set<int> st;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a1(n), a2(m);
        bool found = false;
        for (int i = 0; i < n; i++)
            cin >> a1[i];
        for (int i = 0; i < m; i++)
            cin >> a2[i];
        for (int i = 0; i < m; i++)
        {
            st.insert(a2[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (st.find(a1[i]) == st.end())
            {
                found = true;
                cout << a1[i] << "  ";
            }
        }
        cout << endl;
        if (!found)
            cout << "NOT FOUND" << endl;
        st.clear();
    }
}

void solveByMap(int t)
{
    map<int, bool> mp;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a1(n), a2(m);
        bool found = false;
        for (int i = 0; i < n; i++)
            cin >> a1[i];
        for (int i = 0; i < m; i++)
            cin >> a2[i];
        for (int i = 0; i < m; i++)
        {
            mp[a2[i]] = true;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp.find(a1[i]) == mp.end())
            {
                found = true;
                cout << a1[i] << "  ";
            }
        }
        cout << endl;
        if (!found)
            cout << "NOT FOUND" << endl;
        mp.clear();
    }
}

int main()
{
    int t;
    cin >> t;
    // solveBySet(t);
    solveByMap(t);
}