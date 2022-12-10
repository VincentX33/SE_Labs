#include<stdio.h>
#include<stdlib.h>

struct Node{
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};

int height(struct Node *N){
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b){
  return (a > b)? a : b;
}

struct Node* newNode(int key){
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->key   = key;
  node->left   = NULL;
  node->right  = NULL;
  node->height = 1;
  return(node);
}
struct Node * searchAVL(struct Node * root, int k){
  if (root == NULL){
    return NULL;
  }else {
    if (root->key == k)
      return root;
    else  if (k < root->key)
      return searchAVL(root->left, k);
    else if (k > root->key)
      return searchAVL(root->right, k);
  }
  return NULL;
}

struct Node *rightRotate(struct Node *y){
  struct Node *x = y->left;
  struct Node *T2 = x->right;
  // Rotation
  x->right = y;
  y->left = T2;
  // Update heights
  y->height = max(height(y->left),height(y->right)) + 1;
  x->height = max(height(x->left),height(x->right)) + 1;
  // Return new root
  return x;
}
struct Node *leftRotate(struct Node *x){
  struct Node *y = x->right;
  struct Node *T2 = y->left;
// Perform rotation
  y->left = x;
  x->right = T2;
//  Update heights
  x->height = max(height(x->left),height(x->right)) + 1;
  y->height = max(height(y->left),height(y->right)) + 1;
// Return new root
  return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N){
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct Node* insert(struct Node* node, int key){
  /* Normal BST insertion */
  if (node == NULL)
    return(newNode(key));
  if (key < node->key)
    node->left  = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  else // If already present nothing inserted
    return node;
  /*Height update*/ 
  node->height = 1 + max(height(node->left),height(node->right));
  int balance = getBalance(node);
  //Modify only if balance indicates unbalanced tree
  // Left Left 
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);
  // Right Right 
  if (balance < -1 && key > node->right->key)
    return leftRotate(node);
  // Left Right 
  if (balance > 1 && key > node->left->key){
    node->left =  leftRotate(node->left);
    return rightRotate(node);
  }
  // Right Left Case
  if (balance < -1 && key < node->right->key){
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  /* return the (unchanged) node pointer */
  return node;
}

void preOrder(struct Node *root){
  if(root != NULL){
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
  }
}
void inorder(struct Node *root){
  if(root != NULL){
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}
void descOrder(struct Node *root){
  if(root != NULL){
    descOrder(root->right);
    printf("%d ", root->key);
    descOrder(root->left);
  }
}
struct Node * minValueNode(struct Node* node)
{
  struct Node* ptr = node;
  /* loop down to find the leftmost leaf */
  while (ptr->left != NULL)
    ptr = ptr->left;
  return ptr; 
}
struct Node *maxValue(struct Node * node){
  struct Node* ptr = node;
  if (ptr == NULL)
    return NULL;
  while (ptr->right != NULL)
    ptr = ptr->right;
  return ptr;
}
struct Node* deleteNode(struct Node* root, int key){
  //bst delete
	if (root == NULL)
		return root;
	if ( key < root->key )
		root->left = deleteNode(root->left, key);
	else if( key > root->key )
		root->right = deleteNode(root->right, key);
	else{
		if( (root->left == NULL) || (root->right == NULL) ){
			struct Node *temp = root->left ? root->left :root->right;
			// No child
			if (temp == NULL){
				temp = root;
				root = NULL;
			}
			else // One child 
			*root = *temp; // move child up
			free(temp);
		}
		else{
			// replace with inorder successor
			struct Node* temp = minValueNode(root->right);
			// Copy temp to root
			root->key = temp->key;
			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->key);
		}
	}
	if (root == NULL)
	  return root;
	// Height updation
	root->height = 1 + max(height(root->left),height(root->right));
	// check for balance
	int balance = getBalance(root);
	// if unbalanced, update
	// Left Left
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);
	// Left Right 
	if (balance > 1 && getBalance(root->left) < 0){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	// Right Right
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);
	// Right Left
	if (balance < -1 && getBalance(root->right) > 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
int main()
{
  struct Node *root = NULL;
  int treeValues[] = {34,23,43,24,65,37,96};
  int widths[10];
  //predefinition 
  for (int i = 0; i<7;i++)
    root = insert(root,treeValues[i]);
  for (int i = 0; i < 10;i++)
    widths[i] = 0;
  struct Node * temp;
  calWidth(root,widths,0);
  for (int i = 0;i<10; i++)
    printf("Width of level %d is %d\n",i, widths[i]);
  int c, x,m;
  do {
    printf("\nEnter:\n");
    printf(""
    "1. Insertion of a new element \n"
    "2. Deletion of an existing element \n"
    "3. Searching for a given element \n"
    "4. Finding the width of the tree\n"
    "5. Finding the max value node\n"
    "6. Finding the min value node\n"
    "7. Listing the elements of the AVL in descending order\n"
    "8. Exit\n  :"
    "");
    scanf("%d",&c);
    switch(c){
      case 1:
        printf("Enter element to be inserted:");
        scanf("%d", &x);
        root = insert(root,x);
        break;
      case 2:
        printf("Enter element to be deleted:");
        scanf("%d", &x);
        root = deleteNode(root,x);
        break;
      case 3:
        printf("Enter element to be searched:");
        scanf("%d", &x);
        if ((temp = searchAVL(root, x))!=NULL)
          printf("Value %d found @ %p\n",x,temp);
        else
          printf("Value %d not found in tree\n");
        break;
      case 4:
        //pass
        for (int i = 0; i < 10;i++)
    		  widths[i] = 0;
        calWidth(root,widths,0);
        m = widths[0];
        for (int i = 0;i<10; i++){
          if (widths[i]>m)
            m = widths[i];
        }
        printf("Width of tree: %d\n", m);
        break;
      case 5:
        if ((temp = maxValue(root))!=NULL)
          printf("Max Value %d found @ %p\n",temp->key,temp);
        else
          printf("Empty tree\n");
        break;
      case 6:
        if ((temp = minValueNode(root))!=NULL)
          printf("Min Value %d found @ %p\n",temp->key,temp);
        else
          printf("Empty tree\n");
        break;
      case 7:
        printf("In descending order:");
        descOrder(root);
        break;
      case 8:
        break;
      default:
        printf("Invalid choice \n");
    }
  }while(c!=8);
  return 0;
}