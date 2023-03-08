#ifndef RB_H
#define RB_H

//implement red black here
#define RED 0
#define BLACK 1
//RB NODE
template <class T>
class RB_NODE{
    public:
    T key;
    RB_NODE* left;
    RB_NODE* right;
    RB_NODE* p;
    bool color;
    RB_NODE(){
        this->left = 0;
        this->right = 0;
        this->p = 0;
        this->color = RED;
        this->key = T();
    }
    RB_NODE(T key){
        this->key = key;
        this->left = 0;
        this->right = 0;
        this->p = 0;
        this->color = RED;
    }
    RB_NODE(RB_NODE<T>& node){
        this->key = node->key;
        this->left = new RB_NODE(node->left);
        this->right = new RB_NODE(node->right);
        this->p = new RB_NODE(node->p);
        this->color = node->color;
    }
    RB_NODE<T>& operator=(RB_NODE<T>& node){
        this->key = node->key;
        if (this->left)
            delete this->left;
        this->left = new RB_NODE(node->left);
        if (this->right)
            delete this->right;
        this->right = new RB_NODE(node->right);
        if (this->p)
            delete this->p;
        this->p = new RB_NODE(node->p);
        this->color = node->color;
        return *this;
    }
    ~RB_NODE(){}
};

//RB TREE
template <class T>
class RB{
    T root;
    T nil;
    RB():root(RB_NODE<T>()),nil(RB_NODE<T>()){}
    RB(RB_NODE<T>& root):root(root),nil(RB_NODE()){}
    RB<RB_NODE<T> >& operator=(RB<RB_NODE<T> >& tree){
        this->root = tree->root;
        this->nil = tree->nil;
        return *this;
    }
    ~RB(){}
};

//RB tree minimum
template <class T>
RB_NODE<T>* TREE_MINIMUM(RB_NODE<T> root){
    RB<RB_NODE<T> >* tree;
    while (root.left != tree->nil)
        x = x.left;
    return x;
}

//RB tree maximum
template <class T>
RB_NODE<T>* TREE_MAXIMUM(RB_NODE<T> root){
    RB<RB_NODE<T> >* tree;
    while (root.right != tree->nil)
        x = x.right;
    return x;
}

//RB tree search
template <class T>
RB_NODE<T>* TREE_SEARCH(RB_NODE<T> *x, T k){
    RB<RB_NODE<T> >* tree;
    if (x == tree->nil || k == x->key)
        return x;
    if (k < x->key)
        return TREE_SEARCH(x->left, k);
    else
        return TREE_SEARCH(x->right, k);
}

//RB insert
template <class T>
RB_NODE<T>* RB_INSERT(RB<RB_NODE<T> > *tree, RB_NODE<T> *z){
    RB_NODE<T> *y = tree->nil;
    RB_NODE<T> *x = tree->root;

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

//RB insert fixup
template <class T>
void RB_INSERT_FIXUP(RB<RB_NODE<T> > *tree, RB_NODE<T> *z){
    while (z->p->color == RED)
    {
        if (z->p == z->p->p->left)
        {
            RB_NODE<T> *y = z->p->p->right;
            if (y->color == RED)
            {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else
            {
                if (z == z->p->right)
                {
                    z = z->p;
                    LEFT_ROTATE(tree,z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                RIGHT_ROTATE(tree,z->p->p);
            }
        }
        else
        {
            RB_NODE<T> *y = z->p->p->left;
            if (y->color == RED)
            {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else
            {
                if (z == z->p->left)
                {
                    z = z->p;
                    RIGHT_ROTATE(tree,z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                LEFT_ROTATE(tree,z->p->p);
            }
        }
    }
    tree->root->color = BLACK;
}

//RB left rotation
template <class T>
void LEFT_ROTATE(RB<RB_NODE<T> > *tree, RB_NODE<T> *x){
    RB_NODE<T> *y = x->right;
    x->right = y->left;
    if (y->left != tree->nil)
        y->left->p = x;
    y->p = x->p;
    if (x->p == tree->nil)
        tree->root = y;
    else if (x == x->p->left)
        x->p->left = y;
    else
        x->p->right = y;
    y->left = x;
    x->p = y;
}

//RB right rotation
template <class T>
void RIGHT_ROTATE(RB<RB_NODE<T> > *tree, RB_NODE<T> *y){
    RB_NODE<T> *x = y->left;
    y->left = x->right;
    if (x->right != tree->nil)
        x->right->p = y;
    x->p = y->p;
    if (y->p == tree->nil)
        tree->root = x;
    else if (y == y->p->right)
        y->p->right = x;
    else
        y->p->left = x;
    x->right = y;
    y->p = x;
}

//RB transplant
template <class T>
void RB_TRANSPLANT(RB<RB_NODE<T> > *tree, RB_NODE<T> *u, RB_NODE<T> *v){
    if (u->p == tree->nil)
        tree->root = v;
    else if (u == u->p->left)
        u->p->left = v;
    else
        u->p->right = v;
    v->p = u->p;
}

//RB delete
template <class T>
void RB_DELETE(RB<RB_NODE<T> > *tree, RB_NODE<T> *z){
    RB_NODE<T> *y = z;
    RB_NODE<T> *x;
    bool y_original_color = y->color;
    if (z->left == tree->nil)
    {
        x = z->right;
        RB_TRANSPLANT(tree,z,z->right);
    }
    else if (z->right == tree->nil)
    {
        x = z->left;
        RB_TRANSPLANT(tree,z,z->left);
    }
    else
    {
        y = TREE_MINIMUM(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->p == z)
            x->p = y;
        else
        {
            RB_TRANSPLANT(tree,y,y->right);
            y->right = z->right;
            y->right->p = y;
        }
        RB_TRANSPLANT(tree,z,y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;
    }
    if (y_original_color == BLACK)
        RB_DELETE_FIXUP(tree,x);
}

//RB delete fixup
template <class T>
void RB_DELETE_FIXUP(RB<RB_NODE<T> > *tree, RB_NODE<T> *x){
    while (x != tree->root && x->color == BLACK)
    {
        if (x == x->p->left)
        {
            RB_NODE<T> *w = x->p->right;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->p->color = RED;
                LEFT_ROTATE(tree,x->p);
                w = x->p->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->p;
            }
            else
            {
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    RIGHT_ROTATE(tree,w);
                    w = x->p->right;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->right->color = BLACK;
                LEFT_ROTATE(tree,x->p);
                x = tree->root;
            }
        }
        else
        {
            RB_NODE<T> *w = x->p->left;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->p->color = RED;
                RIGHT_ROTATE(tree,x->p);
                w = x->p->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK)
            {
                w->color = RED;
                x = x->p;
            }
            else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    LEFT_ROTATE(tree,w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->left->color = BLACK;
                RIGHT_ROTATE(tree,x->p);
                x = tree->root;
            }
        }
    }
    x->color = BLACK;
}
#endif