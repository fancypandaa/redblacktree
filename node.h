// node.h
#ifndef RED_BLACK_TREE_NODE_H
#define RED_BLACK_TREE_NODE_H
//template <typename T>
class Node {
  public:
   	int val;
   	string color;
	Node *left,*right,*parent;
	Node(int val);
/*	Node(int val){
	  val = val;
	  color = "RED";
	  left = NULL;
	  right = NULL;
	  parent = NULL; 
	}*/
};

#endif
