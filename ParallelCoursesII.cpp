class Solution {
public:
    int n,k;
    vector<int>preq[15];
    vector<int> dp;
    int num_sems(int mask)
    {
        if(mask == (1<<n)-1)
        {
            return 0;
        }
        if(dp[mask] != -1)
        {
            return dp[mask];
        }
        
        vector<int>indeg(n,0);
        for(int i = 0 ; i < n ; i++)
        {
            if(mask & (1 << i))
            {
                continue;
            }
            for(int j = 0 ; j < preq[i].size() ; j++)
            {
                indeg[preq[i][j]]++;  // All the courses dependent on i
            }
        }
        
        int ok = 0;   // The courses which are avaiable to be taken on the current day , first no curces can be taken
        for(int i = 0; i < n ; i++)
        {
            if(indeg[i] == 0 and !(mask&(1<<i)))
            {
                ok |= (1<<i);
            }
        }
        
        // We have the number of cources available on that perticular day
        int num_avail = __builtin_popcount(ok);
        int taken = n+1;
        // If num_avail > k, then we will have to check all possibilities 
        int m = ok;
        int s;
        if(num_avail > k)
        {
            for(s = m; s ; s = (s-1)&m)
            {
                if(__builtin_popcount(s) != k)
                {
                    continue;
                }
                else
                {
                    taken = std::min(taken,1 + num_sems(mask|s));
                }
            }
        }
        else
        {
            taken = std::min(taken,1 + num_sems(mask|ok));
        }
        
        return dp[mask] = taken;
    }
    
    
    int minNumberOfSemesters(int N, vector<vector<int>>& dependencies, int K) {
        n = N;
        k = K;
        dp.assign(1<<n,-1);
        // memset(dp,-1,sizeof(dp));
        for(int i = 0 ; i < dependencies.size() ; ++i)
        {
            dependencies[i][1] --;
            dependencies[i][0] --;
            preq[dependencies[i][0]].push_back(dependencies[i][1]);
        }
        
        int ans = num_sems(0);
        return ans;
    }
};
