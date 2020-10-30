#include <bits/stdc++.h>
using namespace std;
// Represents a node of an n-ary tree
struct Node
{
    char key;
    vector<Node *> child;
    struct Node *next;
};

// Utility function to create a new tree node
Node *newNode(char key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
//BFS traverse to print output
void levelTraverse(Node *root)
{

    Node *temp = root;
    if (temp == NULL)
        return;

    queue<Node *> q; // Create a queue
    q.push(temp);    // Enqueue root
    while (!q.empty())
    {
        int n = q.size();
        // If this node has children
        cout<<" ";
        while (n > 0)
        {
            Node *p = q.front();
            q.pop();
            cout << p->key << " ";

            if (p->child.size() > 0 && p->child[0])
            {
                q.push(p->child[0]);
            }
            if (p->next)
            {
                q.push(p->next);
            }
            n--;
        }

        cout << endl;
    }
}

//print binary tree Preorder
void traverse(Node *root)
{

    if (root)
    {
        cout << root->key << " ";
        if (root->child.size() > 0)
            traverse(root->child[0]);
        traverse(root->next);
    }
}
// Prints the n-ary tree level wise
void LevelOrderTraversal(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
        return;
    // Standard level order traversal code using queue
    queue<Node *> q; // Create a queue
    q.push(temp);    // Enqueue root
    while (!q.empty())
    {
        int n = q.size();
        // If this node has children
        while (n > 0)
        {
            // Dequeue an item from queue and print it
            Node *p = q.front();
            q.pop();
            cout << p->key << " ";
            // Enqueue all children of the dequeued item
            //main logic to convert it into binary tree using left-chlid-right-sibling representation
            for (int i = 0; i < p->child.size(); i++)
            {
                if (i != p->child.size() - 1)
                {
                    q.push(p->child[i]);
                    p->child[i]->next = p->child[i + 1];
                }
                else
                {
                    q.push(p->child[i]);
                    p->child[i]->next = NULL;
                }
            }
            n--;
        }
        cout << endl; // Print new line between two levels
    }
    cout << "Preorder traversal after converting to binary tree\n";
    traverse(root);
    cout << "\n";
    cout << "Level Order traversal after converting to binary tree\n";
    levelTraverse(root);
}
int main()
{
    //creating General tree

    Node *root = newNode('a');
    (root->child).push_back(newNode('b'));
    (root->child).push_back(newNode('c'));
    (root->child).push_back(newNode('d'));
    (root->child).push_back(newNode('e'));
    (root->child[0]->child).push_back(newNode('f'));
    (root->child[0]->child).push_back(newNode('g'));
    (root->child[3]->child).push_back(newNode('h'));
    (root->child[3]->child).push_back(newNode('i'));
    (root->child[3]->child).push_back(newNode('j'));

    cout << "Level order traversal of general tree\n";
    LevelOrderTraversal(root);

    return 0;
}
