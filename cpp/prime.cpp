#include<vector>

std::vector<long long> primes;
void init_primes(long long N)
{
    std::vector<bool> is_prime(N+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i<N+1; ++i)
    if (is_prime[i])
    {
        primes.push_back(i);
        for (long long j = (long long)i*i; j<=N; j += i)
            is_prime[j] = false;
    }
}
