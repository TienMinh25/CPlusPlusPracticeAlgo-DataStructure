#include <iostream>
#include <vector>
using namespace std;

vector<int> A(10000); // khai bao 10000 ptu
int n, k;
bool check = true;

void khoitao()
{
    for (int i = 1; i <= k; i++)
    {
        A[i] = i;
    }
}

void sinh()
{
    int i = k;
    while (i >= 1 && A[i] == n - k + i)
    {
        i--;
    }

    if (i == 0)
    {
        check = false;
    }
    else
    {
        A[i]++;

        for (int j = i + 1; j <= k; j++)
        {
            A[j] = A[j - 1] + 1;
        }
    }
}

int main()
{
    int T;
    cout<<"Nhap so luong test case: "<<endl;
    cin>>T;
     while (T) {
        cin >> n >> k;

        khoitao();
        while (check)
        {
            for (int i = 1; i <= k; i++)
            {
                cout << A[i];
            }
            cout<< " ";
            sinh();
        }
        cout << endl;
        check = true; //reset lai gia tri check
        T--;
    }

    return 0;
}