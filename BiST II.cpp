//include library
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
//class bst
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
//inserthelper	
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
//displayhelper
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
//searchhelper
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
//replace at parent
	void replaceatparent(Node * curr, Node *temp){
			
		if(curr->parent->left == curr){
					
					curr->parent->left = temp;
					if(curr->left != NULL)
					curr->left->parent = curr->parent;
					}
				else{
					
					curr->parent->right = temp;
					if(curr->right != NULL)
					curr->right->parent = curr->parent;
				}

		delete curr;
		}
//Delete Node
	void del(int value){
	    //tree null
		if((root ==NULL)||(search(value) == NULL))
			return;
			//for parent at root
		else if (search(value) == root){
		    //right sided tree
			if((root->left == NULL)&&(root->right != NULL)){
			Node * temp = root;
			root = temp->right;
			root->parent = NULL;
			delete temp;
			}
			//left sided tree
			else if((root->left!= NULL)&&(root->right == NULL)){
			Node * temp = root;
			root = temp->left;
			root->parent = NULL;
			delete temp;
			}
			//other case
			else{
			    Node * temp = root;
				Node* min = find_min(temp->right);
				temp->data = min->data;
				
					replaceatparent(min, min->right);			
				
		}}
		else{
			Node* temp = search(value);
			if((search(value)->left == NULL)&&(search(value)->right == NULL)){
				replaceatparent(temp, NULL);			
			}
			else if((search(value)->left!= NULL)&&(search(value)->right == NULL)){
				replaceatparent(temp, temp->left);				
			}
			else if((search(value)->left == NULL)&&(search(value)->right != NULL)){
				
				replaceatparent(temp, temp->right);				
			}
			else{	
				Node* min = find_min(search(value)->right);
				temp->data = min->data;
				
					replaceatparent(min, min->right);			
				}
	}}
	int count(Node * curr){
		}
	
};
int main(){
bst b1;
b1.insert(1);
b1.insert(4);
b1.insert(7);
b1.insert(8);
b1.insert(9);
b1.insert(2);
b1.insert(3);
b1.insert(5);
b1.insert(6);
b1.insert(10);
b1.display();
Node * a = b1.find_min(b1.search(3));
cout<<a->data<<endl;
b1.del(7);
b1.display();
b1.del(9);
b1.display();
b1.del(4);
b1.display();
return 0;
}
