#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>
#include <QObject>
#include <QByteArray>
#include <QMessageBox>
#include <QDesktopServices>
#include "mycrypt.h"
#include "popup.h"
#include <QFile>
#include <iostream>
#include <ctime>

/*XenforoAPI v2.0*/
/*Coded by Lithe*/

QString MyCryptD(QString data){ SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023));QString result = crypto.decryptToString(data);return result;}
QString MyCrypteE(QString data){SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023));QString result = crypto.encryptToString(data);return result;}
QString Base64D(QString data){std::string s = data.toStdString();std::string decoded = base64_decode(s);return QString::fromUtf8(decoded.c_str());}
QString Base64E(QString data){std::string s = data.toStdString();std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());return QString::fromUtf8(encoded.c_str());}

QString WebSite = "http://localhost/dashboard/";
namespace App {
QString Version = "v1.0.0";
QString ServerIP;
int ServerPort = 4200;
}

namespace User {
QString ID;
QString Username;
QString Email;

QString Rank1;
QString Rank2;
QString VRank;

bool Admin = false;
bool Premium = false;
bool Ban = false;

QString Messagecount = 0;
QString Notificationcount = 0;

QString FindRank(QString rankkey)
{
    if(rankkey == "7"){return /*Founder*/XorStr<0xC8,8,0x85B65CA6>("\x8E\xA6\xBF\xA5\xA8\xA8\xBC"+0x85B65CA6).s;}
    if(rankkey == "3"){return /*Admin*/XorStr<0x17,6,0x234FD2D3>("\x56\x7C\x74\x73\x75"+0x234FD2D3).s;}
    if(rankkey == "4"){return /*Moderator*/XorStr<0xC2,10,0x607A18C6>("\x8F\xAC\xA0\xA0\xB4\xA6\xBC\xA6\xB8"+0x607A18C6).s;}
    if(rankkey == "8"){return /*Premium*/XorStr<0xCE,8,0xAE05FF58>("\x9E\xBD\xB5\xBC\xBB\xA6\xB9"+0xAE05FF58).s;}
    if(rankkey == "2"){return /*Member*/XorStr<0xD5,7,0x8B5B37BC>("\x98\xB3\xBA\xBA\xBC\xA8"+0x8B5B37BC).s;}
    if(rankkey == "9"){return /*Banned*/XorStr<0xDE,7,0x51C8919F>("\x9C\xBE\x8E\x8F\x87\x87"+0x51C8919F).s;}
}


QString FindRankCSS(QString rankkey)
{
    if(rankkey == "7"){return "QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 2px;\nbackground-color: #D80000;\ncolor: rgb(255, 255, 255);\n}\nQPushButton:hover {\n\n }";}
    if(rankkey == "3"){return "QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 2px;\nbackground-color: #FFCB00;\ncolor: rgb(255, 255, 255);\n}\nQPushButton:hover {\n\n }";}
    if(rankkey == "4"){return "QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 2px;\nbackground-color: #FFFF91;\ncolor: rgb(255, 255, 255);\n}\nQPushButton:hover {\n\n }";}
    if(rankkey == "8"){return "QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 2px;\nbackground-color: #09E5F1;\ncolor: rgb(255, 255, 255);\n}\nQPushButton:hover {\n\n }";}
    if(rankkey == "2"){return "QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 2px;\nbackground-color: #808080;\ncolor: rgb(255, 255, 255);\n}\nQPushButton:hover {\n\n }";}
    if(rankkey == "9"){return "QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 2px;\nbackground-color: #929292;\ncolor: rgb(255, 255, 255);\n}\nQPushButton:hover {\n\n }";}
}

}

namespace XenforoAPI {
QString XenforoURL = "http://localhost/dashboard";
QString XenforoLogin = /*/xfapi.php*/XorStr<0xF6,11,0xFFC909BA>("\xD9\x8F\x9E\x98\x8A\x92\xD2\x8D\x96\x8F"+0xFFC909BA).s;
QString XenforoAvatar = /*/xfapi_avatar.php*/XorStr<0xB3,18,0x19E1DC18>("\x9C\xCC\xD3\xD7\xC7\xD1\xE6\xDB\xCD\xDD\xC9\xDF\xCD\xEE\xB1\xAA\xB3"+0x19E1DC18).s;


namespace DefaultPaths {
QString CheatsList = "/ui/cheatslist/cheats.php";
QString News =  "/ui/control/news.php";
QString Version = "/ui/control/version.php";
QString Power = "/ui/control/power.php";
QString ChatPower ="/ui/control/chatpower.php";
QString ChatIP = "/ui/control/chatip.php";
QString Hosts = "/ui/control/hosts.php";
}


QString DownwloadString(QString url)
{
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
    QEventLoop event;
    QObject::connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    QString content = response->readAll();
    return content;
}

QPixmap DownloadImage(QString url, int w,int h)
{
    QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
    QNetworkRequest request(url);
    QNetworkReply *reply = netAccManager->get(request);
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    QByteArray bytes = reply->readAll();
    QImage img(w, h, QImage::Format_Indexed8);
    img.loadFromData(bytes);
    return QPixmap::fromImage(img);
}

QString CreateKey()
{
    int hour = DownwloadString(XenforoURL + "/date.php?method=1").toInt();
    int minute = DownwloadString(XenforoURL + "/date.php?method=2").toInt();
    int is = hour + minute * 7 * 9 + 20000000;
    QString tostring = QString::number(is);
    return tostring;
}

QString Login(QString Username, QString Password)
{
    //http://localhost/dashboard/xfapi.php?security=1&username=Lithe&password=alpalpalp123
    QString data = DownwloadString(XenforoURL + XenforoLogin + "?security=" + CreateKey() + "&username=" + Username + "&password=" + Password);
    data= Base64D(Base64D(Base64D(Base64D(Base64D(Base64D(data)))))).replace("<br>" , "");
    if(data.lastIndexOf(XorStr<0xBC,22,0xCCF8D015>("\xF5\xD3\xCA\xDA\xB2\xAF\xA3\xAF\xE4\x96\xA3\xB5\xBE\xAC\xB8\xEB\x89\xBF\xBC\xA0\xA2"+0xCCF8D015).s) > 0)
    {
        return XorStr<0x64,6,0x2F4017FE>("\x22\x04\x0A\x14\x0D"+0x2F4017FE).s;
    }
     else
    {
        if(data.length() > 5)
        {
            return data;
        }
        else
        {
             return XorStr<0x64,6,0x2F4017FE>("\x22\x04\x0A\x14\x0D"+0x2F4017FE).s;
        }

    }
}
}


void OpenURL(QString url)
{
   QDesktopServices::openUrl(QUrl(url));
}

void WriteFile(QString filename, QString data)
{
    QFile file(filename);
    if(!file.open(QFile::WriteOnly))
    {
        qCritical() << file.errorString();
        return;
    }
    QByteArray br = data.toUtf8();
    file.write(br);
    file.close();
}

void Messagebox(QString title, QString message)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(message);
    msgBox.exec();
}

void Messagebox2(QString message)
{
    PopUp *popUp;
    popUp = new PopUp();
    popUp->setPopupText(message);
    popUp->show();
}

QString Encode(QString data)
{
   QString Sifrele1 = MyCrypteE(data);
   return Sifrele1;
}

QString Decode(QString data)
{
   QString Coz1 = MyCryptD(data);
   return Coz1;
}


QString Server(QString path)
{
    if(path != XenforoAPI::DefaultPaths::News)
    return Decode(XenforoAPI::DownwloadString("http://localhost/dashboard" + path + "?security=" + XenforoAPI::CreateKey()));
    else
    return XenforoAPI::DownwloadString("http://localhost/dashboard" + path + "?security=" + XenforoAPI::CreateKey());
}


QString DownwloadString(QString url)
{
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
    QEventLoop event;
    QObject::connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    QString content = response->readAll();
    return content;
}

QString CreateKey()
{
    int hour = DownwloadString(XenforoAPI::XenforoURL + "/date.php?method=1").toInt();
    int minute = DownwloadString(XenforoAPI::XenforoURL + "/date.php?method=2").toInt();
    int is = hour + minute + 20000000;
    QString tostring = QString::number(is);
    return tostring;
}
