#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define D 1024

#include "afini.h"
#include "parse.h"

START_TEST(test1) {
  char str[D];
  data_d data;
  data_d *pdata = &data;
  pdata->count_of_vertexes = 0;
  pdata->count_of_facets = 0;
  pdata->count_of_facets_all = 0;
  FILE *fp = fopen("test.obj", "rb");
  while (fgets(str, D, fp)) {
    parse1(pdata, str);
  }
  fclose(fp);
  ck_assert_int_eq(pdata->count_of_vertexes, 3);
  ck_assert_int_eq(pdata->count_of_facets, 1);
  ck_assert_int_eq(pdata->count_of_facets_all, 3);
  array_d arrays;
  array_d *p_arrays = &arrays;
  arrays.n = (pdata->count_of_vertexes) * 3;
  arrays.vertexesarray = (float *)malloc(arrays.n * sizeof(float));
  arrays.b = (pdata->count_of_facets_all) * 2;
  arrays.facetsarray = (int *)malloc(arrays.b * sizeof(int));
  arrays.fcount = 0;
  arrays.vcount = 0;
  ck_assert_int_eq(arrays.n, 9);
  ck_assert_int_eq(arrays.b, 6);
  char str1[D];
  FILE *sp = fopen("test.obj", "rb");
  while (fgets(str1, D, sp)) {
    parse2(p_arrays, str1);
  }
  fclose(sp);
  int f[6] = {0, 1, 1, 2, 0, 2};
  for (int j = 0; j < arrays.b; j++) {
    ck_assert_int_eq(arrays.facetsarray[j], f[j]);
  }
  int v[9] = {0, 1, -1, 1, 0, -1, 1, 1, 1};
  for (int j = 0; j < arrays.n; j++) {
    ck_assert_float_eq(arrays.vertexesarray[j], v[j]);
  }

  scale(p_arrays, 3);                          // scale
  float s[9] = {0, 3, -3, 3, 0, -3, 3, 3, 3};  // arr scale
  for (int k = 0; k < arrays.n; k++) {
    ck_assert_float_eq(arrays.vertexesarray[k], s[k]);
  }

  move_x(p_arrays, 3);
  float mx[9] = {3, 3, -3, 6, 0, -3, 6, 3, 3};  // arr move_x
  for (int k = 0; k < arrays.n; k++) {
    ck_assert_float_eq(arrays.vertexesarray[k], mx[k]);
  }

  move_y(p_arrays, 3);
  float my[9] = {3, 6, -3, 6, 3, -3, 6, 6, 3};  // arr move_x
  for (int k = 0; k < arrays.n; k++) {
    ck_assert_float_eq(arrays.vertexesarray[k], my[k]);
  }

  move_z(p_arrays, 1);
  float mz[9] = {3, 6, -2, 6, 3, -2, 6, 6, 4};  // arr move_x
  for (int k = 0; k < arrays.n; k++) {
    ck_assert_float_eq(arrays.vertexesarray[k], mz[k]);
  }

  rotation_by_ox(p_arrays, 1);
  float rx[9] = {3.000000, 4.924756, 3.968221,  6.000000, 3.303849,
                 1.443808, 6.000000, -0.124070, 7.210035};
  for (int k = 0; k < arrays.n; k++) {
    ck_assert_float_eq_tol(arrays.vertexesarray[k], rx[k], 1);
  }
  rotation_by_oy(p_arrays, 1);
  float ry[9] = {4.960050,  4.924756, -0.380374, 4.456737, 3.303849,
                 -4.268733, 9.308849, -0.124070, -1.153227};
  for (int k = 0; k < arrays.n; k++) {
    ck_assert_float_eq_tol(arrays.vertexesarray[k], ry[k], 1);
  }
  rotation_by_oz(p_arrays, 1);
  float rz[9] = {-1.464112, 6.834595, -0.380374, -0.372108, 5.535292,
                 -4.268733, 5.133994, 7.766091,  -1.153227};
  for (int k = 0; k < arrays.n; k++) {
    ck_assert_float_eq_tol(arrays.vertexesarray[k], rz[k], 1);
  }

  free(arrays.vertexesarray);
  free(arrays.facetsarray);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("s21_viewer");
  TCase *tcase_test = tcase_create("s21_viewer_test");
  SRunner *sr = srunner_create(s1);
  int nf;
  tcase_set_timeout(tcase_test, 90);
  suite_add_tcase(s1, tcase_test);

  tcase_add_test(tcase_test, test1);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf;
}
