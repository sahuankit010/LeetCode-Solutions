class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int k=0;
        if(n==0) return true;
        if(n==1 and flowerbed.size()==1){
            return (flowerbed[0]==0);
        } 
        for(int i=0; i<flowerbed.size(); i++){
            
            if(i==0){
                if(flowerbed[i+1]==0 && flowerbed[i]==0){
                    flowerbed[i]=1;
                    k++;
                }
            } else if(i==flowerbed.size()-1 ){
                if(flowerbed[i-1]==0 && flowerbed[i]==0){
                    flowerbed[i]=1;
                    k++;
                }
            }else if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]!=1){
                k++;
                flowerbed[i]=1;
            }
            if(k==n) return true;
        }
        return false;
    }
};