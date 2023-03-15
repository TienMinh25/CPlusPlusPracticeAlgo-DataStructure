#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

void solveBySet(int t)
{
    while (t--)
    {
        int n;
        cin >> n;
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            st.insert(x);
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
            if (st.find(x) != st.end())
            {
                cout << "YES \n";
            }
            else
                cout << "NO\n";
        }
    }
}

void solveByMap(int t)
{
    while (t--)
    {
        int n;
        cin >> n;
        map<int, bool> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x] = true;
        }

        int q;
        cin >> q;

        while (q--)
        {
            int x;
            cin >> x;
            if (mp.find(x) != mp.end())
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }
}

int main()
{
    int t;
    cin >> t;
    solveBySet(t);
    solveByMap(t);
    return 0;
}