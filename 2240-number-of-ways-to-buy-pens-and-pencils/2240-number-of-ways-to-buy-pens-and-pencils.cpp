typedef long long ll;
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
          
        ll pens=total/cost1;
        ll ans=0;
        for(ll i=0;i<=pens;i++)
        {
            ll newtotal=total-cost1*i;
            ll pencil=newtotal/cost2;
            ans+=pencil+1;
        }
        
        return ans;
    }
};