#include <iostream>
using namespace std;

int main() {
    struct pt3D
    {
        double x;
        double y;
        double z;
    };

    pt3D A = {1.5, 2.3, 10.98};
    cout << "A = (" << A.x << ", " << A.y << ", " << A.z << ")" << endl;
    A.x = 5.7;
    cout << "A = (" << A.x << ", " << A.y << ", " << A.z << ")" << endl;

    pt3D* ptrB = &A;
    ptrB->y = 0.6;
    cout << ptrB << endl;
    cout << "*ptrB = (" <<ptrB->x << ", " << ptrB->y << ", " << ptrB->z << ")" << endl;
    cout << "A = (" << A.x << ", " << A.y << ", " << A.z << ")" << endl;

    ptrB = new pt3D {9.1, 3.5, 11.1};
    cout << ptrB << endl;
    cout << "*ptrB = (" <<ptrB->x << ", " << ptrB->y << ", " << ptrB->z << ")" << endl;
    cout << "A = (" << A.x << ", " << A.y << ", " << A.z << ")" << endl;
    delete ptrB;

    pt3D* arrayOfpt3D = new pt3D[5] {{2.5, 3.1, 6.2}};
    for(int i = 0; i < 5; i++)
    {
        cout << "(" << arrayOfpt3D[i].x ;
        cout << ", " << arrayOfpt3D[i].y ;
        cout << ", " << arrayOfpt3D[i].z << ")" << endl;
    }
    return 0;
}
