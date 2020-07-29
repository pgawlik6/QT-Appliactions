#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //-------------------------------------------------Operacje na 1 macierzy------------------------------------------------------
    ui->scalar->setValidator( new QDoubleValidator(-100.00000, 100.00000, 5, this) );
    ui->scalar->setAlignment(Qt::AlignCenter);
    ui->scalar->setPlaceholderText("Wprowadź wartość");

    //Wlasnosci table start
    ui->table_properties->setGeometry(210,380,431,431);
    ui->table_properties->setStyleSheet("QTableView {border:2px solid black;} QTableView:item {border:2px solid black;}");
    for(int i=0; i<ui->table_properties->rowCount();i++){
            ui->table_properties->item(i,0)->setTextAlignment(Qt::AlignCenter);
            ui->table_properties->item(i,0)->setTextColor(Qt::darkBlue);
    }

    //----------------------------------------------------Set invisible------------------------------------------------------------

    //-------------------------------------------------Operacje na 1 macierzy------------------------------------------------------
    ui->table_matrix_op1->setVisible(0);
    ui->label_12->setVisible(0);
    ui->label_13->setVisible(0);
    ui->label_14->setVisible(0);
    ui->size_label_3->setVisible(0);
    ui->line_7->setVisible(0);
    ui->line_8->setVisible(0);
    this->visible_multi(0);
    this->visible_trans(0);
    this->visible_minor(0);
    this->visible_minor_2(0);
    this->visible_algebraic(0);
    ui->pushButton_matrix_det->setVisible(0);
    ui->pushButton_matrix_minor->setVisible(0);
    ui->pushButton_matrix_multi_scalar->setVisible(0);
    ui->pushButton_matrix_inverse->setVisible(0);
    ui->pushButton_matrix_transpose->setVisible(0);
    ui->pushButton_matrix_trace->setVisible(0);
    ui->pushButton_matrix_algebraic->setVisible(0);
    this->visible_6(0);
    ui->minor_button_11->setVisible(0);
    ui->minor_button_12->setVisible(0);
    ui->minor_button_21->setVisible(0);
    ui->minor_button_22->setVisible(0);
    ui->minor_button_13->setVisible(0);
    ui->minor_button_23->setVisible(0);
    ui->minor_button_31->setVisible(0);
    ui->minor_button_32->setVisible(0);
    ui->minor_button_33->setVisible(0);


    //-------------------------------------------------Operacje na 2 macierzach----------------------------------------------------

    //Operations' buttons
    ui->pushButton_matrix_add->setVisible(0);
    ui->pushButton_matrix_sub->setVisible(0);
    ui->pushButton_matrix_multi->setVisible(0);

    //Labels
    QLabel* lab_visible[50] = {ui->lab_1, ui->lab_2, ui->lab_3, ui->lab_4,ui->lab_5,ui->lab_6,ui->lab_7,ui->lab_8,
                                 ui->lab_9, ui->lab_10, ui->lab_11, ui->lab_12, ui->lab_13, ui->lab_14, ui->lab_15,
                                 ui->a_00, ui->a_01, ui->a_02, ui->a_10, ui->a_11, ui->a_12, ui->a_20, ui->a_21, ui->a_22,
                                 ui->b_00, ui->b_01, ui->b_02, ui->b_10, ui->b_11, ui->b_12, ui->b_20, ui->b_21, ui->b_22,
                                 ui->sign_a00, ui->sign_a01, ui->sign_a02, ui->sign_a10, ui->sign_a11, ui->sign_a12, ui->sign_a20,
                              ui->sign_a21, ui->sign_a22, ui->label_19, ui->label_20, ui->label_21, ui->label_44, ui->label_45, ui->label_46, ui->label_47, ui->label_48};
    for (int i = 0; i < 50; i++){
        lab_visible[i]->setVisible(0);
    }
    //Lines which are creating table
    QFrame* lines[9] = {ui->line1, ui->line2, ui->line3, ui->line4, ui->line5, ui->line6, ui->line7, ui->line8, ui->line9};
    for (int i = 0; i < 9; i++){
        lines[i]->setVisible(0);
    }
    ui->matrix_A->setVisible(0);
    ui->matrix_B->setVisible(0);
    ui->matrix_A2->setVisible(0);
    ui->matrix_B2->setVisible(0);
    ui->matrix_AB->setVisible(0);

    this->visible_4(0);
    this->visible_5(0);

    //-------------------------------------------------Wlasnosci macierzy-----------------------------------------------------------
    ui->pushButton_properties->setVisible(0);
    ui->table_matrix->setVisible(0);
    ui->label_4->setVisible(0);
    ui->label_5->setVisible(0);
    ui->label_6->setVisible(0);
    ui->label_35->setVisible(0);
    ui->size_label->setVisible(0);
    this->visible_3(0);
    this->inverse_matrix_visible(0);

    //-------------------------------------------------------------------------------------------------------------------------------
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionZakoncz_triggered()
{

}

void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt(this,"Matrix Calculator - O Qt");
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,"Matrix Calculator - O programie","   Matrix Calculator jest to aplikacja pomagająca w nauce działań na macierzach o wymiarach 2x2 oraz 3x3."
                                                              "\n\nOperacje na jednej macierzy jakie wykonuje aplikacja:\n- obliczanie wyznacznika,\n-obliczanie minorów,\n-obliczanie śladu macierzy,"
                                                              "\n-wzynaczanie macierzy transponowanej,\n-wyznaczanie macierzy odwrotnej,\n-obliczanie dopełnień algebraicznych,"
                                                              "\n-mnożenie macierzy przez skalar."
                                                              "\n\nOperacje na dwóch macierzach jakie wykonuje aplikacja:"
                                                              "\n-mnożenie macierzy,\n-sumowanie macierzy,\n-odejmowanie macierzy."
                                                              "\n\n   Aplikacja posiada również funkcjonalność taką, jak sprawdzenie wybranych właśności podanej przez użytkownika macierzy."
                                                              "\n\n\n \t\t\t  WAŻNE!\n Aby obliczyć minor, należy wiedzieć, jak oblicza się wyznacznik."
                                                              "\n Aby obliczyć dopełnienie algebraiczne należy wiedzieć jak oblicza się minor i wyznacznik."
                                                              "\n Aby obliczyć macierz odwrotną należy wiedzieć jak oblicza się minor, wyznacznik, dopełnienia algebraiczne oraz jak mnoży się "
                                                              "macierz przez skalar");
}

void MainWindow::on_actionPaste_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{
    QMessageBox::StandardButton quit = QMessageBox::question(this,"Zakończ program","Czy naprawdę chcesz wyłączyć program?",QMessageBox::Yes | QMessageBox::No);
    if(quit==QMessageBox::Yes){
        QApplication::quit();
    }
}
void MainWindow::on_pushButton_released()
{

}

//Matrices
//properties
Matrix<double> matrix(2,2);
//2 matrices operations
Matrix<double> matrixA(2,2);
Matrix<double> matrixB(2,2);
//1 matrix operations
Matrix<double> matrix_op1(2,2);


//--------------------------------------------------------------------------------------------------------------------------------------
//<-------------------------------------------------------- Wlasnosci macierzy -------------------------------------------------------->
//--------------------------------------------------------------------------------------------------------------------------------------

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Methods>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void MainWindow::visible_3(int i){
    QTableWidget* tables[2] = {ui->table_properties, ui->table_transpose};
    for (int k = 0; k < 2; k++) {
        tables[k]->setVisible(i);
    }

    QLabel* labels[7] = {ui->label_24, ui->label_25, ui->label_26, ui->label_27, ui->label_28, ui->label_32, ui->label_34};
    for (int k = 0; k < 7; k++) {
        labels[k]->setVisible(i);
    }

    QFrame* lines[3]= {ui->line, ui->line_2, ui->line_3};
    for (int k = 0; k < 3; k++) {
        lines[k]->setVisible(i);
    }
}

void MainWindow::inverse_matrix_visible(int i){
    ui->table_inverse->setVisible(i);
    QLabel* labels[4]= {ui->label_29, ui->label_30, ui->label_31, ui->label_33};
    for (int k = 0; k < 4; k++) {
        labels[k]->setVisible(i);
    }
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Buttons>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//Matrix 2x2 button
void MainWindow::on_pushButton_matrix2x2_released()
{
    ui->table_matrix->setColumnCount(2);
    ui->table_matrix->setRowCount(2);
    ui->table_inverse->setRowCount(2);
    ui->table_inverse->setColumnCount(2);
    ui->table_transpose->setColumnCount(2);
    ui->table_transpose->setRowCount(2);
    for(int i=0; i<ui->table_matrix->rowCount();i++){
        for(int j=0; j<(ui->table_matrix->columnCount());j++){
            ui->table_matrix->setItem(i, j, new QTableWidgetItem("0"));
            ui->table_matrix->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->table_transpose->setItem(i, j, new QTableWidgetItem("0"));
            ui->table_transpose->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->table_inverse->setItem(i, j, new QTableWidgetItem(""));
            ui->table_inverse->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
    ui->table_matrix->setStyleSheet("QTableView {selection-background-color: green;border-style:none;}");
    ui->table_matrix->setGeometry(360,160,122,82);
    ui->table_transpose->setGeometry(190,670,122,82);
    ui->table_inverse->setGeometry(590,670,122,82);
    ui->size_label->setText("2x2");
    ui->pushButton_properties->setVisible(1);
    ui->table_matrix->setVisible(1);
    ui->label_4->setVisible(1);
    ui->label_5->setVisible(1);
    ui->label_6->setVisible(1);
    ui->size_label->setVisible(1);
    this->inverse_matrix_visible(0);
    ui->label_35->setVisible(0);
    this->visible_3(0);
}

//Matrix 3x3 button
void MainWindow::on_pushButton_matrix3x3_released()
{
    ui->table_matrix->setColumnCount(3);
    ui->table_matrix->setRowCount(3);
    ui->table_inverse->setRowCount(3);
    ui->table_inverse->setColumnCount(3);
    ui->table_transpose->setColumnCount(3);
    ui->table_transpose->setRowCount(3);
    for(int i=0; i<ui->table_matrix->rowCount();i++){
        for(int j=0; j<(ui->table_matrix->columnCount());j++){
            ui->table_matrix->setItem(i, j, new QTableWidgetItem("0"));
            ui->table_matrix->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->table_transpose->setItem(i, j, new QTableWidgetItem("0"));
            ui->table_transpose->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->table_inverse->setItem(i, j, new QTableWidgetItem(""));
            ui->table_inverse->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
    ui->table_matrix->setStyleSheet("QTableView {selection-background-color: green;border-style:none;}");
    ui->table_matrix->setGeometry(331,141,182,122);
    ui->table_transpose->setGeometry(160,650,182,122);
    ui->table_inverse->setGeometry(560,650,182,122);
    ui->size_label->setText("3x3");
    ui->pushButton_properties->setVisible(1);
    ui->table_matrix->setVisible(1);
    ui->label_4->setVisible(1);
    ui->label_5->setVisible(1);
    ui->label_6->setVisible(1);
    ui->size_label->setVisible(1);
    this->inverse_matrix_visible(0);
    ui->label_35->setVisible(0);
    this->visible_3(0);
}

void MainWindow::on_pushButton_properties_clicked()
{
    //Set size of matrices
    matrix.setH(ui->table_matrix->rowCount());
    matrix.setW(ui->table_matrix->columnCount());

    //Set geometry and cell values of properties table
    ui->table_properties->setGeometry(210,380,431,431);

    // Get the values from the table
    for(int i = 0; i < ui->table_matrix->rowCount(); i++)
    {
        for(int j = 0; j < ui->table_matrix->columnCount(); j++)
        {
            QString s = ui->table_matrix->item(i, j)->text();
            ui->table_matrix->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);

                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix->item(i, j)->setBackgroundColor(Qt::red);

                }
            }
            double value = s.toDouble();
            matrix(i, j)=value;
        }
    }

    //Determinant
    double deter = matrix.det();
    QString det = QString::number(deter);
    ui->table_properties->setItem(0,1,new QTableWidgetItem("det(A) = " + det));
    ui->table_properties->item(0,1)->setTextAlignment(Qt::AlignCenter);

    //Trace
    double trace = matrix.tr();
    QString tr = QString::number(trace);
    ui->table_properties->setItem(1,1,new QTableWidgetItem("tr(A) = " + tr));
    ui->table_properties->item(1,1)->setTextAlignment(Qt::AlignCenter);


    //is Diagonal Matrix
    if(matrix.isDiagonalMatrix()){
        ui->table_properties->setItem(2,1,new QTableWidgetItem("Tak"));
    }else {
        ui->table_properties->setItem(2,1,new QTableWidgetItem("Nie"));
    }
    ui->table_properties->item(2,1)->setTextAlignment(Qt::AlignCenter);

    //is Symetric Matrix
    if(matrix.isSymmetricMatrix()){
        ui->table_properties->setItem(3,1,new QTableWidgetItem("Tak"));
    }else {
        ui->table_properties->setItem(3,1,new QTableWidgetItem("Nie"));
    }
    ui->table_properties->item(3,1)->setTextAlignment(Qt::AlignCenter);

    //is Triangular
    if(matrix.isTriangularMatrix()){
        if(matrix.isUpperTriangularMatrix()){
            ui->table_properties->setItem(4,1,new QTableWidgetItem("Tak, macierz trójkatna dolna"));
        }
        if(matrix.isLowerTriangularMatrix()){
            ui->table_properties->setItem(4,1,new QTableWidgetItem("Tak, macierz trójkatna górna"));
        }
        if(matrix.isLowerTriangularMatrix() && matrix.isUpperTriangularMatrix()){
            ui->table_properties->setItem(4,1,new QTableWidgetItem("Nie"));
        }
    }else {
        ui->table_properties->setItem(4,1,new QTableWidgetItem("Nie"));
    }
    ui->table_properties->item(4,1)->setTextAlignment(Qt::AlignCenter);

    //is Singular Matrix
    if(matrix.isSingularMatrix()){
        ui->table_properties->setItem(5,1,new QTableWidgetItem("Tak"));
    }else {
        ui->table_properties->setItem(5,1,new QTableWidgetItem("Nie"));
    }
    ui->table_properties->item(5,1)->setTextAlignment(Qt::AlignCenter);
    ui->table_properties->item(5,1)->setBackgroundColor(QColor(212, 192, 190));

    //is Square Matrix
    if(matrix.isSquareMatrix()){
        ui->table_properties->setItem(6,1,new QTableWidgetItem("Tak"));
    }else {
        ui->table_properties->setItem(6,1,new QTableWidgetItem("Nie"));
    }
    ui->table_properties->item(6,1)->setTextAlignment(Qt::AlignCenter);

    //Transpose Matrix
    for(int i = 0; i < ui->table_transpose->rowCount(); i++)
    {
        for(int j = 0; j < ui->table_transpose->columnCount(); j++)
        {
            double value = matrix.transpose()(i,j);
            QString val = QString::number(value);
            ui->table_transpose->setItem(i,j,new QTableWidgetItem(val));
            ui->table_transpose->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    //Inverse Matrix
    if(matrix.det()==0){
        this->inverse_matrix_visible(0);
        QMessageBox::critical(this,"Wystąpił Błąd","Wyznacznik podanej macierzy A ma wartość 0, zatem macierz odwrotna nie istnieje");
        ui->label_35->setVisible(1);
    }else{
        ui->label_35->setVisible(0);
        this->inverse_matrix_visible(1);
            for(int i = 0; i < ui->table_inverse->rowCount(); i++)
            {
                for(int j = 0; j < ui->table_inverse->columnCount(); j++)
                {
                    QString val = QString::number(matrix.inverse()(i,j));
                    ui->table_inverse->setItem(i,j,new QTableWidgetItem(val));
                    ui->table_inverse->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }

    }
    ui->table_properties->setFocusPolicy(Qt::NoFocus);
    ui->table_properties->setSelectionMode(QAbstractItemView::NoSelection);
    ui->table_inverse->setFocusPolicy(Qt::NoFocus);
    ui->table_inverse->setSelectionMode(QAbstractItemView::NoSelection);

    ui->table_transpose->setFocusPolicy(Qt::NoFocus);
    ui->table_transpose->setSelectionMode(QAbstractItemView::NoSelection);

    this->visible_3(1);
}

void MainWindow::on_pushButton_properties_released()
{

}

//--------------------------------------------------------------------------------------------------------------------------------------
//<-------------------------------------------------------- Operacje na 2 macierzach -------------------------------------------------------->
//--------------------------------------------------------------------------------------------------------------------------------------

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Methods>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//Setting visible buttons and labels after chosen matrix size
void MainWindow::visible_1(){
    ui->pushButton_matrix_add->setVisible(1);
    ui->pushButton_matrix_sub->setVisible(1);
    ui->pushButton_matrix_multi->setVisible(1);
    ui->matrix_A->setVisible(1);
    ui->matrix_B->setVisible(1);
    QLabel* lab_visible[10]={ui->label_19, ui->label_20, ui->label_21, ui->label_44, ui->label_45, ui->label_46, ui->label_47, ui->label_48, ui->size_label_A,
                           ui->size_label_B};
    for (int i = 0; i < 10; i++){
        lab_visible[i]->setVisible(1);
    }
}

//Setting visible tables, labels and lines after chosen operation
void MainWindow::visible_2(int v){
    QLabel* lab_visible[45] = {ui->lab_1, ui->lab_2, ui->lab_3, ui->lab_4,ui->lab_5,ui->lab_6,ui->lab_7,ui->lab_8,
                                 ui->lab_9, ui->lab_10, ui->lab_11, ui->lab_12, ui->lab_13, ui->lab_14, ui->lab_15,
                                 ui->a_00, ui->a_01, ui->a_02, ui->a_10, ui->a_11, ui->a_12, ui->a_20, ui->a_21, ui->a_22,
                                 ui->b_00, ui->b_01, ui->b_02, ui->b_10, ui->b_11, ui->b_12, ui->b_20, ui->b_21, ui->b_22,
                                 ui->sign_a00, ui->sign_a01, ui->sign_a02, ui->sign_a10, ui->sign_a11, ui->sign_a12, ui->sign_a20,
                              ui->sign_a21, ui->sign_a22, ui->matrix_sign,  ui->matrix_sign_2, ui->matrix_sign_3};
    for (int i = 0; i < 45; i++){
        lab_visible[i]->setVisible(v);
    }
    //Lines which are creating table
    QFrame* lines[9] = {ui->line1, ui->line2, ui->line3, ui->line4, ui->line5, ui->line6, ui->line7, ui->line8, ui->line9};
    for (int i = 0; i < 9; i++){
        lines[i]->setVisible(v);
    }
    ui->matrix_A2->setVisible(v);
    ui->matrix_B2->setVisible(v);
    ui->matrix_AB->setVisible(v);
}

void MainWindow::visible_4(int v){
    QLabel* lab_visible[33] = {ui->lab_31, ui->lab_32, ui->matrix_sign_7,
                                 ui->a_00_1, ui->a_01_1, ui->a_02, ui->a_10_1, ui->a_11_1, ui->a_12, ui->a_20, ui->a_21, ui->a_22,
                                 ui->b_00_0, ui->b_01_1, ui->b_02, ui->b_10_0, ui->b_11_1, ui->b_10, ui->b_20, ui->b_21, ui->b_22,
                                 ui->sign_a01_0, ui->sign_a01_1, ui->sign_a01_2, ui->sign_a01_3, ui->sign_a11_2, ui->sign_a11_3, ui->sign_a11_4,
                              ui->sign_a11_5, ui->sign_a22, ui->matrix_sign,  ui->matrix_sign_2, ui->matrix_sign_3};
    for (int i = 0; i < 33; i++){
        lab_visible[i]->setVisible(v);
    }
}
void MainWindow::visible_5(int v){

            QLabel* lab_visible[57] = {ui->sign_a01_9, ui->sign_a01_15,ui->b_20_1, ui->a_20_1, ui->sign_a20_3, ui->b_00_2, ui->sign_a01_20, ui->a_21_1,
                                       ui->sign_a21_3, ui->b_10_2, ui->sign_a01_19, ui->a_22_1, ui->sign_a22_3, ui->sign_a01_11, ui->a_02_3, ui->sign_a11_14,
                                       ui->sign_a01_14, ui->a_12_1, ui->sign_a12_3, ui->b_21_1, ui->a_20_2, ui->sign_a20_4, ui->b_01_2, ui->sign_a01_21,
                                       ui->a_21_2, ui->sign_a21_4, ui->b_11_2, ui->sign_a01_18, ui->a_22_2, ui->sign_a21_5, ui->b_21_2, ui->a_00_3, ui->sign_a11_11,
                                       ui->sign_a01_4, ui->a_01_3, ui->sign_a11_12, ui->sign_a01_10, ui->a_02_2, ui->sign_a11_13, ui->a_10_2, ui->sign_a10_3, ui->b_02_1,
                                       ui->sign_a01_12, ui->a_11_2, ui->sign_a11_15, ui->b_12_1, ui->sign_a01_13, ui->a_12_2, ui->sign_a12_4, ui->b_22_1, ui->b_02_1,
                                       ui->sign_a01_16, ui->b_12_2, ui->sign_a01_17, ui->b_22_2, ui->b_02_2, ui->b_20_2};
            for (int i = 0; i < 57; i++){
                lab_visible[i]->setVisible(v);
            }
}
void MainWindow::set_cells_colors(){
    //Set matrix colors
    if(ui->matrix_A->rowCount() == 2){
        //Matrix A cells colors
        ui->matrix_A2->item(0,0)->setBackgroundColor(Qt::darkBlue);
        ui->matrix_A2->item(0,1)->setBackgroundColor(Qt::darkRed);
        ui->matrix_A2->item(1,0)->setBackgroundColor(QColor(0, 100, 0));
        ui->matrix_A2->item(1,1)->setBackgroundColor(QColor(151, 117, 0));

        //Text Color
        ui->matrix_A2->item(0,0)->setTextColor(Qt::white);
        ui->matrix_A2->item(0,1)->setTextColor(Qt::white);
        ui->matrix_A2->item(1,0)->setTextColor(Qt::white);
        ui->matrix_A2->item(1,1)->setTextColor(Qt::white);

        //Matrix B cells colors
        ui->matrix_B2->item(0,0)->setBackgroundColor(QColor(153, 194, 255));
        ui->matrix_B2->item(0,1)->setBackgroundColor(QColor(255, 153, 153));
        ui->matrix_B2->item(1,0)->setBackgroundColor(QColor(144, 238, 144));
        ui->matrix_B2->item(1,1)->setBackgroundColor(QColor(255, 204, 128));
    }
    if(ui->matrix_A->rowCount() == 3){
        //Matrix A cells colors
        ui->matrix_A2->item(0,0)->setBackgroundColor(Qt::darkBlue);
        ui->matrix_A2->item(0,1)->setBackgroundColor(Qt::darkRed);
        ui->matrix_A2->item(0,2)->setBackgroundColor(Qt::darkMagenta);
        ui->matrix_A2->item(1,0)->setBackgroundColor(QColor(0, 100, 0));
        ui->matrix_A2->item(1,1)->setBackgroundColor(QColor(151, 117, 0));
        ui->matrix_A2->item(1,2)->setBackgroundColor(Qt::darkYellow);
        ui->matrix_A2->item(2,0)->setBackgroundColor(Qt::darkGray);
        ui->matrix_A2->item(2,1)->setBackgroundColor(QColor(0, 102, 102));
        ui->matrix_A2->item(2,2)->setBackgroundColor(Qt::black);
        //Text Color
        ui->matrix_A2->item(0,0)->setTextColor(Qt::white);
        ui->matrix_A2->item(0,1)->setTextColor(Qt::white);
        ui->matrix_A2->item(0,2)->setTextColor(Qt::white);
        ui->matrix_A2->item(1,0)->setTextColor(Qt::white);
        ui->matrix_A2->item(1,1)->setTextColor(Qt::white);
        ui->matrix_A2->item(1,2)->setTextColor(Qt::white);
        ui->matrix_A2->item(2,0)->setTextColor(Qt::white);
        ui->matrix_A2->item(2,1)->setTextColor(Qt::white);
        ui->matrix_A2->item(2,2)->setTextColor(Qt::white);
        //Matrix B cells colors
        ui->matrix_B2->item(0,0)->setBackgroundColor(QColor(153, 194, 255));
        ui->matrix_B2->item(0,1)->setBackgroundColor(QColor(255, 153, 153));
        ui->matrix_B2->item(0,2)->setBackgroundColor(QColor(255, 153, 255));
        ui->matrix_B2->item(1,0)->setBackgroundColor(QColor(144, 238, 144));
        ui->matrix_B2->item(1,1)->setBackgroundColor(QColor(255, 204, 128));
        ui->matrix_B2->item(1,2)->setBackgroundColor(QColor(255, 255, 128));
        ui->matrix_B2->item(2,0)->setBackgroundColor(QColor(211, 211, 211));
        ui->matrix_B2->item(2,1)->setBackgroundColor(QColor(128, 255, 255));
        ui->matrix_B2->item(2,2)->setBackgroundColor(Qt::white);
    }
}

void MainWindow::set_values_on_labels(){
    //Set values on labels
    //for matrixA_3x3
    QLabel* lab_A3[3][3]={{ui->a_00, ui->a_01, ui->a_02},
                            {ui->a_10, ui->a_11, ui->a_12},
                            {ui->a_20, ui->a_21, ui->a_22}};
    QLabel* lab_A3_2[3][3]={{ui->a_00_1, ui->a_01_1, ui->a_02_2},
                            {ui->a_10_1, ui->a_11_1, ui->a_12_1},
                            {ui->a_20_1, ui->a_21_1, ui->a_22_1}};
    QLabel* lab_A3_3[3][3]={{ui->a_00_3, ui->a_01_3, ui->a_02_3},
                            {ui->a_10_2, ui->a_11_2, ui->a_12_2},
                            {ui->a_20_2, ui->a_21_2, ui->a_22_2}};
    //for matrixA_2x2
    QLabel* lab_A2[2][2]={{ui->a_00, ui->a_01},
                            {ui->a_10, ui->a_11}};
    QLabel* lab_A2_2[2][2]={{ui->a_00_1, ui->a_01_1},
                            {ui->a_10_1, ui->a_11_1}};
    //for matrixB_3x3
    QLabel* lab_B3[3][3]={{ui->b_00, ui->b_01, ui->b_02},
                            {ui->b_10, ui->b_11, ui->b_12},
                            {ui->b_20, ui->b_21, ui->b_22}};
    QLabel* lab_B3_2[3][3]={{ui->b_00_0, ui->b_01_1, ui->b_02_1},
                            {ui->b_10_0, ui->b_11_1, ui->b_12_1},
                            {ui->b_20_1, ui->b_21_1, ui->b_22_1}};
    QLabel* lab_B3_3[3][3]={{ui->b_00_2, ui->b_01_2, ui->b_02_2},
                            {ui->b_10_2, ui->b_11_2, ui->b_12_2},
                            {ui->b_20_2, ui->b_21_2, ui->b_22_2}};
    //for matrixB_2x2
    QLabel* lab_B2[2][2]={{ui->b_00, ui->b_01},
                            {ui->b_10, ui->b_11}};
    QLabel* lab_B2_2[2][2]={{ui->b_00_0, ui->b_01_1},
                            {ui->b_10_0, ui->b_11_1}};

    //Set value on labels (3x3)
    if(ui->matrix_A->rowCount()==3){
        for (int i = 0;i < ui->matrix_A->rowCount();i++) {
            for (int j = 0;j < ui->matrix_A->columnCount();j++) {
              lab_A3[i][j]->setText(ui->matrix_A->item(i,j)->text());
              lab_B3[i][j]->setText(ui->matrix_B->item(i,j)->text());
              lab_A3_2[i][j]->setText(ui->matrix_A->item(i,j)->text());
              lab_B3_2[i][j]->setText(ui->matrix_B->item(i,j)->text());
              lab_A3_3[i][j]->setText(ui->matrix_A->item(i,j)->text());
              lab_B3_3[i][j]->setText(ui->matrix_B->item(i,j)->text());
            }
        }
    }

    //Set value on labels (2x2)
    if(ui->matrix_A->rowCount()==2){
        for (int i = 0;i < ui->matrix_A->rowCount();i++) {
            for (int j = 0;j < ui->matrix_A->columnCount();j++) {
              lab_A2[i][j]->setText(ui->matrix_A->item(i,j)->text());
              lab_A2_2[i][j]->setText(ui->matrix_A->item(i,j)->text());
              lab_B2[i][j]->setText(ui->matrix_B->item(i,j)->text());
              lab_B2_2[i][j]->setText(ui->matrix_B->item(i,j)->text());
            }
        }
    }
}

//For substract and add
void MainWindow::create_matrixAB_labels(){
    //for 2x2 matrix
    if(ui->matrix_A->rowCount()==2){

        //a lables
        ui->a_00->setGeometry(269,620,40,25);
        ui->a_01->setGeometry(369,620,40,25);
        ui->a_10->setGeometry(269,660,40,25);
        ui->a_11->setGeometry(369,660,40,25);

        //b labels
        ui->b_00->setGeometry(320,620,40,25);
        ui->b_01->setGeometry(420,620,40,25);
        ui->b_10->setGeometry(320,660,40,25);
        ui->b_11->setGeometry(420,660,40,25);

        //lines
        ui->line1->setGeometry(263,603,202,20);
        ui->line2->setGeometry(263,683,201,20);
        ui->line3->setGeometry(254,613,20,81);
        ui->line4->setGeometry(454,613,20,81);
        ui->line5->setGeometry(354,613,20,81);
        ui->line7->setGeometry(263,643,201,20);

        //signs
        ui->sign_a00->setGeometry(307,612,16,41);
        ui->sign_a01->setGeometry(407,612,16,41);
        ui->sign_a10->setGeometry(307,652,16,41);
        ui->sign_a11->setGeometry(407,652,16,41);

        //labels
        ui->lab_11->setGeometry(184,573,40,161);
        ui->lab_12->setGeometry(494,573,51,161);
        ui->lab_13->setGeometry(565,633,16,41);
        ui->lab_14->setGeometry(600,588,40,128);
        ui->lab_15->setGeometry(800,588,40,128);
        QFont f("Arial", 100, QFont::StyleNormal);
        ui->lab_11->setFont(f);
        ui->lab_12->setFont(f);

        //Matrix_AB
        ui->matrix_AB->setGeometry(660,621,122,62);

        //set rest invisible
        QLabel* tab_labels[15]={ui->a_02, ui->a_12, ui->a_20, ui->a_21, ui->a_22, ui->b_02, ui->b_12, ui->b_20, ui->b_21, ui->b_22,
                              ui->sign_a02, ui->sign_a12, ui->sign_a20, ui->sign_a21, ui->sign_a22};
        for (int i = 0;i < 15;i++) {
            tab_labels[i]->setVisible(0);
        }
        ui->line6->setVisible(0);
        ui->line8->setVisible(0);
    }
    //for 3x3 matrix
    if(ui->matrix_A->rowCount()==3){

        ui->matrix_AB->setGeometry(630,606,182,92);

        //a lables
        ui->a_00->setGeometry(220,600,40,25);
        ui->a_01->setGeometry(320,600,40,25);
        ui->a_02->setGeometry(420,600,40,25);
        ui->a_10->setGeometry(220,640,40,25);
        ui->a_11->setGeometry(320,640,40,25);
        ui->a_12->setGeometry(420,640,40,25);
        ui->a_20->setGeometry(220,680,40,25);
        ui->a_21->setGeometry(320,680,40,25);
        ui->a_22->setGeometry(420,680,40,25);

        //b labels
        ui->b_00->setGeometry(271,600,40,25);
        ui->b_01->setGeometry(371,600,40,25);
        ui->b_02->setGeometry(471,600,40,25);
        ui->b_10->setGeometry(271,640,40,25);
        ui->b_11->setGeometry(371,640,40,25);
        ui->b_12->setGeometry(471,640,40,25);
        ui->b_20->setGeometry(271,680,40,25);
        ui->b_21->setGeometry(371,680,40,25);
        ui->b_22->setGeometry(471,680,40,25);

        //lines
        ui->line1->setGeometry(214,583,301,20);
        ui->line2->setGeometry(214,703,302,20);
        ui->line3->setGeometry(205,592,20,120);
        ui->line4->setGeometry(505,592,20,120);
        ui->line5->setGeometry(305,593,20,120);
        ui->line6->setGeometry(405,593,20,120);
        ui->line7->setGeometry(214,623,301,20);
        ui->line8->setGeometry(214,663,301,20);

        //signs
        ui->sign_a00->setGeometry(258,592,16,41);
        ui->sign_a01->setGeometry(358,592,16,41);
        ui->sign_a02->setGeometry(458,592,16,41);
        ui->sign_a10->setGeometry(258,632,16,41);
        ui->sign_a11->setGeometry(358,632,16,41);
        ui->sign_a12->setGeometry(458,632,16,41);
        ui->sign_a20->setGeometry(258,672,16,41);
        ui->sign_a21->setGeometry(358,672,16,41);
        ui->sign_a22->setGeometry(458,672,16,41);

        //labels
        ui->lab_11->setGeometry(184,573,40,161);
        ui->lab_12->setGeometry(494,573,51,161);
        ui->lab_13->setGeometry(565,633,16,41);
        ui->lab_14->setGeometry(600,588,40,128);
        ui->lab_15->setGeometry(800,588,40,128);
        QFont f("Arial", 100, QFont::StyleNormal);
        ui->lab_11->setFont(f);
        ui->lab_12->setFont(f);

        //set invisible labels from multiplication 3x3
        this->visible_5(0);
        //set rest visible
        QLabel* tab_labels[15]={ui->a_02, ui->a_12, ui->a_20, ui->a_21, ui->a_22, ui->b_02, ui->b_12, ui->b_20, ui->b_21, ui->b_22,
                              ui->sign_a02, ui->sign_a12, ui->sign_a20, ui->sign_a21, ui->sign_a22};
        for (int i = 0;i < 15;i++) {
            tab_labels[i]->setVisible(1);
        }
        ui->line6->setVisible(1);
        ui->line8->setVisible(1);
    }

}

//For multiplication
void MainWindow::create_matrixAB_labels_2(){
    //for 2x2 matrix
    if(ui->matrix_A->rowCount()==2){

        //a lables
        ui->a_00->setGeometry(220,620,40,25);
        ui->a_01->setGeometry(324,620,40,25);
        ui->a_10->setGeometry(220,660,40,25);
        ui->a_11->setGeometry(324,660,40,25);

        ui->a_00_1->setGeometry(425,620,40,25);
        ui->a_01_1->setGeometry(529,620,40,25);
        ui->a_10_1->setGeometry(425,660,40,25);
        ui->a_11_1->setGeometry(529,660,40,25);

        //b labels
        ui->b_00->setGeometry(271,620,40,25);
        ui->b_01->setGeometry(476,620,40,25);
        ui->b_10->setGeometry(375,620,40,25);
        ui->b_11->setGeometry(581,620,40,25);

        ui->b_00_0->setGeometry(271,660,40,25);
        ui->b_01_1->setGeometry(476,660,40,25);
        ui->b_10_0->setGeometry(375,660,40,25);
        ui->b_11_1->setGeometry(581,660,40,25);

        //lines
        ui->line1->setGeometry(214,603,411,20);
        ui->line2->setGeometry(214,683,411,20);
        ui->line3->setGeometry(205,612,20,81);
        ui->line4->setGeometry(615,612,20,82);
        ui->line5->setGeometry(410,612,20,80);
        ui->line7->setGeometry(214,643,411,20);

        //signs
        ui->sign_a00->setGeometry(258,612,16,41);
        ui->sign_a01->setGeometry(362,612,16,41);
        ui->sign_a10->setGeometry(258,652,16,41);
        ui->sign_a11->setGeometry(362,652,16,41);

        ui->sign_a01_0->setGeometry(310,612,16,41);
        ui->sign_a01_1->setGeometry(515,612,16,41);
        ui->sign_a01_2->setGeometry(310,652,16,41);
        ui->sign_a01_3->setGeometry(515,652,16,41);

        ui->sign_a11_2->setGeometry(463,612,16,41);
        ui->sign_a11_3->setGeometry(568,612,16,41);
        ui->sign_a11_4->setGeometry(463,652,16,41);
        ui->sign_a11_5->setGeometry(568,652,16,41);

        ui->matrix_sign_7->setGeometry(89,794,16,41);
        ui->matrix_sign_3->setGeometry(90,630,21,41);

        //labels
        ui->lab_11->setGeometry(184,573,40,160);
        ui->lab_12->setGeometry(603,573,51,161);
        ui->lab_13->setGeometry(160,794,21,41);
        ui->lab_14->setGeometry(185,750,40,128);
        ui->lab_15->setGeometry(376,750,40,128);
        ui->lab_31->setGeometry(119,794,40,41);
        ui->lab_32->setGeometry(49,794,40,41);
        ui->lab_8->setGeometry(50,630,40,41);
        ui->lab_9->setGeometry(120,630,40,41);
        ui->lab_10->setGeometry(165,630,21,41);
        QFont f("Arial", 100, QFont::StyleNormal);
        ui->lab_11->setFont(f);
        ui->lab_12->setFont(f);
        //Matrix_AB
        ui->matrix_AB->setGeometry(240,785,122,62);

        //set rest invisible
        QLabel* tab_labels[15]={ui->a_02, ui->a_12, ui->a_20, ui->a_21, ui->a_22, ui->b_02, ui->b_12, ui->b_20, ui->b_21, ui->b_22,
                              ui->sign_a02, ui->sign_a12, ui->sign_a20, ui->sign_a21, ui->sign_a22};
        for (int i = 0;i < 15;i++) {
            tab_labels[i]->setVisible(0);
        }
        this->visible_5(0);
        ui->line6->setVisible(0);
        ui->line8->setVisible(0);
    }
    //for 3x3 matrix
    if(ui->matrix_A->rowCount()==3){
        this->visible_5(1);
        //a lables
        ui->a_00->setGeometry(233,589,40,20);
        ui->a_01->setGeometry(336,589,40,20);
        ui->a_02->setGeometry(284,614,40,20);
        ui->a_10->setGeometry(233,642,40,20);
        ui->a_11->setGeometry(336,642,40,20);
        ui->a_12->setGeometry(284,667,40,20);
        ui->a_20->setGeometry(633,695,40,20);
        ui->a_21->setGeometry(736,695,40,20);
        ui->a_22->setGeometry(684,720,40,20);

        ui->a_00_1->setGeometry(433,589,40,20);
        ui->a_01_1->setGeometry(536,589,40,20);
        ui->a_10_1->setGeometry(433,642,40,20);
        ui->a_11_1->setGeometry(536,642,40,20);

        //b labels
        ui->b_00->setGeometry(284,589,40,20);
        ui->b_01->setGeometry(484,589,40,20);
        ui->b_02->setGeometry(684,589,40,20);
        ui->b_10->setGeometry(387,589,40,20);
        ui->b_11->setGeometry(587,589,40,20);
        ui->b_12->setGeometry(787,589,40,20);
        ui->b_20->setGeometry(336,614,40,20);
        ui->b_21->setGeometry(536,614,40,20);
        ui->b_22->setGeometry(736,614,40,20);

        ui->b_00_0->setGeometry(284,642,40,20);
        ui->b_10_0->setGeometry(387,642,40,20);
        ui->b_01_1->setGeometry(484,642,40,20);
        ui->b_11_1->setGeometry(587,642,40,20);

        //lines
        ui->line1->setGeometry(230,575,601,20);
        ui->line2->setGeometry(230,734,601,20);
        ui->line3->setGeometry(220,584,20,161);
        ui->line4->setGeometry(820,585,20,160);
        ui->line5->setGeometry(420,585,20,160);
        ui->line6->setGeometry(620,585,20,160);
        ui->line7->setGeometry(230,628,601,20);
        ui->line8->setGeometry(230,681,601,20);

        //signs
        ui->sign_a00->setGeometry(271,589,16,20);
        ui->sign_a01->setGeometry(374,589,16,20);
        ui->sign_a02->setGeometry(322,614,16,20);
        ui->sign_a10->setGeometry(271,642,16,20);
        ui->sign_a11->setGeometry(374,642,16,20);
        ui->sign_a12->setGeometry(322,667,16,20);
        ui->sign_a20->setGeometry(671,695,16,20);
        ui->sign_a21->setGeometry(774,695,16,20);
        ui->sign_a22->setGeometry(722,720,16,20);

        ui->sign_a01_0->setGeometry(322,589,16,20);
        ui->sign_a01_1->setGeometry(522,589,16,20);
        ui->sign_a01_2->setGeometry(322,642,16,20);
        ui->sign_a01_3->setGeometry(522,642,16,20);
        ui->sign_a11_2->setGeometry(471,589,16,20);
        ui->sign_a11_3->setGeometry(574,589,16,20);
        ui->sign_a11_4->setGeometry(471,642,16,20);
        ui->sign_a11_5->setGeometry(574,642,16,20);
        ui->matrix_sign_7->setGeometry(89,814,21,41);

        //labels
        ui->lab_11->setGeometry(192,558,50,210);
        ui->lab_12->setGeometry(817,558,50,210);
        ui->lab_13->setGeometry(164,814,21,41);
        ui->lab_14->setGeometry(199,770,40,128);
        ui->lab_15->setGeometry(390,770,40,128);
        ui->lab_31->setGeometry(119,814,40,41);
        ui->lab_32->setGeometry(49,814,40,41);
        ui->lab_8->setGeometry(50,630,40,41);
        ui->lab_9->setGeometry(120,630,40,41);
        ui->lab_10->setGeometry(165,630,21,41);

        QFont f("Arial", 130, QFont::StyleNormal);
        ui->lab_11->setFont(f);
        ui->lab_12->setFont(f);

        //Matrix_AB
        ui->matrix_AB->setGeometry(225,788,182,92);

        //set rest visible
        QLabel* tab_labels[15]={ui->a_02, ui->a_12, ui->a_20, ui->a_21, ui->a_22, ui->b_02, ui->b_12, ui->b_20, ui->b_21, ui->b_22,
                              ui->sign_a02, ui->sign_a12, ui->sign_a20, ui->sign_a21, ui->sign_a22};
        for (int i = 0;i < 15;i++) {
            tab_labels[i]->setVisible(1);
        }
        ui->line6->setVisible(1);
        ui->line8->setVisible(1);
    }

}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Buttons>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//Matrix 2x2 button
void MainWindow::on_pushButton_matrix2x2_2_released()
{
    //Set visible
    this->visible_1();
    this->visible_2(0);
    this->visible_4(0);
    this->visible_5(0);

    ui->matrix_A->setColumnCount(2);
    ui->matrix_A->setRowCount(2);
    ui->matrix_B->setRowCount(2);
    ui->matrix_B->setColumnCount(2);
    ui->matrix_A2->setColumnCount(2);
    ui->matrix_A2->setRowCount(2);
    ui->matrix_B2->setRowCount(2);
    ui->matrix_B2->setColumnCount(2);
    ui->matrix_AB->setRowCount(2);
    ui->matrix_AB->setColumnCount(2);
    for(int i=0; i<ui->matrix_A->rowCount();i++){
        for(int j=0; j<(ui->matrix_A->columnCount());j++){
            ui->matrix_A->setItem(i, j, new QTableWidgetItem("0"));
            ui->matrix_A->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->matrix_B->setItem(i, j, new QTableWidgetItem("0"));
            ui->matrix_B->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->matrix_A2->setItem(i, j, new QTableWidgetItem("0"));
            ui->matrix_A2->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->matrix_B2->setItem(i, j, new QTableWidgetItem("0"));
            ui->matrix_B2->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->matrix_AB->setItem(i, j, new QTableWidgetItem("0"));
            ui->matrix_AB->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
    //Set green background color selection
    QTableWidget* tabs[2] = {ui->matrix_A, ui->matrix_B};
    for (int i=0 ; i<2 ; i++) {
        tabs[i]->setStyleSheet("QTableView {selection-background-color: green;}");
    }
    ui->matrix_A->setGeometry(215,208,122,62);
    ui->matrix_B->setGeometry(625,208,122,62);
    ui->matrix_A2->setGeometry(255,463,122,62);
    ui->matrix_B2->setGeometry(555,463,122,62);
    ui->size_label_A->setText("2x2");
    ui->size_label_B->setText("2x2");

    //Set cells colors
    this->set_cells_colors();

    //Set values on matrix AB with signs
    this->set_values_on_labels();

    //Create matrixAB with signs
    this->create_matrixAB_labels();

    //No selection and no focus on displaying tables
    ui->matrix_A2->setFocusPolicy(Qt::NoFocus);
    ui->matrix_A2->setSelectionMode(QAbstractItemView::NoSelection);
    ui->matrix_B2->setFocusPolicy(Qt::NoFocus);
    ui->matrix_B2->setSelectionMode(QAbstractItemView::NoSelection);
    ui->matrix_AB->setFocusPolicy(Qt::NoFocus);
    ui->matrix_AB->setSelectionMode(QAbstractItemView::NoSelection);

}

//Matrix 3x3 button
void MainWindow::on_pushButton_matrix3x3_2_released()
{
    //Set visibility
    this->visible_1();
    this->visible_2(0);
    this->visible_4(0);
    this->visible_5(0);

    ui->matrix_A->setColumnCount(3);
    ui->matrix_A->setRowCount(3);
    ui->matrix_B->setRowCount(3);
    ui->matrix_B->setColumnCount(3);
    ui->matrix_A2->setColumnCount(3);
    ui->matrix_A2->setRowCount(3);
    ui->matrix_B2->setRowCount(3);
    ui->matrix_B2->setColumnCount(3);
    ui->matrix_AB->setRowCount(3);
    ui->matrix_AB->setColumnCount(3);
    for(int i=0; i<ui->matrix_A->rowCount();i++){
        for(int j=0; j<(ui->matrix_A->columnCount());j++){
            ui->matrix_A->setItem(i, j, new QTableWidgetItem("0"));
            ui->matrix_A->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->matrix_B->setItem(i, j, new QTableWidgetItem("0"));
            ui->matrix_B->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->matrix_A2->setItem(i, j, new QTableWidgetItem("0"));
            ui->matrix_A2->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->matrix_B2->setItem(i, j, new QTableWidgetItem("0"));
            ui->matrix_B2->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->matrix_AB->setItem(i, j, new QTableWidgetItem("0"));
            ui->matrix_AB->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    //Set tables start positions
    ui->matrix_A->setGeometry(185,193,182,92);
    ui->matrix_B->setGeometry(595,193,182,92);
    ui->matrix_A2->setGeometry(225,448,182,92);
    ui->matrix_B2->setGeometry(525,448,182,92);
    ui->matrix_AB->setGeometry(630,606,182,92);

    //Set size_labels
    ui->size_label_A->setText("3x3");
    ui->size_label_B->setText("3x3");

    //Set cells colors
    this->set_cells_colors();

    //Set values on matrix AB with signs
    this->set_values_on_labels();

    //No selection and no focus on displaying tables
    ui->matrix_A2->setFocusPolicy(Qt::NoFocus);
    ui->matrix_A2->setSelectionMode(QAbstractItemView::NoSelection);
    ui->matrix_B2->setFocusPolicy(Qt::NoFocus);
    ui->matrix_B2->setSelectionMode(QAbstractItemView::NoSelection);
    ui->matrix_AB->setFocusPolicy(Qt::NoFocus);
    ui->matrix_AB->setSelectionMode(QAbstractItemView::NoSelection);

}


//add Matrices
void MainWindow::on_pushButton_matrix_add_clicked()
{
    int add_flag = 1;
    this->visible_4(0);

    //Set size of matrices
    matrixA.setH(ui->matrix_A->rowCount());
    matrixA.setW(ui->matrix_A->columnCount());
    matrixB.setH(ui->matrix_B->rowCount());
    matrixB.setW(ui->matrix_B->columnCount());


    //Get values to matrixA from table
    for (int i = 0;i<ui->matrix_A->rowCount() ;i++) {
        for (int j = 0;j<ui->matrix_A->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->matrix_A->item(i, j)->text();
            ui->matrix_A->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->matrix_A->item(i, j)->setBackgroundColor(Qt::red);
                   add_flag = 0;
                }
            }
            double value = s.toDouble();
            matrixA(i, j)=value;
        }
    }

    //Get values to matrixB from table
    for (int i = 0;i<ui->matrix_B->rowCount() ;i++) {
        for (int j = 0;j<ui->matrix_B->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->matrix_B->item(i, j)->text();
            ui->matrix_B->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce b(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->matrix_B->item(i, j)->setBackgroundColor(Qt::red);
                   add_flag = 0;
                }
            }
            double value = s.toDouble();
            matrixB(i, j)=value;
        }
    }
    //Set values on tables
    for (int i = 0;i<ui->matrix_AB->rowCount() ;i++) {
        for (int j = 0;j<ui->matrix_AB->columnCount() ;j++) {
            if(add_flag){
                //Set visible
                this->visible_2(1);
                //Set + signs
                QLabel* matrix_signs[12] = {ui->sign_a00, ui->sign_a01, ui->sign_a02, ui->sign_a10, ui->sign_a11, ui->sign_a12, ui->sign_a20,
                                          ui->sign_a21, ui->sign_a22, ui->matrix_sign, ui->matrix_sign_2, ui->matrix_sign_3};
                for (int i = 0;i < 12;i++) {
                    matrix_signs[i]->setText("+");
                }

                //Set values on table A2 and B2
                QString val_A = QString::number(matrixA(i,j));
                ui->matrix_A2->setItem(i,j,new QTableWidgetItem(val_A));
                ui->matrix_A2->item(i,j)->setTextAlignment(Qt::AlignCenter);
                QString val_B = QString::number(matrixB(i,j));
                ui->matrix_B2->setItem(i,j,new QTableWidgetItem(val_B));
                ui->matrix_B2->item(i,j)->setTextAlignment(Qt::AlignCenter);
                //Set values on table AB
                QString val_AB = QString::number((matrixA+matrixB)(i,j));
                ui->matrix_AB->setItem(i,j,new QTableWidgetItem(val_AB));
                ui->matrix_AB->item(i,j)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
    this->set_cells_colors();
    this->set_values_on_labels();
    //Create matrixAB with signs
    this->create_matrixAB_labels();
}

void MainWindow::on_pushButton_matrix_sub_clicked()
{
    int sub_flag = 1;
    this->visible_4(0);

    //Set size of matrices
    matrixA.setH(ui->matrix_A->rowCount());
    matrixA.setW(ui->matrix_A->columnCount());
    matrixB.setH(ui->matrix_B->rowCount());
    matrixB.setW(ui->matrix_B->columnCount());

    //Get values to matrixA from table
    for (int i = 0;i<ui->matrix_A->rowCount() ;i++) {
        for (int j = 0;j<ui->matrix_A->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->matrix_A->item(i, j)->text();
            ui->matrix_A->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->matrix_A->item(i, j)->setBackgroundColor(Qt::red);
                   sub_flag = 0;
                }
            }
            double value = s.toDouble();
            matrixA(i, j)=value;
        }
    }

    //Get values to matrixB from table
    for (int i = 0;i<ui->matrix_B->rowCount() ;i++) {
        for (int j = 0;j<ui->matrix_B->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->matrix_B->item(i, j)->text();
            ui->matrix_B->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce b(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->matrix_B->item(i, j)->setBackgroundColor(Qt::red);
                   sub_flag = 0;
                }
            }
            double value = s.toDouble();
            matrixB(i, j)=value;
        }
    }

    //Set values on tables and signs
    for (int i = 0;i<ui->matrix_AB->rowCount() ;i++) {
        for (int j = 0;j<ui->matrix_AB->columnCount() ;j++) {
            if(sub_flag){
                //Set visible
                this->visible_2(1);

                //Set - signs
                QLabel* matrix_signs[12] = {ui->sign_a00, ui->sign_a01, ui->sign_a02, ui->sign_a10, ui->sign_a11, ui->sign_a12, ui->sign_a20,
                                          ui->sign_a21, ui->sign_a22, ui->matrix_sign, ui->matrix_sign_2, ui->matrix_sign_3};
                for (int i = 0;i < 12;i++) {
                    matrix_signs[i]->setText("-");
                }

                //Set values on table A2 and B2
                QString val_A = QString::number(matrixA(i,j));
                ui->matrix_A2->setItem(i,j,new QTableWidgetItem(val_A));
                ui->matrix_A2->item(i,j)->setTextAlignment(Qt::AlignCenter);
                QString val_B = QString::number(matrixB(i,j));
                ui->matrix_B2->setItem(i,j,new QTableWidgetItem(val_B));
                ui->matrix_B2->item(i,j)->setTextAlignment(Qt::AlignCenter);
                //Set values on table AB
                QString val_AB = QString::number((matrixA-matrixB)(i,j));
                ui->matrix_AB->setItem(i,j,new QTableWidgetItem(val_AB));
                ui->matrix_AB->item(i,j)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
    this->set_cells_colors();
    this->set_values_on_labels();
    //Create matrixAB with signs
    this->create_matrixAB_labels();
}

void MainWindow::on_pushButton_matrix_multi_clicked()
{
    int mul_flag = 1;
    //Set size of matrices
    matrixA.setH(ui->matrix_A->rowCount());
    matrixA.setW(ui->matrix_A->columnCount());
    matrixB.setH(ui->matrix_B->rowCount());
    matrixB.setW(ui->matrix_B->columnCount());

    //Get values to matrixA from table
    for (int i = 0;i<ui->matrix_A->rowCount() ;i++) {
        for (int j = 0;j<ui->matrix_A->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->matrix_A->item(i, j)->text();
            ui->matrix_A->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->matrix_A->item(i, j)->setBackgroundColor(Qt::red);
                   mul_flag = 0;
                }
            }
            double value = s.toDouble();
            matrixA(i, j)=value;
        }
    }

    //Get values to matrixB from table
    for (int i = 0;i<ui->matrix_B->rowCount() ;i++) {
        for (int j = 0;j<ui->matrix_B->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->matrix_B->item(i, j)->text();
            ui->matrix_B->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce b(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->matrix_B->item(i, j)->setBackgroundColor(Qt::red);
                   mul_flag = 0;
                }
            }
            double value = s.toDouble();
            matrixB(i, j)=value;
        }
    }
    for (int i = 0;i<ui->matrix_AB->rowCount() ;i++) {
        for (int j = 0;j<ui->matrix_AB->columnCount() ;j++) {
            if(mul_flag){
                //Set visible
                this->visible_2(1);
                this->visible_4(1);

                //Set - signs
                QLabel* matrix_signs[12] = {ui->sign_a00, ui->sign_a01, ui->sign_a02, ui->sign_a10, ui->sign_a11, ui->sign_a12, ui->sign_a20,
                                          ui->sign_a21, ui->sign_a22, ui->matrix_sign, ui->matrix_sign_2, ui->matrix_sign_3};
                for (int i = 0;i < 12;i++) {
                    matrix_signs[i]->setText("x");
                }

                //Set values on table A2 and B2
                QString val_A = QString::number(matrixA(i,j));
                ui->matrix_A2->setItem(i,j,new QTableWidgetItem(val_A));
                ui->matrix_A2->item(i,j)->setTextAlignment(Qt::AlignCenter);
                QString val_B = QString::number(matrixB(i,j));
                ui->matrix_B2->setItem(i,j,new QTableWidgetItem(val_B));
                ui->matrix_B2->item(i,j)->setTextAlignment(Qt::AlignCenter);
                //Set values on table AB
                QString val_AB = QString::number((matrixA*matrixB)(i,j));
                ui->matrix_AB->setItem(i,j,new QTableWidgetItem(val_AB));
                ui->matrix_AB->item(i,j)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
    this->set_cells_colors();
    this->set_values_on_labels();
    //Create matrixAB with signs
    this->create_matrixAB_labels_2();
}

//--------------------------------------------------------------------------------------------------------------------------------------
//<-------------------------------------------------------- Operacje na 1 macierzy -------------------------------------------------------->
//--------------------------------------------------------------------------------------------------------------------------------------

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Methods>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void MainWindow::visible_6(int v){
    QLabel* labels[15]={ui->label_15, ui->label_16, ui->label_17, ui->label_61, ui->label_62, ui->label_18, ui->label_64, ui->label_65, ui->label_66,
                       ui->label_67, ui->label_69, ui->label_70, ui->label_71, ui->label_72, ui->scalar_label};
    for (int i = 0;i<15;i++) {
        labels[i]->setVisible(v);
    }
    QTableWidget* tables[3] = {ui->table_matrix_op1_2, ui->table_matrix_op1_3, ui->table_matrix_op1_4};
    for (int i = 0;i<3;i++) {
        tables[i]->setVisible(v);
    }
}

void MainWindow::visible_multi(int v){
    ui->multi_button->setVisible(v);
    ui->label_15->setVisible(v);
    ui->label_68->setVisible(v);
    ui->scalar->setVisible(v);
}

//matrix and matrix transpose cell colors
void MainWindow::set_cells_colors2(){
    //Set matrix colors
    if(ui->table_matrix_op1_2->rowCount() == 2){
        //Matrix A cells colors
        ui->table_matrix_op1_2->item(0,0)->setBackgroundColor(Qt::darkBlue);
        ui->table_matrix_op1_2->item(0,1)->setBackgroundColor(Qt::darkRed);
        ui->table_matrix_op1_2->item(1,0)->setBackgroundColor(QColor(0, 100, 0));
        ui->table_matrix_op1_2->item(1,1)->setBackgroundColor(QColor(151, 117, 0));

        //Matrix A transpose cells colors
        ui->table_matrix_op1_4->item(0,0)->setBackgroundColor(Qt::darkBlue);
        ui->table_matrix_op1_4->item(0,1)->setBackgroundColor(QColor(0, 100, 0));
        ui->table_matrix_op1_4->item(1,0)->setBackgroundColor(Qt::darkRed);
        ui->table_matrix_op1_4->item(1,1)->setBackgroundColor(QColor(151, 117, 0));

        //Text Color
        ui->table_matrix_op1_2->item(0,0)->setTextColor(Qt::white);
        ui->table_matrix_op1_2->item(0,1)->setTextColor(Qt::white);
        ui->table_matrix_op1_2->item(1,0)->setTextColor(Qt::white);
        ui->table_matrix_op1_2->item(1,1)->setTextColor(Qt::white);

        ui->table_matrix_op1_4->item(0,0)->setTextColor(Qt::white);
        ui->table_matrix_op1_4->item(0,1)->setTextColor(Qt::white);
        ui->table_matrix_op1_4->item(1,0)->setTextColor(Qt::white);
        ui->table_matrix_op1_4->item(1,1)->setTextColor(Qt::white);

    }
    if(ui->table_matrix_op1_2->rowCount() == 3){
        //Matrix A cells colors
        ui->table_matrix_op1_2->item(0,0)->setBackgroundColor(Qt::darkBlue);
        ui->table_matrix_op1_2->item(0,1)->setBackgroundColor(Qt::darkRed);
        ui->table_matrix_op1_2->item(0,2)->setBackgroundColor(Qt::darkMagenta);
        ui->table_matrix_op1_2->item(1,0)->setBackgroundColor(QColor(0, 100, 0));
        ui->table_matrix_op1_2->item(1,1)->setBackgroundColor(QColor(151, 117, 0));
        ui->table_matrix_op1_2->item(1,2)->setBackgroundColor(Qt::darkYellow);
        ui->table_matrix_op1_2->item(2,0)->setBackgroundColor(Qt::darkGray);
        ui->table_matrix_op1_2->item(2,1)->setBackgroundColor(QColor(0, 102, 102));
        ui->table_matrix_op1_2->item(2,2)->setBackgroundColor(Qt::black);

        //Matrix A transpose cells colors
        ui->table_matrix_op1_4->item(0,0)->setBackgroundColor(Qt::darkBlue);
        ui->table_matrix_op1_4->item(1,0)->setBackgroundColor(Qt::darkRed);
        ui->table_matrix_op1_4->item(2,0)->setBackgroundColor(Qt::darkMagenta);
        ui->table_matrix_op1_4->item(0,1)->setBackgroundColor(QColor(0, 100, 0));
        ui->table_matrix_op1_4->item(1,1)->setBackgroundColor(QColor(151, 117, 0));
        ui->table_matrix_op1_4->item(2,1)->setBackgroundColor(Qt::darkYellow);
        ui->table_matrix_op1_4->item(0,2)->setBackgroundColor(Qt::darkGray);
        ui->table_matrix_op1_4->item(1,2)->setBackgroundColor(QColor(0, 102, 102));
        ui->table_matrix_op1_4->item(2,2)->setBackgroundColor(Qt::black);

        //Text Color
        ui->table_matrix_op1_2->item(0,0)->setTextColor(Qt::white);
        ui->table_matrix_op1_2->item(0,1)->setTextColor(Qt::white);
        ui->table_matrix_op1_2->item(0,2)->setTextColor(Qt::white);
        ui->table_matrix_op1_2->item(1,0)->setTextColor(Qt::white);
        ui->table_matrix_op1_2->item(1,1)->setTextColor(Qt::white);
        ui->table_matrix_op1_2->item(1,2)->setTextColor(Qt::white);
        ui->table_matrix_op1_2->item(2,0)->setTextColor(Qt::white);
        ui->table_matrix_op1_2->item(2,1)->setTextColor(Qt::white);
        ui->table_matrix_op1_2->item(2,2)->setTextColor(Qt::white);

        ui->table_matrix_op1_4->item(0,0)->setTextColor(Qt::white);
        ui->table_matrix_op1_4->item(0,1)->setTextColor(Qt::white);
        ui->table_matrix_op1_4->item(0,2)->setTextColor(Qt::white);
        ui->table_matrix_op1_4->item(1,0)->setTextColor(Qt::white);
        ui->table_matrix_op1_4->item(1,1)->setTextColor(Qt::white);
        ui->table_matrix_op1_4->item(1,2)->setTextColor(Qt::white);
        ui->table_matrix_op1_4->item(2,0)->setTextColor(Qt::white);
        ui->table_matrix_op1_4->item(2,1)->setTextColor(Qt::white);
        ui->table_matrix_op1_4->item(2,2)->setTextColor(Qt::white);

    }
}

//matrix transpose visible
void MainWindow::visible_trans(int v){
    QLabel* labels[9] = {ui->label_16, ui->label_17, ui->label_18, ui->label_36, ui->label_37, ui->label_61, ui->label_70, ui->label_71, ui->label_72};
    for(int i=0; i<9; i++){
        labels[i]->setVisible(v);
    }
    ui->table_matrix_op1_2->setVisible(v);
    ui->table_matrix_op1_4->setVisible(v);
}

//minor visible
void MainWindow::visible_minor(int v){
    //for matrix 2x2
        ui->label_15->setVisible(v);
        ui->minor_button_11->setVisible(v);
        ui->minor_button_12->setVisible(v);
        ui->minor_button_21->setVisible(v);
        ui->minor_button_22->setVisible(v);
        ui->minor_button_13->setVisible(0);
        ui->minor_button_23->setVisible(0);
        ui->minor_button_31->setVisible(0);
        ui->minor_button_32->setVisible(0);
        ui->minor_button_33->setVisible(0);

    //for matrix 3x3
    if(ui->table_matrix_op1->rowCount() == 3){
        ui->minor_button_13->setVisible(v);
        ui->minor_button_23->setVisible(v);
        ui->minor_button_31->setVisible(v);
        ui->minor_button_32->setVisible(v);
        ui->minor_button_33->setVisible(v);
    }
}

//determining minors visible
void MainWindow::visible_minor_2(int v){
    QLabel* labels[61]={ui->label_65, ui->label_3, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                        ui->label_61, ui->size_label_4, ui->a_00_4, ui->a_01_4, ui->a_02_4, ui->a_10_4, ui->a_11_4, ui->a_12_4, ui->a_20_4,
                        ui->a_21_4, ui->a_22_4, ui->size_label_5, ui->minor_label, ui->label_70, ui->a_00_5, ui->a_01_5, ui->a_02_5,
                        ui->a_10_5, ui->a_11_5, ui->a_12_5, ui->a_20_5, ui->a_21_5, ui->a_22_5, ui->sign_det_1, ui->sign_det_2, ui->sign_det_3,
                        ui->sign_det_4, ui->sign_det_5, ui->sign_det_6, ui->sign_det_7, ui->sign_det_8, ui->sign_det_9, ui->sign_det_10,
                        ui->sign_det_11, ui->sign_det_12, ui->sign_det_13, ui->sign_det_14, ui->sign_det_15, ui->sign_det_16, ui->sign_det_17,
                        ui->a_01_6, ui->a_11_6,ui->minor_label_2, ui->size_label_6, ui->size_label_7, ui->label_9, ui->label_10,
                        ui->label_63, ui->label_75, ui->label_76, ui->label_77, ui->label_38, ui->label_74};
    for (int i = 0; i < 61; i++) {
        labels[i]->setVisible(v);
    }
    ui->line_4->setVisible(v);
    ui->line_5->setVisible(v);
    ui->line_6->setVisible(v);
    ui->table_matrix_op1_4->setVisible(v);
    ui->table_matrix_op1_5->setVisible(v);
}

//Algebraic Complements visible
void MainWindow::visible_algebraic(int v){
    //for matrix 2x2
        ui->label_15->setVisible(v);
        ui->algebraic_button_11->setVisible(v);
        ui->algebraic_button_12->setVisible(v);
        ui->algebraic_button_21->setVisible(v);
        ui->algebraic_button_22->setVisible(v);
        ui->algebraic_button_13->setVisible(0);
        ui->algebraic_button_23->setVisible(0);
        ui->algebraic_button_31->setVisible(0);
        ui->algebraic_button_32->setVisible(0);
        ui->algebraic_button_33->setVisible(0);

    //for matrix 3x3
    if(ui->table_matrix_op1->rowCount() == 3){
        ui->algebraic_button_13->setVisible(v);
        ui->algebraic_button_23->setVisible(v);
        ui->algebraic_button_31->setVisible(v);
        ui->algebraic_button_32->setVisible(v);
        ui->algebraic_button_33->setVisible(v);
    }
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Buttons>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//for 2x2 matrix
void MainWindow::on_pushButton_matrix2x2_op1_released()
{
    ui->table_matrix_op1->setColumnCount(2);
    ui->table_matrix_op1->setRowCount(2);
    ui->table_matrix_op1_2->setColumnCount(2);
    ui->table_matrix_op1_2->setRowCount(2);

    for(int i=0; i<ui->table_matrix_op1->rowCount();i++){
        for(int j=0; j<(ui->table_matrix_op1->columnCount());j++){
            ui->table_matrix_op1->setItem(i, j, new QTableWidgetItem("0"));
            ui->table_matrix_op1->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
    ui->table_matrix_op1->setStyleSheet("QTableView {selection-background-color: green;border-style:none;}");
    ui->table_matrix_op1->setGeometry(240,170,122,82);
    ui->size_label_3->setText("2x2");

    ui->scalar->setText("");

    ui->table_matrix_op1->setVisible(1);
    ui->label_12->setVisible(1);
    ui->label_13->setVisible(1);
    ui->label_14->setVisible(1);
    ui->size_label_3->setVisible(1);
    ui->line_7->setVisible(1);
    ui->line_8->setVisible(1);
    ui->pushButton_matrix_det->setVisible(1);
    ui->pushButton_matrix_minor->setVisible(1);
    ui->pushButton_matrix_multi_scalar->setVisible(1);
    ui->pushButton_matrix_inverse->setVisible(1);
    ui->pushButton_matrix_transpose->setVisible(1);
    ui->pushButton_matrix_trace->setVisible(1);
    ui->pushButton_matrix_algebraic->setVisible(1);

    ui->table_matrix_op1_2->setFocusPolicy(Qt::NoFocus);
    ui->table_matrix_op1_2->setSelectionMode(QAbstractItemView::NoSelection);
    ui->table_matrix_op1_3->setFocusPolicy(Qt::NoFocus);
    ui->table_matrix_op1_3->setSelectionMode(QAbstractItemView::NoSelection);
    ui->table_matrix_op1_4->setFocusPolicy(Qt::NoFocus);
    ui->table_matrix_op1_4->setSelectionMode(QAbstractItemView::NoSelection);

    this->visible_trans(0);
    this->visible_multi(0);
    this->visible_6(0);
    this->visible_minor(0);
    this->visible_minor_2(0);
    this->visible_algebraic(0);
}

//for 3x3 matrix
void MainWindow::on_pushButton_matrix3x3_op1_released()
{    
    ui->table_matrix_op1->setColumnCount(3);
    ui->table_matrix_op1->setRowCount(3);
    ui->table_matrix_op1_2->setColumnCount(3);
    ui->table_matrix_op1_2->setRowCount(3);

    for(int i=0; i<ui->table_matrix_op1->rowCount();i++){
        for(int j=0; j<(ui->table_matrix_op1->columnCount());j++){
            ui->table_matrix_op1->setItem(i, j, new QTableWidgetItem("0"));
            ui->table_matrix_op1->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
    ui->table_matrix_op1->setStyleSheet("QTableView {selection-background-color: green;border-style:none;}");
    ui->table_matrix_op1->setGeometry(211,151,181,122);
    ui->size_label_3->setText("3x3");

    ui->scalar->setText("");

    ui->table_matrix_op1->setVisible(1);
    ui->label_12->setVisible(1);
    ui->label_13->setVisible(1);
    ui->label_14->setVisible(1);
    ui->size_label_3->setVisible(1);
    ui->line_7->setVisible(1);
    ui->line_8->setVisible(1);
    ui->pushButton_matrix_det->setVisible(1);
    ui->pushButton_matrix_minor->setVisible(1);
    ui->pushButton_matrix_multi_scalar->setVisible(1);
    ui->pushButton_matrix_inverse->setVisible(1);
    ui->pushButton_matrix_transpose->setVisible(1);
    ui->pushButton_matrix_trace->setVisible(1);
    ui->pushButton_matrix_algebraic->setVisible(1);

    ui->table_matrix_op1_2->setFocusPolicy(Qt::NoFocus);
    ui->table_matrix_op1_2->setSelectionMode(QAbstractItemView::NoSelection);
    ui->table_matrix_op1_3->setFocusPolicy(Qt::NoFocus);
    ui->table_matrix_op1_3->setSelectionMode(QAbstractItemView::NoSelection);
    ui->table_matrix_op1_4->setFocusPolicy(Qt::NoFocus);
    ui->table_matrix_op1_4->setSelectionMode(QAbstractItemView::NoSelection);

    this->visible_trans(0);
    this->visible_multi(0);
    this->visible_6(0);
    this->visible_minor(0);
    this->visible_minor_2(0);
    this->visible_algebraic(0);
}


//scalar multiplication step 1
void MainWindow::on_pushButton_matrix_multi_scalar_clicked()
{
    this->visible_multi(0);
    this->visible_6(0);
    this->visible_trans(0);
    this->visible_minor(0);
    this->visible_minor_2(0);
    this->visible_algebraic(0);

    //flag
    int mul_s_flag = 1;

    QFont font("Arial", 24, QFont::Bold) ;
    ui->label_61->setFont(font);
    ui->label_70->setFont(font);

    //labels
    ui->label_15->setText("Skalar");
    ui->label_15->setGeometry(94,320,111,31);
    ui->scalar->setGeometry(205,320,191,31);
    ui->multi_button->setGeometry(420,320,101,31);
    ui->label_16->setText("Mnożenie przez skalar:");
    ui->label_62->setGeometry(45,500,41,41);
    ui->label_61->setGeometry(80,500,101,41);
    ui->label_61->setText("x A =");
    ui->scalar_label->setGeometry(190,503,91,41);
    ui->label_64->setGeometry(295,500,31,41);
    ui->label_64->setText("x");
    ui->label_18->setGeometry(320,440,51,161);
    ui->label_18->setText("[");
    ui->label_17->setGeometry(510,440,51,161);
    ui->label_17->setText("]");
    ui->label_65->setGeometry(585,690,31,41);
    ui->label_66->setGeometry(230,630,51,161);
    ui->label_66->setText("[");
    QFont f("Arial", 100, QFont::StyleNormal);
    ui->label_66->setFont(f);
    ui->label_67->setGeometry(518,630,51,161);
    ui->label_67->setText("]");
    ui->label_67->setFont(f);
    ui->label_66->setVisible(0);
    ui->label_67->setVisible(0);
    ui->label_69->setGeometry(20,693,91,41);
    ui->label_70->setGeometry(120,690,101,41);
    ui->label_70->setText("x A =");
    ui->label_71->setGeometry(630,630,51,161);
    ui->label_71->setText("[");
    ui->label_72->setGeometry(820,630,51,161);
    ui->label_72->setText("]");

    //for2x2
    if(ui->table_matrix_op1->rowCount() == 2){
        ui->table_matrix_op1_2->setColumnCount(2);
        ui->table_matrix_op1_2->setRowCount(2);
        ui->table_matrix_op1_3->setColumnCount(2);
        ui->table_matrix_op1_3->setRowCount(2);
        ui->table_matrix_op1_4->setColumnCount(2);
        ui->table_matrix_op1_4->setRowCount(2);
        ui->table_matrix_op1_2->setGeometry(380,480,122,82);
        ui->table_matrix_op1_3->setGeometry(305,670,188,82);
        ui->table_matrix_op1_4->setGeometry(690,670,122,82);
    }

    //for3x3
    if(ui->table_matrix_op1->rowCount() == 3){
        ui->table_matrix_op1_2->setColumnCount(3);
        ui->table_matrix_op1_2->setRowCount(3);
        ui->table_matrix_op1_3->setColumnCount(3);
        ui->table_matrix_op1_3->setRowCount(3);
        ui->table_matrix_op1_4->setColumnCount(3);
        ui->table_matrix_op1_4->setRowCount(3);
        ui->table_matrix_op1_2->setGeometry(350,460,182,122);
        ui->table_matrix_op1_3->setGeometry(260,650,281,122);
        ui->table_matrix_op1_4->setGeometry(660,650,182,122);
    }

    matrix_op1.setH(ui->table_matrix_op1->rowCount());
    matrix_op1.setW(ui->table_matrix_op1->rowCount());

    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   mul_s_flag = 0;
                }
            }
            double value = s.toDouble();
            matrix_op1(i, j)=value;
        }
    }

    if(mul_s_flag){
        this->visible_multi(1);
    }
}

//scalar multiplication step 2
void MainWindow::on_multi_button_released()
{


    int multi_flag = 1;

    if(ui->scalar->text().isEmpty()){
        QMessageBox::critical(this,"Wystąpił Błąd","Nie podano wartości skalaru \"a\".");
    }else {
        //Get values to table_maptrix_op1_2, _3 from table op1
        for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
            for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
                //Get values and check their correctness
                QString s = ui->table_matrix_op1->item(i, j)->text();
                ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
                for (int k =0;k<s.size();k++){
                    if(s[k].isLetter()){
                       QString w = QString::number(i+1);
                       QString h = QString::number(j+1);
                       QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                       ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                       multi_flag = 0;
                       this->visible_6(0);
                       ui->label_15->setVisible(1);
                    }
                }
                double value = s.toDouble();
                matrix_op1(i, j)=value;
            }
        }
        //scalar value
        QString scalar_val = ui->scalar->text();
        scalar_val.replace(",",".");
        ui->scalar_label->setText(scalar_val);
        ui->label_69->setText(scalar_val);
        double temp_scalar = scalar_val.toDouble();

        //setting values on tables
        for (int i = 0; i < ui->table_matrix_op1->rowCount(); i++) {
            for (int j = 0; j < ui->table_matrix_op1->columnCount(); j++) {
                    //Set values on tables
                    QString val_1 = QString::number(matrix_op1(i,j));
                    ui->table_matrix_op1_2->setItem(i,j,new QTableWidgetItem(val_1));
                    ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
                    ui->table_matrix_op1_3->setItem(i,j,new QTableWidgetItem(scalar_val+" x "+val_1));
                    ui->table_matrix_op1_3->item(i,j)->setTextAlignment(Qt::AlignCenter);

                    QString val_2 = QString::number(temp_scalar*matrix_op1(i,j));
                    ui->table_matrix_op1_4->setItem(i,j,new QTableWidgetItem(val_2));
                    ui->table_matrix_op1_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
            }
        }
        if(multi_flag){
            this->visible_6(1);
        }

    }
}

void MainWindow::on_pushButton_matrix_transpose_released()
{
    ui->scalar->setText("");
    this->visible_multi(0);
    this->visible_6(0);
    this->visible_minor(0);
    this->visible_minor_2(0);
    this->visible_algebraic(0);

    int trans_flag = 1;

    QFont font("Arial", 24, QFont::Bold) ;
    ui->label_61->setFont(font);
    ui->label_70->setFont(font);

    //for2x2
    if(ui->table_matrix_op1->rowCount() == 2){
        ui->table_matrix_op1_2->setColumnCount(2);
        ui->table_matrix_op1_2->setRowCount(2);
        ui->table_matrix_op1_4->setColumnCount(2);
        ui->table_matrix_op1_4->setRowCount(2);
        ui->table_matrix_op1_2->setGeometry(220,480,122,82);
        ui->table_matrix_op1_4->setGeometry(220,670,122,82);
    }

    //for3x3
    if(ui->table_matrix_op1->rowCount() == 3){
        ui->table_matrix_op1_2->setColumnCount(3);
        ui->table_matrix_op1_2->setRowCount(3);
        ui->table_matrix_op1_4->setColumnCount(3);
        ui->table_matrix_op1_4->setRowCount(3);
        ui->table_matrix_op1_2->setGeometry(190,460,182,122);
        ui->table_matrix_op1_4->setGeometry(190,650,182,122);
    }

    matrix_op1.setH(ui->table_matrix_op1->rowCount());
    matrix_op1.setW(ui->table_matrix_op1->columnCount());

    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   trans_flag = 0;
                   this->visible_trans(0);
                }
            }
            double value = s.toDouble();
            matrix_op1(i, j)=value;
        }
    }
    //setting values on tables
    for (int i = 0; i<ui->table_matrix_op1->rowCount(); i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount(); j++) {
                //Set values on tables
                QString val_1 = QString::number(matrix_op1(i,j));
                ui->table_matrix_op1_2->setItem(i,j,new QTableWidgetItem(val_1));
                ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);

                QString val_2 = QString::number(matrix_op1.transpose()(i,j));
                ui->table_matrix_op1_4->setItem(i,j,new QTableWidgetItem(val_2));
                ui->table_matrix_op1_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
    //set labels
    ui->label_16->setText("Wyznaczanie macierzy transponowanej (A ):");
    ui->label_37->setGeometry(681,370,16,16);
    ui->label_37->setText("T");
    ui->label_36->setGeometry(105,690,21,16);
    ui->label_36->setText("T");
    ui->label_61->setGeometry(80,500,101,41);
    ui->label_61->setText("A =");
    ui->label_18->setGeometry(160,440,51,161);
    ui->label_18->setText("[");
    ui->label_17->setGeometry(350,440,51,161);
    ui->label_17->setText("]");
    ui->label_70->setGeometry(80,690,101,41);
    ui->label_70->setText("A =");
    ui->label_71->setGeometry(160,630,51,161);
    ui->label_71->setText("[");
    ui->label_72->setGeometry(350,630,51,161);
    ui->label_72->setText("]");
    this->set_cells_colors2();
    if(trans_flag){
        this->visible_trans(1);
    }

}

//minor 1st step
void MainWindow::on_pushButton_matrix_minor_released()
{
    ui->scalar->setText("");
    this->visible_multi(0);
    this->visible_trans(0);
    this->visible_6(0);
    this->visible_minor(0);
    this->visible_minor_2(0);
    this->visible_algebraic(0);

    int minor_flag = 1;
    QFont font("Arial", 24, QFont::Bold) ;
    ui->label_61->setFont(font);
    ui->label_70->setFont(font);

    //for2x2
    if(ui->table_matrix_op1->rowCount() == 2){
        ui->table_matrix_op1_2->setColumnCount(2);
        ui->table_matrix_op1_2->setRowCount(2);
        ui->table_matrix_op1_2->setGeometry(220,480,122,82);
        ui->minor_button_11->setGeometry(280,308,41,21);
        ui->minor_button_12->setGeometry(322,308,41,21);
        ui->minor_button_21->setGeometry(280,330,41,21);
        ui->minor_button_22->setGeometry(322,330,41,21);
        QFont f("Arial", 40, QFont::StyleNormal);
        ui->label_66->setFont(f);
        ui->label_67->setFont(f);
    }

    //for3x3
    if(ui->table_matrix_op1->rowCount() == 3){
        ui->table_matrix_op1_2->setColumnCount(3);
        ui->table_matrix_op1_2->setRowCount(3);
        ui->table_matrix_op1_2->setGeometry(190,460,182,122);
        ui->minor_button_11->setGeometry(280,296,41,21);
        ui->minor_button_12->setGeometry(322,296,41,21);
        ui->minor_button_13->setGeometry(364,296,41,21);
        ui->minor_button_21->setGeometry(280,318,41,21);
        ui->minor_button_22->setGeometry(322,318,41,21);
        ui->minor_button_23->setGeometry(364,318,41,21);
        ui->minor_button_31->setGeometry(280,340,41,21);
        ui->minor_button_32->setGeometry(322,340,41,21);
        ui->minor_button_33->setGeometry(364,340,41,21);
        QFont f("Arial", 100, QFont::StyleNormal);
        ui->label_66->setFont(f);
        ui->label_67->setFont(f);
    }

    matrix_op1.setH(ui->table_matrix_op1->rowCount());
    matrix_op1.setW(ui->table_matrix_op1->columnCount());

    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   minor_flag = 0;

                }
            }
        }
    }
    //setting values on tables
    for (int i = 0; i<ui->table_matrix_op1->rowCount(); i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount(); j++) {
                //Set values on tables
                ui->table_matrix_op1_2->setItem(i,j,new QTableWidgetItem(ui->table_matrix_op1->item(i, j)->text()));
                ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
    //set labels
    ui->label_15->setGeometry(94,320,171,31);
    ui->label_15->setText("Wybierz minor:");
    ui->label_16->setText("Obliczanie minora (podwyznacznika):");
    ui->label_70->setText("M  =");
    if(minor_flag){
        this->visible_minor(1);
    }
}

//minor_11
void MainWindow::on_minor_button_11_released()
{

    int minor_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   minor_flag = 0;
                   ui->table_matrix_op1_2->setVisible(0);
                   this->visible_minor_2(0);
                }
            }
        }
    }

    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            ui->table_matrix_op1_2->item(i,j)->setText(ui->table_matrix_op1->item(i, j)->text());
            ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->size_label_4->setText("11");
    ui->size_label_5->setText("11");
    if(minor_flag){
        //for matrix 2x2
        if(ui->table_matrix_op1->rowCount() == 2){
            ui->label_3->setText(ui->table_matrix_op1->item(1, 1)->text());
            ui->label_7->setText(ui->table_matrix_op1->item(1, 1)->text());
            ui->size_label_4->setGeometry(115,528,31,16);
             ui->label_61->setGeometry(80,500,101,41);
             ui->label_61->setText("M  =");
             ui->label_18->setGeometry(160,440,51,161);
             ui->label_18->setText("|");
             ui->label_17->setGeometry(350,440,51,161);
             ui->label_17->setText("|");
             ui->label_66->setGeometry(470,485,21,71);
             ui->label_66->setText("|");
             ui->label_67->setGeometry(560,485,21,71);
             ui->label_67->setText("|");
             ui->label_73->setGeometry(590,500,31,41);
             ui->label_7->setGeometry(640,508,121,31);
             ui->label_3->setGeometry(500,500,51,41);
             ui->label_65->setGeometry(420,500,31,41);


                 QLabel* labels[10]={ui->label_65, ui->label_3, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                     ui->label_61, ui->size_label_4};
                 for (int i = 0; i < 10; i++) {
                     labels[i]->setVisible(1);
                 }


             ui->line_4->setGeometry(230,490,101,20);
             ui->line_5->setGeometry(240,485,20,71);

             ui->table_matrix_op1_2->setGeometry(220,480,122,82);

        }

        //for matrix 3x3
        if(ui->table_matrix_op1->rowCount() == 3){
            ui->table_matrix_op1_4->setColumnCount(2);
            ui->table_matrix_op1_4->setRowCount(2);

            ui->table_matrix_op1_2->setGeometry(200,460,182,122);
            ui->table_matrix_op1_4->setGeometry(510,480,122,82);

            //set values on matrix_op1
            for (int i =0; i<ui->table_matrix_op1->rowCount() ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount() ;j++) {
                    QString s = ui->table_matrix_op1->item(i, j)->text();
                    matrix_op1(i, j) = s.toDouble();
                }
            }

            //set values on table_matrix_op1_4
            for (int i =0; i<ui->table_matrix_op1->rowCount()-1 ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount()-1 ;j++) {
                    QString val = QString::number(matrix_op1.subMatrix(0,0)(i,j));
                    ui->table_matrix_op1_4->setItem(i,j,new QTableWidgetItem(val));
                    ui->table_matrix_op1_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }

            //seting labels and tabels geometry and visibility
            ui->label_7->setText(QString::number(matrix_op1.subMatrix(0,0).det()));
            ui->minor_label->setGeometry(180,698,351,31);
            ui->minor_label->setText("(" + ui->table_matrix_op1_4->item(0,0)->text() + " x " + ui->table_matrix_op1_4->item(1,1)->text() + ") - " + "(" + ui->table_matrix_op1_4->item(0,1)->text() + " x " + ui->table_matrix_op1_4->item(1,0)->text() + ")");
            ui->minor_label->setVisible(1);
            ui->size_label_4->setGeometry(115,528,31,16);
            ui->size_label_5->setGeometry(115,718,31,16);
            ui->label_61->setGeometry(80,500,101,41);
            ui->label_61->setText("M  =");
            ui->label_18->setGeometry(160,440,51,161);
            ui->label_18->setText("|");
            ui->label_17->setGeometry(370,440,51,161);
            ui->label_17->setText("|");
            ui->label_66->setGeometry(470,440,51,161);
            ui->label_66->setText("|");
            ui->label_67->setGeometry(620,440,51,161);
            ui->label_67->setText("|");
            ui->label_70->setGeometry(80,690,101,41);
            ui->label_61->setText("M  =");
            ui->label_73->setGeometry(530,690,31,41);
            ui->label_7->setGeometry(580,698,121,31);
            ui->label_65->setGeometry(430,500,31,41);
            ui->minor_label->setGeometry(180,698,351,31);

            QLabel* labels[12]={ui->label_65, ui->label_70, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                ui->label_61, ui->size_label_4, ui->size_label_5, ui->minor_label};
            for (int i = 0; i < 12; i++) {
                labels[i]->setVisible(1);
            }

            ui->line_4->setGeometry(225,470,131,20);
            ui->line_5->setGeometry(220,470,20,101);

            ui->table_matrix_op1_4->setVisible(1);
        }
        ui->label_16->setVisible(1);
        ui->line_4->setVisible(1);
        ui->line_5->setVisible(1);
        ui->table_matrix_op1_2->setVisible(1);
    }
}

//minor_12
void MainWindow::on_minor_button_12_released()
{
    int minor_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   minor_flag = 0;
                   ui->table_matrix_op1_2->setVisible(0);
                   this->visible_minor_2(0);
                }
            }
        }
    }

    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            ui->table_matrix_op1_2->item(i,j)->setText(ui->table_matrix_op1->item(i, j)->text());
            ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->label_3->setText(ui->table_matrix_op1->item(1, 0)->text());
    ui->label_7->setText(ui->table_matrix_op1->item(1, 0)->text());

    ui->size_label_4->setText("12");
    ui->size_label_5->setText("12");
    if(minor_flag){
        //for matrix 2x2
        if(ui->table_matrix_op1->rowCount() == 2){
             ui->size_label_4->setGeometry(115,528,31,16);
             ui->label_61->setGeometry(80,500,101,41);
             ui->label_61->setText("M  =");
             ui->label_18->setGeometry(160,440,51,161);
             ui->label_18->setText("|");
             ui->label_17->setGeometry(350,440,51,161);
             ui->label_17->setText("|");
             ui->label_66->setGeometry(470,485,21,71);
             ui->label_66->setText("|");
             ui->label_67->setGeometry(560,485,21,71);
             ui->label_67->setText("|");
             ui->label_73->setGeometry(590,500,31,41);
             ui->label_7->setGeometry(640,508,121,31);
             ui->label_3->setGeometry(500,500,51,41);
             ui->label_65->setGeometry(420,500,31,41);

             QLabel* labels[10]={ui->label_65, ui->label_3, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                 ui->label_61, ui->size_label_4};
             for (int i = 0; i < 10; i++) {
                 labels[i]->setVisible(1);
             }

             ui->line_4->setVisible(1);
             ui->line_5->setVisible(1);
             ui->line_4->setGeometry(230,490,101,20);
             ui->line_5->setGeometry(300,485,20,71);

             ui->table_matrix_op1_2->setGeometry(220,480,122,82);

        }

        //for matrix 3x3
        if(ui->table_matrix_op1->rowCount() == 3){
            ui->table_matrix_op1_4->setColumnCount(2);
            ui->table_matrix_op1_4->setRowCount(2);

            ui->table_matrix_op1_2->setGeometry(200,460,182,122);
            ui->table_matrix_op1_4->setGeometry(510,480,122,82);

            //set values on matrix_op1
            for (int i =0; i<ui->table_matrix_op1->rowCount() ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount() ;j++) {
                    QString s = ui->table_matrix_op1->item(i, j)->text();
                    matrix_op1(i, j) = s.toDouble();
                }
            }

            //set values on table_matrix_op1_4
            for (int i =0; i<ui->table_matrix_op1->rowCount()-1 ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount()-1 ;j++) {
                    QString val = QString::number(matrix_op1.subMatrix(0,1)(i,j));
                    ui->table_matrix_op1_4->setItem(i,j,new QTableWidgetItem(val));
                    ui->table_matrix_op1_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }

            //seting labels and tabels geometry and visibility
            ui->label_7->setText(QString::number(matrix_op1.subMatrix(0,1).det()));
            ui->minor_label->setGeometry(180,698,351,31);
            ui->minor_label->setText("(" + ui->table_matrix_op1_4->item(0,0)->text() + " x " + ui->table_matrix_op1_4->item(1,1)->text() + ") - " + "(" + ui->table_matrix_op1_4->item(0,1)->text() + " x " + ui->table_matrix_op1_4->item(1,0)->text() + ")");
            ui->minor_label->setVisible(1);
            ui->size_label_4->setGeometry(115,528,31,16);
            ui->size_label_5->setGeometry(115,718,31,16);
            ui->label_61->setGeometry(80,500,101,41);
            ui->label_61->setText("M  =");
            ui->label_18->setGeometry(160,440,51,161);
            ui->label_18->setText("|");
            ui->label_17->setGeometry(370,440,51,161);
            ui->label_17->setText("|");
            ui->label_66->setGeometry(470,440,51,161);
            ui->label_66->setText("|");
            ui->label_67->setGeometry(620,440,51,161);
            ui->label_67->setText("|");
            ui->label_70->setGeometry(80,690,101,41);
            ui->label_61->setText("M  =");
            ui->label_73->setGeometry(530,690,31,41);
            ui->label_7->setGeometry(580,698,121,31);
            ui->label_65->setGeometry(430,500,31,41);
            ui->minor_label->setGeometry(180,698,351,31);

            QLabel* labels[12]={ui->label_65, ui->label_70, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                ui->label_61, ui->size_label_4, ui->size_label_5, ui->minor_label};
            for (int i = 0; i < 12; i++) {
                labels[i]->setVisible(1);
            }

            ui->line_4->setGeometry(225,470,131,20);
            ui->line_5->setGeometry(280,470,20,101);

            ui->table_matrix_op1_4->setVisible(1);
        }

        ui->label_16->setVisible(1);
        ui->line_4->setVisible(1);
        ui->line_5->setVisible(1);
        ui->table_matrix_op1_2->setVisible(1);
    }
}

//minor_21
void MainWindow::on_minor_button_21_released()
{
    int minor_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   minor_flag = 0;
                   ui->table_matrix_op1_2->setVisible(0);
                   this->visible_minor_2(0);
                }
            }
        }
    }

    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            ui->table_matrix_op1_2->item(i,j)->setText(ui->table_matrix_op1->item(i, j)->text());
            ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->label_3->setText(ui->table_matrix_op1->item(0, 1)->text());
    ui->label_7->setText(ui->table_matrix_op1->item(0, 1)->text());

    ui->size_label_4->setText("21");
    ui->size_label_5->setText("21");

    if(minor_flag){
        //for matrix 2x2
        if(ui->table_matrix_op1->rowCount() == 2){
             ui->size_label_4->setGeometry(115,528,31,16);
             ui->label_61->setGeometry(80,500,101,41);
             ui->label_61->setText("M  =");
             ui->label_18->setGeometry(160,440,51,161);
             ui->label_18->setText("|");
             ui->label_17->setGeometry(350,440,51,161);
             ui->label_17->setText("|");
             ui->label_66->setGeometry(470,485,21,71);
             ui->label_66->setText("|");
             ui->label_67->setGeometry(560,485,21,71);
             ui->label_67->setText("|");
             ui->label_73->setGeometry(590,500,31,41);
             ui->label_7->setGeometry(640,508,121,31);
             ui->label_3->setGeometry(500,500,51,41);
             ui->label_65->setGeometry(420,500,31,41);

             QLabel* labels[10]={ui->label_65, ui->label_3, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                 ui->label_61, ui->size_label_4};
             for (int i = 0; i < 10; i++) {
                 labels[i]->setVisible(1);
             }

             ui->line_4->setVisible(1);
             ui->line_5->setVisible(1);
             ui->line_4->setGeometry(230,530,101,20);
             ui->line_5->setGeometry(240,485,20,71);

             ui->table_matrix_op1_2->setGeometry(220,480,122,82);

        }

        //for matrix 3x3
        if(ui->table_matrix_op1->rowCount() == 3){
            ui->table_matrix_op1_4->setColumnCount(2);
            ui->table_matrix_op1_4->setRowCount(2);

            ui->table_matrix_op1_2->setGeometry(200,460,182,122);
            ui->table_matrix_op1_4->setGeometry(510,480,122,82);

            //set values on matrix_op1
            for (int i =0; i<ui->table_matrix_op1->rowCount() ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount() ;j++) {
                    QString s = ui->table_matrix_op1->item(i, j)->text();
                    matrix_op1(i, j) = s.toDouble();
                }
            }

            //set values on table_matrix_op1_4
            for (int i =0; i<ui->table_matrix_op1->rowCount()-1 ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount()-1 ;j++) {
                    QString val = QString::number(matrix_op1.subMatrix(1,0)(i,j));
                    ui->table_matrix_op1_4->setItem(i,j,new QTableWidgetItem(val));
                    ui->table_matrix_op1_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }

            //seting labels and tabels geometry and visibility
            ui->label_7->setText(QString::number(matrix_op1.subMatrix(1,0).det()));
            ui->minor_label->setGeometry(180,698,351,31);
            ui->minor_label->setText("(" + ui->table_matrix_op1_4->item(0,0)->text() + " x " + ui->table_matrix_op1_4->item(1,1)->text() + ") - " + "(" + ui->table_matrix_op1_4->item(0,1)->text() + " x " + ui->table_matrix_op1_4->item(1,0)->text() + ")");
            ui->minor_label->setVisible(1);
            ui->size_label_4->setGeometry(115,528,31,16);
            ui->size_label_5->setGeometry(115,718,31,16);
            ui->label_61->setGeometry(80,500,101,41);
            ui->label_61->setText("M  =");
            ui->label_18->setGeometry(160,440,51,161);
            ui->label_18->setText("|");
            ui->label_17->setGeometry(370,440,51,161);
            ui->label_17->setText("|");
            ui->label_66->setGeometry(470,440,51,161);
            ui->label_66->setText("|");
            ui->label_67->setGeometry(620,440,51,161);
            ui->label_67->setText("|");
            ui->label_70->setGeometry(80,690,101,41);
            ui->label_61->setText("M  =");
            ui->label_73->setGeometry(530,690,31,41);
            ui->label_7->setGeometry(580,698,121,31);
            ui->label_65->setGeometry(430,500,31,41);
            ui->minor_label->setGeometry(180,698,351,31);

            QLabel* labels[12]={ui->label_65, ui->label_70, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                ui->label_61, ui->size_label_4, ui->size_label_5, ui->minor_label};
            for (int i = 0; i < 12; i++) {
                labels[i]->setVisible(1);
            }

            ui->line_4->setGeometry(225,510,131,20);
            ui->line_5->setGeometry(220,470,20,101);

            ui->table_matrix_op1_4->setVisible(1);
        }

        ui->label_16->setVisible(1);
        ui->line_4->setVisible(1);
        ui->line_5->setVisible(1);
        ui->table_matrix_op1_2->setVisible(1);
    }
}

//minor_22
void MainWindow::on_minor_button_22_released()
{
    int minor_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   minor_flag = 0;
                   ui->table_matrix_op1_2->setVisible(0);
                   this->visible_minor_2(0);
                }
            }
        }
    }

    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            ui->table_matrix_op1_2->item(i,j)->setText(ui->table_matrix_op1->item(i, j)->text());
            ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->size_label_4->setText("22");
    ui->size_label_5->setText("22");

    if(minor_flag){
        //for matrix 2x2
        if(ui->table_matrix_op1->rowCount() == 2){
             ui->label_3->setText(ui->table_matrix_op1->item(0, 0)->text());
             ui->label_7->setText(ui->table_matrix_op1->item(0, 0)->text());
             ui->size_label_4->setGeometry(115,528,31,16);
             ui->label_61->setGeometry(80,500,101,41);
             ui->label_61->setText("M  =");
             ui->label_18->setGeometry(160,440,51,161);
             ui->label_18->setText("|");
             ui->label_17->setGeometry(350,440,51,161);
             ui->label_17->setText("|");
             ui->label_66->setGeometry(470,485,21,71);
             ui->label_66->setText("|");
             ui->label_67->setGeometry(560,485,21,71);
             ui->label_67->setText("|");
             ui->label_73->setGeometry(590,500,31,41);
             ui->label_7->setGeometry(640,508,121,31);
             ui->label_3->setGeometry(500,500,51,41);
             ui->label_65->setGeometry(420,500,31,41);

             QLabel* labels[10]={ui->label_65, ui->label_3, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                 ui->label_61, ui->size_label_4};
             for (int i = 0; i < 10; i++) {
                 labels[i]->setVisible(1);
             }

             ui->line_4->setGeometry(230,530,101,20);
             ui->line_5->setGeometry(300,485,20,71);

             ui->table_matrix_op1_2->setGeometry(220,480,122,82);

        }

        //for matrix 3x3
        if(ui->table_matrix_op1->rowCount() == 3){
            ui->table_matrix_op1_4->setColumnCount(2);
            ui->table_matrix_op1_4->setRowCount(2);

            ui->table_matrix_op1_2->setGeometry(200,460,182,122);
            ui->table_matrix_op1_4->setGeometry(510,480,122,82);

            //set values on matrix_op1
            for (int i =0; i<ui->table_matrix_op1->rowCount() ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount() ;j++) {
                    QString s = ui->table_matrix_op1->item(i, j)->text();
                    matrix_op1(i, j) = s.toDouble();
                }
            }

            //set values on table_matrix_op1_4
            for (int i =0; i<ui->table_matrix_op1->rowCount()-1 ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount()-1 ;j++) {
                    QString val = QString::number(matrix_op1.subMatrix(1,1)(i,j));
                    ui->table_matrix_op1_4->setItem(i,j,new QTableWidgetItem(val));
                    ui->table_matrix_op1_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }

            //seting labels and tabels geometry and visibility
            ui->label_7->setText(QString::number(matrix_op1.subMatrix(1,1).det()));
            ui->minor_label->setGeometry(180,698,351,31);
            ui->minor_label->setText("(" + ui->table_matrix_op1_4->item(0,0)->text() + " x " + ui->table_matrix_op1_4->item(1,1)->text() + ") - " + "(" + ui->table_matrix_op1_4->item(0,1)->text() + " x " + ui->table_matrix_op1_4->item(1,0)->text() + ")");
            ui->minor_label->setVisible(1);
            ui->size_label_4->setGeometry(115,528,31,16);
            ui->size_label_5->setGeometry(115,718,31,16);
            ui->label_61->setGeometry(80,500,101,41);
            ui->label_61->setText("M  =");
            ui->label_18->setGeometry(160,440,51,161);
            ui->label_18->setText("|");
            ui->label_17->setGeometry(370,440,51,161);
            ui->label_17->setText("|");
            ui->label_66->setGeometry(470,440,51,161);
            ui->label_66->setText("|");
            ui->label_67->setGeometry(620,440,51,161);
            ui->label_67->setText("|");
            ui->label_70->setGeometry(80,690,101,41);
            ui->label_61->setText("M  =");
            ui->label_73->setGeometry(530,690,31,41);
            ui->label_7->setGeometry(580,698,121,31);
            ui->label_65->setGeometry(430,500,31,41);
            ui->minor_label->setGeometry(180,698,351,31);

            QLabel* labels[12]={ui->label_65, ui->label_70, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                ui->label_61, ui->size_label_4, ui->size_label_5, ui->minor_label};
            for (int i = 0; i < 12; i++) {
                labels[i]->setVisible(1);
            }

            ui->line_4->setGeometry(225,510,131,20);
            ui->line_5->setGeometry(280,470,20,101);

            ui->table_matrix_op1_4->setVisible(1);
        }

        ui->label_16->setVisible(1);
        ui->line_4->setVisible(1);
        ui->line_5->setVisible(1);
        ui->table_matrix_op1_2->setVisible(1);
    }
}

void MainWindow::on_minor_button_13_released()
{
    int minor_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   minor_flag = 0;
                   ui->table_matrix_op1_2->setVisible(0);
                   this->visible_minor_2(0);
                }
            }
        }
    }

    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            ui->table_matrix_op1_2->item(i,j)->setText(ui->table_matrix_op1->item(i, j)->text());
            ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->size_label_4->setText("13");
    ui->size_label_5->setText("13");

    if(minor_flag){
        //for matrix 3x3
        if(ui->table_matrix_op1->rowCount() == 3){
            ui->table_matrix_op1_4->setColumnCount(2);
            ui->table_matrix_op1_4->setRowCount(2);

            ui->table_matrix_op1_2->setGeometry(200,460,182,122);
            ui->table_matrix_op1_4->setGeometry(510,480,122,82);

            //set values on matrix_op1
            for (int i =0; i<ui->table_matrix_op1->rowCount() ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount() ;j++) {
                    QString s = ui->table_matrix_op1->item(i, j)->text();
                    matrix_op1(i, j) = s.toDouble();
                }
            }

            //set values on table_matrix_op1_4
            for (int i =0; i<ui->table_matrix_op1->rowCount()-1 ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount()-1 ;j++) {
                    QString val = QString::number(matrix_op1.subMatrix(0,2)(i,j));
                    ui->table_matrix_op1_4->setItem(i,j,new QTableWidgetItem(val));
                    ui->table_matrix_op1_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }

            //seting labels and tabels geometry and visibility
            ui->label_7->setText(QString::number(matrix_op1.subMatrix(0,2).det()));
            ui->minor_label->setGeometry(180,698,351,31);
            ui->minor_label->setText("(" + ui->table_matrix_op1_4->item(0,0)->text() + " x " + ui->table_matrix_op1_4->item(1,1)->text() + ") - " + "(" + ui->table_matrix_op1_4->item(0,1)->text() + " x " + ui->table_matrix_op1_4->item(1,0)->text() + ")");
            ui->minor_label->setVisible(1);
            ui->size_label_4->setGeometry(115,528,31,16);
            ui->size_label_5->setGeometry(115,718,31,16);
            ui->label_61->setGeometry(80,500,101,41);
            ui->label_61->setText("M  =");
            ui->label_18->setGeometry(160,440,51,161);
            ui->label_18->setText("|");
            ui->label_17->setGeometry(370,440,51,161);
            ui->label_17->setText("|");
            ui->label_66->setGeometry(470,440,51,161);
            ui->label_66->setText("|");
            ui->label_67->setGeometry(620,440,51,161);
            ui->label_67->setText("|");
            ui->label_70->setGeometry(80,690,101,41);
            ui->label_61->setText("M  =");
            ui->label_73->setGeometry(530,690,31,41);
            ui->label_7->setGeometry(580,698,121,31);
            ui->label_65->setGeometry(430,500,31,41);
            ui->minor_label->setGeometry(180,698,351,31);

            QLabel* labels[12]={ui->label_65, ui->label_70, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                ui->label_61, ui->size_label_4, ui->size_label_5, ui->minor_label};
            for (int i = 0; i < 12; i++) {
                labels[i]->setVisible(1);
            }

            ui->line_4->setGeometry(225,470,131,20);
            ui->line_5->setGeometry(340,470,20,101);

            ui->table_matrix_op1_4->setVisible(1);
        }

        ui->label_16->setVisible(1);
        ui->line_4->setVisible(1);
        ui->line_5->setVisible(1);
        ui->table_matrix_op1_2->setVisible(1);
    }

}

void MainWindow::on_minor_button_23_released()
{
    int minor_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   minor_flag = 0;
                   ui->table_matrix_op1_2->setVisible(0);
                   this->visible_minor_2(0);
                }
            }
        }
    }

    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            ui->table_matrix_op1_2->item(i,j)->setText(ui->table_matrix_op1->item(i, j)->text());
            ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->size_label_4->setText("23");
    ui->size_label_5->setText("23");

    if(minor_flag){
        //for matrix 3x3
        if(ui->table_matrix_op1->rowCount() == 3){
            ui->table_matrix_op1_4->setColumnCount(2);
            ui->table_matrix_op1_4->setRowCount(2);

            ui->table_matrix_op1_2->setGeometry(200,460,182,122);
            ui->table_matrix_op1_4->setGeometry(510,480,122,82);

            //set values on matrix_op1
            for (int i =0; i<ui->table_matrix_op1->rowCount() ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount() ;j++) {
                    QString s = ui->table_matrix_op1->item(i, j)->text();
                    matrix_op1(i, j) = s.toDouble();
                }
            }

            //set values on table_matrix_op1_4
            for (int i =0; i<ui->table_matrix_op1->rowCount()-1 ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount()-1 ;j++) {
                    QString val = QString::number(matrix_op1.subMatrix(1,2)(i,j));
                    ui->table_matrix_op1_4->setItem(i,j,new QTableWidgetItem(val));
                    ui->table_matrix_op1_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }

            //seting labels and tabels geometry and visibility
            ui->label_7->setText(QString::number(matrix_op1.subMatrix(1,2).det()));
            ui->minor_label->setGeometry(180,698,351,31);
            ui->minor_label->setText("(" + ui->table_matrix_op1_4->item(0,0)->text() + " x " + ui->table_matrix_op1_4->item(1,1)->text() + ") - " + "(" + ui->table_matrix_op1_4->item(0,1)->text() + " x " + ui->table_matrix_op1_4->item(1,0)->text() + ")");
            ui->minor_label->setVisible(1);
            ui->size_label_4->setGeometry(115,528,31,16);
            ui->size_label_5->setGeometry(115,718,31,16);
            ui->label_61->setGeometry(80,500,101,41);
            ui->label_61->setText("M  =");
            ui->label_18->setGeometry(160,440,51,161);
            ui->label_18->setText("|");
            ui->label_17->setGeometry(370,440,51,161);
            ui->label_17->setText("|");
            ui->label_66->setGeometry(470,440,51,161);
            ui->label_66->setText("|");
            ui->label_67->setGeometry(620,440,51,161);
            ui->label_67->setText("|");
            ui->label_70->setGeometry(80,690,101,41);
            ui->label_61->setText("M  =");
            ui->label_73->setGeometry(530,690,31,41);
            ui->label_7->setGeometry(580,698,121,31);
            ui->label_65->setGeometry(430,500,31,41);
            ui->minor_label->setGeometry(180,698,351,31);

            QLabel* labels[12]={ui->label_65, ui->label_70, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                ui->label_61, ui->size_label_4, ui->size_label_5, ui->minor_label};
            for (int i = 0; i < 12; i++) {
                labels[i]->setVisible(1);
            }

            ui->line_4->setGeometry(225,510,131,20);
            ui->line_5->setGeometry(340,470,20,101);

            ui->table_matrix_op1_4->setVisible(1);
        }

        ui->label_16->setVisible(1);
        ui->line_4->setVisible(1);
        ui->line_5->setVisible(1);
        ui->table_matrix_op1_2->setVisible(1);
    }
}

void MainWindow::on_minor_button_31_released()
{
    int minor_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   minor_flag = 0;
                   ui->table_matrix_op1_2->setVisible(0);
                   this->visible_minor_2(0);
                }
            }
        }
    }

    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            ui->table_matrix_op1_2->item(i,j)->setText(ui->table_matrix_op1->item(i, j)->text());
            ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->size_label_4->setText("31");
    ui->size_label_5->setText("31");

    if(minor_flag){
        //for matrix 3x3
        if(ui->table_matrix_op1->rowCount() == 3){
            ui->table_matrix_op1_4->setColumnCount(2);
            ui->table_matrix_op1_4->setRowCount(2);

            ui->table_matrix_op1_2->setGeometry(200,460,182,122);
            ui->table_matrix_op1_4->setGeometry(510,480,122,82);

            //set values on matrix_op1
            for (int i =0; i<ui->table_matrix_op1->rowCount() ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount() ;j++) {
                    QString s = ui->table_matrix_op1->item(i, j)->text();
                    matrix_op1(i, j) = s.toDouble();
                }
            }

            //set values on table_matrix_op1_4
            for (int i =0; i<ui->table_matrix_op1->rowCount()-1 ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount()-1 ;j++) {
                    QString val = QString::number(matrix_op1.subMatrix(2,0)(i,j));
                    ui->table_matrix_op1_4->setItem(i,j,new QTableWidgetItem(val));
                    ui->table_matrix_op1_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }

            //seting labels and tabels geometry and visibility
            ui->label_7->setText(QString::number(matrix_op1.subMatrix(2,0).det()));
            ui->minor_label->setGeometry(180,698,351,31);
            ui->minor_label->setText("(" + ui->table_matrix_op1_4->item(0,0)->text() + " x " + ui->table_matrix_op1_4->item(1,1)->text() + ") - " + "(" + ui->table_matrix_op1_4->item(0,1)->text() + " x " + ui->table_matrix_op1_4->item(1,0)->text() + ")");
            ui->minor_label->setVisible(1);
            ui->size_label_4->setGeometry(115,528,31,16);
            ui->size_label_5->setGeometry(115,718,31,16);
            ui->label_61->setGeometry(80,500,101,41);
            ui->label_61->setText("M  =");
            ui->label_18->setGeometry(160,440,51,161);
            ui->label_18->setText("|");
            ui->label_17->setGeometry(370,440,51,161);
            ui->label_17->setText("|");
            ui->label_66->setGeometry(470,440,51,161);
            ui->label_66->setText("|");
            ui->label_67->setGeometry(620,440,51,161);
            ui->label_67->setText("|");
            ui->label_70->setGeometry(80,690,101,41);
            ui->label_61->setText("M  =");
            ui->label_73->setGeometry(530,690,31,41);
            ui->label_7->setGeometry(580,698,121,31);
            ui->label_65->setGeometry(430,500,31,41);
            ui->minor_label->setGeometry(180,698,351,31);

            QLabel* labels[12]={ui->label_65, ui->label_70, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                ui->label_61, ui->size_label_4, ui->size_label_5, ui->minor_label};
            for (int i = 0; i < 12; i++) {
                labels[i]->setVisible(1);
            }

            ui->line_4->setGeometry(225,550,131,20);
            ui->line_5->setGeometry(220,470,20,101);

            ui->table_matrix_op1_4->setVisible(1);
        }

        ui->label_16->setVisible(1);
        ui->line_4->setVisible(1);
        ui->line_5->setVisible(1);
        ui->table_matrix_op1_2->setVisible(1);
    }
}

void MainWindow::on_minor_button_32_released()
{
    int minor_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   minor_flag = 0;
                   ui->table_matrix_op1_2->setVisible(0);
                   this->visible_minor_2(0);
                }
            }
        }
    }

    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            ui->table_matrix_op1_2->item(i,j)->setText(ui->table_matrix_op1->item(i, j)->text());
            ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->size_label_4->setText("32");
    ui->size_label_5->setText("32");

    if(minor_flag){
        //for matrix 3x3
        if(ui->table_matrix_op1->rowCount() == 3){
            ui->table_matrix_op1_4->setColumnCount(2);
            ui->table_matrix_op1_4->setRowCount(2);

            ui->table_matrix_op1_2->setGeometry(200,460,182,122);
            ui->table_matrix_op1_4->setGeometry(510,480,122,82);

            //set values on matrix_op1
            for (int i =0; i<ui->table_matrix_op1->rowCount() ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount() ;j++) {
                    QString s = ui->table_matrix_op1->item(i, j)->text();
                    matrix_op1(i, j) = s.toDouble();
                }
            }

            //set values on table_matrix_op1_4
            for (int i =0; i<ui->table_matrix_op1->rowCount()-1 ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount()-1 ;j++) {
                    QString val = QString::number(matrix_op1.subMatrix(2,1)(i,j));
                    ui->table_matrix_op1_4->setItem(i,j,new QTableWidgetItem(val));
                    ui->table_matrix_op1_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }

            //seting labels and tabels geometry and visibility
            ui->label_7->setText(QString::number(matrix_op1.subMatrix(2,1).det()));
            ui->minor_label->setGeometry(180,698,351,31);
            ui->minor_label->setText("(" + ui->table_matrix_op1_4->item(0,0)->text() + " x " + ui->table_matrix_op1_4->item(1,1)->text() + ") - " + "(" + ui->table_matrix_op1_4->item(0,1)->text() + " x " + ui->table_matrix_op1_4->item(1,0)->text() + ")");
            ui->minor_label->setVisible(1);
            ui->size_label_4->setGeometry(115,528,31,16);
            ui->size_label_5->setGeometry(115,718,31,16);
            ui->label_61->setGeometry(80,500,101,41);
            ui->label_61->setText("M  =");
            ui->label_18->setGeometry(160,440,51,161);
            ui->label_18->setText("|");
            ui->label_17->setGeometry(370,440,51,161);
            ui->label_17->setText("|");
            ui->label_66->setGeometry(470,440,51,161);
            ui->label_66->setText("|");
            ui->label_67->setGeometry(620,440,51,161);
            ui->label_67->setText("|");
            ui->label_70->setGeometry(80,690,101,41);
            ui->label_61->setText("M  =");
            ui->label_73->setGeometry(530,690,31,41);
            ui->label_7->setGeometry(580,698,121,31);
            ui->label_65->setGeometry(430,500,31,41);
            ui->minor_label->setGeometry(180,698,351,31);

            QLabel* labels[12]={ui->label_65, ui->label_70, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                ui->label_61, ui->size_label_4, ui->size_label_5, ui->minor_label};
            for (int i = 0; i < 12; i++) {
                labels[i]->setVisible(1);
            }

            ui->line_4->setGeometry(225,550,131,20);
            ui->line_5->setGeometry(280,470,20,101);

            ui->table_matrix_op1_4->setVisible(1);
        }

        ui->label_16->setVisible(1);
        ui->line_4->setVisible(1);
        ui->line_5->setVisible(1);
        ui->table_matrix_op1_2->setVisible(1);
    }
}

void MainWindow::on_minor_button_33_released()
{
    int minor_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   minor_flag = 0;
                   ui->table_matrix_op1_2->setVisible(0);
                   this->visible_minor_2(0);
                }
            }
        }
    }

    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            ui->table_matrix_op1_2->item(i,j)->setText(ui->table_matrix_op1->item(i, j)->text());
            ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->size_label_4->setText("33");
    ui->size_label_5->setText("33");

    if(minor_flag){
        //for matrix 3x3
        if(ui->table_matrix_op1->rowCount() == 3){
            ui->table_matrix_op1_4->setColumnCount(2);
            ui->table_matrix_op1_4->setRowCount(2);

            ui->table_matrix_op1_2->setGeometry(200,460,182,122);
            ui->table_matrix_op1_4->setGeometry(510,480,122,82);

            //set values on matrix_op1
            for (int i =0; i<ui->table_matrix_op1->rowCount() ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount() ;j++) {
                    QString s = ui->table_matrix_op1->item(i, j)->text();
                    matrix_op1(i, j) = s.toDouble();
                }
            }

            //set values on table_matrix_op1_4
            for (int i =0; i<ui->table_matrix_op1->rowCount()-1 ;i++) {
                for (int j =0; j<ui->table_matrix_op1->columnCount()-1 ;j++) {
                    QString val = QString::number(matrix_op1.subMatrix(2,2)(i,j));
                    ui->table_matrix_op1_4->setItem(i,j,new QTableWidgetItem(val));
                    ui->table_matrix_op1_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }

            //seting labels and tabels geometry and visibility
            ui->label_7->setText(QString::number(matrix_op1.subMatrix(2,2).det()));
            ui->minor_label->setGeometry(180,698,351,31);
            ui->minor_label->setText("(" + ui->table_matrix_op1_4->item(0,0)->text() + " x " + ui->table_matrix_op1_4->item(1,1)->text() + ") - " + "(" + ui->table_matrix_op1_4->item(0,1)->text() + " x " + ui->table_matrix_op1_4->item(1,0)->text() + ")");
            ui->minor_label->setVisible(1);
            ui->size_label_4->setGeometry(115,528,31,16);
            ui->size_label_5->setGeometry(115,718,31,16);
            ui->label_61->setGeometry(80,500,101,41);
            ui->label_61->setText("M  =");
            ui->label_18->setGeometry(160,440,51,161);
            ui->label_18->setText("|");
            ui->label_17->setGeometry(370,440,51,161);
            ui->label_17->setText("|");
            ui->label_66->setGeometry(470,440,51,161);
            ui->label_66->setText("|");
            ui->label_67->setGeometry(620,440,51,161);
            ui->label_67->setText("|");
            ui->label_70->setGeometry(80,690,101,41);
            ui->label_61->setText("M  =");
            ui->label_73->setGeometry(530,690,31,41);
            ui->label_7->setGeometry(580,698,121,31);
            ui->label_65->setGeometry(430,500,31,41);
            ui->minor_label->setGeometry(180,698,351,31);

            QLabel* labels[12]={ui->label_65, ui->label_70, ui->label_7, ui->label_73, ui->label_67, ui->label_66, ui->label_17, ui->label_18,
                                ui->label_61, ui->size_label_4, ui->size_label_5, ui->minor_label};
            for (int i = 0; i < 12; i++) {
                labels[i]->setVisible(1);
            }

            ui->line_4->setGeometry(225,550,131,20);
            ui->line_5->setGeometry(340,470,20,101);

            ui->table_matrix_op1_4->setVisible(1);
        }

        ui->label_16->setVisible(1);
        ui->line_4->setVisible(1);
        ui->line_5->setVisible(1);
        ui->table_matrix_op1_2->setVisible(1);
    }
}

//matrix determinant
void MainWindow::on_pushButton_matrix_det_released()
{
    this->visible_trans(0);
    this->visible_multi(0);
    this->visible_6(0);
    this->visible_minor(0);
    this->visible_minor_2(0);
    this->visible_algebraic(0);

    QFont font("Arial", 18, QFont::Bold) ;
    ui->label_61->setFont(font);
    ui->label_70->setFont(font);

    int det_flag = 1;

    //for2x2
    if(ui->table_matrix_op1->rowCount() == 2){
        ui->label_16->setText("Obliczanie wyznacznika:");
        ui->table_matrix_op1_2->setColumnCount(2);
        ui->table_matrix_op1_2->setRowCount(2);
        ui->table_matrix_op1_2->setGeometry(230,480,122,82);
    }

    //for3x3
    if(ui->table_matrix_op1->rowCount() == 3){
        ui->label_16->setText("Obliczanie wyznacznika (metodą Sarussa):");
        ui->table_matrix_op1_2->setColumnCount(3);
        ui->table_matrix_op1_2->setRowCount(3);
        ui->table_matrix_op1_2->setGeometry(200,460,182,122);

    }

    matrix_op1.setH(ui->table_matrix_op1->rowCount());
    matrix_op1.setW(ui->table_matrix_op1->columnCount());

    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   det_flag = 0;
                }
            }
            matrix_op1(i, j) = s.toDouble();
        }
    }
    //setting values on tables
    for (int i = 0; i<ui->table_matrix_op1->rowCount(); i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount(); j++) {
                //Set values on tables
                ui->table_matrix_op1_2->setItem(i,j,new QTableWidgetItem(ui->table_matrix_op1->item(i, j)->text()));
                ui->table_matrix_op1_2->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    //set determinant result on label
    ui->label_7->setText(QString::number(matrix_op1.det()));

    if(det_flag){
        ui->table_matrix_op1_2->setVisible(1);
        ui->label_16->setVisible(1);
        //for2x2
        if(ui->table_matrix_op1->rowCount() == 2){
            //Matrix A cells colors
            ui->table_matrix_op1_2->item(0,0)->setBackgroundColor(Qt::darkBlue);
            ui->table_matrix_op1_2->item(0,1)->setBackgroundColor(Qt::darkRed);
            ui->table_matrix_op1_2->item(1,0)->setBackgroundColor(QColor(0, 100, 0));
            ui->table_matrix_op1_2->item(1,1)->setBackgroundColor(QColor(151, 117, 0));

            //Text Color
            ui->table_matrix_op1_2->item(0,0)->setTextColor(Qt::white);
            ui->table_matrix_op1_2->item(0,1)->setTextColor(Qt::white);
            ui->table_matrix_op1_2->item(1,0)->setTextColor(Qt::white);
            ui->table_matrix_op1_2->item(1,1)->setTextColor(Qt::white);

            //for matrix 2x2
            QLabel* lab_A2[2][2]={{ui->a_00_4, ui->a_01_6},
                                    {ui->a_10_4, ui->a_11_6}};


            //Set value on labels (2x2)
            for (int i = 0;i < ui->table_matrix_op1_2->rowCount();i++) {
                for (int j = 0;j < ui->table_matrix_op1_2->columnCount();j++) {
                   lab_A2[i][j]->setText(ui->table_matrix_op1_2->item(i,j)->text());
                }
            }

            //Set labels' geometry
            ui->a_00_4->setGeometry(170,685,40,20);
            ui->a_01_6->setGeometry(350,685,40,20);
            ui->a_10_4->setGeometry(296,685,40,20);
            ui->a_11_6->setGeometry(224,685,40,20);
            ui->sign_det_1->setGeometry(210,685,16,21);
            ui->sign_det_2->setGeometry(336,685,16,21);
            ui->sign_det_9->setGeometry(272,685,16,21);
            ui->label_7-> setGeometry(440,677,71,31);
            ui->label_73-> setGeometry(400,670,31,41);
            ui->label_17->setGeometry(370,440,51,161);
            ui->label_17->setText("|");
            ui->label_18->setGeometry(160,440,51,161);
            ui->label_18->setText("|");
            ui->label_61->setGeometry(30,500,141,41);
            ui->label_61->setText("det(A) =");
            ui->label_70->setGeometry(30,674,141,41);
            ui->label_70->setText("det(A) =");

            //Set lables visible
            QLabel* labels[13]={ui->label_61, ui->label_70, ui->label_17, ui->label_18, ui->label_73, ui->label_7, ui->a_00_4, ui->a_01_6,
                                ui->a_10_4, ui->a_11_6, ui->sign_det_1, ui->sign_det_2, ui->sign_det_9};
            for (int i = 0; i < 13; i++) {
                labels[i]->setVisible(1);
            }
        }

        //for3x3
        if(ui->table_matrix_op1->rowCount() == 3){
            //Matrix A cells colors
            ui->table_matrix_op1_2->item(0,0)->setBackgroundColor(Qt::darkBlue);
            ui->table_matrix_op1_2->item(0,1)->setBackgroundColor(Qt::darkRed);
            ui->table_matrix_op1_2->item(0,2)->setBackgroundColor(Qt::darkMagenta);
            ui->table_matrix_op1_2->item(1,0)->setBackgroundColor(QColor(0, 100, 0));
            ui->table_matrix_op1_2->item(1,1)->setBackgroundColor(QColor(151, 117, 0));
            ui->table_matrix_op1_2->item(1,2)->setBackgroundColor(Qt::darkYellow);
            ui->table_matrix_op1_2->item(2,0)->setBackgroundColor(Qt::darkGray);
            ui->table_matrix_op1_2->item(2,1)->setBackgroundColor(QColor(0, 102, 102));
            ui->table_matrix_op1_2->item(2,2)->setBackgroundColor(Qt::black);

            //Text Color
            ui->table_matrix_op1_2->item(0,0)->setTextColor(Qt::white);
            ui->table_matrix_op1_2->item(0,1)->setTextColor(Qt::white);
            ui->table_matrix_op1_2->item(0,2)->setTextColor(Qt::white);
            ui->table_matrix_op1_2->item(1,0)->setTextColor(Qt::white);
            ui->table_matrix_op1_2->item(1,1)->setTextColor(Qt::white);
            ui->table_matrix_op1_2->item(1,2)->setTextColor(Qt::white);
            ui->table_matrix_op1_2->item(2,0)->setTextColor(Qt::white);
            ui->table_matrix_op1_2->item(2,1)->setTextColor(Qt::white);
            ui->table_matrix_op1_2->item(2,2)->setTextColor(Qt::white);

            //Set values on labels
            //for matrix 3x3
            QLabel* lab_A3[3][3]={{ui->a_00_4, ui->a_01_4, ui->a_02_4},
                                    {ui->a_10_4, ui->a_11_4, ui->a_12_4},
                                    {ui->a_20_4, ui->a_21_4, ui->a_22_4}};
            QLabel* lab_A3_2[3][3]={{ui->a_00_5, ui->a_01_5, ui->a_02_5},
                                    {ui->a_10_5, ui->a_11_5, ui->a_12_5},
                                    {ui->a_20_5, ui->a_21_5, ui->a_22_5}};

            //Set value on labels (3x3)
            for (int i = 0;i < ui->table_matrix_op1_2->rowCount();i++) {
                for (int j = 0;j < ui->table_matrix_op1_2->columnCount();j++) {
                  lab_A3[i][j]->setText(ui->table_matrix_op1_2->item(i,j)->text());
                  lab_A3_2[i][j]->setText(ui->table_matrix_op1_2->item(i,j)->text());
                }
            }

            //Set labels' geometry
            ui->label_7->setGeometry(740,723,121,31);
            ui->label_17->setGeometry(370,440,51,161);
            ui->label_17->setText("|");
            ui->label_18->setGeometry(160,440,51,161);
            ui->label_18->setText("|");
            ui->label_61->setGeometry(30,500,141,41);
            ui->label_61->setText("det(A) =");
            ui->label_70->setGeometry(30,674,141,41);
            ui->label_70->setText("det(A) =");
            ui->label_73->setGeometry(695,715,31,41);

            ui->a_00_4->setGeometry(170,685,40,20);
            ui->a_01_4->setGeometry(586,685,40,20);
            ui->a_02_4->setGeometry(458,685,40,20);
            ui->a_10_4->setGeometry(350,685,40,20);
            ui->a_11_4->setGeometry(224,685,40,20);
            ui->a_12_4->setGeometry(640,685,40,20);
            ui->a_20_4->setGeometry(532,685,40,20);
            ui->a_21_4->setGeometry(404,685,40,20);
            ui->a_22_4->setGeometry(278,685,40,20);

            ui->a_00_5->setGeometry(350,730,40,20);
            ui->a_01_5->setGeometry(586,730,40,20);
            ui->a_02_5->setGeometry(278,730,40,20);
            ui->a_10_5->setGeometry(530,730,40,20);
            ui->a_11_5->setGeometry(224,730,40,20);
            ui->a_12_5->setGeometry(458,730,40,20);
            ui->a_20_5->setGeometry(170,730,40,20);
            ui->a_21_5->setGeometry(404,730,40,20);
            ui->a_22_5->setGeometry(640,730,40,20);

            ui->sign_det_1->setGeometry(210,685,16,20);
            ui->sign_det_2->setGeometry(264,685,16,20);
            ui->sign_det_3->setGeometry(326,685,16,20);
            ui->sign_det_4->setGeometry(390,685,16,20);
            ui->sign_det_5->setGeometry(444,685,16,20);
            ui->sign_det_6->setGeometry(508,685,16,20);
            ui->sign_det_7->setGeometry(572,685,16,20);
            ui->sign_det_8->setGeometry(626,685,16,20);
            ui->sign_det_9->setGeometry(690,685,16,20);

            ui->sign_det_10->setGeometry(326,730,16,20);
            ui->sign_det_11->setGeometry(508,730,16,20);
            ui->sign_det_12->setGeometry(626,730,16,20);
            ui->sign_det_13->setGeometry(264,730,16,20);
            ui->sign_det_14->setGeometry(444,730,16,20);
            ui->sign_det_15->setGeometry(572,730,16,20);
            ui->sign_det_16->setGeometry(210,730,16,20);
            ui->sign_det_17->setGeometry(390,730,16,20);

            //Set lables visible
            QLabel* labels[41]={ui->label_61, ui->label_70, ui->label_17, ui->label_18, ui->label_73, ui->label_7, ui->a_00_4, ui->a_01_4, ui->a_02_4,
                                ui->a_10_4, ui->a_11_4, ui->a_12_4, ui->a_20_4, ui->a_21_4, ui->a_22_4, ui->a_00_5, ui->a_01_5, ui->a_02_5,
                                ui->a_10_5, ui->a_11_5, ui->a_12_5, ui->a_20_5, ui->a_21_5, ui->a_22_5, ui->sign_det_1, ui->sign_det_2, ui->sign_det_3,
                                ui->sign_det_4, ui->sign_det_5, ui->sign_det_6, ui->sign_det_7, ui->sign_det_8, ui->sign_det_9, ui->sign_det_10,
                                ui->sign_det_11, ui->sign_det_12, ui->sign_det_13, ui->sign_det_14, ui->sign_det_15, ui->sign_det_16, ui->sign_det_17};
            for (int i = 0; i < 41; i++) {
                labels[i]->setVisible(1);
            }

        }
    }
}

//Matrix Trace
void MainWindow::on_pushButton_matrix_trace_released()
{
    this->visible_trans(0);
    this->visible_multi(0);
    this->visible_6(0);
    this->visible_minor(0);
    this->visible_minor_2(0);
    this->visible_algebraic(0);

    QFont font("Arial", 18, QFont::Bold);
    QFont font2("Arial", 24, QFont::Bold);
    ui->label_61->setFont(font);
    ui->label_70->setFont(font2);

    int trace_flag = 1;

    //For 2x2 Matrix
    if(ui->table_matrix_op1->rowCount() == 2){
        ui->table_matrix_op1_4->setColumnCount(2);
        ui->table_matrix_op1_4->setRowCount(2);
        ui->table_matrix_op1_4->setGeometry(340,480,122,82);
    }

    //For 3x3 Matrix
    if(ui->table_matrix_op1->rowCount() == 3){
        ui->table_matrix_op1_4->setColumnCount(3);
        ui->table_matrix_op1_4->setRowCount(3);
        ui->table_matrix_op1_4->setGeometry(330,460,182,122);

    }

    matrix_op1.setH(ui->table_matrix_op1->rowCount());
    matrix_op1.setW(ui->table_matrix_op1->columnCount());

    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   trace_flag = 0;
                }
            }
            matrix_op1(i, j) = s.toDouble();
        }
    }
    //setting values on tables
    for (int i = 0; i<ui->table_matrix_op1->rowCount(); i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount(); j++) {
                //Set values on tables
                ui->table_matrix_op1_4->setItem(i,j,new QTableWidgetItem(ui->table_matrix_op1->item(i, j)->text()));
                ui->table_matrix_op1_4->item(i,j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    if(trace_flag){
        ui->label_16->setText("Obliczanie śladu macierzy:");
        ui->label_16->setVisible(1);
        ui->label_7->setText(QString::number(matrix_op1.tr()));
        ui->a_00_4->setText(QString::number(matrix_op1(0,0)));
        ui->label_66->setFont(QFont("Arial", 100, QFont::Normal));
        ui->label_67->setFont(QFont("Arial", 100, QFont::Normal));
        //for 2x2
        if(ui->table_matrix_op1->rowCount() == 2){
            ui->a_11_6->setText(QString::number(matrix_op1(1,1)));
            //Set labels' geometry
            ui->a_00_4->setGeometry(350,647,40,20);
            ui->a_11_6->setGeometry(406,647,40,20);
            ui->sign_det_3->setGeometry(390,647,16,21);
            ui->label_7-> setGeometry(495,640,71,31);
            ui->label_65-> setGeometry(455,632,31,41);
            ui->label_61->setGeometry(230,634,111,41);
            ui->label_61->setText("tr(A) =");
            ui->label_70->setGeometry(230,500,71,41);
            ui->label_70->setText("A =");

            ui->label_66->setGeometry(300,440,51,161);
            ui->label_66->setText("[");
            ui->label_67->setGeometry(450,440,51,161);
            ui->label_67->setText("]");

            //Matrix A cells colors
            ui->table_matrix_op1_4->item(0,0)->setBackgroundColor(Qt::darkBlue);
            ui->table_matrix_op1_4->item(1,1)->setBackgroundColor(QColor(151, 117, 0));

            //Text Color
            ui->table_matrix_op1_4->item(0,0)->setTextColor(Qt::white);
            ui->table_matrix_op1_4->item(1,1)->setTextColor(Qt::white);
            //Set lables visible
            QLabel* labels[9]={ui->label_61, ui->label_65, ui->label_66, ui->label_67, ui->label_7, ui->a_00_4, ui->a_11_6, ui->sign_det_3,
                                ui->label_70};
            for (int i = 0; i < 9; i++) {
                labels[i]->setVisible(1);
            }
        }

        //for 3x3
        if(ui->table_matrix_op1->rowCount() == 3){
            ui->a_11_4->setText(QString::number(matrix_op1(1,1)));
            ui->a_22_4->setText(QString::number(matrix_op1(2,2)));
            //Set labels' geometry
            ui->a_00_4->setGeometry(350,647,40,20);
            ui->a_11_4->setGeometry(406,647,40,20);
            ui->a_22_4->setGeometry(462,647,40,20);
            ui->sign_det_3->setGeometry(390,647,16,21);
            ui->sign_det_6->setGeometry(446,647,16,21);
            ui->label_7-> setGeometry(550,640,71,31);
            ui->label_65-> setGeometry(510,632,31,41);
            ui->label_61->setGeometry(230,634,111,41);
            ui->label_61->setText("tr(A) =");
            ui->label_70->setGeometry(230,500,71,41);
            ui->label_70->setText("A =");
            ui->label_66->setGeometry(300,440,51,161);
            ui->label_66->setText("[");
            ui->label_67->setGeometry(490,440,51,161);
            ui->label_67->setText("]");

            //Matrix A cells colors
            ui->table_matrix_op1_4->item(0,0)->setBackgroundColor(Qt::darkBlue);
            ui->table_matrix_op1_4->item(1,1)->setBackgroundColor(QColor(151, 117, 0));
            ui->table_matrix_op1_4->item(2,2)->setBackgroundColor(Qt::black);

            //Text Color
            ui->table_matrix_op1_4->item(0,0)->setTextColor(Qt::white);
            ui->table_matrix_op1_4->item(1,1)->setTextColor(Qt::white);
            ui->table_matrix_op1_4->item(2,2)->setTextColor(Qt::white);
            //Set lables visible
            QLabel* labels[11]={ui->label_61, ui->label_65, ui->label_66, ui->label_67, ui->label_7, ui->a_00_4, ui->a_11_4, ui->a_22_4, ui->sign_det_3,
                                ui->sign_det_6, ui->label_70};
            for (int i = 0; i < 11; i++) {
                labels[i]->setVisible(1);
            }

        }
        ui->table_matrix_op1_4->setVisible(1);
    }

}

// Algebraic Complements 1st step
void MainWindow::on_pushButton_matrix_algebraic_released()
{
    ui->scalar->setText("");
    this->visible_multi(0);
    this->visible_trans(0);
    this->visible_6(0);
    this->visible_minor(0);
    this->visible_minor_2(0);
    this->visible_algebraic(0);

    int algebraic_flag = 1;
    QFont font("Arial", 24, QFont::Bold) ;
    ui->label_61->setFont(font);
    ui->label_70->setFont(font);

    //for2x2
    if(ui->table_matrix_op1->rowCount() == 2){
        ui->algebraic_button_11->setGeometry(408,310,41,21);
        ui->algebraic_button_12->setGeometry(450,310,41,21);
        ui->algebraic_button_21->setGeometry(408,332,41,21);
        ui->algebraic_button_22->setGeometry(450,332,41,21);

    }

    //for3x3
    if(ui->table_matrix_op1->rowCount() == 3){
        ui->algebraic_button_11->setGeometry(406,296,41,21);
        ui->algebraic_button_12->setGeometry(448,296,41,21);
        ui->algebraic_button_13->setGeometry(490,296,41,21);
        ui->algebraic_button_21->setGeometry(406,318,41,21);
        ui->algebraic_button_22->setGeometry(448,318,41,21);
        ui->algebraic_button_23->setGeometry(490,318,41,21);
        ui->algebraic_button_31->setGeometry(406,340,41,21);
        ui->algebraic_button_32->setGeometry(448,340,41,21);
        ui->algebraic_button_33->setGeometry(490,340,41,21);
    }

    matrix_op1.setH(ui->table_matrix_op1->rowCount());
    matrix_op1.setW(ui->table_matrix_op1->columnCount());

    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   algebraic_flag = 0;
                }
            }
        }
    }
    //set labels
    ui->label_61->setGeometry(90,572,81,41);
    ui->label_70->setGeometry(90,470,81,41);
    ui->minor_label->setGeometry(190,475,151,31);
    ui->minor_label_2->setGeometry(180,580,161,31);
    ui->label_65->setGeometry(340,572,31,41);

    ui->label_36->setGeometry(250,473,31,16);
    ui->size_label_4->setGeometry(340,493,31,16);
    ui->size_label_5->setGeometry(120,498,31,16);
    ui->size_label_6->setGeometry(120,600,31,16);
    ui->label_15->setGeometry(34,320,361,31);
    ui->label_15->setText("Wybierz dopełnienie algebraiczne:");
    ui->label_16->setText("Obliczanie dopełnienia algebraicznego:");
    ui->label_61->setText("A  =");
    ui->label_70->setText("A  =");
    ui->minor_label->setText("(-1)     x  M");
    if(algebraic_flag){
        this->visible_algebraic(1);
    }
}

//algebraic complement A11
void MainWindow::on_algebraic_button_11_released()
{
    int algebraic_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   algebraic_flag = 0;
                }
            }
            matrix_op1(i, j) = s.toDouble();
        }
    }
    ui->size_label_4->setText("11");
    ui->size_label_5->setText("11");
    ui->size_label_6->setText("11");
    ui->label_36->setText("1+1");
    if(matrix_op1.subMatrix(0,0).det() > 0){
        ui->minor_label_2->setText("1 x " + QString::number(matrix_op1.subMatrix(0,0).det()));
    }
    else {
        ui->minor_label_2->setText("1 x (" + QString::number(matrix_op1.subMatrix(0,0).det()) + ")");
    }
    ui->label_7->setText(QString::number(matrix_op1.algebraicComplements()(0,0)));
    ui->label_7->setGeometry(380,575,121,41);
    QLabel* labels [13] = { ui->label_61, ui->label_70, ui->minor_label, ui->minor_label_2, ui->label_65, ui->label_7, ui->label_36, ui->size_label_4, ui->size_label_5,
                          ui->size_label_6, ui->label_16, ui->label_61, ui->label_70};
    if(algebraic_flag){
        //Set visible if algebraic_flag = 1
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(1);
        }
    }
    else{
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(0);
        }
    }
}

//algebraic complement A12
void MainWindow::on_algebraic_button_12_released()
{
    int algebraic_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   algebraic_flag = 0;
                }
            }
            matrix_op1(i, j) = s.toDouble();
        }
    }
    ui->size_label_4->setText("12");
    ui->size_label_5->setText("12");
    ui->size_label_6->setText("12");
    ui->label_36->setText("1+2");
    if(matrix_op1.subMatrix(0,1).det() > 0){
        ui->minor_label_2->setText("(-1) x " + QString::number(matrix_op1.subMatrix(0,1).det()));
    }
    else {
        ui->minor_label_2->setText("(-1) x (" + QString::number(matrix_op1.subMatrix(0,1).det()) + ")");
    }
    ui->label_7->setText(QString::number(matrix_op1.algebraicComplements()(0,1)));
    ui->label_7->setGeometry(380,575,121,41);
    QLabel* labels [13] = { ui->label_61, ui->label_70, ui->minor_label, ui->minor_label_2, ui->label_65, ui->label_7, ui->label_36, ui->size_label_4, ui->size_label_5,
                          ui->size_label_6, ui->label_16, ui->label_61, ui->label_70};
    if(algebraic_flag){
        //Set visible if algebraic_flag = 1
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(1);
        }
    }
    else{
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(0);
        }
    }
}

//algebraic complement A13
void MainWindow::on_algebraic_button_13_released()
{
    int algebraic_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   algebraic_flag = 0;
                }
            }
            matrix_op1(i, j) = s.toDouble();
        }
    }
    ui->size_label_4->setText("13");
    ui->size_label_5->setText("13");
    ui->size_label_6->setText("13");
    ui->label_36->setText("1+3");
    if(matrix_op1.subMatrix(0,2).det() > 0){
        ui->minor_label_2->setText("1 x " + QString::number(matrix_op1.subMatrix(0,2).det()));
    }
    else {
        ui->minor_label_2->setText("1 x (" + QString::number(matrix_op1.subMatrix(0,2).det()) + ")");
    }
    ui->label_7->setText(QString::number(matrix_op1.algebraicComplements()(0,2)));
    ui->label_7->setGeometry(380,575,121,41);
    QLabel* labels [13] = { ui->label_61, ui->label_70, ui->minor_label, ui->minor_label_2, ui->label_65, ui->label_7, ui->label_36, ui->size_label_4, ui->size_label_5,
                          ui->size_label_6, ui->label_16, ui->label_61, ui->label_70};
    if(algebraic_flag){
        //Set visible if algebraic_flag = 1
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(1);
        }
    }
    else{
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(0);
        }
    }
}

//algebraic complement A21
void MainWindow::on_algebraic_button_21_released()
{
    int algebraic_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   algebraic_flag = 0;
                }
            }
            matrix_op1(i, j) = s.toDouble();
        }
    }
    ui->size_label_4->setText("21");
    ui->size_label_5->setText("21");
    ui->size_label_6->setText("21");
    ui->label_36->setText("2+1");
    if(matrix_op1.subMatrix(1,0).det() > 0){
        ui->minor_label_2->setText("(-1) x " + QString::number(matrix_op1.subMatrix(1,0).det()));
    }
    else {
        ui->minor_label_2->setText("(-1) x (" + QString::number(matrix_op1.subMatrix(1,0).det()) + ")");
    }
    ui->label_7->setText(QString::number(matrix_op1.algebraicComplements()(1,0)));
    ui->label_7->setGeometry(380,575,121,41);
    QLabel* labels [13] = { ui->label_61, ui->label_70, ui->minor_label, ui->minor_label_2, ui->label_65, ui->label_7, ui->label_36, ui->size_label_4, ui->size_label_5,
                          ui->size_label_6, ui->label_16, ui->label_61, ui->label_70};
    if(algebraic_flag){
        //Set visible if algebraic_flag = 1
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(1);
        }
    }
    else{
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(0);
        }
    }
}

//algebraic complement A22
void MainWindow::on_algebraic_button_22_released()
{
    int algebraic_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   algebraic_flag = 0;
                }
            }
            matrix_op1(i, j) = s.toDouble();
        }
    }
    ui->size_label_4->setText("22");
    ui->size_label_5->setText("22");
    ui->size_label_6->setText("22");
    ui->label_36->setText("2+2");
    if(matrix_op1.subMatrix(1,1).det() > 0){
        ui->minor_label_2->setText("1 x " + QString::number(matrix_op1.subMatrix(1,1).det()));
    }
    else {
        ui->minor_label_2->setText("1 x (" + QString::number(matrix_op1.subMatrix(1,1).det()) + ")");
    }
    ui->label_7->setText(QString::number(matrix_op1.algebraicComplements()(1,1)));
    ui->label_7->setGeometry(380,575,121,41);
    QLabel* labels [13] = { ui->label_61, ui->label_70, ui->minor_label, ui->minor_label_2, ui->label_65, ui->label_7, ui->label_36, ui->size_label_4, ui->size_label_5,
                          ui->size_label_6, ui->label_16, ui->label_61, ui->label_70};
    if(algebraic_flag){
        //Set visible if algebraic_flag = 1
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(1);
        }
    }
    else{
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(0);
        }
    }
}

//algebraic complement A23
void MainWindow::on_algebraic_button_23_released()
{
    int algebraic_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   algebraic_flag = 0;
                }
            }
            matrix_op1(i, j) = s.toDouble();
        }
    }
    ui->size_label_4->setText("23");
    ui->size_label_5->setText("23");
    ui->size_label_6->setText("23");
    ui->label_36->setText("2+3");
    if(matrix_op1.subMatrix(1,2).det() > 0){
        ui->minor_label_2->setText("(-1) x " + QString::number(matrix_op1.subMatrix(1,2).det()));
    }
    else {
        ui->minor_label_2->setText("(-1) x (" + QString::number(matrix_op1.subMatrix(1,2).det()) + ")");
    }
    ui->label_7->setText(QString::number(matrix_op1.algebraicComplements()(1,2)));
    ui->label_7->setGeometry(380,575,121,41);
    QLabel* labels [13] = { ui->label_61, ui->label_70, ui->minor_label, ui->minor_label_2, ui->label_65, ui->label_7, ui->label_36, ui->size_label_4, ui->size_label_5,
                          ui->size_label_6, ui->label_16, ui->label_61, ui->label_70};
    if(algebraic_flag){
        //Set visible if algebraic_flag = 1
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(1);
        }
    }
    else{
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(0);
        }
    }
}

//algebraic complement A31
void MainWindow::on_algebraic_button_31_released()
{
    int algebraic_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   algebraic_flag = 0;
                }
            }
            matrix_op1(i, j) = s.toDouble();
        }
    }
    ui->size_label_4->setText("31");
    ui->size_label_5->setText("31");
    ui->size_label_6->setText("31");
    ui->label_36->setText("3+1");
    if(matrix_op1.subMatrix(2,0).det() > 0){
        ui->minor_label_2->setText("1 x " + QString::number(matrix_op1.subMatrix(2,0).det()));
    }
    else {
        ui->minor_label_2->setText("1 x (" + QString::number(matrix_op1.subMatrix(2,0).det()) + ")");
    }
    ui->label_7->setText(QString::number(matrix_op1.algebraicComplements()(2,0)));
    ui->label_7->setGeometry(380,575,121,41);
    QLabel* labels [13] = { ui->label_61, ui->label_70, ui->minor_label, ui->minor_label_2, ui->label_65, ui->label_7, ui->label_36, ui->size_label_4, ui->size_label_5,
                          ui->size_label_6, ui->label_16, ui->label_61, ui->label_70};
    if(algebraic_flag){
        //Set visible if algebraic_flag = 1
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(1);
        }
    }
    else{
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(0);
        }
    }
}

//algebraic complement A32
void MainWindow::on_algebraic_button_32_released()
{
    int algebraic_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   algebraic_flag = 0;
                }
            }
            matrix_op1(i, j) = s.toDouble();
        }
    }
    ui->size_label_4->setText("32");
    ui->size_label_5->setText("32");
    ui->size_label_6->setText("32");
    ui->label_36->setText("3+2");
    if(matrix_op1.subMatrix(2,1).det() > 0){
        ui->minor_label_2->setText("(-1) x " + QString::number(matrix_op1.subMatrix(2,1).det()));
    }
    else {
        ui->minor_label_2->setText("(-1) x (" + QString::number(matrix_op1.subMatrix(2,1).det()) + ")");
    }
    ui->label_7->setText(QString::number(matrix_op1.algebraicComplements()(2,1)));
    ui->label_7->setGeometry(380,575,121,41);
    QLabel* labels [13] = { ui->label_61, ui->label_70, ui->minor_label, ui->minor_label_2, ui->label_65, ui->label_7, ui->label_36, ui->size_label_4, ui->size_label_5,
                          ui->size_label_6, ui->label_16, ui->label_61, ui->label_70};
    if(algebraic_flag){
        //Set visible if algebraic_flag = 1
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(1);
        }
    }
    else{
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(0);
        }
    }
}

//algebraic complement A33
void MainWindow::on_algebraic_button_33_released()
{
    int algebraic_flag = 1;
    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   algebraic_flag = 0;
                }
            }
            matrix_op1(i, j) = s.toDouble();
        }
    }
    ui->size_label_4->setText("33");
    ui->size_label_5->setText("33");
    ui->size_label_6->setText("33");
    ui->label_36->setText("3+3");
    if(matrix_op1.subMatrix(2,2).det() > 0){
        ui->minor_label_2->setText("1 x " + QString::number(matrix_op1.subMatrix(2,2).det()));
    }
    else {
        ui->minor_label_2->setText("1 x (" + QString::number(matrix_op1.subMatrix(2,2).det()) + ")");
    }
    ui->label_7->setText(QString::number(matrix_op1.algebraicComplements()(2,2)));
    ui->label_7->setGeometry(380,575,121,41);
    QLabel* labels [13] = { ui->label_61, ui->label_70, ui->minor_label, ui->minor_label_2, ui->label_65, ui->label_7, ui->label_36, ui->size_label_4, ui->size_label_5,
                          ui->size_label_6, ui->label_16, ui->label_61, ui->label_70};
    if(algebraic_flag){
        //Set visible if algebraic_flag = 1
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(1);
        }
    }
    else{
        for (int i = 0; i < 13; i++){
            labels[i]->setVisible(0);
        }
    }
}


//Matrix inverse
void MainWindow::on_pushButton_matrix_inverse_released()
{
    this->visible_trans(0);
    this->visible_multi(0);
    this->visible_6(0);
    this->visible_minor(0);
    this->visible_minor_2(0);
    this->visible_algebraic(0);

    ui->label_16->setText("Obliczanie macierzy odwrotnej (A  ):");
    QFont font("Arial", 24, QFont::Bold);
    ui->label_61->setFont(font);
    ui->label_70->setFont(font);

    QFont font2("Arial", 100, QFont::Normal);
    ui->label_66->setFont(font2);
    ui->label_67->setFont(font2);
    ui->label_17->setFont(font2);
    ui->label_18->setFont(font2);
    ui->label_71->setFont(font2);
    ui->label_72->setFont(font2);

    int inverse_flag = 1;
    //for2x2
    if(ui->table_matrix_op1->rowCount() == 2){
        ui->table_matrix_op1_2->setColumnCount(2);
        ui->table_matrix_op1_2->setRowCount(2);
        ui->table_matrix_op1_3->setColumnCount(2);
        ui->table_matrix_op1_3->setRowCount(2);
        ui->table_matrix_op1_4->setColumnCount(2);
        ui->table_matrix_op1_4->setRowCount(2);
        ui->table_matrix_op1_5->setColumnCount(2);
        ui->table_matrix_op1_5->setRowCount(2);
        ui->table_matrix_op1_2->setGeometry(550,480,122,82);
        ui->table_matrix_op1_3->setGeometry(400,640,188,82);
        ui->table_matrix_op1_4->setGeometry(240,480,122,82);
        ui->table_matrix_op1_5->setGeometry(250,800,122,82);
        ui->label_71->setGeometry(350,600,51,161);
        ui->label_72->setGeometry(584,600,51,161);
    }

    //for3x3
    if(ui->table_matrix_op1->rowCount() == 3){
        ui->table_matrix_op1_2->setColumnCount(3);
        ui->table_matrix_op1_2->setRowCount(3);
        ui->table_matrix_op1_3->setColumnCount(3);
        ui->table_matrix_op1_3->setRowCount(3);
        ui->table_matrix_op1_4->setColumnCount(3);
        ui->table_matrix_op1_4->setRowCount(3);
        ui->table_matrix_op1_5->setColumnCount(3);
        ui->table_matrix_op1_5->setRowCount(3);
        ui->table_matrix_op1_2->setGeometry(520,460,182,122);
        ui->table_matrix_op1_3->setGeometry(380,620,283,122);
        ui->table_matrix_op1_4->setGeometry(210,460,182,122);
        ui->table_matrix_op1_5->setGeometry(220,780,182,122);
        ui->label_71->setGeometry(350,600,51,161);
        ui->label_72->setGeometry(640,600,51,161);
    }

    matrix_op1.setH(ui->table_matrix_op1->rowCount());
    matrix_op1.setW(ui->table_matrix_op1->columnCount());

    //Get values to table_maptrix_op1_2, _3 from table op1
    for (int i = 0; i<ui->table_matrix_op1->rowCount() ;i++) {
        for (int j = 0; j<ui->table_matrix_op1->columnCount() ;j++) {
            //Get values and check their correctness
            QString s = ui->table_matrix_op1->item(i, j)->text();
            ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::white);
            for (int k =0;k<s.size();k++){
                if(s[k].isLetter()){
                   QString w = QString::number(i+1);
                   QString h = QString::number(j+1);
                   QMessageBox::critical(this,"Wystąpił Błąd","W komórce a(" + w +(",")+ h + (") podano znak, który nie jest liczbą.") );
                   ui->table_matrix_op1->item(i, j)->setBackgroundColor(Qt::red);
                   inverse_flag = 0;
                }
            }
            double value = s.toDouble();
            matrix_op1(i, j)=value;
        }
    }
    if(matrix_op1.det() == 0){
        QMessageBox::critical(this,"Wystąpił Błąd","Macierz odwrotna nie istnieje, ponieważ \nwyznacznik det(A) = 0.");
    }else{
        if(inverse_flag){
            //setting values on tables
            for (int i = 0; i<ui->table_matrix_op1->rowCount(); i++) {
                for (int j = 0; j<ui->table_matrix_op1->columnCount(); j++) {
                        QString det = QString::number(matrix_op1.det());
                        if(matrix_op1.det()<0){
                            det = "("+QString::number(matrix_op1.det())+")";
                        }
                        //Set values on tables
                        QString val_1 = QString::number(matrix_op1.algebraicComplements()(i,j));
                        ui->table_matrix_op1_2->setItem(j,i,new QTableWidgetItem(val_1));
                        ui->table_matrix_op1_2->item(j,i)->setTextAlignment(Qt::AlignCenter);

                        ui->table_matrix_op1_3->setItem(j,i,new QTableWidgetItem(val_1 +"/" + det));
                        ui->table_matrix_op1_3->item(j,i)->setTextAlignment(Qt::AlignCenter);

                        QString w = QString::number(i+1);
                        QString h = QString::number(j+1);
                        ui->table_matrix_op1_4->setItem(j,i,new QTableWidgetItem("A" + w + h));
                        ui->table_matrix_op1_4->item(j,i)->setTextAlignment(Qt::AlignCenter);

                        QString val_2 = QString::number(matrix_op1.inverse()(i,j));
                        ui->table_matrix_op1_5->setItem(i,j,new QTableWidgetItem(val_2));
                        ui->table_matrix_op1_5->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }
            //Set labels geometry and visible
            ui->label_70->setGeometry(80,500,81,51);
            ui->label_70->setText("A  =");
            ui->label_36->setGeometry(105,505,16,16);
            ui->label_36->setText("D");
            ui->label_37->setGeometry(630,370,16,16);
            ui->label_37->setText("-1");
            ui->label_66->setGeometry(180,440,51,161);
            ui->label_66->setText("[");
            ui->label_67->setGeometry(370,440,51,161);
            ui->label_67->setText("]");
            ui->label_18->setGeometry(490,440,51,161);
            ui->label_18->setText("[");
            ui->label_17->setGeometry(680,440,51,161);
            ui->label_17->setText("]");
            ui->label_61->setGeometry(80,649,81,51);
            ui->label_61->setText("A  =");
            ui->size_label_6->setGeometry(105,653,31,16);
            ui->size_label_6->setText("-1");
            ui->sign_det_7->setGeometry(240,665,16,20);
            ui->label_71->setText("[");
            ui->label_72->setText("]");

            QLabel* labels[22] = {ui->label_70, ui->label_36, ui->label_37, ui->label_66, ui->label_67, ui->label_74, ui->label_17, ui->label_18, ui->label_61,
                                 ui->size_label_6, ui->size_label_7, ui->label_9, ui->label_10, ui->label_76, ui->label_77, ui->label_75, ui->label_63, ui->label_38, ui->sign_det_7,
                                 ui->label_71, ui->label_72, ui->label_16};
            for (int i = 0; i < 22; i++) {
                labels[i]->setVisible(1);
            }
            ui->line_6->setVisible(1);
            //Set tables visible
            ui->table_matrix_op1_2->setVisible(1);
            ui->table_matrix_op1_3->setVisible(1);
            ui->table_matrix_op1_4->setVisible(1);
            ui->table_matrix_op1_5->setVisible(1);
        }
    }
}
