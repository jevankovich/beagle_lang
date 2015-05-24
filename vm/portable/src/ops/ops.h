#ifndef OPS_H
#define OPS_H

#include <stdbool>

struct opParam {
	unsigned int op: 6;
	unsigned int dst: 8;
	unsigned int src1: 9;
	unsigned int src2: 9;
};

// declare ops as array 64 of constant pointer to function (struct opParam)
// returning void
void (*const ops[64])(struct opParam);

#endif // OPS_H
