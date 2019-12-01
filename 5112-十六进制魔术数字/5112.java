class Solution {
  public String toHexspeak(String num) {
      long a = Long.parseLong(num);
      String hex = Long.toHexString(a);
      StringBuilder sb = new StringBuilder();
      for(int i = 0;i < hex.length();i++){
          if(hex.charAt(i) >= '2' && hex.charAt(i) <= '9'){
              return "ERROR";
          }
          if(hex.charAt(i) == '0'){
              sb.append('O');
          } else if(hex.charAt(i) == '1'){
              sb.append('I');
          } else {
              sb.append(Character.toUpperCase(hex.charAt(i)));
          }
      }
      return sb.toString();
  }
}