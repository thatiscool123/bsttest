/*
github exercise
*/

#include<iostream>

using namespace std;


class node
{
    public:
    int data;
    node *left,*right;
};


class bst
{
	node *root;

    void insert(int data); 	//take integer as an argument and inserts it into tree
	void search_minimum();	//print the smallest number in the entire tree

	//theses 3 function work together to delete specified node
	void search_del(node *&, int , node *&); //this function gets the node to be deleted and its parent
	void delete_node(node *&, int); //this deletes the node with help of search_del and inoder_successor functions
	node* inoder_successor(node*);	//this returns the inorder successor of node to deleted which has 2 childrens



	public:
	bst()
	{
		root=NULL;
	}
	void menu();

};


void bst::insert(int data)
{
	node *curr,*temp;
	temp=new node;
	if(temp==NULL)
    {
        cout<<"memory not allocated"<<endl;
        return;
    }

    temp->data=data;
    temp->left=temp->right=NULL;

    if(root==NULL)
    {
    	root=temp;
    	cout<<"\n"<<data<<" inserted in the bst";
    	return;
    }


    curr=root;

    while(1)
    {
    	if(curr->data>data)
    	{
    		if(curr->left==NULL)
    		{
    			curr->left=temp;
    			cout<<"\n"<<data<<" inserted in the bst";
		    	return;
    		}
    		else
    			curr=curr->left;
    	}
    	else if(curr->data<data)
    	{
    		if(curr->right==NULL)
    		{
    			curr->right=temp;
    			cout<<"\n"<<data<<" inserted in the bst";
		    	return;
    		}
    		else
    			curr=curr->right;
    	}
    	else
    	{
    		cout<<"\n"<<data<<" already exits in the bst";
		    return;
    	}
    }
}


void bst::search_minimum()
{
	node *current=root;
	while(current->left!=NULL)
		current=current->left;
	cout<<"\nminimum data value in the tree is : "<< current->data;
}


void bst::search_del(node*& curr,int data,node*&parent) // used '*&' cause i wanted to pass the reference of pointer and not just the reference of variable
{
	if(curr==NULL)
		return;
	else if(curr->data>data)
	{
		parent=curr;
		curr=curr->left;
		search_del(curr,data,parent);
	}
	else if(curr->data<data)
	{
		parent=curr;
		curr=curr->right;
		search_del(curr,data,parent);
	}
	else
		return;	//this just stops the execution as changes made in this function also reflect in fuction that called this function
}


void bst::delete_node(node*& root,int data)//this needs to be *& to change curr->right in function that called this 
{
	node* curr=root;
	node* parent=NULL;
	node* temp;

	search_del(curr,data,parent);
	temp=curr;
	if(curr==NULL)
	{
		cout<<"\nnumber doesn't exist in the tree";
		return;
	}
	if (curr->left==NULL && curr->right==NULL)
	{
		if(curr!=root)
		{
			if(parent->left==curr)
				parent->left=NULL;
			else
				parent->right=NULL;

		}
		else
			root=NULL;

		free(curr);
		cout<<"\n"<<data<<" is deleted from the tree";
	}
	else if(curr->left!=NULL && curr->right!=NULL)
	{
		node * succ=inoder_successor(curr->right);
		int val=succ->data;			//swap node to be deleted with the inoder_successor node
		succ->data=curr->data;
		curr->data=val;
		delete_node(curr->right,succ->data);	//call the delete_node of swaped node
	}
	else
	{
		temp=(curr->left)?curr->left:curr->right;
		if(curr!=root)
		{
			if(parent->left==curr)
				parent->left=temp;
			else
				parent->right=temp;
		}
		else
			root=temp;

		free(curr);
		cout<<"\n"<<data<<" is deleted from the tree";
	}
	return;

}


node* bst::inoder_successor(node* curr)
{
	while(curr->left!=NULL)
		curr=curr->left;
	return curr;
}


void bst::menu()
{
	int ch,data;

    //sample data
    insert(15);
	insert(10);
	insert(20);
    insert(17);                 
	insert(11);
	insert(5);
    insert(7);
	insert(23);
	insert(30);

    /*
                    15
                 /      \
                10       20
              /   \    /    \
             5     11 17     23
               \               \ 
                7               30
    */



    while(true)
    {
		cout<<"\n\n\n------------------------------------\nMENU";
		cout<<"\n1. insert";
		cout<<"\n2. Number of nodes in the longest path"; //find the number of nodes int the longest path from root 
		cout<<"\n3. search minimun data value"; // find minimum data value in the entire tree. 
		cout<<"\n4. Swap tree order"; //all left nodes will become right nodes and all left nodes will become left nodes
		cout<<"\n5. search in tree";    
		cout<<"\n6. display inorder";   
		cout<<"\n7. display preorder";  
		cout<<"\n8. display postorder";
		cout<<"\n9. delete node"; 
		cout<<"\n10.exit";
		cout<<"\n\nEnter the choice: ";
		cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"\nenter the number you want to insert: ";
				cin>>data;
            	insert(data);
                break;
            case 2:
                break;
            case 3:
				//searches and prints the smallest value in the entire tree
				search_minimum();
                break;
            case 4:
                break;
			case 5:
				break;
            case 6:
				break;
			case 7:
                break;
			case 8:
                break;
			case 9:
				cout<<"\nenter the number you want to delete: ";
				cin>>data;
				delete_node(root,data);
                break;
			case 10:
                return;
            default:
                cout<<"\nenter the correct choice";
        }
    }
}


int main()
{
	bst b;
	b.menu();
}
