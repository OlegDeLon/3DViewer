#include "parse.h"
#define A 1024
void parse1(data_d *pdata, char *str) {
  int i = 0;  // counter str index
  if (str[i] == 'v') pdata->count_of_vertexes++;
  if (str[i] == 'f') {
    pdata->count_of_facets++;
    for (unsigned int i = 2; i < strlen(str); i++) {
      if ((isdigit(str[i]))) {
        pdata->count_of_facets_all++;
        while (str[i] != ' ') {
          i++;
        }
      }
    }
  }
}

void parse2(array_d *p_arrays, char *str) {
  int i = 0;
  if (p_arrays->fcount != 0) p_arrays->fcount += 1;
  if (str[i] == 'v') {
    i = i + 2;
    for (unsigned int i = 2; i < strlen(str); i++) {
      if ((isdigit(str[i]))) {
        if (str[i - 1] == '-') {
          p_arrays->vertexesarray[p_arrays->vcount] = atof(&str[i]) * (-1);
          p_arrays->vcount++;
        } else {
          p_arrays->vertexesarray[p_arrays->vcount] = atof(&str[i]);
          p_arrays->vcount++;
        }
        while (str[i] != ' ') {
          i++;
        }
      }
    }
  } else if (str[0] == 'f') {
    int tmp = 0;
    int check = 0;
    for (unsigned int i = 2; i < strlen(str); i++) {
      if ((isdigit(str[i]))) {
        p_arrays->facetsarray[p_arrays->fcount] = atof(&str[i]) - 1;
        tmp = atof(&str[i]) - 1;
        while (isdigit(str[i])) i++;
        if (check) {
          p_arrays->facetsarray[p_arrays->fcount + 1] = tmp;
          p_arrays->fcount += 2;
        } else {
          p_arrays->fcount += 1;
        }
        if (str[i] == ' ') {
          check = 1;
        } else if (str[i] == '/') {
          while (str[i] != ' ') {
            i++;
          }
          check = 1;
        }
      }
    }
    int t = atof(&str[2]) - 1;
    p_arrays->facetsarray[p_arrays->fcount - 1] = t;
    p_arrays->facetsarray[p_arrays->fcount] =
        p_arrays->facetsarray[p_arrays->fcount - 2];
  }
}

// void main() {
// char str[A];
// data_d data;
// data_d *pdata = &data;
// pdata->count_of_vertexes = 0;
// pdata->count_of_facets = 0;
// pdata->count_of_facets_all = 0;
// FILE *fp = fopen("cube_norm.obj", "rb");
// while (fgets(str, A, fp)) {
//   parse1(pdata, str);
// }
// fclose(fp);
// FILE *pp = fopen("cube_norm.obj", "rb");
// array_d arrays;
// array_d *p_arrays = &arrays;
// arrays.n = pdata->count_of_vertexes * 3;
// arrays.vertexesarray = (float *)malloc(arrays.n * sizeof(float));
// arrays.b = pdata->count_of_facets_all * 2;
// arrays.facetsarray = (int *)malloc(arrays.b * sizeof(int));
// arrays.fcount = 0;
// arrays.vcount = 0;
// while (fgets(str, A, pp)) {
//   parse2(p_arrays, str);
// }
// fclose(pp);
// // for (int i = 0; i < arrays.n; i++) {
// //   printf(" %f", arrays.vertexesarray[i]);
// // }
// for (int i = 0; i < arrays.b; i++) {
//   printf(" %d", arrays.facetsarray[i]);
// }
// free(arrays.facetsarray);
// free(arrays.vertexesarray);
// }
