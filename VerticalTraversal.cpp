//
// Tree Traversal Program - Vertical or Column Traversal
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

//
// Get Minimum and Maximum of the tree - LeftMost and Rightmost node horizontal distance wont work
//
void getMinMax ( node* root, int *min , int* max, int hd) {

if ( root == NULL) {
   return;
}

if ( hd < *min)
   *min = hd;
else
	{
	 if (hd > *max ) {
	 	*max = hd;
	 }
	}


getMinMax ( root->left , min, max, hd - 1 );
getMinMax ( root-> right, min, max, hd + 1);

}

void printVertical ( node* root, int currenthd, int hd) {
	 if ( root == NULL) 
	 	return;
	 	
	 if ( hd == currenthd) {
	 	printf(" %d ", root->element);
	 }
	 
	 printVertical (root->left, currenthd - 1, hd);
	 printVertical (root->right, currenthd + 1, hd);
	 
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
    int min = 0,max = 0;
    
    getMinMax(root,&min, &max,0);
    printf ( "\n Min = %d Max = %d", min, max);

   //
   // For every level
   //
   for ( int i = min; i <= max; i++) {
   	   	 printf("\n Level = %d \n ", i);
	   	 printVertical(root, 0 , i);
    }


return 0;
}



// Complexity of the program is O(n^2) 
//
// Output
//

 Min = -2 Max = 3
	 
 Level = -2
  4
 Level = -1
  2
 Level = 0
  1  5  6
 Level = 1
  3  8
 Level = 2
  7
 Level = 3
  9
