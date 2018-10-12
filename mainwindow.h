#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
/*#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

//QNetworkAccessManager *manager;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

/*private slots:
    void replyFinished(QNetworkReply *reply);*/

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
