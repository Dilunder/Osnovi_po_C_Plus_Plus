#ifndef LAB_1_F_CALL_H
#define LAB_1_F_CALL_H

#include <vector>
#include <string>

using namespace std;

void t5(double *);
void t5(double &);

void t8(double *);
void t8(double &);

typedef struct {
    double X1, Y1, X2, Y2, X3, Y3, X4, Y4;
} kv;

void t13_1(kv *first, double *, double *, double *);
void t13_1(kv *second ,double &, double &, double &);
void t13_2(kv *first, double *, double *);
void t13_2(kv *second, double &, double &);

void read_matrix(vector<vector<int>> *matrix);
void read_matrix(vector<vector<int>> &matrix);
void write_matrix(vector<vector<int>> *matrix);
void write_matrix(vector<vector<int>> &matrix);
void swap_lines(vector<vector<int>> *matrix, int *line1, int *line2);
void swap_lines(vector<vector<int>> &matrix, int &line1, int &line2);

#endif
