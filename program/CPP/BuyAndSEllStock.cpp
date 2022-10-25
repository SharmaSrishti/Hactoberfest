class Solution {
public:
   
  
    int findans(vector<int>& prices,int currentday,bool canbuy,int count,vector<vector<vector<int>>>& dp)
    {
        long b=0;
        if(count==0 || currentday==prices.size())
        {
            return 0;
        }
      
      if(dp[currentday][canbuy][count]!= -1)
      {
          return dp[currentday][canbuy][count];
      }
      
         
        if(canbuy)
        {
           
             b = max(-prices[currentday]+findans(prices,currentday+1,0,count,dp), findans(prices,currentday+1,1,count,dp));
            
        }
        else
        {
       
             b = max(prices[currentday]+findans(prices,currentday+1,1,count-1,dp),findans(prices,currentday+1,0,count,dp));
           
          
        }
        return dp[currentday][canbuy][count]=b;
       
    }
   int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1))); 
       return findans(prices,0,1,2,dp);        
    }
    
};




