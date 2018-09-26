#include <iostream>

using namespace std;

//a binary tree has data, pointer to left child,
//and a pointer to right child

bool isSubtree(struct Node *T, struct Node *S);

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

//given a binary tree, print its nodes according to
//"bottom-up" postorder traversal

void printPostorder(struct Node *node)
{
    if(node == NULL)
        return;

     printPostorder(node->left);

     printPostorder(node->right);

     cout << node->data << " ";
}

void printInorder(struct Node *node)
{
    if(node == NULL)
        return;

    printInorder(node->left);

    cout << node->data << " ";

    printInorder(node->right);

}

bool isIdentical(struct Node *root1, struct Node *root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }

    //they are different
    if(root1 == NULL || root2 == NULL)
    {
        return false;
    }

    return (root1->data == root2->data && isIdentical(root1->left, root2->left)
    && isIdentical(root1->right, root2->right));
}

bool isSubtree(struct Node *T, struct Node *S)
{
    //base case
    if(S == NULL)
        return true;
    if(T == NULL)
        return false;

    //check the tree with root as current node
    if(isIdentical(T,S))
        return true;


    //if tree with root as current node doesn't match, then try left and subtrees

    return (isSubtree(T->left, S) || isSubtree(T->right, S));

}


void printPreorder(struct Node *node)
{
    if(node == NULL)
        return;

    cout << node->data << " ";
    
    printPreorder(node->left);

    printPreorder(node->right);


}

int main(int argc, const char * argv[])
{
    struct Node *T = new Node(26);
    T->left = new Node(10);
    T->right = new Node(3);
    T->left->left = new Node(4);
    T->left->right = new Node(6);
    T->left->left->right = new Node(30);
    T->right->right = new Node(3);

    struct Node *S = new Node(10);
    S->right = new Node(6);
    S->left = new Node(4);
    S->left->right = new Node(30);

    if(isSubtree(T,S))
        cout << "Tree 2 is a subtree of Tree 1";
    else
        cout << "Tree 2 is not a subtree of Tree 1";
   /* cout << "\n Preorder traversal is \n";
    printPreorder(root);

    cout << "\n Inorder traversal is \n";
    printInorder(root);

    cout << "\n Postorder traversal is \n";
    printPostorder(root);
   */
    return 0;
}

