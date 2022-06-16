/*Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B']. */


package DailyCodingProblem;

public class DailyCodingProblem35 {
    public static void sort(char[] array)
	{
	  int low=0;
	  int mid=0;
	  int high=array.length-1;
	  while(mid<=high){
		  if(array[mid]=='R'){
			  swap(array,low,mid);
			  low++;
			  mid++;
		  }
		  else if(array[mid]=='G'){
			  mid++;
		  }
		  else{
			  swap(array,mid,high);
			  high--;
		  }
		  
	  }
	}

	private static void swap(char[] array, int idx1, int idx2)
	{
		char temp = array[idx1];
		array[idx1] = array[idx2];
		array[idx2] = temp;
	}

	public static void main(String args[])
	{
		char[] array = new char[]{'G', 'B', 'R', 'R', 'B', 'R', 'G'};
		sort(array);
		for(int i=0;i<array.length;i++){
            System.out.print(array[i]);
        }
	}
}

