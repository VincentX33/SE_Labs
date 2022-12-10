#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
    int lthread;
    int rthread;
    int balance;
};

struct node *in_succ(struct node *ptr){
    if (ptr->rthread == 1)
        return ptr->rchild;
    else{
        ptr = ptr->rchild;
        while (ptr->lthread == 0)
            ptr = ptr->lchild;
        return ptr;
    }
}
void inorder(struct node *root){
    struct node *ptr;
    if (root == NULL){
        printf("Tree is empty");
        return;
    }
    ptr = root;
    while (ptr->lthread ==0)
        ptr = ptr->lchild;
    while (ptr != NULL){
        printf("%d ", ptr->info);
        ptr = in_succ(ptr);
    }
}
struct node *in_pred(struct node *ptr){
    if (ptr->lthread == 1)
        return ptr->lchild;
    else{
        ptr = ptr->lchild;
        while (ptr->rthread == 0)
            ptr = ptr->rchild;
        return ptr;
    }
}
struct node *case_a(struct node *root, struct node *par, struct node *ptr){
    if (ptr == NULL)
        root = NULL;
    else if (par->lchild == ptr){
        par->lthread = 1;
        par->lchild = ptr->lchild;
    }
    else{
        par->rthread = 1;
        par->rchild = ptr->rchild;
    }
    free(ptr);
    return root;
}
struct node *case_b(struct node *root, struct node *par, struct node *ptr){
    struct node *child, *p, *s;
    if (ptr->lthread == 0)
        child = ptr->lchild;
    else
        child = ptr->rchild;
    if (par == NULL)
        root = child;
    else if (par->lchild == ptr)
        par->lchild = child;
    else
        par->rchild = child;
    s = in_succ(ptr);
    p = in_pred(ptr);
    if (ptr->lthread == 0)
        p->rchild = s;
    else if (ptr->rthread == 0)
        s->lchild = p;
    free(ptr);
    return root;
}

struct node *case_c(struct node *root, struct node *par, struct node *ptr){
    struct node *succ, *parsucc;
    parsucc = ptr;
    succ = ptr->rchild;
    while (succ->lchild != NULL){
        parsucc = succ;
        succ = succ->lchild;
    }
    ptr->info = succ->info;
    if (succ->lthread == 1 && succ->rthread == 1)
        root = case_a(root, parsucc, succ);
    else
        root = case_b(root, parsucc, succ);
    return root;
}

struct node *del(struct node *root, int dkey){
    struct node *par, *ptr;
    int found = 0;
    ptr = root;
    par = NULL;
    while (ptr != NULL){
        if (dkey == ptr->info){
            found = 1;
            break;
        }
        par = ptr;
        if (dkey < ptr->info){
            if (ptr->lthread == 0)
                ptr = ptr->lchild;
            else
                break;
        }
        else{
            if (ptr->rthread == 0)
                ptr = ptr->rchild;
            else
                break;
        }
    }
    if (found == 0)
        printf("%d not present in the tree", dkey);
    else if (ptr->lthread == 0 && ptr->rthread ==0)
        root = case_c(root, par, ptr);
    else if (ptr->lthread == 0)
        root = case_b(root, par, ptr);
    else if (ptr->rthread == 0)
        root = case_b(root, par, ptr);
    else
        root = case_a(root, par, ptr);
    return root;
}
struct node *insert(struct node *root, int ikey){
    struct node *tmp, *par, *ptr;
    int found = 0;
    ptr = root;
    par = NULL;
    while (ptr != NULL){
        if (ikey == ptr->info){
            found = 1;
            break;
        }
        par = ptr;
        if (ikey < ptr->info){
            if (ptr->lthread ==0)
                ptr = ptr->lchild;
            else
                break;
        }
        else{
            if (ptr->rthread ==0)
                ptr = ptr->rchild;
            else
                break;
        }
    }
    if (found)
        printf("Duplicate key");
    else{
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = ikey;
        tmp->lthread = 1;
        tmp->rthread = 1;
        if (par == NULL){
            root = tmp;
            tmp->lchild = NULL;
            tmp->rchild = NULL;
        }
        else if (ikey < par->info){
            tmp->lchild = par->lchild;
            tmp->rchild = par;
            par->lthread = 0;
            par->lchild = tmp;
        }
        else{
            tmp->rchild = par->rchild;
            tmp->lchild = par;
            par->rthread = 0;
            par->rchild = tmp;
        }
    }
    return root;
}
void search(struct node *root, int key)
{
	struct node *pptr = root;
	if (pptr == NULL){
		printf("\nElement %d is not fouund ", key);
		return;
	}
	else{
		if (key < pptr->info)
		  search(pptr->lchild, key);
		else if (key > pptr->info)
		  search(pptr->rchild, key);
		else{
			printf("\nElement %d is found in the tree", key);
			return;
		}
	}
}
void min(struct node *root){
	struct node *pptr = root;
	if (pptr != NULL){
		while (pptr->lchild != NULL)
		  pptr = pptr->lchild;
		printf("\nThe minimum element in the tree is : %d", pptr->info);
	}
}
int main(){
    int n, ele, choice, key;
    int dele;
    struct node *root = NULL;
    int i=0;
    printf("Enter n:");
    scanf("%d", &n);
    int a[20];
    printf("Enter %d numbers: ");
    for (i = 0; i< n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        root=insert(root,a[i]);
    printf("\nTree inorder traversal : ");
    inorder(root);
    do {
        printf("\n\n");
        printf("\n1.Insert an element in inthreaded binary search tree");
        printf("\n2.delete an element from the inthreaded binary search tree");
        printf("\n3.searching an element in inthreaded binary search tree");
        printf("\n4.inorder traversl of inthreaded bst");
        printf("\n5 to exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &ele);
            root = insert(root, ele);
            printf("\nTree inorder traversal after inserting %d : \n", ele);
            inorder(root);
            break;
        case 2:
            printf("\nEnter the element to be deleted : ");
            scanf("%d", &dele);
            root = del(root, dele);
            printf("\n");
            inorder(root);
            break;
        case 3:
            printf("\nEnter the element to be searched : ");
            scanf("%d", &key);
            search(root, key);
            break;
        case 4:
            printf("\nThe inorder traversal is :");
            inorder(root);
            break;
        case 5:
            break;
        default:
            printf("Invalid input: 1-5\n");
            break;
        }

    }while(choice!=5);
    return 0;
}
