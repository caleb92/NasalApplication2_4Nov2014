#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "stasm_lib.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void openCamera();
    void styleInit();

    QString qstrMenusDefault;
    QString qstrMenuActive;
    QString qstrSubMenuActive;

    cv::VideoCapture capWebcam;

    //cv::Mat matOriginal;
    cv::Mat_<unsigned char> matOriginal;//(cv::imread(path, CV_LOAD_IMAGE_GRAYSCALE));
    int foundface;
    float landmarks[2 * stasm_NLANDMARKS]; // x,y coords (note the 2)
    int nNumberNasalLandmarks;
    float fNasalLandmarks;

    cv::Mat matProcessed;
    QImage qimgOriginal;
    QImage qimgProcessed;
    std::vector<cv::Vec3f> vecCircles;
    std::vector<cv::Vec3f>::iterator itrCircles;
    QTimer *tmrTimer;

public slots:
    void displayHelp();
    void processFrameAndUpdateGUI();

private slots:
    void on_btnFiles_clicked();
    void on_btnSetup_clicked();
    void on_btnSubMenu1_clicked();

    void on_btnSubMenu3_clicked();
    void on_btnSubMenu2_clicked();
    void on_btnVerification_clicked();
    void on_btnHelp_clicked();
};

#endif // MAINWINDOW_H
