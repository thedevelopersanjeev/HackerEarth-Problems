class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] mergedArray = new int[nums1.length + nums2.length];
        int i = 0, j = 0;
        for(int k = 0; k<mergedArray.length; k++){
            if(i < nums1.length && j >= nums2.length){
                // nums1 remaining
                while(i < nums1.length){
                    mergedArray[k] = nums1[i];
                    i++;
                    k++;
                }
                break;
            }
            else if(i >= nums1.length && j < nums2.length){
                // nums2 remaining
                while(j < nums2.length){
                    mergedArray[k] = nums2[j];
                    j++;
                    k++;
                }
                break;
            }
            else{
                if(nums1[i] > nums2[j]){
                    mergedArray[k] = nums2[j];
                    j++;
                }
                else{
                    mergedArray[k] = nums1[i];
                    i++;
                }
            }
        }
        int len = mergedArray.length/2;
        if(mergedArray.length % 2 == 0){
            double ans = (mergedArray[len-1] + mergedArray[len])/2.0;
            return ans;
        }
        else
            return mergedArray[len];
            
    }
}