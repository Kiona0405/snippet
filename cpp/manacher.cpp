#include<vector>
#include<iostream>

std::vector<int> manacher(std::string s)
{
	int N = s.size();
    std::vector<int> table(N);
	int pos = 0;
	int k=1;
	while (pos<N)
	{
      // check palindromness
      while (0<=pos-k and pos+k<N and s[pos-k]==s[pos+k])
      	++k;
      table[pos] = k;

      if (k==1){++pos; continue;}

      // use previous result
      int j=1;
      while (pos+j<N and j+table[pos-j]<k)
      {
        table[pos+j] = table[pos-j];
        ++j;
      }
      pos += j;
      k -= j;
	}
	return table;
}
