#include<iostream>
using namespace std;
#include "node.h"


Node::Node(int val){
     this->val=val;
     this->color = "RED";
     this->left=NULL;
     this->right= NULL;
     this->parent=NULL;
     }
