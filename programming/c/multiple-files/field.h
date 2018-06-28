#ifndef FIELD_H_
#define FIELD_H_

#include <stdio.h>
#include <stdlib.h>

#define NX 256
#define NY 256
#define DX 0.01
#define DY 0.01


// Field structure definition
typedef struct {
    int nx;
    int ny;
    double dx;
    double dy;
    double dx2;
    double dy2;
    double data[NX + 2][NY + 2];
} field;

void init_field(field *f, int nx, int ny);

void laplacian(field *f);

void print_field(field *f);

#endif
