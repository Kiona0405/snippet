#include <vector>


struct CumulativeSum2d
{
    int H, W;
    std::vector<std::vector<int>> csum;
    CumulativeSum2d(std::vector<std::vector<int>>&mat)
    {
        H = mat.size();
        W = mat[0].size();
        
        csum.assign(H+1, std::vector<int>(W+1, 0));
        for (int i=0; i<H; ++i)
            for (int j=0; j<W; ++j)
            {
                csum[i+1][j+1] = mat[i][j];
                csum[i+1][j+1] += csum[i+1][j];
                csum[i+1][j+1] += csum[i][j+1];
                csum[i+1][j+1] -= csum[i][j];
            }        
    }
    
    int get_sum(int h1, int w1, int h2, int w2)
    {
        int ret = 0;
        ret += csum[h2+1][w2+1];
        ret -= csum[h2+1][w1];
        ret -= csum[h1][w2+1];
        ret += csum[h1][w1];
        return ret;
    }
};
