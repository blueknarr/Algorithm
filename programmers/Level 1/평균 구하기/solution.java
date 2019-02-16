class Solution {
    public double solution(int[] arr) {
        double answer = 0;
        int length = arr.length;
        
        for(int i=0; i<length; ++i)
            answer+=arr[i];
        
        return answer/length;
    }
  }