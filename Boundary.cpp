//
// Tree Traversal Program - Boundary Traversal in Anti-clockwise Direction
//
#include <stdio.h>
#include <stdlib.h>

struct node {
	   int element;
	   node *left;
	   node *right;
};

struct node* newNode ( int element) {

	   struct node* temp = (struct node*) malloc (sizeof(struct node));
	   temp-> element = element;
	   temp-> left = NULL;
	   temp-> right = NULL;
}


void printLeaf( struct node *root) {
	 if ( root == NULL)
	 	return;
 	
 	if (( root->left == NULL ) && ( root -> right == NULL )) {
 	   printf ("\n %d" , root->element);
 	   return;
	 }
	 
	 printLeaf(root->left);
	 printLeaf(root->right);

}

//
// Print Boundary Left nodes in Left tree 
//
void boundaryLeftTraversal ( node *root) {
	 
	 //
	 // If you choose to print data in here, leaf nodes dataa will also be printed 
	 //
	 if ( root == NULL)	{
	 return;
	 } 
	 
	 
	 
	 if ( root->left != NULL) { 
	 	 //
	 	 // Please note for top-down you print first and then call recursively
	 	 //
  	 	 printf ("\n %d ", root->element);
		 boundaryLeftTraversal(root->left);
	 } else { 
	   		  if ( root->right != NULL) {
	   		     printf ("\n %d ", root->element);
	   		  	 boundaryLeftTraversal(root->right);
	 		  }
 		
	 }

} 



//
// Print Right Boundary nodes in Right tree 
//
void boundaryRightTraversal ( node *root) {
	 
	 if ( root == NULL)	{
	 return;
	 } 
	 
	 if ( root->right != NULL) {
        
		 boundaryRightTraversal(root->right);
	     printf ("\n %d ", root->element);

	 } else { 
	   		  if ( root->left != NULL) {
	   		     //
	   		     // Please note for bottom up, you call into recursive function first and then print
     	         //
	   		  	 boundaryRightTraversal(root->left);
	   		  	 printf ("\n %d ", root->element);
	 		  }
	   		
	 }
	 
	 

}
int main() {

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
     
     // Print Root first
	 printf(" %d", root->element);
     
	 // Print top down all the left subtree boundary node   
     boundaryLeftTraversal(root->left);
     
     // Print leaf nodes of the left subtree from left to right
     printLeaf(root->left);
     
     // Print leaf nodes of the right subtree from left to right
     printLeaf(root->right);
     
     // Print bottom up all the right subtree boundary node 
     boundaryRightTraversal(root->right);
 

return 0;
}

// Complexity of the program is O(n) 
