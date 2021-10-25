#include <bits/stdc++.h>

using namespace std;

int modpow(int x, int n, int m)
{

    if (n == 0)
    {
        return 1 % m;
    }
    long long u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1)
    {
        u = (u * x) % m;
    }
    return u;
}

int main()
{
    int P, Q, N, M;
    cin >> P >> Q >> N >> M;
    int i, sum = 0, modSum = 0, temp = 0;

    for (i = 1; i <= N; i++)
    {
        temp = (modpow(P, i, M) * modpow(i, Q, M));
        modSum += temp % M;
    }

    cout << modSum % M;
}

//was not able to get full marks from this answer