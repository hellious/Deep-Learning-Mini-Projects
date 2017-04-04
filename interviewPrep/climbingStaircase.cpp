long get_ways(int n)
{

   long long ways[n+1];
    ways[0] = 1;
    ways[1] = 1;
    for (int i = 2;  i < n + 1; i++)
    {
       ways[i] = 0;
       for (int j = 1; j <= 2 && j <= i; j++)
         ways[i] += ways[i-j];
    }
    return ways[n] % 10000000007;
}

