#include<iostream>
using namespace std;
#include "node.h"
#include "global.h"
#include "order.h"

void inorder_helper(Node* node){
   if(node != NIL){
     inorder_helper(node->left);
     cout<<node->val<<" ";
     inorder_helper(node->right);
   }
} 

void postorder_helper(Node* node){
  if(node != NIL){
    postorder_helper(node->left);
    postorder_helper(node->right);
    cout<<node->val << " ";
  }
}

void preorder_helper(Node* node){
  if(node !=NIL){
    cout<<node->val<<" ";
    preorder_helper(node->left);
    preorder_helper(node->right);
  }
}

