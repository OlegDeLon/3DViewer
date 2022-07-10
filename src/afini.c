#include "afini.h"

void scale(array_d *pdata, double a) {
    for (int i = 0; i < pdata->n; i++) {
        pdata->vertexesarray[i] = pdata->vertexesarray[i] * a;
    }
}

void move_x(array_d *pdata, double a) {
    for (int i = 0; i < pdata->n; i+=3) {
        pdata->vertexesarray[i] = pdata->vertexesarray[i] + a;
    }
}

void move_y(array_d *pdata, double a) {
    for (int i = 1; i < pdata->n; i+=3) {
        pdata->vertexesarray[i] = pdata->vertexesarray[i] + a;
    }
}

void move_z(array_d *pdata, double a) {
    for (int i = 2; i < pdata->n; i+=3) {
        pdata->vertexesarray[i] = pdata->vertexesarray[i] + a;
    }
}

void rotation_by_ox(array_d *pdata, double angle) {
    for (int i = 1; i < pdata->n; i += 3) {
        double temp_y = pdata->vertexesarray[i];
        double temp_z = pdata->vertexesarray[i + 1];
        pdata->vertexesarray[i] = cos(angle) * temp_y - sin(angle) * temp_z;
        pdata->vertexesarray[i + 1] = sin(angle) * temp_y + cos(angle) * temp_z;
    }
}

void rotation_by_oy(array_d *pdata, double angle) {
    for (int i = 0; i < pdata->n; i += 3) {
        double temp_x = pdata->vertexesarray[i];
        double temp_z = pdata->vertexesarray[i + 2];
        pdata->vertexesarray[i] = cos(angle) * temp_x + sin(angle) * temp_z;
        pdata->vertexesarray[i + 2] = (-1) * sin(angle) * temp_x + cos(angle) * temp_z;
    }
}

void rotation_by_oz(array_d *pdata, double angle) {
    for (int i = 0; i < pdata->n; i += 3) {
        double temp_x = pdata->vertexesarray[i];
        double temp_y = pdata->vertexesarray[i + 1];
        pdata->vertexesarray[i] = cos(angle) * temp_x - sin(angle) * temp_y;
        pdata->vertexesarray[i + 1] = sin(angle) * temp_x + cos(angle) * temp_y;
    }
}
