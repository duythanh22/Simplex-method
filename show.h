#pragma once
#include <iostream>
#include "var.h"

using namespace std;
// hien thi bai toan
void showOr() {
    cout << endl << "Bai toan: " << endl;
    if (min_max == 1){
    	cout << "Max z = ";
	}
    else{
    	cout << "Min z = ";
	}
	
    if (c[0]==1){
    	cout << "x[1]";
	}
    else if(c[0]==-1){
    	cout << "-x[1]";
	}
    else if(c[0]!=0){
    	cout << " " << c[0] << "x[1]";
	}
    for (size_t i=1; i<x_num; ++i) {
        if(c[i]==1){
        	cout << " + x[" << i+1 << "]";
		}
        else if (c[i]==-1){
        	cout << " - x[" << i+1 << "]";
		}
        else if (c[i]>0){
        	cout << " + " << c[i] << "x[" << i+1 << "]";
		}
        else if (c[i]<0){
        	cout << " - " << -c[i] << "x[" << i+1 << "]";
		}
    }

    //cout << a[0][1] << endl;

    cout << endl << "Cac rang buoc: " << endl;
    for (size_t i=0; i<st_num; ++i) {
        for (size_t j=0; j<x_num; ++j) {
            if (a[i][j] != 0) {
                if (a[i][j]==1 && j==0){
                	cout << " x[" << j+1 << "]";
				}
                else if (a[i][j]==1 && j!=0){
                	cout << " + x[" << j+1 << "]";
				}
                else if (a[i][j]==-1 && j==0){
                	cout << " -x[" << j+1 << "]";
				}
                else if (a[i][j]==-1 && j!=0){
                	cout << " - x[" << j+1 << "]";
				}
                else if (a[i][j]>0 && j==0){
                	cout << " " << a[i][j] << "x[" << j+1 << "]";
				}
                else if (a[i][j]>0 && j!=0){
                	cout << " + " << a[i][j] << "x[" << j+1 << "]";
				}
                else if (a[i][j]<0 && j==0){
                	cout << " " << a[i][j] << "x[" << j+1 << "]";
				}
                else if (a[i][j]<0 && j!=0){
                	cout << " - " << -a[i][j] << "x[" << j+1 << "]";
				}
            }
        }
        switch (eql[i]) {
        case 1:
            cout << " == " << b[i];
            break;
        case 2:
            cout << " >= " << b[i];
            break;
        case 3:
            cout << " <= " << b[i];
            break;
        }
        cout << endl;
    }
    cout << " x[1]~x[" << x_num << "] >= 0" << endl << endl;



}



void showPr() {
    if (section == 1) {   // bien doi bai toan lan 1
        cout << "min z = x[" << ar_id[0] << "]";
        for (size_t i=1; i<ar_num; ++i) {
            cout << " + x[" << ar_id[i] << "]";
        }
    } else if (section == 2) {   // bien doi bai toan lan 2
        cout << "min z = ";
        if (c[0]==1){
        	cout << "x[1]";
		}
        else if(c[0]==-1){
        	cout << "-x[1]";
		}
        else if(c[0]!=0){
        	cout << " " << c[0] << "x[1]";
		}
        for (size_t i=1; i<x_num; ++i) {
            if(c[i]==1){
            	cout << " + x[" << i+1 << "]";
			}
            else if (c[i]==-1){
            	cout << " - x[" << i+1 << "]";
			}
            else if (c[i]>0){
            	cout << " + " << c[i] << "x[" << i+1 << "]";
			}
            else if (c[i]<0){
            	cout << " - " << -c[i] << "x[" << i+1 << "]";
			}
        }
    } 
	else cout << "Loi bien doi." << endl;


    cout << endl << "Cac rang buoc: " << endl;
    for (size_t i=0; i<st_num; ++i) {
        int k = 0;
        for (size_t j=0; j<x_num; ++j) {
            if (a[i][j] != 0) {
                if (a[i][j]==1 && k==0){
                	cout << " x[" << j+1 << "]";
				}
                else if (a[i][j]==1 && k!=0){
                	cout << " + x[" << j+1 << "]";
				}
                else if (a[i][j]==-1 && k==0){
                	cout << " -x[" << j+1 << "]";
				}
                else if (a[i][j]==-1 && k!=0){
                	cout << " - x[" << j+1 << "]";
				}
                else if (a[i][j]>0 && k==0){
                	cout << " " << a[i][j] << "x[" << j+1 << "]";
				}
                else if (a[i][j]>0 && k!=0){
                	cout << " + " << a[i][j] << "x[" << j+1 << "]";
				}
                else if (a[i][j]<0 && k==0){
                	cout << " " << a[i][j] << "x[" << j+1 << "]";
				}
                else if (a[i][j]<0 && k!=0){
                	cout << " - " << -a[i][j] << "x[" << j+1 << "]";
				}
                k = 1;
            }
        }
        cout << " = " << b[i] << endl;
    }
    cout << " x[1]~x[" << x_num << "] >= 0" << endl << endl;;
}

