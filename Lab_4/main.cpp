#include <iostream>
#include <vector>
#include "vector.h"
#include "six_edges.h"
using namespace std;

int main(){
    vector<IFigue*> figure;
    int choice;
    while (true){
        cout << "Option: "<< endl;
        cout << "0) Finish "<< endl;
        cout << "1) Add Vector"<< endl;
        cout << "2) Add Hexagon"<< endl;
        cout << "3) Calculate total area of all figures"<< endl;
        cout << "4) Calculate total perimeter of all figures"<< endl;
        cout << "5) Calculate mass center of all figures"<< endl;
        cout << "6) Calculate total memory of all figures"<< endl;
        cout << "7) Draw all figures" << endl;
        cout << "8) Sort figures among themselves by weight" << endl;
        cout << "Choice: ";
        cin >> choice;
        if (choice == 0)
            break;
        else if(choice == 1){
            IFigue *f = new Vector();
            f->initFromDialog();
            figure.push_back(f);
        }
        else if(choice == 2){
            IFigue *f = new Hexagon();
            f->initFromDialog();
            figure.push_back(f);
        }
        else if(choice == 3){
            double area = 0;
            for(auto f:figure)
                area += f->square();
            cout << "Total area: " << area << endl;
        }
        else if(choice == 4){
            double p =0;
            for(auto f:figure)
                p += f->perimeter();
            cout << "Total perimeter: " << p << endl;
        }
        else if(choice == 5){
            CVector2D c;
            double mass_sum = 0;
            for(auto f:figure){
                c.x += f->position().x * f->mass();
                c.y += f->position().y * f->mass();
                mass_sum += f->mass();
            }
            c.x /= mass_sum;
            c.y /= mass_sum;
            cout << "Center: " << "(" << c.x << ", " << c.y << ")" << endl;
        }
        else if (choice == 6){
            int total_size = 0;
            for(auto f:figure)
                total_size += f->size();
            cout << "Size: " << total_size << endl;
        }
        else if(choice == 7)
            for (auto f:figure)
                f->draw();
        else if(choice == 8){
            for(int i = 0; i < figure.size() - 1; i++){
                for(int j = 0; j < figure.size() - i - 1; j++){
                    if (*figure[j + 1] < *figure[j]){
                        IFigue *temp = figure[j];
                        figure[j] = figure[j + 1];
                        figure[j + 1] = temp;
                        delete temp;
                    }
                }
            }
        }
        else cout << "Wrong choice!" << endl;
    }
    return 0;
}
