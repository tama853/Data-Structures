#include <iostream>
#include <string>

class Node
{
    public:
        int name;
        Node* left = NULL;
        Node* right = NULL;
};

Node* insert(Node* root, int key)
{
    if(root==NULL)
    {
        Node* temp=new Node();
        temp->name=key;
        return temp;
    }
    if (key < root->name)
        root->left  = insert(root->left, key);
    else if (key > root->name)
        root->right = insert(root->right, key);   

    return root;
}

std::string traverse(Node* head)
{
    std::string string1, string2, string3;

    if (head == NULL)
        return "";
    string1 = traverse(head->left);
    string2 = std::to_string(head->name);
    string3 = traverse(head->right);
    return string1+string2+string3;
}


int height(Node* head)
{
     if (head == NULL) return -1;
     if ((head->left == NULL) && (head->right == NULL))
        return 0;
     int heightLeft = 0;
     int heightRight = 0;
     if (head->left != NULL)
            heightLeft = height(head->left);
     if (head->right != NULL)
             heightRight = height(head->right);
     if (heightLeft > heightRight)
        return 1+heightLeft;
    else
        return 1+heightRight;

}

Node* rotateLeft(Node *node)
{
	Node* pivot = node -> right;
    node -> right = pivot -> left;
    pivot -> left = node;
    return pivot;
}

Node* rotateRight(Node *node)
{
    Node* pivot = node -> left;
    node -> left = pivot -> right;
    pivot -> right = node;
    return pivot;
}

Node* rotateLeftRight(Node *node)
{
	node->left = rotateLeft(node->left);
    return rotateRight(node);
}

int main()
{
    Node* root=NULL;
    int x;
    int num;
    std::cin >> num;
    for(int i=0;i<num;i++)
    {
        std::cin>>x;
        root=insert(root,x);
    }
    root=rotateLeftRight(root);
    std::cout << traverse(root) << std::endl;
    std::cout << height(root);
}
