class Solution {
    public int[] getConcatenation(int[] nums) {
        int n = nums.length;
        int[] a = new int[n*2];
        for(int i=0; i<2*n; i++){
            if(i>=n){
                a[i]=nums[i-n];
            }
            else{
                a[i]=nums[i];
            }
        }
        return a;
    }
}