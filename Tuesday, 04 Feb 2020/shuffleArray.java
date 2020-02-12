
class Solution {
    int[] array;
    int original[] ;
    
    public Solution(int[] nums) { 
        array = nums;
        original=nums.clone();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {     
        Random rand = new Random();
        for(int i=0;i<array.length;i++){
            int randIndex = rand.nextInt(array.length);
            int temp = array[i];
            array[i]= array[randIndex];
            array[randIndex] = temp;
        }
        
        return array;
    }
}
