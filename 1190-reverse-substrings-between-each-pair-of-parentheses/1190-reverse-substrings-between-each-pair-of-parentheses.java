import java.util.*;

class Solution {
    public String reverseParentheses(String s) {
        int n = s.length();
        Stack<Integer> st = new Stack<>();
        int[] pair = new int[n];
        for(int i=0; i<n; i++){
            if(s.charAt(i) == '('){
                st.push(i);
            }
            else if(s.charAt(i) == ')'){
                int j = st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        StringBuilder ans = new StringBuilder("");
        int flag = 1;
        for(int i=0; i<n; i+= flag){
            if(s.charAt(i) == '(' || s.charAt(i) == ')'){
                i = pair[i];
                flag = -flag;
            }else{
                ans.append(s.charAt(i));
            }
        }
        
        return ans.toString();
    }
}