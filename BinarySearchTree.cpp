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
