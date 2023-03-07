#ifndef RB_H
#define RB_H

 //implement red black here

//RED BLACK NODE
template <class T>
class RB_node{
    public:
    T key;
    RB_node* left;
    RB_node* right;
    RB_node* p;
    bool color;
};

//RED BLACK TREE
template <class T>
class RB{
    T *root;
    T *nil;    
};

template <class T>
RB_node<T>* RB_INSERT(RB<RB_node<T> > *tree, RB_node<T> *z){
    RB_node<T> *y = tree->nil;
    RB_node<T> *x = tree->root;

    while (x != tree->nil)
    {
        y = x;
        if (z->key < x->key)
            x = x.left;
        else
            x = x.right;
    }
    z->p = y;
    if (y == tree->nil)
        tree->root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y.right = z;
    z->left = tree->nil;
    z->right = tree->nil;
    z->color = RED;
    RB_INSERT_FIXUP(tree,z);
}

template <class T>
void   RB_INSERT_FIXUP(RB<RB_node<T> > *tree, RB_node<T> *z){
    RB_node<T> *y = tree->nil;
    
    while (z->p->color == RED)
    {
        if (z->p == z->p->p->left)
        {
            y = z->p->p->right;
            if (y->color == RED)
            {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else if (z == z->p->right)
            {
                z = z->p;
                LEFT_ROTATE(T, z);
                z->p->color = BLACK;
                z->p->p->color = RED;
                RIGHT_ROTATE(T, z);
            }
        }
        else 
        {
            //(same as then clause with “right” and “left” exchanged)
        }
    }
    tree->root->color = BLACK;
}

#endif