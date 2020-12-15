#include <iostream>
using namespace std;

struct Leaf
{
int data;
Leaf* right;
Leaf* left;
};

Leaf* NewLeaf(int input)
{
Leaf* TempLeaf = new Leaf;
TempLeaf->data = input;
TempLeaf->left = nullptr;
TempLeaf->right = nullptr;
return TempLeaf;
}

Leaf* insert(Leaf* leaf, int index)
{
    if(leaf == nullptr)
    {
        return NewLeaf(index);
        //Base Case
    }
    else if(index < leaf->data) // Left index
    {
        leaf->left = insert(leaf->left,index);
    }
    else // right index
    {
        leaf->right = insert(leaf->right,index);
    }
    return leaf;
}

Leaf *MinValue(Leaf *leaf)
{
    Leaf *position = leaf;
    bool t = position && position->left != (nullptr);
    while(t){position = position->left;}
    return position;}

void order(Leaf *root)
{
    if(root != nullptr)
    {
        order(root->left);
        cout << root->data << endl;
        order(root->right);
        
    }
    
}

Leaf *DeleteNode(Leaf* leaf, int index)
{

    if(leaf==nullptr)
    {
        return nullptr;
    }
    else if(index > leaf->data)
    {
        leaf->right = DeleteNode(leaf->right,index);
    }
    else
    {
        //if node has one child
        if(leaf->left == nullptr)
        {
            Leaf *TempPointer = leaf->right;
            free(leaf);
            return TempPointer;
        }
        else if(leaf->right == nullptr)
        {
            Leaf* TempPointer = leaf->right;
            free(leaf);
            return TempPointer;

        }
        else//When Leaf has two leaves
        {
            Leaf* TempPointer = MinValue(leaf->right);
            leaf->data = TempPointer->data;
            leaf->right = DeleteNode(leaf->right, TempPointer->data);

        }
    }
    return leaf;
}

int main()
{
    Leaf* Root = nullptr;
    Root = insert(Root,8);
    Root = insert(Root,4);
    Root = insert(Root,3);
    Root = insert(Root,2);
    Root = DeleteNode(Root,2);
  
    order(Root);
    
}