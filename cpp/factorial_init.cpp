#include<vector>
const int MOD = 1000000007;

std::vector<long long> factorials;
void init_factorial(int N)
{
    factorials.assign(N+1, 1);
    for (int i=2; i<N+1; ++i) {
        factorials[i] = factorials[i-1] *i;
        factorials[i] %= MOD;
    }
}
