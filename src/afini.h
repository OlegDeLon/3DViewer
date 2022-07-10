#ifndef SRC_AFINI_H_
#define SRC_AFINI_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "parse.h"

void scale(array_d *pdata, double a);
void move_x(array_d *pdata, double a);
void move_y(array_d *pdata, double a);
void move_z(array_d *pdata, double a);
void rotation_by_ox(array_d *pdata, double angle);
void rotation_by_oy(array_d *pdata, double angle);
void rotation_by_oz(array_d *pdata, double angle);
#endif  //  SRC_AFINI_H_
