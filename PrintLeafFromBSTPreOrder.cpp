//
// Print Leaf nodes from preorder of a BST Traversal
//
#include <stdio.h>

int main(){
	int preorder[] = {200,150,130,140,170,300,250,400,350};
	int length = 9;
	
	int stack[9],top = 0;
	
	int i , j , flag = 0;
	
	// 
	// Divide the array into left tree and right tree
	//
	// Keep two indices and push the elements onto the stack till its in decreasing order
	//
	i = 0;
	for ( j = 1 ; j < length ; j++ ) {

		flag = 0;
	
		if ( preorder[i] > preorder[j]) {
			// Elements till 150 will be pushed  
			stack[top++] = preorder[i];	
 		  
		} else {
            // First Iteration
		    // Pop elements which are less than 170 which includes all the elements belonging to the tree where 170 is the rightmost element
		    // i.e 130, 140 and 150
		    // i points to 140 and j is 170 , i will get printed 
			while  ( top >= 0) {
	  			  if ( preorder[j] > stack[top])  {
	 			        top--; 
	  				    flag = 1;
	  			  } else {
	  			  		break;
	              }
			} 
		}
		
		if ( flag == 1) {
			printf ( " \n %d ", preorder[i]);
		}
		i++;
	}
	//
	// RightMost element in preorder traversal is always a leaf
	//
	printf ( "\n %d", preorder[length-1]);
        	
	return 0;
}

// Complexity - O(n)
