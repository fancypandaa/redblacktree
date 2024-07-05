#include<bits/stdc++.h>
using namespace std;
#include "node.h"
#include "global.h"
#include "redBlack.h"
#include "order.h"

class RedBlackTree{
private:
   // Node* root;
   // Node* NIL;
   void leftRotate(Node* x){
    Node* y= x->right;
    x->right=y->left;
    if(y->left != NIL){
      y->left->parent=x;
    }
    y->parent=x->parent;
    if(x->parent == nullptr){
     root = y;
    }
    else if(x == x->parent->left){
      x->parent->left = y;
    }
    else{
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }
  void rightRotate(Node* x){
  Node* y= x->left;
  x->left = y->right;
  if(y->right != NIL){
     y->right->parent = x;
  }
  y->parent = x->parent;
  if(x->parent == nullptr){
    root = y;
  }
  else if( x== x->parent->right){
    x->parent->right = y;
  }
  else{
   x->parent->left = y;
  }
 y->right = x;
 x->parent = y;
  }
  void recolor(Node* n,Node* m){
      n->parent->color="BLACK";
      m->color="BLACK";
      n->parent->parent->color = "RED";
      n = n->parent->parent;
  }
  // dir 0->left,1->right
  void reorder(Node *n,bool dir){
    if(!dir){
     if(n == n->parent->right){
       n=n->parent;
       leftRotate(n);
     }
      n->parent->color = "BLACK";
      n->parent->parent->color = "RED";
      rightRotate(n->parent->parent);
    }
    else{
      if(n==n->parent->left){
        n=n->parent;
	rightRotate(n);
      }
      n->parent->color = "BLACK";
      n->parent->parent->color = "RED";
      leftRotate(n->parent->parent);
    }
  }
  void fixInsert(Node* n){
   while(n != root && n->parent->color == "RED"){
    if(n->parent == n->parent->parent->left){
     Node* m = n->parent->parent->right;
     if(m->color == "RED"){
      recolor(n,m);
     }
     else{
      reorder(n,0);
     }
    }
    else{
     Node* m = n->parent->parent->left;
     if(m->color == "RED"){
       recolor(n,m);
     }
     else{
      reorder(n,1);
     }
    }
   }
   root->color = "BLACK";
  }
public:
  RedBlackTree(){
    NIL = new Node(0);
    NIL->color = "BLACK";
    NIL->left = NIL->right =NIL;
    root = NIL;
  }
  void insert(int val){
  Node* new_node = new Node(val);
  new_node->left = NIL;
  new_node->right = NIL;
//  cout<<new_node->val<<" ";
  Node* parent = nullptr;
  Node* current = root;
  while(current != NIL){
    parent = current;
    if(new_node->val < current->val){
      current=current->left;
    }
    else{
     current= current->right;
    }
  }
  new_node->parent = parent;
  if(parent == nullptr){
    root = new_node;
  }
  else if(new_node->val < parent->val){
    parent->left = new_node;
  }
  else{
    parent->right = new_node;
  }
  if(new_node -> parent == nullptr){
    new_node->color = "BLACK";
    return;
  }
  if(new_node->parent->parent == nullptr){
    return;
  }
  fixInsert(new_node);
  }
  void inorder(){ inorder_helper(root); }
  void postorder() { postorder_helper(root); }
  void preoder() {  preorder_helper(root); }
}; 

int main(){
 cout<<" !!! RED BLACK TREE !!! "<<endl;
 RedBlackTree rdbt;  
 rdbt.insert(10);
 rdbt.insert(20);
 rdbt.insert(30);
 rdbt.insert(15);
 cout<< "Inorder Traveresl: "<<endl;
 rdbt.inorder();

}
