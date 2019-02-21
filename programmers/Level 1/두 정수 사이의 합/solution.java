class Solution {
  public long solution(int a, int b) {
      long answer = 0;
      long mid = 0;
      
      if(a==b){
          return a;
      }else if(a>b){
          for(int i=b+1; i<a; ++i)
              mid+=i;
          
      }else if(a<b){
          for(int i=a+1; i<b; ++i)
              mid+=i;
      }
      return a+mid+b;
  }
}