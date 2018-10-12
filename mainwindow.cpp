#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QJsonArray>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*//-------------------- requete------------------------------------//
    manager = new QNetworkAccessManager(this);

    QUrl url("https://api.openchargemap.io/v2/poi/?output=json&maxresults=10&latitude=48.85&longitude=2.33&&distance=2&distanceunit=KM"); //on rentre l'url contenant les données du format jason
    QNetworkRequest request; //on declare une variable pour l'envoi de notre requete
    request.setUrl(url);//on fait un set avec l'url
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    QNetworkReply* currentReply = manager->get(request); //get*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::replyFinished(QNetworkReply *reply)
{
    QByteArray ret=reply->readAll();
    //qDebug()<<ret; //voir si l'url marche

    QJsonDocument myJson=QJsonDocument::fromJson(ret);
    QJsonObject objetJson=myJson.object(); //à la place du tableau on choisit ici un objet
    //qDebug() << objetJson.toVariantMap()["DataProvider"].toList().at(0).toList().at(0);

    for(int i=0; i<myJson.array().count(); i++){
        qDebug()<< "-------------" << i << "-------------------";
        qDebug() << myJson.array()[i].toObject().toVariantMap()["ID"].toInt();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["UUID"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["DataProvider"].toMap()["WebsiteURL"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["ID"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Title"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["AddressLine1"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Town"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Postcode"].toString();

        //qDebug() << myJson.array()[0].toObject().toVariantMap()["AddressInfo"].toMap()["Country"].totoMap()["Title"];
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Country"].toMap()["ContinentCode"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["ContactTelephone1"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Distance"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["NumberOfPoints"].toString(); //ou toInt()

       // qDebug() << myJson.array().count(); //pour recuperer le nombre de bornes disponible
    }

}*/

