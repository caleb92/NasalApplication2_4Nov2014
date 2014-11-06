#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWidget>
#include <QtCore>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QDesktopServices>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    styleInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayHelp()
{
    QMessageBox::information(this, "Title", "This is the Help");

}

void MainWindow::on_btnFiles_clicked()
{
    //set file menu styling for active buttons
    ui->btnFiles->setStyleSheet(qstrMenuActive);
    ui->btnSubMenu1->setStyleSheet(qstrSubMenuActive);
    ui->btnSubMenu2->setStyleSheet(qstrSubMenuActive);
    ui->btnSubMenu3->setStyleSheet(qstrSubMenuActive);

    //set file sub menu text
    ui->btnSubMenu1->setText("Open File");
    ui->btnSubMenu2->setText("Close File");
    ui->btnSubMenu3->setText("Viewer Settings");
    ui->btnSubMenu4->setText("");

    //remove file menu styling for inactive buttons
    ui->btnSetup->setStyleSheet("");
    ui->btnVerification->setStyleSheet("");
    ui->btnHelp->setStyleSheet("");
    ui->btnSubMenu4->setStyleSheet("");
    ui->btnSubMenu5->setStyleSheet("");

    //empty display frame: frmDisplay
   // ui->lblDisplay->hide();

    //do file menu stuff


}



void MainWindow::on_btnSetup_clicked()
{

    //set file menu styling for active buttons
    ui->btnSetup->setStyleSheet(qstrMenuActive);
    ui->btnSubMenu1->setStyleSheet(qstrSubMenuActive);
    ui->btnSubMenu2->setStyleSheet(qstrSubMenuActive);
    ui->btnSubMenu3->setStyleSheet(qstrSubMenuActive);
    ui->btnSubMenu4->setStyleSheet(qstrSubMenuActive);
    //set file sub menu text
    ui->btnSubMenu1->setText("Open Capture");
    ui->btnSubMenu2->setText("Pause Capture");
    ui->btnSubMenu3->setText("Close Capture");
    ui->btnSubMenu4->setText("Capture Settings");

    //remove file menu styling for inactive buttons
    ui->btnFiles->setStyleSheet("");
    ui->btnVerification->setStyleSheet("");
    ui->btnHelp->setStyleSheet("");
    ui->btnSubMenu5->setStyleSheet("");
    //remove file sub menu text
    ui->btnSubMenu5->setText("");

    //empty display frame: frmDisplay


    //do file menu stuff
    ui->lblDisplay->show();

}

void MainWindow::on_btnVerification_clicked()
{
    //set file menu styling for active buttons
    ui->btnVerification->setStyleSheet(qstrMenuActive);
    ui->btnSubMenu1->setStyleSheet(qstrSubMenuActive);
    ui->btnSubMenu2->setStyleSheet(qstrSubMenuActive);
    ui->btnSubMenu3->setStyleSheet(qstrSubMenuActive);
    //set file sub menu text
    ui->btnSubMenu1->setText("Use Tool1");
    ui->btnSubMenu2->setText("Use Tool2");
    ui->btnSubMenu3->setText("Display Settings");

    //remove file menu styling for inactive buttons
    ui->btnFiles->setStyleSheet("");
    ui->btnSetup->setStyleSheet("");
    ui->btnHelp->setStyleSheet("");
    ui->btnSubMenu4->setStyleSheet("");
    ui->btnSubMenu5->setStyleSheet("");
    //remove file sub menu text
    ui->btnSubMenu4->setText("");
    ui->btnSubMenu5->setText("");

    //empty display frame: frmDisplay


    //do file menu stuff
    ui->lblDisplay->show();
}

void MainWindow::on_btnHelp_clicked()
{
    ui->TextPage->setVisible(true);
    ui->textBrowser->setVisible(true);

    QFile helpfile("C://Users/Mike/Documents/SENIOR DESIGN/help.txt");
    if(!helpfile.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",helpfile.errorString());
    ui->lblDisplay_2->hide();
    QTextStream in(&helpfile);
    ui->textBrowser->setText(in.readAll());
}


void MainWindow::on_btnSubMenu1_clicked()
{
    QString currentText = ui->btnSubMenu1->text();
    if(currentText == "Open Capture"){
        openCamera();
        ui->TextPage->setVisible(false);
        ui->CamPage->setVisible(true);
        ui->lblDisplay_2->setVisible(true);
    }
    if(currentText == "Open File")
    {
        QString filename = QFileDialog::getOpenFileName(
                    this,
                    tr("Open File"),
                    "C://Users/Mike/Documents",
                    "Text files (*.txt)"
                    );
       // QDesktopServices::openUrl(QUrl("file:///"+ filename ,QUrl::TolerantMode));

        ui->textBrowser->setVisible(true);
        ui->CamPage->setVisible(false);
        ui->TextPage->setVisible(true);

        QFile file(filename);
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        ui->lblDisplay_2->hide();
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());

    }
}

void MainWindow::openCamera()
{

    capWebcam.open(0);

    /*if(capWebcam.isOpened() == false)
    {
        ui->txtXYRadius->appendPlainText("error: capWebcam not accessed sucessfully");
        return;
    }*/

    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
    tmrTimer->start(20);


}

void MainWindow::processFrameAndUpdateGUI()
{
    capWebcam.read(matOriginal);
    if(matOriginal.empty() == true) return;
    cv::cvtColor(matOriginal, matOriginal, CV_BGR2RGB);
    QImage qimgOriginal((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);
    ui->lblDisplay->setPixmap(QPixmap::fromImage(qimgOriginal));
    ui->lblDisplay_2->setPixmap(QPixmap::fromImage(qimgOriginal));
}

void MainWindow::on_btnSubMenu3_clicked()
{

    tmrTimer->stop();
    QPixmap *blank = new QPixmap(640,480);
    blank->fill(Qt::black);
    ui->lblDisplay_2->setPixmap(*blank);


}

void MainWindow::on_btnSubMenu2_clicked()
{
    QString currentText = ui->btnSubMenu2->text();

    if(currentText == "Pause Capture" || "Resume" ){
       if(tmrTimer->isActive() == true)
        {
        tmrTimer->stop();
        ui->btnSubMenu2->setText("Resume");
        } else
         {
        tmrTimer->start(20);
        ui->btnSubMenu2->setText("Pause Capture");
        }
    }
    if(currentText == "Close File")
    {
 /*
        QFile blankfile("C://Users/Mike/Documents/SENIOR DESIGN/blank.txt");
        if(!blankfile.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",blankfile.errorString());
        QTextStream in(&blankfile);
*/
    ui->textBrowser->setText(QString("hello"));
            }

}

void MainWindow::styleInit()
{

    qstrMenusDefault = "";

    /*
    qstrMenusDefault =  "QPushButton {background-color: #393939;}"
                        "QPushButton {border-top-left-radius: 0px;}"
                        "QPushButton {border-bottom-left-radius: 0px;}"
                        "QPushButton {color: #f3843E;}"
                        "QPushButton {font-weight: normal}";
                        */

    qstrMenuActive =    "background-color: #6E6E6E;"
                        "border-top-left-radius: 5px;"
                        "border-bottom-left-radius: 5px;"
                        "color: #FF5109;"
                        "font-weight: bold";

    qstrSubMenuActive =   "background-color: #6E6E6E;"
                            "border-top-right-radius: 0px;"
                            "border-top-left-radius: 0px;"
                            "color: #FF5109;"
                            "font-weight: bold;";
}




