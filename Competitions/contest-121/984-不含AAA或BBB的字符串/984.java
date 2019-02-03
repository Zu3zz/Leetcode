class Solution {
    public String strWithout3a3b(int A, int B) {
        String sb = new String();
        do {
            if (A >= B) { //a多，尽量先消费a（贪心策略）
                if (sb.endsWith("aa")) { //实在不能消耗a才消费b
                    sb = sb.concat("b");
                    B--;
                } else { //先消费a
                    sb = sb.concat("a");
                    A--;
                }
            } else {
                if (sb.endsWith("bb")) {
                    sb = sb.concat("a");
                    A--;
                } else {
                    sb = sb.concat("b");
                    B--;
                }
            }
        } while (A>0 || B>0); //只要A或B不等于0，则一直循环
        return sb;
    }
}