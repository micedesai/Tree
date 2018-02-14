//
// Tree Traversal Program - Recursive Level Order Traversal
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

int maximum ( int a, int b) {
	if ( a > b) 
	    return a;
    else 
    	return b; 
}

int height ( node *root) {
  	
     if ( root == NULL)
     	return 0;
  	
  	 return 1 + maximum ( height(root->left) , height(root->right)) ;


}

//
// Recursive Level Order Traversal
//

void PrintLevelOrder ( node* root , int height) {
     
     if ( root == NULL) 
     	return;
     	
	 if ( height == 1) {
	 	printf (" %d", root->element);
	 }
	 
	 PrintLevelOrder(root->left  , height-1);
	 PrintLevelOrder(root->right ,height-1);

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
     
   
    for ( int i = 1; i <= height(root) ;i++) {
		printf ("\n");
		PrintLevelOrder(root , i);
	}
 

return 0;
}

// Complexity of the program is O(n) 

// Output

 1
 2 3
 4 5 6 7
 8 9
