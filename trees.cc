//tree class
struct Node { 
  int key; 
  Node *left, *right; 
  Node (int x) 
  { 
     key = x; 
     left = right = NULL; 
  } 
}; 
//insert function
void insert(Node* temp, int key) 
{ 
    queue<Node*> q; 
    q.push(temp); 
    while (!q.empty()) { 
        Node* temp = q.front(); 
        q.pop(); 
  
        if (!temp->left) { 
            temp->left = new Node(key); 
            break; 
        } else
            q.push(temp->left); 
  
        if (!temp->right) { 
            temp->right = new Node(key); 
            break; 
        } else
            q.push(temp->right); 
    } 
}

//delete node
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
}
struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->key = temp->key; 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
}

//traversal
void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
    printPostorder(node->left); 
    printPostorder(node->right); ode 
    cout << node->data << " "; 
} 
void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
    cout << node->data << " "; 
    printPreorder(node->left);  
    printPreorder(node->right); 
}  
void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    cout << node->data << " "; 
    printInorder(node->right); 
}

//find height
int maxDepth(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
} 

//leafcount
unsigned int getLeafCount(struct node* node)  
{  
    if(node == NULL)      
        return 0;  
    if(node->left == NULL && node->right == NULL)  
        return 1;          
    else
        return getLeafCount(node->left)+  
            getLeafCount(node->right);  
} 

//