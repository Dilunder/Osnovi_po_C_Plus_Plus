#include <iostream>

#include "f_call.h"

int main() {

    cout << "Task 5" << endl;
    cout << "Vvedite 2 veshestvennih chisla" << endl;
    double x, y;
    cin >> x >> y;
    t5(&x);
    t5(y);
    cout << x << "  " << y << endl;

    cout << "Task 8" << endl;
    cout << "Vvedite 2 veshestvennih chisla" << endl;
    double w, z;
    cin >> w >> z;
    t8(&w);
    t8(z);
    cout << w << "  " << z << endl;

    cout << "Task 13" << endl;
    kv first;
    kv second;
    cout << "Vvedite koordinatu levoy nijney tochki 1 kvadrata x1 y1, 2 kvadrata x2 y2 i dlini storon 1 kvadrata i 2 kvadrata" << endl;
    double x1, y1, x2, y2, n1, n2, nx1, ny1, nx2, ny2;
    cin >> x1 >> y1 >> x2 >> y2 >> n1 >> n2;
    t13_1(&first, &x1, &y1, &n1);
    t13_1(&second, x2, y2, n2);
    cout << "koordinati vershin 1 kvadrata: " << "(" << first.X1 << ", " << first.Y1 << ") " << "(" << first.X2 << ", " << first.Y2 << ") " << "(" << first.X3 << ", " << first.Y3 << ") " << "(" << first.X4 << ", " << first.Y4 << ")" << endl;
    cout << "koordinati vershin 2 kvadrata: " << "(" << second.X1 << ", " << second.Y1 << ") " << "(" << second.X2 << ", " << second.Y2 << ") " << "(" << second.X3 << ", " << second.Y3 << ") " << "(" << second.X4 << ", " << second.Y4 << ")" << endl;
    cout << "Vvedite novuu koordinatu levoy nijney tochki 1 kvadrata nx1 ny1 i 2 kvadrata nx2 ny2" << endl;
    cin >> nx1 >> ny1 >> nx2 >> ny2;
    t13_2(&first, &nx1, &ny1);
    t13_2(&second, nx2, ny2);
    cout << "koordinati vershin 1 kvadrata: " << "(" << first.X1 << ", " << first.Y1 << ") " << "(" << first.X2 << ", " << first.Y2 << ") " << "(" << first.X3 << ", " << first.Y3 << ") " << "(" << first.X4 << ", " << first.Y4 << ")" << endl;
    cout << "koordinati vershin 2 kvadrata: " << "(" << second.X1 << ", " << second.Y1 << ") " << "(" << second.X2 << ", " << second.Y2 << ") " << "(" << second.X3 << ", " << second.Y3 << ") " << "(" << second.X4 << ", " << second.Y4 << ")" << endl;

    cout << "Task 16" << endl;
    int lines, columns, line1, line2;
    cout << "vvedite kolichestvo liniy i stolbcov" << endl;
    cin >> lines >> columns;
    if (lines <= 0 || columns <= 0){
        cerr << "Size of matrix must be positive";
        return 1;
    }
    vector<vector<int>> matrix(lines, vector<int>(columns));

    read_matrix(&matrix);
    write_matrix(&matrix);
    cin >> line1 >> line2;
    if (line1 < 0 || line1 >= lines || line2 < 0 || line2 >= lines){
        cerr << "Lines must be >= 0 and < " << lines << endl;
        return 1;
    }
    swap_lines(&matrix, &line1, &line2);
    write_matrix(&matrix);

    read_matrix(matrix);
    write_matrix(matrix);
    cin >> line1 >> line2;
    if (line1 < 0 || line1 >= lines || line2 < 0 || line2 >= lines){
        cerr << "Lines must be >= 0 and < " << lines << endl;
        return 1;
    }
    swap_lines(matrix, line1, line2);
    write_matrix(matrix);

    return 0;
}
