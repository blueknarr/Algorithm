class Solution {
  public String solution(String s) {
      String answer= " ";
      String[] str = s.split(" ");
      int [] num = new int[str.length];
      int min=987654321;
      int max=-987654321;
      for(int i=0; i<str.length; ++i){
          num[i] = Integer.parseInt(str[i]);
          if(min > num[i])
              min = num[i];
          if(max < num[i])
              max = num[i];
      }
      answer = String.valueOf(min) + " " + String.valueOf(max);
      return answer;
  }
}