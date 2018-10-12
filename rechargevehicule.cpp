#include "rechargevehicule.h"
#include "ui_rechargevehicule.h"
#include <QTableWidgetItem>
#include <QTableWidget>



RechargeVehicule::RechargeVehicule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RechargeVehicule)
{
    ui->setupUi(this);

    //-------------------- requete------------------------------------//

        manager = new QNetworkAccessManager(this);
        QUrl url("https://api.openchargemap.io/v2/poi/?output=json&maxresults=10&latitude=48.85&longitude=2.33&&distance=2&distanceunit=KM");
        //url.setQuery(query);//on rentre l'url contenant les données du format json
        QNetworkRequest request; //on declare une variable pour l'envoi de notre requete
        request.setUrl(url);//on fait un set avec l'url
        //qDebug() << url;
        QNetworkReply* currentReply = manager->get(request); //get
        connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
       // connect(ui->, SIGNAL(textChanged(QString)), this, SLOT(recupererLineEdit()));

}

RechargeVehicule::~RechargeVehicule()
{
    delete ui;
}


void RechargeVehicule::replyFinished(QNetworkReply *reply)
{
    QByteArray ret=reply->readAll();
    //qDebug()<<ret; //voir si l'url marche

    QJsonDocument myJson=QJsonDocument::fromJson(ret);
    QJsonObject objetJson=myJson.object(); //à la place du tableau on choisit ici un objet
    /*qDebug() << objetJson.toVariantMap()["DataProvider"].toList().at(0).toList().at(0);*/
    QFont font("Bavaria",9,QFont::Bold); //augmenter la taille de la police
    ui->tableWidget->setFont(font);

    ui->tableWidget->setColumnCount(3); //nombre de colonne;
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->horizontalHeader()->hide();//pour cacher le nom ou numero des ligne
    ui->tableWidget->verticalHeader()->hide();//pour cacher le nom ou numero des colonne

    /*for(int i=0; i<myJson.array().count(); i++){
        qDebug()<< "-------------" << i << "-------------------";
        qDebug() << myJson.array()[i].toObject().toVariantMap()["ID"].toInt();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["UUID"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["DataProvider"].toMap()["WebsiteURL"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["ID"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Title"].toString();
        QString address(myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["AddressLine1"].toString());
        QString ville(myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Town"].toString());
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Postcode"].toString();

        //qDebug() << myJson.array()[0].toObject().toVariantMap()["AddressInfo"].toMap()["Country"].totoMap()["Title"];
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Country"].toMap()["ContinentCode"].toString();
        qDebug() << myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["ContactTelephone1"].toString();
        QString distance(myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Distance"].toString());
        qDebug() << myJson.array()[i].toObject().toVariantMap()["NumberOfPoints"].toString();

       //qDebug() << myJson.array().count(); //pour recuperer le nombre de bornes disponible
       // ui->textEdit->setText(myJson.array()[i].toObject().toVariantMap()["NumberOfPoints"].toString()
                //+myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Distance"].toString());


        ui->tableWidget->setRowCount(i+1);  //nombre de lignes
        QTableWidgetItem *item1= new QTableWidgetItem(address); //item1 pour recuperer l'adresse
        ui->tableWidget->setItem(i,0,item1);
        QTableWidgetItem *item2= new QTableWidgetItem(ville);//item1 pour recuperer la ville
        ui->tableWidget->setItem(i,1,item2);
        QTableWidgetItem *item3= new QTableWidgetItem(distance);//item1 pour recuperer la distance
        ui->tableWidget->setItem(i,2,item3);
    }*/

    if (myJson.array().count() >3) { //alors on affiche le nombre des autres bornes et la distance de celle la plus proche
        for (int i=0; i<3; i++) {
            ui->tableWidget->setRowCount(i+1);  //nombre de lignes
            QString addresse(myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["AddressLine1"].toString());
            QString ville(myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Town"].toString());
            QString distan(myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Distance"].toString());

            QString distance=distan.left(4); //je recupere les 4premiers chiffre
            QString distance1=distance.append("km"); //pour rajouter km à distance
            //QString distance1=distance+"km";//pour rajouter km à distance

            ui->tableWidget->setRowCount(i+1);  //nombre de lignes
            QTableWidgetItem *item1= new QTableWidgetItem(addresse); //item1 pour recuperer l'adresse
            ui->tableWidget->setItem(i,0,item1);
            QTableWidgetItem *item2= new QTableWidgetItem(ville);//item1 pour recuperer la ville
            ui->tableWidget->setItem(i,1,item2);
            QTableWidgetItem *item3= new QTableWidgetItem(distance1);//item1 pour recuperer la distance
            ui->tableWidget->setItem(i,2,item3);
        }

        //qDebug() << myJson.array().count();
        int rest= myJson.array().count()-3;
        QString autresBornes=QString::number(rest);//on convertit un double en QString*/
        QString distance(myJson.array()[myJson.array().count()-1].toObject().toVariantMap()["AddressInfo"].toMap()["Distance"].toString());
        QString dist=distance.left(4);
        //ui->label_2->setText(autresBornes);
        ui->label_2->setText("+"+autresBornes+ " autres bornes à moins de " +dist+"km");

    } else {
        for(int i=0; i<myJson.array().count(); i++){
            ui->tableWidget->setRowCount(i+1);  //nombre de lignes
            QString addresse(myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["AddressLine1"].toString());
            QString ville(myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Town"].toString());
            QString distan(myJson.array()[i].toObject().toVariantMap()["AddressInfo"].toMap()["Distance"].toString());

            QString distance=distan.left(4);
            QString distance1=distance.append("km");
            qDebug() << distance1;

            ui->tableWidget->setRowCount(i+1);  //nombre de lignes
            QTableWidgetItem *item1= new QTableWidgetItem(addresse); //item1 pour recuperer l'adresse
            ui->tableWidget->setItem(i,0,item1);
            QTableWidgetItem *item2= new QTableWidgetItem(ville);//item1 pour recuperer la ville
            ui->tableWidget->setItem(i,1,item2);
            QTableWidgetItem *item3= new QTableWidgetItem(distance1);//item1 pour recuperer la distance
            ui->tableWidget->setItem(i,2,item3);
        }
    }
}


/*void RechargeVehicule::recupererLineEdit()
 {

    QString Max= ui->tableWidget->;
    qDebug() << "lineeDIT = " << Max;

 }*/
/*double dist= myJson.array()[9].toObject().toVariantMap()["AddressInfo"].toMap()["Distance"].toDouble();
QString distance1=QString::number(dist);//on convertit un double en QString*/
