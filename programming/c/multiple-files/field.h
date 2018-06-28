#ifndef FIELD_H_
#define FIELD_H_

#define NX 256
#define NY 256

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
