#include <iostream>
#include <vector>

using namespace std;

void khoitao(vector<int> &A, int n)
{
    A.clear(); // lam sach mang truoc khi nhap
    for (int i = 1; i <= n; i++)
        cin >> A[i];
}

void nextConfig(vector<int> &A, int n)
{
    int i = n;
    while (i >= 1 && A[i] > A[i + 1])
    { // tim con A[i] < A[i + 1]
        i--;
    }

    if (i != 0)
    { // nghia la chua phai cau hinh cuoi cung
        // doi cho con be nhat trong khoang tu [i+1, n] ma lon hon A[i]
        for (int j = n; j > i; j--)
        {
            if (A[j] > A[i])
            {
                swap(A[i], A[j]);
                break;
            }
        }

        int left = i + 1, right = n;
        while (left < right)
        {
            swap(A[left], A[right]);
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
            A[i] = i;
    }
}

int main()
{
    int T;
    cout << "Nhap vao so luong test case: " << endl;
    cin >> T;

    while (T)
    {
        int n;
        cin >> n;
        vector<int> A(n + 1);

        khoitao(A, n);    // nhap dau vao
        nextConfig(A, n); // next cau hinh tiep theo

        cout << "Cau hinh moi la: ";
        for (int i = 1; i <= n; i++)
        { // in ra man hinh sau khi next cau hinh
            cout << A[i] << " ";
        }

        cout << endl;
        T--;
    }
    return 0;
}