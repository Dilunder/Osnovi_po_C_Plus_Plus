#include "f_call.h"
#include <cmath>
#include <algorithm>
#include <iostream>

void t5(double *x){
    double celoe1;
    *x = modf(*x, &celoe1);
}

void t5(double &y){
    double celoe2;
    y = modf(y, &celoe2);
}

void t8(double *w){
    string Num1 = to_string(*w);
    string Num2 = "";
    for (int i = Num1.size() - 1; i >= 0; --i) {
        Num2 += Num1[i];
    }
    *w = stod(Num2);
}

void t8(double &z){
    //string Num2 = to_string(z);
    //reverse(Num2.begin(), Num2.end());
    //z = stod(Num2);
    string Num1 = to_string(z);
    string Num2 = "";
    for (int i = Num1.size() - 1; i >= 0; --i) {
        Num2 += Num1[i];
    }
    z = stod(Num2);
}

void t13_1(kv *first, double *x1, double *y1, double *n1){
    first->X1 = *x1;
    first->Y1 = *y1;
    first->X2 = *x1 + *n1;
    first->Y2 = *y1;
    first->X3 = *x1;
    first->Y3 = *y1 + *n1;
    first->X4 = *x1 + *n1;
    first->Y4 = *y1 + *n1;
}

void t13_1(kv *second, double &x2, double &y2, double &n2){
    second->X1 = x2;
    second->Y1 = y2;
    second->X2 = x2 + n2;
    second->Y2 = y2;
    second->X3 = x2;
    second->Y3 = y2 + n2;
    second->X4 = x2 + n2;
    second->Y4 = y2 + n2;
}

void t13_2(kv *first, double *nx1, double *ny1){
    int num1 = abs(first->X1 - first->X4), num2 = abs(first->Y1 - first->Y4);
    first->X1 = *nx1;
    first->Y1 = *ny1;
    first->X2 = *nx1 + num1;
    first->Y2 = *ny1;
    first->X3 = *nx1;
    first->Y3 = *ny1 + num2;
    first->X4 = *nx1 + num1;
    first->Y4 = *ny1 + num2;
}

void t13_2(kv *second, double &nx2, double &ny2) {
    int num1 = abs(second->X1 - second->X4), num2 = abs(second->Y1 - second->Y4);
    second->X1 = nx2;
    second->Y1 = ny2;
    second->X2 = nx2 + num1;
    second->Y2 = ny2;
    second->X3 = nx2;
    second->Y3 = ny2 + num2;
    second->X4 = nx2 + num1;
    second->Y4 = ny2 + num2;
}
//for task 16
void read_matrix(vector<vector<int>> *matrix){
    for (int i = 0; i < matrix->size(); ++i) {
        for (int j = 0; j < (*matrix)[i].size(); ++j) {
            cin >> (*matrix)[i][j];
        }
    }
}

void read_matrix(vector<vector<int>> &matrix){
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cin >> matrix[i][j];
        }
    }
}

void write_matrix(vector<vector<int>> *matrix){
    for (int i = 0; i < matrix->size(); ++i) {
        for (int j = 0; j < (*matrix)[i].size(); ++j) {
            cout << (*matrix)[i][j] << ' ';
        }
        cout << endl;
    }
}

void write_matrix(vector<vector<int>> &matrix){
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void swap_lines(vector<vector<int>> *matrix, int *line1, int *line2){
    for (int i = 0; i < (*matrix)[*line1].size(); ++i) {
        int num = (*matrix)[*line1][i];
        (*matrix)[*line1][i] = (*matrix)[*line2][i];
        (*matrix)[*line2][i] = num;
    }
}

void swap_lines(vector<vector<int>> &matrix, int &line1, int &line2){
    for (int i = 0; i < matrix[line1].size(); ++i) {
        int num = matrix[line1][i];
        matrix[line1][i] = matrix[line2][i];
        matrix[line2][i] = num;
    }
}