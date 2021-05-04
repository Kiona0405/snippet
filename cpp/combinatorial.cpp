#include<vector>
int const MOD = 1000000007;

std::vector<long long> factorials;
void init_factorial(int N)
{
    factorials.assign(N+1, 1);
    for (int i=2; i<N+1; ++i) {
        factorials[i] = factorials[i-1] *i;
        factorials[i] %= MOD;
    }
}

long long power_mod(long long n, long long m)
{
    long long res = 1;
    long long base = n;
    while (m > 0)
    {
        if (m&1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        m >>= 1;
    }
    return res;
}

long long inv_mod(long long n)
{
    return power_mod(n, MOD-2);
}

long long comb(long long n, long long m)
{
    m = std::min(m, n-m);
    long long res = factorials[n];
    res *= inv_mod(factorials[n-m]);
    res %= MOD;
    res *= inv_mod(factorials[m]);
    res %= MOD;
    return res;
}

long long dup_comb(long long n, long long m)
{
    return comb(n+m-1, n-1);
}
