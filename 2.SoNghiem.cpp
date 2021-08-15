// #include<bits/stdc++.h>
#include <iostream>
using namespace std;
int giaithua (int n)
{
    int s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return s;
}
int so_nghiem(int m, int n)
{
    return giaithua(n + m - 1) / (giaithua(m) * giaithua(n - 1));
}
int main()
{
    int n, m;
    cin >> m;
    cin >> n;
    cout << so_nghiem(m, n) << endl;
    return 0;
}