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

	public:
	bst()
	{
		root=NULL;
	}
	void menu();

};

void bst::menu()
{
	int ch;

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
		cout<<"\n13.exit";
		cout<<"\n\nEnter the choice: ";
		cin>>ch;

        switch(ch)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
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
				break;
			case 11:
                break;
			case 12:
                break;
			case 13:
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
