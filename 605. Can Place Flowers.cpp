class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0,temp=n;
        if(n==0)
        return true;
        if(flowerbed.size()==1&&flowerbed[0]==0)return true;
        else if(flowerbed.size()==1&&flowerbed[0]==1)return false;
        if(flowerbed[0]==0&&flowerbed[1]==0){
        n--;
        flowerbed[0]=1;
        }
        if(flowerbed[flowerbed.size()-1]==0&&flowerbed[flowerbed.size()-2]==0){
        n--;
        flowerbed[flowerbed.size()-1]=1;
        }
        while(n>0){
       for(int i=1;i<flowerbed.size()-1;i++){
           if(flowerbed[i-1]==0 && flowerbed[i+1]==0&&flowerbed[i]!=1){
           flowerbed[i]=1;
           n--;
           }
       } 
        count++;
        if(count>temp) return false;
        }
        if(n>0)
        return false;
        return true;
    }
};
