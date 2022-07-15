#ifndef RBT_H
#define RBT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define RED true
#define BLACK false

#define Key int
#define Value int
#define NULL_Value -1

typedef struct rbt_t {
    Key key;
    Value val;
    bool color;
    struct rbt_t* l;
    struct rbt_t* r;
} rbt;

Value search(rbt *n, Key key);
bool is_red(rbt* x);
rbt* rotate_left(rbt* h);
rbt* rotate_right(rbt* h);
void flip_colors(rbt* h);
rbt* create_node(Key key, Value val, bool color);
int compare(Key a, Key b);
rbt* rbt_insert(rbt* h, Key key, Value val);

#endif /* RBT_H */