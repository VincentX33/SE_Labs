#include <stdio.h>
#include <stdlib.h>

struct treenode{
  struct treenode * left;
  int value;
  struct treenode * right;
};
/*
implement bst:
insertion:
deletion:
search:
*/
struct treenode * insertBST(struct treenode * root, int key);
int inBST(struct treenode * root, int key);
struct treenode * searchBST(struct treenode * root, int key);
struct treenode * deleteInBST(struct treenode * root, int key);
void inorderTrav(struct treenode * root);
void preorderTrav(struct treenode * root);
void postorderTrav(struct treenode * root);


int main(){
  struct treenode * rootTree = NULL;
  rootTree = insertBST(rootTree, 4);
  rootTree = insertBST(rootTree, 2);
  rootTree = insertBST(rootTree, 3);
  rootTree = insertBST(rootTree, 1);
  rootTree = insertBST(rootTree, 5);
  rootTree = insertBST(rootTree, 6);
  //preorderTrav(rootTree);
  //postorderTrav(rootTree);
  //inorderTrav(rootTree);
  if (inBST(rootTree, 6)){
    struct treenode * dkey = searchBST(rootTree, 6);
    printf("Value %d found @ %p\n",6,dkey);
  }
  rootTree = deleteInBST(rootTree, 6);
  if (inBST(rootTree, 6)){
    struct treenode * dkey = searchBST(rootTree, 6);
    printf("Value %d found @ %p\n",6,dkey);
  }
  //struct treenode * dkey = search(rootTree, 10);
  return 0;
}
struct treenode * insertBST(struct treenode * root, int key){
  //recursive function
  //if empty then create new node using malloc and return
  if (root == NULL){
    struct treenode * temp = (struct treenode *)malloc(sizeof(struct treenode));
    if (!temp)
      return NULL;
    temp->left = NULL;
    temp->right = NULL;
    temp->value = key;
    return temp;
  }else{
    if (key < root->value ){
      root->left = insertBST(root->left,key);
    }else if (key > root->value){
      root->right = insertBST(root->right,key);
    }
    return root;
  }
}
struct treenode * searchBST(struct treenode * root, int key){
  if (root == NULL){
    return NULL;
  }else {
    if (root->value == key)
      return root;
    else  if (key < root->value)
      return searchBST(root->left, key);
    else if (key > root->value)
      return searchBST(root->right, key);
  }
  return NULL;
}
int inBST(struct treenode * root, int key){
  if (root == NULL){
    return 0;
  }else {
    if (root->value == key)
      return 1;
    else  if (key < root->value)
      return inBST(root->left, key);
    else if (key > root->value)
      return inBST(root->right, key);
  }
  return 0;
}

//deletion: recursive
/*
first perform bst like traversal to find node
if node is null means its not there
traverse left/right until u reach ptr having the required key 
once key found :
  for case ptr having two leafs:
    delete its successor and replace ptr value with it
  for 1 leaf:
    replace with leaf value
*/
struct treenode * deleteInBST(struct treenode * ptr, int key){
  struct treenode * temp, *succ;
  if (ptr == NULL){
    return NULL;
  }
  else if (key < ptr->value){
    ptr->left = deleteInBST(ptr->left, key);
  }else if (key > ptr->value){
    ptr->right = deleteInBST(ptr->right, key);
  }else {
    // when ptr is having the key
    if (ptr->left != NULL && ptr->right != NULL){
      //find inorder successor
      succ = ptr->right;
      while (succ->left != NULL)
        succ = succ->left;
      ptr->value = succ->value;
      ptr->right = deleteInBST(ptr->right,succ->value);
    }else{
      temp = ptr;
      if (ptr->left)
        ptr = ptr->left;
      else if (ptr->right)
        ptr = ptr->right;
      else 
        ptr = NULL;
      free(temp);
    }
  }
  return ptr;
}
