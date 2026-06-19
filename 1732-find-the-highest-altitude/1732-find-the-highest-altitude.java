class Solution {
    public int largestAltitude(int[] gain) {
        int ans=-101;
        int temp=0;
        for(int i:gain){
          ans=Math.max(ans,temp);
          temp+=i;  
        }
        ans=Math.max(ans,temp);
        return ans;
    }
}