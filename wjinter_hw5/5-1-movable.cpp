#include<utility>
#include<iostream>

//Yes it is better. In lecture, we spoke about the some further improvements.
//By taking at the null, we can make function to move from p1 and and p2

using namespace std;

//10/10

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

        btree(const btree& other):root(other.root){cout<<"copy\n";}

        btree(btree&& other):root(move(other.root)){cout<<"move\n";}

        btree& operator=(const btree&){cout<<"copy\n"; return *this;}

        btree& operator=(btree&& other){
        	cout<<"move\n";
			root=move(other.root);
        	return *this;
        }

        void insert(int key);
        node *search(int key);
        void destroy_tree();

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);

        node *root;
};

btree::btree(){root=NULL;}

btree::~btree(){destroy_tree();}

//given
void btree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}
void btree::insert(int key, node *leaf)
{
  if(key< leaf->key_value)
    {
      if(leaf->left!=NULL)
       insert(key, leaf->left);
      else
      {
        leaf->left=new node;
        leaf->left->key_value=key;
        leaf->left->left=NULL;
        leaf->left->right=NULL;
      }
    }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;
      leaf->right->right=NULL;
    }
  }
}
node *btree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->key_value)
      return leaf;
    if(key<leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}
void btree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->key_value=key;
    root->left=NULL;
    root->right=NULL;
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
    btree first(construct);
    btree second(move(construct));
    assign2=assign;
    assign3=move(assign);
}
