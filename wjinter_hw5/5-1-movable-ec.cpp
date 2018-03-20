#include<utility>
#include<iostream>

//Yes it is better. In lecture, we spoke about the some further improvements.
//By taking at the nullptr, we can make function to move from p1 and and p2

using namespace std;

//8/10
//I provided the feedback from my MACOS system. I am not sure if they help.

struct node
{
    int key_value;
    node *left;
    node *right;
};

class btree
{
public:
    btree();
    ~btree();

    btree(const btree& other):root(other.root){ }

    btree(btree&& other):root(move(other.root)){ }

    btree& operator=(const btree&){ return *this;}

    btree& operator=(btree&& other){
        root=move(other.root);
        return *this;
    }

    void insert(int key);
    node *search(int key);
    void destroy_tree();

    //find max
    btree* find_Max(node *leaf);

    //find min
    btree* find_Min(node *leaf);

private:
    void destroy_tree(node *leaf);
    void insert(int key, node *leaf);
    node *search(int key, node *leaf);

    node *root;
};

btree::btree(){root=nullptr;}

btree::~btree(){destroy_tree();}

//given
void btree::destroy_tree(node *leaf)
{
    if(leaf!=nullptr)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}



btree* btree::find_Max(node *leaf){
    if(leaf->right == NULL){
        return this;
    }else{
        return find_Max(leaf->right);
    }
}

btree* btree::find_Min(node *leaf){
    if(leaf->left == NULL){
        return this;
    }else{
        return find_Min(leaf->left);
    }
}

void btree::insert(int key, node *leaf)
{
    if(key< leaf->key_value)
    {
        if(leaf->left!=nullptr)
            insert(key, leaf->left);
        else
        {
            leaf->left=new node;
            leaf->left->key_value=key;
            leaf->left->left=nullptr;
            leaf->left->right=nullptr;
        }
    }
    else if(key>=leaf->key_value)
    {
        if(leaf->right!=nullptr)
            insert(key, leaf->right);
        else
        {
            leaf->right=new node;
            leaf->right->key_value=key;
            leaf->right->left=nullptr;
            leaf->right->right=nullptr;
        }
    }
}
node *btree::search(int key, node *leaf)
{
    if(leaf!=nullptr)
    {
        if(key==leaf->key_value)
            return leaf;
        if(key<leaf->key_value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else return nullptr;
}
void btree::insert(int key)
{
    if(root!=nullptr)
        insert(key, root);
    else
    {
        root=new node;
        root->key_value=key;
        root->left=nullptr;
        root->right=nullptr;
    }
}

node *btree::search(int key)
{
    return search(key, root);
}

void btree::destroy_tree()
{
    destroy_tree(root);
}


int main(){
    btree construct, assign, assign2, assign3;

    construct.insert(1);
    construct.insert(2);
    construct.insert(3);
    construct.insert(4);
    construct.insert(5);

    construct.search(5);

    construct.search(99);

    btree first(construct);
    btree second(move(construct));
    assign2=assign;
    assign3=move(assign);


}
