class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
     long long ans  = 0;
     int n = damage.size();

     sort(begin(damage), end (damage));


     damage[n-1] -= armor;

     for(int i=n-1; i>=0; i--){

         if(damage[i]>0)

         ans += damage[i];

     }   


     return ans+1;
    }
};