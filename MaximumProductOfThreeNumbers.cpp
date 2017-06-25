class Solution {
public:
    void negMax(int& a, int& b, int& c, int n){
        if(a == INT_MIN){
            a = n;
        }    
        else if(b == INT_MIN){
            if(a < n){
                b = a;
                a = n;
            }
            else{
                b = n;
            }
        }
        else if(c == INT_MIN){
            if(a <= n){
                c = b;
                b = a;
                a = n;
            }
            else if(b <= n){
                c = b;
                b = n;
            }
            else{
                c = n;
            }
        }
        else{
            if(a <= n){
                c = b;
                b = a;
                a = n;
            }
            else if(b <= n){
                c = b;
                b = n;
            }
            else if(c < n){
                c = n;
            }
        }    
    }
    
    void negMin(int& a, int& b, int& c, int n){
        if(a == INT_MAX){
            a = n;
        }    
        else if(b == INT_MAX){
            if(a >= n){
                b = a;
                a = n;
            }
            else{
                b = n;
            }
        }
        else if(c == INT_MAX){
            if(a >= n){
                c = b;
                b = a;
                a = n;
            }
            else if(b >= n){
                c = b;
                b = n;
            }
            else{
                c = n;
            }
        }
        else{
            if(a >= n){
                c = b;
                b = a;
                a = n;
            }
            else if(b >= n){
                c = b;
                b = n;
            }
            else if(c > n){
                c = n;
            }
        }    
    }
    
    void posMax(int& a, int& b, int& c, int n){
        if(a == INT_MIN){
            a = n;
        }    
        else if(b == INT_MIN){
            if(a < n){
                b = a;
                a = n;
            }
            else{
                b = n;
            }
        }
        else if(c == INT_MIN){
            if(a <= n){
                c = b;
                b = a;
                a = n;
            }
            else if(b <= n){
                c = b;
                b = n;
            }
            else{
                c = n;
            }
        }
        else{
            if(a <= n){
                c = b;
                b = a;
                a = n;
            }
            else if(b <= n){
                c = b;
                b = n;
            }
            else if(c < n){
                c = n;
            }
        }    
    }
    
    void posMin(int& a, int& b, int& c, int n){
        if(a == INT_MAX){
            a = n;
        }    
        else if(b == INT_MAX){
            if(a >= n){
                b = a;
                a = n;
            }
            else{
                b = n;
            }
        }
        else if(c == INT_MAX){
            if(a >= n){
                c = b;
                b = a;
                a = n;
            }
            else if(b >= n){
                c = b;
                b = n;
            }
            else{
                c = n;
            }
        }
        else{
            if(a >= n){
                c = b;
                b = a;
                a = n;
            }
            else if(b >= n){
                c = b;
                b = n;
            }
            else if(c > n){
                c = n;
            }
        }    
    }
    
    int maximumProduct(vector<int>& nums) {
        int pMax1 = INT_MIN, pMax2 = INT_MIN, pMax3 = INT_MIN, pcount = 0;
        int nMin1 = INT_MAX, nMin2 = INT_MAX, nMin3 = INT_MAX, ncount = 0;
        int nMax1 = INT_MIN, nMax2 = INT_MIN, nMax3 = INT_MIN;
        int pMin1 = INT_MAX, pMin2 = INT_MAX, pMin3 = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0){
                ncount++;
                negMax(nMax1, nMax2, nMax3, nums[i]);
                negMin(nMin1, nMin2, nMin3, nums[i]);
            }
            else{
                pcount++;
                posMax(pMax1, pMax2, pMax3, nums[i]);
                posMin(pMin1, pMin2, pMin3, nums[i]);
            }
            // cout << "pMax1: " << pMax1 << " " << "pMax2: " << pMax2 << " pMax3: " << pMax3 << endl;
        }
        
        // cout << "pMax1: " << pMax1 << " " << "pMax2: " << pMax2 << " pMax3: " << pMax3 << endl;
        // cout << "pMin1: " << pMin1 << " " << "pMin2: " << pMin2 << " pMin3: " << pMin3 << endl;
        // cout << "nMax1: " << nMax1 << " " << "nMax2: " << nMax2 << " nMax3: " << nMax3 << endl;
        // cout << "nMin1: " << nMin1 << " " << "nMin2: " << nMin2 << " nMax1: " << nMax1 << endl;
        
        // return -1;
        
        if(pcount == 0){
            return nMax1*nMax2*nMax3;
        }
        else if(pcount == 1){
            return nMin1*nMin2*pMax1;
        }
        else if(pcount == 2){
            return pMax1*nMin1*nMin2;
        }
        else if(ncount >= 2){
            return max(pMax1*pMax2*pMax3, pMax1*nMin1*nMin2);
        }
        
        return pMax1*pMax2*pMax3;
    }
};
