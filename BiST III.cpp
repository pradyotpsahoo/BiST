#include<iostream>
using namespace std;
//class Node
class Node{
	public:
	int data;
	Node * left;
	Node * right;
	Node * parent;
//constuctor
	Node(int value){
		data = value;
		left = NULL;
		right = NULL;
		parent = NULL;
		}
};
//clas bst
class bst{
	public:
	Node * root;
	bst(){
		root = NULL;
	}
//insert	
	Node * insert(int val){
		insert2(root, val);
	}
//insert2	
	Node * insert2(Node * curr, int val){
		if(root ==NULL){
			root = new Node(val);
		}
		else if (val < curr->data)  {
            
            	if (curr->left == NULL) {
                	curr->left = new Node(val);
                	curr->left->parent = curr;
            	}
             //recursive call
            	else insert2(curr->left, val);
        	}
        	else {
            
            	if (curr->right == NULL) {
            	    	curr->right = new Node(val);
                	curr->right->parent = curr;
            }
            
            else insert2(curr->right, val);
        }
	}
//display	
	void display(){
		display2(root);
		cout<<endl;
	}
//display2
	void display2(Node * curr){
		if(curr == NULL)
			return;
		display2(curr->left);
		cout<<curr->data<<",";
		display2(curr->right);
	}
//search	
	Node * search(int val){
		search2(root,val);
	}
//search2
	Node * search2(Node * curr, int val){
		if(curr == NULL)
			return curr;
		else if(curr->data == val)
			return curr;
		else if(val >= curr->data)
			search2(curr->right,val);
		else 
			search2(curr->left, val);
	}
//find min of subtree
	Node * find_min(Node * parent){
		Node * curr = parent;
		while(curr->left != NULL){
			curr = curr->left;
		}
		return curr;
	}
	//height function
	int height(Node * curr){
		if(curr == NULL )
			return -1;
		else
    	{  
        /* compute the height of each subtree */
        int lh = height(curr->left);  
        int rh = height(curr->right);  
      
        /* use the larger one */
        if (lh > rh)  
            return(lh + 1);  
        else return(rh + 1);  
    	}  
	}
	//count function
	int count(Node * curr){
		if(curr == NULL)
				return 0;
			else	
				return count(curr->left) + 1 + count(curr->right);
	}
	//rangeSearch function
	int rangeSearch(Node*current,int k1,int k2){
			if (current==NULL) return 0; 
			if (current->data == k2 && current->data == k1){ 
				cout<<current->data<<","<<endl;
				return 1;
			}
			if (current->data <= k2 && current->data >= k1){ 
				//print the data
				cout<<current->data<<",";
				//count the nodes
				return 1 + rangeSearch(current->left, k1, k2) + rangeSearch(current->right, k1, k2); 
			} 
			else if (current->data < k2){ 
				return rangeSearch(current->right, k1, k2); 
			} 
			else {
				cout<<endl;
				return rangeSearch(current->left, k1, k2); 
			}
		}
};
int main(){
bst b1;
b1.insert(7);
b1.insert(4);
b1.insert(9);
b1.insert(8);
b1.insert(2);
b1.insert(6);
b1.insert(5);
b1.insert(3);
b1.insert(10);
b1.insert(1);
b1.insert(11);
b1.insert(12);
b1.display();
cout<<"Height of the tree is:"<<b1.height(b1.root)<<endl;
cout<<"Number of elements in the tree is:"<<b1.count(b1.root)<<endl;
cout<<"Number of elements between the given range is:"<<b1.rangeSearch(b1.root,4,11)<<endl;;
return 0;
}
