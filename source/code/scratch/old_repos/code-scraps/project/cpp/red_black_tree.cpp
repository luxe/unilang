#include <iostream>
#include <string>
#include <cstdlib>

#include<iostream>
using namespace std;

typedef enum {RED, BLACK} nodecolor ;

struct node
{
    node * left;
    node * right;
    node * parent;
    node * nil;
    node * root;
    node * key;
    int data;
    nodecolor color;
};

node *root=NULL;
int choice;

void PrintMenu()
{
    cout<<"\t\tR E D  B L A C K  T R E E"<<endl<<endl;
    cout<<"\t\t     [1] INSERT "<<endl;
    cout<<"\t\t     [2] DELETE "<<endl;
    cout<<"\t\t     [3] DISPLAY "<<endl;
    cout<<"\t\t     [4] INORDER TREE WALK "<<endl;
    cout<<"\t\t     [5] EXIT"<<endl;
}

void LeftRotate(node* &tree, node* x)
{
    node* y;
    node* nil=tree->nil;
    y=x->right;
    x->right=y->left;
    if (y->left != nil)
        y->left->parent=x;
    y->parent=x->parent;
    if(x==x->parent->left)
        x->parent->left=y;
    else
        x->parent->right=y;
    y->left=x;
    x->parent=y;
}
void RightRotate(node* &tree, node* y)
{
    node* x;
    node* nil=tree->nil;
    x=y->left;
    y->left=x->right;
    if (nil != x->right)
        x->right->parent=y;
    x->parent=y->parent;
    if( y == y->parent->left)
        y->parent->left=x;
    else
        y->parent->right=x;
    x->right=y;
    y->parent=x;

}

void InsertFixUp(node * &tree, node *z)
{
    node *nil=tree->nil;
    node *y;
    while (z->parent->color==RED)
    {
        if(z->parent==z->parent->parent->left)
        {
            y=z->parent->parent->right;
            if(y->color==RED)
            {
                z->parent->color=BLACK;
                y->color=BLACK;
                z->parent->parent->color=RED;
                z=z->parent->parent;
            }
            else if(z=z->parent->right)
            {
                z=z->parent;
                LeftRotate(tree,z);
            }
                z->parent->color=BLACK;
                z->parent->parent->color=RED;
                RightRotate(tree,z->parent->parent);
        }
        else
        {
             y=z->parent->parent->left;
            if(y->color==RED)
            {
                z->parent->color=BLACK;
                y->color=BLACK;
                z->parent->parent->color=RED;
                z=z->parent->parent;
            }
            else if(z=z->parent->left)
            {
                z=z->parent;
                LeftRotate(tree,z);
            }
                z->parent->color=BLACK;
                z->parent->parent->color=RED;
                RightRotate(tree,z->parent->parent);
        }
    }
}

void Insert(node * &tree, node *&z)
{
    node* nil=tree->nil;
    node* root=tree->root;
    node *y;
    node *x;
    y=tree->nil;
    x=tree->root;
    while(x!=tree->nil)
    {
        y=x;
        if((z->key)<(x->key))
            x=x->left;
        else
            x=x->right;
    }
    y=z->parent;
    if(y=tree->nil)
        z=tree->root;
    else if((z->key)<(y->key))
        z=y->left;
    else
        z=y->right;
    z->left=tree->nil;
    z->right=tree->nil;
    z->color=RED;
    InsertFixUp(tree,z);
}

void DeleteFixUp(node * &tree, node *x)
{
    node *nil=tree->nil;
    node *root=tree->nil;
    node *w;
    while(x!=tree->root&&x->color==BLACK)
    {
        if(x==x->parent->left)
        {
             w=x->parent->right;
             if(w->color==RED)
             {
                 w->color=BLACK;
                 x->parent->color=RED;
                 LeftRotate(tree,x->parent);
                 w=x->parent->right;
             }
             if((w->left->color==BLACK)&&(w->right->color==BLACK))
             {
                 w->color=RED;
                 x=x->parent;
             }
             else if(w->right->color==BLACK)
             {
                 w->left->color=BLACK;
                 w->color=RED;
                 RightRotate(tree,w);
                 w=x->parent->right;
             }
             w->color=x->parent->color;
             x->parent->color=BLACK;
             LeftRotate(tree,x->parent);
             x=tree->root;
        }
        else
        {
             w=x->parent->left;
             if(w->color==RED)
             {
                 w->color=BLACK;
                 x->parent->color=RED;
                 LeftRotate(tree,x->parent);
                 w=x->parent->left;
             }
             if((w->right->color==BLACK)&&(w->left->color==BLACK))
             {
                 w->color=RED;
                 x=x->parent;
             }
             else if(w->left->color==BLACK)
             {
                 w->right->color=BLACK;
                 w->color=RED;
                 RightRotate(tree,w);
                 w=x->parent->left;
             }
             w->color=x->parent->color;
             x->parent->color=BLACK;
             LeftRotate(tree,x->parent);
             x=tree->root;
        }

    }
}

node *Delete(node * &tree, node *z)
{
    node *root=tree->root;
    node *nil=tree->nil;
    node *y;
    node *x;
    if((z->left==tree->nil)||(z->right==tree->nil))
        y=z;
    else
        //y=TreeSuccessor(z);
    if(y->left!=tree->nil)
        x=y->left;
    else
        x=y->right;
    x->parent=y->parent;
    if(y->parent=tree->nil)
        tree->root=x;
    else if(y=y->parent->left)
        y->parent->left=x;
    else
        y->parent->right=x;
    if(y!=z)
        z->key=y->key;
    if(y->color==BLACK)
        DeleteFixUp(tree,x);
    return y;
}

void GetChoice()
{
    cout<<"Enter your choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:
            int again;
            do
            {
                cout<<"Enter data to be inserted:";
                int data;
                cin>>data;
                cout<<"Insert again?[0 if no]:";
                cin>>again;
            }while(again!=0);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
    }
}
int main()
{
    do
    {
        PrintMenu();
        GetChoice();
    }while(choice!=5);
    return 0;
}


