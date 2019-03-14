#include<iostream>
using namespace std;
//node class
class node{
	public:
		int data;
		node *left;
		node *right;
		//constructor
		node(int value){
			left=NULL;
			right=NULL;
			data=value;
		}
};
//class binary search tree
class bst{
	public:
		node * root;
		bst(){
			root=NULL;
		}
		//insert
	void insert(int value){
		inserthelper(root, value);
	}
	void inserthelper(node *curr, int value){
		//base case if curr null,insert value
		if(curr==NULL){
			curr = new node(value);
			if(root == NULL){
				root = curr;
				return ;
			}
		}
		//else compare the curr data with value
		else if(value < curr->data){
		//if  value < curr data 
		//if left is null insert it
		//else move left and call inserthelper
		if(curr->left==NULL) curr->left = new node(value);
	    else  inserthelper(curr->left , value);
		}
		else{
				//else move right and call inserthelper
		 if(curr->right ==NULL) curr->right= new node(value);
		 else inserthelper(curr->right , value);
		}	
	}	
	//display
	void display(){
		display2(root);
		cout<<endl;
	}
	void display2(node * curr){
		//inorder display-left,root,right
		//base condiition
		if(curr==NULL) return;
		//display left
		display2(curr->left);
		//display curr
		cout<<curr->data<<"->";
		//display right
		display2(curr->right);
	}
	//search
	node * search(node * curr , int value){
		//if value found or reached end of tree
			if(curr==NULL|| curr->data==value) return curr;
			else if (value < curr->data) return search(curr->left,value);
			else return search (curr->right , value);
                        
	}

};
int main(){
	bst b1;
	b1.insert(3);
	b1.insert(2);
	b1.insert(1);
	b1.display();
	b1.insert(4);
	b1.insert(6);
	b1.insert(5);
	b1.insert(7);
	b1.insert(9);
	b1.insert(8);
	b1.display();
	if (b1.search (b1.root,1)!=NULL) cout<<"Number is found."<<endl;
	else cout<<"Number is not found."<<endl;
	return 0;
}

