#include <string>
#include <iostream>
#include <vector>
#include "code/utilities/printers/lib.hpp"


//tree
template <typename T>
struct BinaryNode {
    
    BinaryNode(T val):
    val(val) {}
        
    T val;
    struct BinaryNode *left = nullptr;
    struct BinaryNode *right = nullptr;
};


//traverse algorithms
template <typename T, typename Fun>
void perform_preorder(T *root, Fun fun){
    
    if(root == NULL) return;
    fun(root);
    perform_preorder(root->left,fun);
    perform_preorder(root->right,fun);
}

template <typename T, typename Fun>
void perform_inorder(T *root, Fun fun){
    
    if(root == NULL) return;
    perform_inorder(root->left,fun);
    fun(root);
    perform_inorder(root->right,fun);
}

template <typename T, typename Fun>
void perform_inorder_with_previous(T *root, Fun fun){
    T *previous = nullptr;
    perform_inorder(root,[&](T* t){
        if (previous){
            fun(previous,t);
        }
        previous = t;
    });
}

template <typename T, typename Fun>
void perform_postorder(T *root, Fun fun){
    
    if(root == NULL) return;
    perform_postorder(root->left,fun);
    perform_postorder(root->right,fun);
    fun(root);
}

//utility traversals
template <typename T>
std::vector<int> inorder_traversal_list(T *root){
    std::vector<int> result;
    perform_inorder(root,[&](T* t){
        result.emplace_back(t->val);
    });
    return result;
}

template <typename T>
void fix_bst(T *root){
    
    T *node1 = nullptr;
    T *node2 = nullptr;
    
    perform_inorder_with_previous(root,[&](T* previous, T* t){
        if (previous->val > t->val){
            
            if (!node1){
                node1 = previous;
            }
            else{
                node2 = t;
            }
        }
    });
    
    //non-adjacent
    if (!node2){
        std::swap(node1->val,node1->left->val);
    }
    
    //adjacent
    else{
        std::swap(node1->val,node2->val);
    }
}

int main(){
    
    /*   6 
        /  \ 
       10    2 
      / \   / \ 
     1   3 7  12 
     10 and 2 are swapped 
    */
    BinaryNode<int> root(6);
    BinaryNode<int> r1(10);
    BinaryNode<int> r2(2);
    BinaryNode<int> r3(1);
    BinaryNode<int> r4(3);
    BinaryNode<int> r5(7);
    BinaryNode<int> r6(12);
    root.left = &r1;
    root.right = &r2;
    root.left->left = &r3;
    root.left->right = &r4;
    root.right->left = &r5;
    root.right->right = &r6;
    std::cout << inorder_traversal_list(&root) << std::endl;
    fix_bst(&root);
    std::cout << inorder_traversal_list(&root) << std::endl;
}