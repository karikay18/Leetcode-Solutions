class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
      int a=min(prices[0],prices[1]);  
      int b=max(prices[0],prices[1]);
      for(int i=2;i<prices.size();i++)
      {
          if(prices[i]<a)
          {
              b=a;
              a=prices[i];
          }
          else if( prices[i]<b)
          {
              b=prices[i];
          }
      }  
      if(money-(a+b)>=0)
      {
          return money-(a+b);
      }
      else
      {
          return money;
      }
    }
};