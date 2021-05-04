const int MOD = 1000000007;

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
