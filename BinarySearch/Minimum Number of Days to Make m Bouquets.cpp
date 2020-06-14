https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

bool check(vector<int>v,int mid, int m, int k)
{
    int adja=0;
    for(auto it:v){
        adja=it<=mid?adja+1:0;
        if(adja==k)
        {
            m--;
            adja=0;
        }
    }
    return m<=0;
}

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k>bloomDay.size())
            return -1;
        if(m*k==bloomDay.size())
            return *max_element(bloomDay.begin(),bloomDay.end());
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        
        while(low<high)
        {
            int mid=(low+high)/2;
           // cout<<low<<" "<<mid<<" "<<high<<endl;
            if(check(bloomDay,mid,m,k))
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};

