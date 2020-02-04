class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> output= new ArrayList<List<Integer>>();//For C++ use vector instead of List
       
        for(int i=0;i<numRows;i++){
                   
        List<Integer> currentList = new ArrayList<>();
            for(int j=0;j<i+1;j++){
                if(j==0 || j== i){
                    currentList.add(1);
                }
               
                else{
                    currentList.add(output.get(i-1).get(j-1)+output.get(i-1).get(j));                 
		  }
            }
            output.add(currentList);
       }
        return output;
    }
}
