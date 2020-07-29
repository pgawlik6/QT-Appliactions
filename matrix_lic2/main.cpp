#include "mainwindow.h"
#include <QApplication>
#include "matrix.h"
#include <time.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Matrix Calculator");
    w.showMaximized();
    w.setFixedSize(900, 1024);
    w.show();
    Matrix<double> matrix(10,10) ;
            double table[10][10] = {{-4,6,3,2,1,-4,6,3,2,1}, {6,3,2,24,6,-4,6,3,5,8}, {-2,3,12,4,-3,-1,-3,-3,2,6}, {-12,-3,-3,2,6,-1,-3,-3,2,63}, {15,6,7,18,9,-1,-3,-13,21,6},
                                    {-7,6,8,12,1,-44,6,3,2,13}, {9,40,2,4,6,-4,6,3,2,1}, {5,23,12,4,-53,-1,-3,-3,12,6}, {-54,-5,-7,2,6,-1,-3,-3,23,65}, {5,6,7,3,4,-1,-3,-3,2,6}   };
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            matrix(i,j) = table[i][j];
        }
    }
    /*
    //Obliczanie czasu odwracania macierzy
    clock_t time_start = clock();
    std::cout << "\nMacierz odwrotna\n" << matrix.inverse() << std::endl;
    clock_t time_end = clock()-time_start;
    double timeInSeconds = time_end / (double) CLOCKS_PER_SEC;
    std::cout <<  "Czas odwracania macierzy:" << timeInSeconds << std::endl;

    //Obliczanie czasu obliczania wyznacznika
    time_start = clock();
    std::cout << "\nWyznacznik macierzy\n" << matrix.det()<< std::endl;
    time_end = clock()-time_start;
    timeInSeconds = time_end / (double) CLOCKS_PER_SEC;
    std::cout <<  "Czas obliczania wyznacznika:" << timeInSeconds << std::endl;

    //Obliczanie czasu obliczania macierzy dopełnień algebraicznych
    time_start = clock();
    std::cout << "\nMacierz dopelnien algebraicznych.:\n" << matrix.algebraicComplements() << std::endl;
    time_end = clock()-time_start;
    timeInSeconds = time_end / (double) CLOCKS_PER_SEC;
    std::cout <<  "Czas obliczania dopelnien algebraicznych:" << timeInSeconds << std::endl;
    */

    return a.exec();
}
