#ifndef RECHARGEVEHICULE_H
#define RECHARGEVEHICULE_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QUrlQuery>
#include <QLineEdit>
#include <QFont>

namespace Ui {
class RechargeVehicule;
}


class RechargeVehicule : public QWidget
{
    Q_OBJECT
QNetworkAccessManager *manager;
public:
    explicit RechargeVehicule(QWidget *parent = 0);
    ~RechargeVehicule();
     qint8 rayonMax;
    int nombreBorne;
    QString info;
    QString info1;
    QString latitude;
    QString longitude;

private slots:
    void replyFinished(QNetworkReply *reply);
    //void recupererLineEdit();

private:
    Ui::RechargeVehicule *ui;
};

#endif // RECHARGEVEHICULE_H
