#include "./rbt.h"

Value search(rbt *n, Key key) {
    int cmp = 0;
    while(n) {
        cmp = compare(key, n->key);
        if (cmp < 0) n = n->l;
        else if (cmp > 0) n = n->r;
        else return n->val;
    }
    return NULL_Value;
}

bool is_red(rbt* x) {
    if(!x)
        return BLACK;
    
    return x->color;
}

rbt* rotate_left(rbt* h) {
    rbt* x = h->r;
    h->r = x->l;
    x->l = h;
    x->color = x->l->color;
    x->l->color = RED;
    return x;
}

rbt* rotate_right(rbt* h) {
    rbt* x = h->l;
    h->l = x->r;
    x->r = h;
    
    x->color = x->r->color;
    x->r->color = RED;
    
    return x;
}

void flip_colors(rbt* h) {
    h->color = RED;
    h->l->color = BLACK;
    h->r->color = BLACK;
}

rbt* create_node(Key key, Value val, bool color) {
    rbt* h = (rbt*) malloc(sizeof(rbt));
    
    h->key = key;
    h->val = val;
    h->l = NULL;
    h->r = NULL;

    return h;
}

int compare(Key a, Key b) {
    return a - b;
}

rbt* rbt_insert(rbt* h, Key key, Value val) {
    if(!h)
        return create_node(key, val, RED);

    int cmp = compare(key, h->key);
    if(cmp < 0)
        h->l = rbt_insert(h->l, key, val);
    else if(cmp > 0)
        h->r = rbt_insert(h->r, key, val);
    else
        h->val = val;

    if(is_red(h->r) && !is_red(h->l))
        h = rotate_left(h);
    if(is_red(h->l) && is_red(h->l->l))
        h = rotate_right(h);
    if(is_red(h->l) && is_red(h->r))
        flip_colors(h);

    return h;
}