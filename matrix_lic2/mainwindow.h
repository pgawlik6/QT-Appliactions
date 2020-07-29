#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matrix.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionZakoncz_triggered();

    void on_actionAbout_QT_triggered();

    void on_actionAbout_triggered();

    void on_actionPaste_triggered();

    void on_actionExit_triggered();

    void on_actionZoom_window_triggered();

    void on_pushButton_clicked();

    void on_pushButton_released();

    void on_add_col_button_released();

    void on_pushButton_matrix2x2_released();

    void on_pushButton_matrix3x3_released();

    void on_pushButton_properties_clicked();

    void on_pushButton_properties_released();

    void on_pushButton_matrix2x2_2_released();

    void on_pushButton_matrix3x3_2_released();

    void on_pushButton_matrix_add_clicked();

    void on_pushButton_matrix_sub_clicked();

    void on_pushButton_matrix_multi_clicked();

    void on_pushButton_matrix2x2_op1_released();

    void on_pushButton_matrix3x3_op1_released();

    void on_pushButton_matrix_multi_scalar_clicked();

    void on_multi_button_clicked();

    void on_multi_button_released();

    void on_pushButton_matrix_transpose_released();

    void on_pushButton_matrix_minor_released();

    void on_minor_button_11_released();

    void on_minor_button_12_released();

    void on_minor_button_21_released();

    void on_minor_button_22_released();

    void on_minor_button_13_released();

    void on_minor_button_23_released();

    void on_minor_button_31_released();

    void on_minor_button_32_released();

    void on_minor_button_33_released();

    void on_pushButton_matrix_det_released();

    void on_pushButton_matrix_trace_released();

    void on_pushButton_matrix_algebraic_released();

    void on_algebraic_button_11_released();

    void on_algebraic_button_12_released();

    void on_algebraic_button_13_released();

    void on_algebraic_button_21_released();

    void on_algebraic_button_22_released();

    void on_algebraic_button_23_released();

    void on_algebraic_button_31_released();

    void on_algebraic_button_32_released();

    void on_algebraic_button_33_released();

    void on_pushButton_matrix_inverse_released();

private:
    Ui::MainWindow *ui;
    // Methods for operations on 1 matrix
    void visible_6(int);//for scalar multiply
    void visible_multi(int);
    void visible_multi_2(int);
    void visible_trans(int);
    void visible_minor(int);
    void visible_minor_2(int);
    void visible_algebraic(int);
    void set_cells_colors2();
    // Methods for operations on 2 matrices
    void visible_1();
    void visible_2(int);
    void visible_4(int); //for multiplication
    void visible_5(int); //labels which creating table in multiplication
    void set_cells_colors();
    void set_values_on_labels();
    void create_matrixAB_labels();
    void create_matrixAB_labels_2(); //for multiplication
    void get_values(Matrix<double>&,QTabWidget,int,int);

    //Methods for properties of matrix
    void visible_3(int);
    void inverse_matrix_visible(int);
};

#endif // MAINWINDOW_H
