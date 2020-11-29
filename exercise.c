#include <stdio.h>
#include <stdlib.h>


 typedef struct BTreeNode {
     int data;
     struct BTreeNode * left;
     struct BTreeNode * right;
 } Tree;


Tree * newNode(int data) {
    Tree * new = (Tree *)malloc(sizeof(Tree));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Tree * insert(Tree * root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return root;
    }
    Tree * it = root;
    while(1) {
        if (data >= it->data){
            if (it->right == NULL) {
                it->right = newNode(data);
                return it->right;
            }
            else
                it = it->right;
        }
        else if (data < it->data){
            if (it->left == NULL) {
                it->left = newNode(data);
                return it->left;
            }
            else
                it = it->left;
        }
    }
}

int child(Tree * root, int n) {

	if(root!= NULL){
	n=child(root->left,n);
        n=child(root->right,n);
	n++;
	}

	return n;   
}

int main() {
    Tree * root;
    Tree * roottmp;
    int number,N,i,findnum,num=0;
    scanf("%d",&N);

    scanf("%d", &number);
    root = newNode(number);

    for(i=0;i<N-1;i++)
    {
        scanf("%d", &number);
        insert(root, number);
    }
    roottmp=root;
    scanf("%d",&findnum);

    while(roottmp != NULL && roottmp->data != findnum)
    {
     	if(roottmp->data >= findnum)
    		 roottmp=roottmp->left;
    	else
   		 roottmp=roottmp->right;
    }

    num=child(roottmp,num);

    if(roottmp==NULL)
	printf("-1");
    else
        printf("%d", num-1);

}
