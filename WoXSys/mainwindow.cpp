#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xfapi.h"
#include "injector.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_bMousePressed(false),
      m_bDragTop(false),
      m_bDragLeft(false),
      m_bDragRight(false),
      m_bDragBottom(false) {
  ui->setupUi(this);
  setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
  setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
  setMouseTracking(true);
  ui->UIUserWidget->setVisible(false);
  if(Server(XenforoAPI::DefaultPaths::Power) == "1")
  {
       if(Server(XenforoAPI::DefaultPaths::Version) == App::Version){
                ui->UICheatsTreeWidget->header()->resizeSection(0, 130);
                ui->UICheatsTreeWidget->header()->resizeSection(1, 110);
                ui->UICheatsTreeWidget->header()->resizeSection(2, 110);
                ui->UICheatsTreeWidget->header()->resizeSection(3, 110);
                ui->UICheatsTreeWidget->header()->resizeSection(4, 170);
                ui->UICheatsTreeWidget->header()->resizeSection(5, 110);
                ui->UICheatsTreeWidget->header()->resizeSection(5, 140);
                ui->UICheatsTreeWidget->setColumnHidden(7,true);
                ui->UICheatsTreeWidget->setColumnHidden(8,true);
                ui->UICheatsTreeWidget->setColumnHidden(9,true);
                ui->UICheatsTreeWidget->setColumnHidden(10,true);
                ui->UICheatsTreeWidget->setColumnHidden(11,true);
                ui->UICheatsTreeWidget->setColumnHidden(12,true);
                ui->UICheatsTreeWidget->setColumnHidden(13,true);
                ui->UICheatsTreeWidget->setColumnHidden(14,true);
                ui->UIOnlineUsers->header()->resizeSection(0, 548);
                socket = new QTcpSocket(this);
                connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
                connect(socket, SIGNAL(connected()), this, SLOT(connected()));
                process = new QProcess();
                serverx = new ChatterBoxServer();
                serverx->listen(QHostAddress::Any, 4200);
                ui->UINewsTxt->setText(Server(XenforoAPI::DefaultPaths::News));
                QSettings settings(XorStr<0xFB,6,0x30825133>("\xAC\x93\xA5\xAB\xB6"+0x30825133).s, XorStr<0x2D,6,0x6ABE6CCD>("\x61\x41\x48\x59\x5F"+0x6ABE6CCD).s);
                settings.beginGroup(XorStr<0x9F,6,0xF690738D>("\xC8\xCF\xF9\xF7\xEA"+0xF690738D).s);
                if(settings.value(XorStr<0x7C,9,0x3F6BB518>("\x09\x0E\x1B\x0D\xEE\xE0\xEF\xE6"+0x3F6BB518).s).toString() != "" && settings.value(XorStr<0xCD,9,0x510EBC30>("\xBD\xAF\xBC\xA3\xA6\xBD\xA1\xB0"+0x510EBC30).s).toString() != "")
                {
                    ui->UILoginUsername->setText(settings.value(XorStr<0x7C,9,0x3F6BB518>("\x09\x0E\x1B\x0D\xEE\xE0\xEF\xE6"+0x3F6BB518).s).toString());
                    ui->UILoginPassword->setText(settings.value(XorStr<0xCD,9,0x510EBC30>("\xBD\xAF\xBC\xA3\xA6\xBD\xA1\xB0"+0x510EBC30).s).toString());
                    ui->UILoginCheckBox->setChecked(true);
                }
                ReadWXPG(Server(XenforoAPI::DefaultPaths::CheatsList));
                SelectTab(5);
           }
           else
           {
               ui->UIErrorText3->setText(/*Current Version: */XorStr<0x9C,18,0x6A0FB95A>("\xDF\xE8\xEC\xED\xC5\xCF\xD6\x83\xF2\xC0\xD4\xD4\xC1\xC6\xC4\x91\x8C"+0x6A0FB95A).s + App::Version);
               ui->UIErrorText4->setText(/*New Version: */XorStr<0x27,14,0x3572E17F>("\x69\x4D\x5E\x0A\x7D\x49\x5F\x5D\x46\x5F\x5F\x08\x13"+0x3572E17F).s + Server(XenforoAPI::DefaultPaths::Version));
               ui->UIErrorIcon->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 10px;\nimage: url(:/darkstyle/update.png);\n}\n");
               ui->UIErrorText2->setText(/*Updates available. Please reinstall the loader*/XorStr<0xD1,47,0x68AA1762>("\x84\xA2\xB7\xB5\xA1\xB3\xA4\xF8\xB8\xAC\xBA\xB5\xB1\xBF\xBD\x8C\x84\xCC\xC3\xB4\x89\x83\x86\x9B\x8C\xCA\x99\x89\x84\x80\x9C\x84\x90\x9E\x9F\xD4\x81\x9E\x92\xD8\x95\x95\x9A\x98\x98\x8C"+0x68AA1762).s);
               Messagebox2(/*Updates available. Please reinstall the loader*/XorStr<0xD1,47,0x68AA1762>("\x84\xA2\xB7\xB5\xA1\xB3\xA4\xF8\xB8\xAC\xBA\xB5\xB1\xBF\xBD\x8C\x84\xCC\xC3\xB4\x89\x83\x86\x9B\x8C\xCA\x99\x89\x84\x80\x9C\x84\x90\x9E\x9F\xD4\x81\x9E\x92\xD8\x95\x95\x9A\x98\x98\x8C"+0x68AA1762).s);
               SelectTab(6);
           }
       }
       else
       {
           ui->UIErrorText2->setText(/*Connection to server failed! Please try again later.*/XorStr<0x03,53,0x30033411>("\x40\x6B\x6B\x68\x62\x6B\x7D\x63\x64\x62\x2D\x7A\x60\x30\x62\x77\x61\x62\x70\x64\x37\x7E\x78\x73\x77\x79\x79\x3F\x3F\x70\x4D\x47\x42\x57\x40\x06\x53\x5A\x50\x0A\x4A\x4B\x4C\x47\x41\x10\x5D\x53\x47\x51\x47\x18"+0x30033411).s);
           Messagebox2(/*Connection to server failed! Please try again later.*/XorStr<0x03,53,0x30033411>("\x40\x6B\x6B\x68\x62\x6B\x7D\x63\x64\x62\x2D\x7A\x60\x30\x62\x77\x61\x62\x70\x64\x37\x7E\x78\x73\x77\x79\x79\x3F\x3F\x70\x4D\x47\x42\x57\x40\x06\x53\x5A\x50\x0A\x4A\x4B\x4C\x47\x41\x10\x5D\x53\x47\x51\x47\x18"+0x30033411).s);
           SelectTab(6);
       }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::ReadWXPG(QString data)
{
    QJsonDocument document1 = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject root1 = document1.object();

    QJsonValue jv1 = root1.value("cheats");
     if (jv1.isArray()) {
       QJsonArray ja1 = jv1.toArray();
        for (int i = 0; i < ja1.count(); i++) {
        QJsonObject subtree1 = ja1.at(i).toObject();
        QString game = subtree1.value("game").toString();
        QString server = subtree1.value("server").toString();
        QString state = subtree1.value("state").toString();
        QString cheatname = subtree1.value("cheatname").toString();
        QString version = subtree1.value("version").toString();
        QString last = subtree1.value("last").toString();
        QString process = subtree1.value("process").toString();
        QString type = subtree1.value("type").toString();
        QString logolink = subtree1.value("logolink").toString();
        QString link = subtree1.value("link").toString();
        QString topic = subtree1.value("topic").toString();
        QString about = subtree1.value("about").toString();
        QString exe = subtree1.value("exe").toString();
        QString premium = subtree1.value("premium").toString();
        AddCheats(game, server, state, cheatname, version, last, process, type, logolink, link, topic, about,exe,premium);
        }
    }
}

void MainWindow::AddCheats(QString game, QString server, QString state, QString cheatname, QString version, QString last, QString process, QString type,QString logolink,QString link, QString topic, QString about, QString exe, QString premium)
{
    QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
    QNetworkRequest request(logolink);
    QNetworkReply *reply = netAccManager->get(request);
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    QByteArray bytes = reply->readAll();
    QImage img(35, 35, QImage::Format_Indexed8);
    img.loadFromData(bytes);
    item1 = new QTreeWidgetItem();
    item1->setIcon(0, QPixmap::fromImage(img));
    item1->setText(0, game);
    if(premium == "True")
    {
      item1->setIcon(1,QIcon(":/darkstyle/premium.png"));
    }
    item1->setText(2, server);
    item1->setText(3, state);
    if (state == "Undetected")
    {
        item1->setTextColor(3, QColor(1, 196, 5));
    }
    else if (state == "Detected")
    {
        item1->setTextColor(3, QColor(214, 2, 2));
    }
    else if (state == "Beta Test")
    {
        item1->setTextColor(3, QColor(0, 204, 255));
    }
    else if (state == "Updating")
    {
        item1->setTextColor(3, QColor(249, 147, 4));
    }
    item1->setText(4, cheatname);
    item1->setText(5, version);
    item1->setText(6, last);
    item1->setText(7, process);
    item1->setText(8, type);
    item1->setText(9, link);
    item1->setText(10, topic);
    item1->setText(11, about);
    item1->setText(12, exe);
    item1->setText(13, premium);
    ui->UICheatsTreeWidget->addTopLevelItem(item1);
}

void MainWindow::checkBorderDragging(QMouseEvent *event) {
  if (isMaximized()) {
    return;
  }

  QPoint globalMousePos = event->globalPos();
  if (m_bMousePressed) {
    QRect availGeometry = QApplication::desktop()->availableGeometry();
    int h = availGeometry.height();
    int w = availGeometry.width();
    if (QApplication::desktop()->isVirtualDesktop()) {
      QSize sz = QApplication::desktop()->size();
      h = sz.height();
      w = sz.width();
    }
    if (m_bDragTop && m_bDragRight) {
      int diff =
          globalMousePos.x() - (m_StartGeometry.x() + m_StartGeometry.width());
      int neww = m_StartGeometry.width() + diff;
      diff = globalMousePos.y() - m_StartGeometry.y();
      int newy = m_StartGeometry.y() + diff;
      if (neww > 0 && newy > 0 && newy < h - 50) {
        QRect newg = m_StartGeometry;
        newg.setWidth(neww);
        newg.setX(m_StartGeometry.x());
        newg.setY(newy);
        setGeometry(newg);
      }
    }
    else if (m_bDragTop && m_bDragLeft) {
      int diff = globalMousePos.y() - m_StartGeometry.y();
      int newy = m_StartGeometry.y() + diff;
      diff = globalMousePos.x() - m_StartGeometry.x();
      int newx = m_StartGeometry.x() + diff;
      if (newy > 0 && newx > 0) {
        QRect newg = m_StartGeometry;
        newg.setY(newy);
        newg.setX(newx);
        setGeometry(newg);
      }
    }
    else if (m_bDragBottom && m_bDragLeft) {
      int diff =
          globalMousePos.y() - (m_StartGeometry.y() + m_StartGeometry.height());
      int newh = m_StartGeometry.height() + diff;
      diff = globalMousePos.x() - m_StartGeometry.x();
      int newx = m_StartGeometry.x() + diff;
      if (newh > 0 && newx > 0) {
        QRect newg = m_StartGeometry;
        newg.setX(newx);
        newg.setHeight(newh);
        setGeometry(newg);
      }
    } else if (m_bDragTop) {
      int diff = globalMousePos.y() - m_StartGeometry.y();
      int newy = m_StartGeometry.y() + diff;
      if (newy > 0 && newy < h - 50) {
        QRect newg = m_StartGeometry;
        newg.setY(newy);
        setGeometry(newg);
      }
    } else if (m_bDragLeft) {
      int diff = globalMousePos.x() - m_StartGeometry.x();
      int newx = m_StartGeometry.x() + diff;
      if (newx > 0 && newx < w - 50) {
        QRect newg = m_StartGeometry;
        newg.setX(newx);
        setGeometry(newg);
      }
    } else if (m_bDragRight) {
      int diff =
          globalMousePos.x() - (m_StartGeometry.x() + m_StartGeometry.width());
      int neww = m_StartGeometry.width() + diff;
      if (neww > 0) {
        QRect newg = m_StartGeometry;
        newg.setWidth(neww);
        newg.setX(m_StartGeometry.x());
        setGeometry(newg);
      }
    } else if (m_bDragBottom) {
      int diff =
          globalMousePos.y() - (m_StartGeometry.y() + m_StartGeometry.height());
      int newh = m_StartGeometry.height() + diff;
      if (newh > 0) {
        QRect newg = m_StartGeometry;
        newg.setHeight(newh);
        newg.setY(m_StartGeometry.y());
        setGeometry(newg);
      }
    }
  } else {
    if (leftBorderHit(globalMousePos) && topBorderHit(globalMousePos)) {
      setCursor(Qt::SizeFDiagCursor);
    } else if (rightBorderHit(globalMousePos) && topBorderHit(globalMousePos)) {
      setCursor(Qt::SizeBDiagCursor);
    } else if (leftBorderHit(globalMousePos) &&
               bottomBorderHit(globalMousePos)) {
      setCursor(Qt::SizeBDiagCursor);
    } else {
      if (topBorderHit(globalMousePos)) {
        setCursor(Qt::SizeVerCursor);
      } else if (leftBorderHit(globalMousePos)) {
        setCursor(Qt::SizeHorCursor);
      } else if (rightBorderHit(globalMousePos)) {
        setCursor(Qt::SizeHorCursor);
      } else if (bottomBorderHit(globalMousePos)) {
        setCursor(Qt::SizeVerCursor);
      } else {
        m_bDragTop = false;
        m_bDragLeft = false;
        m_bDragRight = false;
        m_bDragBottom = false;
        setCursor(Qt::ArrowCursor);
      }
    }
  }
}


bool MainWindow::leftBorderHit(const QPoint &pos) {
  const QRect &rect = this->geometry();
  if (pos.x() >= rect.x() && pos.x() <= rect.x() + CONST_DRAG_BORDER_SIZE) {
    return true;
  }
  return false;
}

bool MainWindow::rightBorderHit(const QPoint &pos) {
  const QRect &rect = this->geometry();
  int tmp = rect.x() + rect.width();
  if (pos.x() <= tmp && pos.x() >= (tmp - CONST_DRAG_BORDER_SIZE)) {
    return true;
  }
  return false;
}

bool MainWindow::topBorderHit(const QPoint &pos) {
  const QRect &rect = this->geometry();
  if (pos.y() >= rect.y() && pos.y() <= rect.y() + CONST_DRAG_BORDER_SIZE) {
    return true;
  }
  return false;
}

bool MainWindow::bottomBorderHit(const QPoint &pos) {
  const QRect &rect = this->geometry();
  int tmp = rect.y() + rect.height();
  if (pos.y() <= tmp && pos.y() >= (tmp - CONST_DRAG_BORDER_SIZE)) {
    return true;
  }
  return false;
}


bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
  if (isMaximized()) {
    return QWidget::eventFilter(obj, event);
  }
  if (event->type() == QEvent::MouseMove) {
    QMouseEvent *pMouse = dynamic_cast<QMouseEvent *>(event);
    if (pMouse) {
      checkBorderDragging(pMouse);
    }
  }
  else if (event->type() == QEvent::MouseButtonPress && obj == this) {
    QMouseEvent *pMouse = dynamic_cast<QMouseEvent *>(event);
    if (pMouse) {
      mousePressEvent(pMouse);
    }
  } else if (event->type() == QEvent::MouseButtonRelease) {
    if (m_bMousePressed) {
      QMouseEvent *pMouse = dynamic_cast<QMouseEvent *>(event);
      if (pMouse) {
      }
    }
  }
  return QWidget::eventFilter(obj, event);
}

void MainWindow::on_UICloseButton_clicked()
{
        QApplication::quit();
}

void MainWindow::on_UIMinButton_clicked()
{
     setWindowState(Qt::WindowMinimized);
}

void MainWindow::readyRead()
{
    while(socket->canReadLine())
      {
          QString line = QString::fromUtf8(socket->readLine()).trimmed();
          QRegExp usersRegex("^/users:(.*)$");
          if(usersRegex.indexIn(line) != -1)
          {
              QStringList users = usersRegex.cap(1).split(",");
              ui->UIOnlineUsers->clear();
              foreach(QString user, users)
              {
                  item3 = new QTreeWidgetItem();
                  item3->setText(0, user);
                  item3->setIcon(0,QIcon(":/darkstyle/default.png"));
                  ui->UIOnlineUsers->addTopLevelItem(item3);
              }
          }
      }
}

void MainWindow::connected()
{
    socket->write(QString("/me:" + User::Username + "\n").toUtf8());
}

void MainWindow::SelectTab(int key)
{
    if(key == 1)
    {
        ui->UICheatsButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/cheatspage.png);\nborder: 2px solid #61CEB2; \n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UINewsButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/newspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UIOnlineButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/userspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UIAccountButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/accountpage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UITabWidget->setCurrentIndex(key - 1);
        ui->UICheatsButton->setEnabled(true);
        ui->UINewsButton->setEnabled(true);
        ui->UIOnlineButton->setEnabled(true);
        ui->UIAccountButton->setEnabled(true);
    }

    if(key == 2)
    {
        ui->UINewsButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/newspage.png);\nborder: 2px solid #61CEB2; \n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UICheatsButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/cheatspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UIOnlineButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/userspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UIAccountButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/accountpage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UITabWidget->setCurrentIndex(key - 1);
        ui->UICheatsButton->setEnabled(true);
        ui->UINewsButton->setEnabled(true);
        ui->UIOnlineButton->setEnabled(true);
        ui->UIAccountButton->setEnabled(true);
    }

    if(key == 3)
    {
        ui->UIOnlineButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/userspage.png);\nborder: 2px solid #61CEB2; \n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UICheatsButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/cheatspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UINewsButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/newspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UIAccountButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/accountpage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UITabWidget->setCurrentIndex(key - 1);
        ui->UICheatsButton->setEnabled(true);
        ui->UINewsButton->setEnabled(true);
        ui->UIOnlineButton->setEnabled(true);
        ui->UIAccountButton->setEnabled(true);
    }

    if(key == 4)
    {
        ui->UIAccountButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/accountpage.png);\nborder: 2px solid #61CEB2; \n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UICheatsButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/cheatspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UINewsButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/newspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UIOnlineButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/userspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UITabWidget->setCurrentIndex(key - 1);
        ui->UICheatsButton->setEnabled(true);
        ui->UINewsButton->setEnabled(true);
        ui->UIOnlineButton->setEnabled(true);
        ui->UIAccountButton->setEnabled(true);
    }

    if(key == 5)
    {
        ui->UIAccountButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/accountpage.png);\nborder: 2px solid #61CEB2; \n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UICheatsButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/cheatspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UINewsButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/newspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UIOnlineButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/userspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UITabWidget->setCurrentIndex(key - 1);
        ui->UICheatsButton->setEnabled(false);
        ui->UINewsButton->setEnabled(false);
        ui->UIOnlineButton->setEnabled(false);
        ui->UIAccountButton->setEnabled(false);
    }
    if(key == 6)
    {
        ui->UIAccountButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/accountpage.png);\nborder: 2px solid #61CEB2; \n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UICheatsButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/cheatspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UINewsButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/newspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UIOnlineButton->setStyleSheet("QPushButton{\nborder: none;\nmargin: 0px;\npadding: 0px;\nborder-radius: 5px;\nbackground-color: #1E232F;\nimage: url(:/darkstyle/userspage.png);\n}\nQPushButton:hover {\nborder: 2px solid #61CEB2; \n }");
        ui->UITabWidget->setCurrentIndex(key - 1);
        ui->UICheatsButton->setEnabled(false);
        ui->UINewsButton->setEnabled(false);
        ui->UIOnlineButton->setEnabled(false);
        ui->UIAccountButton->setEnabled(false);
    }

}

void MainWindow::on_UICheatsButton_clicked()
{
    SelectTab(1);
}

void MainWindow::on_UINewsButton_clicked()
{
    SelectTab(2);
}

void MainWindow::on_UIOnlineButton_clicked()
{
    SelectTab(3);
}

void MainWindow::on_UIAccountButton_clicked()
{
    SelectTab(4);
}

QString MainWindow::ReadLine(int count)
{
    QTextDocument *doc = ui->UILoginUser->document();
    QTextBlock tb = doc->findBlockByLineNumber(count);
    return tb.text();
}

QString MainWindow::ReadLine2(int count)
{
    QTextDocument *doc = ui->UIXState->document();
    QTextBlock tb = doc->findBlockByLineNumber(count);
    return tb.text();
}


void MainWindow::on_UILoginButton_clicked()
{
    QString data = XenforoAPI::Login(ui->UILoginUsername->text() , ui->UILoginPassword->text());
    if(data != "False")
    {
        ui->UILoginButton->setVisible(false);
        ui->UILoginBackButton->setVisible(false);
        ui->UILoginButton->setEnabled(false);
        ui->UILoginState->setText("");
        if(ui->UILoginCheckBox->isChecked() == true)
        {
            QSettings settings(XorStr<0xFB,6,0x30825133>("\xAC\x93\xA5\xAB\xB6"+0x30825133).s, XorStr<0x2D,6,0x6ABE6CCD>("\x61\x41\x48\x59\x5F"+0x6ABE6CCD).s);
            settings.beginGroup(XorStr<0x9F,6,0xF690738D>("\xC8\xCF\xF9\xF7\xEA"+0xF690738D).s);
            settings.setValue(XorStr<0x7C,9,0x3F6BB518>("\x09\x0E\x1B\x0D\xEE\xE0\xEF\xE6"+0x3F6BB518).s, ui->UILoginUsername->text());
            settings.setValue(XorStr<0xCD,9,0x510EBC30>("\xBD\xAF\xBC\xA3\xA6\xBD\xA1\xB0"+0x510EBC30).s, ui->UILoginPassword->text());
            settings.endGroup();
        }
        else
        {
            QSettings settings(XorStr<0xFB,6,0x30825133>("\xAC\x93\xA5\xAB\xB6"+0x30825133).s, XorStr<0x2D,6,0x6ABE6CCD>("\x61\x41\x48\x59\x5F"+0x6ABE6CCD).s);
            settings.beginGroup(XorStr<0x9F,6,0xF690738D>("\xC8\xCF\xF9\xF7\xEA"+0xF690738D).s);
            settings.setValue(XorStr<0x7C,9,0x3F6BB518>("\x09\x0E\x1B\x0D\xEE\xE0\xEF\xE6"+0x3F6BB518).s, "");
            settings.setValue(XorStr<0xCD,9,0x510EBC30>("\xBD\xAF\xBC\xA3\xA6\xBD\xA1\xB0"+0x510EBC30).s,"");
            settings.endGroup();
        }
        ui->UILoginUser->setPlainText(data);
        User::ID = ReadLine(0).replace(/*ID: */XorStr<0x57,5,0x8AAFCE02>("\x1E\x1C\x63\x7A"+0x8AAFCE02).s,"");
        User::Username = ReadLine(1).replace(/*USERNAME: */XorStr<0xB6,11,0x9699279F>("\xE3\xE4\xFD\xEB\xF4\xFA\xF1\xF8\x84\x9F"+0x9699279F).s,"");
        User::Email = ReadLine(2).replace(/*EMAIL: */XorStr<0x91,8,0xCECE3D11>("\xD4\xDF\xD2\xDD\xD9\xAC\xB7"+0xCECE3D11).s,"");
        User::Notificationcount = ReadLine(3).replace(/*NOTIFICATION: */XorStr<0x62,15,0x8B77F094>("\x2C\x2C\x30\x2C\x20\x2E\x2B\x28\x3E\x22\x23\x23\x54\x4F"+0x8B77F094).s,"");
        User::Messagecount = ReadLine(4).replace(/*MESSAGE: */XorStr<0x81,10,0x5E4FC12B>("\xCC\xC7\xD0\xD7\xC4\xC1\xC2\xB2\xA9"+0x5E4FC12B).s,"");
        QString rank1 = ReadLine(7).replace(/*GROUP1: */XorStr<0x94,9,0x6F2C9208>("\xD3\xC7\xD9\xC2\xC8\xA8\xA0\xBB"+0x6F2C9208).s , "").replace("Array","").replace(" ","");
        QString rank2 = ReadLine(8).replace(/*GROUP2: */XorStr<0xCA,9,0x1F5A768C>("\x8D\x99\x83\x98\x9E\xFD\xEA\xF1"+0x1F5A768C).s , "").replace("Array","").replace(" ","");
        QString vrank = ReadLine(9).replace(/*GROUP3: */XorStr<0xC0,9,0x7BF29E7F>("\x87\x93\x8D\x96\x94\xF6\xFC\xE7"+0x7BF29E7F).s , "").replace("Array","").replace(" ","");
        if(rank1 != "")ui->UIAccountRank1->setText(User::FindRank(rank1));
        if(rank1 != "")ui->UIAccountRank1->setStyleSheet(User::FindRankCSS(rank1));
        if(rank1 != rank2)
        {
            if(rank2 != "")ui->UIAccountRank2->setText(User::FindRank(rank2));
            if(rank2 != "")ui->UIAccountRank2->setStyleSheet(User::FindRankCSS(rank2));
        }
         if(rank1 != vrank && rank2 != vrank)
        {
            if(vrank != "")ui->UIAccountRank3->setText(User::FindRank(vrank));
            if(vrank != "")ui->UIAccountRank3->setStyleSheet(User::FindRankCSS(vrank));
        }
        if(rank1 != ""){User::Rank1 = User::FindRank(rank1);}else{User::Rank1 = /*NULL*/XorStr<0xCB,5,0x9569C7F1>("\x85\x99\x81\x82"+0x9569C7F1).s;}
        if(rank2 != ""){User::Rank1 = User::FindRank(rank2);}else{User::Rank2 = /*NULL*/XorStr<0xCB,5,0x9569C7F1>("\x85\x99\x81\x82"+0x9569C7F1).s;}
        if(vrank != ""){User::VRank = User::FindRank(vrank);}else{User::VRank = /*NULL*/XorStr<0xCB,5,0x9569C7F1>("\x85\x99\x81\x82"+0x9569C7F1).s;}
        QString AllRank = User::Rank1 + " | " +  User::Rank2 + " | " +  User::VRank;
        if(User::Rank1 == /*Premium*/XorStr<0xCE,8,0xAE05FF58>("\x9E\xBD\xB5\xBC\xBB\xA6\xB9"+0xAE05FF58).s){User::Premium = true;} else {User::Premium = false;}
        if(User::Rank2 == /*Premium*/XorStr<0xCE,8,0xAE05FF58>("\x9E\xBD\xB5\xBC\xBB\xA6\xB9"+0xAE05FF58).s){User::Premium = true;} else {User::Premium = false;}
        if(User::VRank == /*Premium*/XorStr<0xCE,8,0xAE05FF58>("\x9E\xBD\xB5\xBC\xBB\xA6\xB9"+0xAE05FF58).s){User::Premium = true;} else {User::Premium = false;}
        if(AllRank.lastIndexOf(/*Founder*/XorStr<0x76,8,0xC6DC7C04>("\x30\x18\x0D\x17\x1E\x1E\x0E"+0xC6DC7C04).s) > 0){User::Premium = true;}
        if(AllRank.lastIndexOf(/*Admin*/XorStr<0x3C,6,0xA9FBF413>("\x7D\x59\x53\x56\x2E"+0xA9FBF413).s) > 0){User::Premium = true;}
        if(AllRank.lastIndexOf(/*Moderator*/XorStr<0xA9,10,0x34B21030>("\xE4\xC5\xCF\xC9\xDF\xCF\xDB\xDF\xC3"+0x34B21030).s) > 0){User::Premium = true;}
        if(ReadLine(5).replace(/*Admin*/XorStr<0x42,6,0x8509C6E3>("\x03\x27\x29\x2C\x28"+0x8509C6E3).s,"") == /*1*/XorStr<0x8A,2,0xEA9B7162>("\xBB"+0xEA9B7162).s) {User::Admin = true;}
        if(ReadLine(6).replace(/*Banned*/XorStr<0xB1,7,0x9B42D243>("\xF3\xD3\xDD\xDA\xD0\xD2"+0x9B42D243).s, "") == /*1*/XorStr<0x8A,2,0xEA9B7162>("\xBB"+0xEA9B7162).s){User::Ban = true;}
        if(ui->UIAccountRank2->text().length() == 0 && ui->UIAccountRank3->text().length() > 0 )
        {
            ui->UIAccountRank3->setGeometry(ui->UIAccountRank2->geometry());
        }
        ui->UIUserNick->setText(User::Username);
        ui->UIAccountUsername->setText(User::Username);
        ui->UIAccountID->setText(User::ID);
        ui->UIAccountMail->setText(User::Email);
        ui->UIUserAvatar->setSize(24);
        ui->UIAccountAvatar->setSize(200);
        WriteFile(XorStr<0x17,38,0x6E68EE49>("\x54\x22\x45\x4D\x72\x72\x79\x71\x68\x53\x7D\x71\x5A\x57\x51\x43\x4A\x1B\x1B\x76\x4F\x5E\x44\x58\x4A\x42\x42\x6E\x56\x40\x56\x6A\x5F\x57\x4A\x4E\x48"+0x6E68EE49).s,Server(XenforoAPI::DefaultPaths::Hosts));
        QImage avatar = XenforoAPI::DownloadImage(XenforoAPI::XenforoURL + XenforoAPI::XenforoAvatar + "?security=" + XenforoAPI::CreateKey() + "&id=" + User::ID,35,35).toImage();
        if(avatar.bytesPerLine() < 1)
        {
            QPixmap pixmap = QPixmap (":/darkstyle/default.png");
            ui->UIAccountAvatar->setImage(pixmap.toImage());
            ui->UIUserAvatar->setImage(pixmap.toImage());
        }
        else
        {
             ui->UIAccountAvatar->setImage(avatar);
             ui->UIUserAvatar->setImage(XenforoAPI::DownloadImage(XenforoAPI::XenforoURL + XenforoAPI::XenforoAvatar + "?security=" + XenforoAPI::CreateKey() + "&id=" + User::ID,35,35).toImage());
        }
        if(User::Premium == true)
        {
            ui->UIUserPremiumIcon->setVisible(true);
        }
        else
        {
            ui->UIUserPremiumIcon->setVisible(false);
        }
        if(User::Ban == true)
        {
            ui->UIErrorText2->setText(/*Your account has been banned. Contact the administrator*/XorStr<0xC8,56,0xE901BA57>("\x91\xA6\xBF\xB9\xEC\xAC\xAD\xAC\xBF\xA4\xBC\xA7\xF4\xBD\xB7\xA4\xF8\xBB\xBF\xBE\xB2\xFD\xBC\xBE\x8E\x8F\x87\x87\xCA\xC5\xA5\x88\x86\x9D\x8B\x88\x98\xCD\x9A\x87\x95\xD1\x93\x97\x99\x9C\x98\x9E\x8B\x8D\x88\x9A\x88\x92\x8C"+0xE901BA57).s);
            Messagebox2(/*Your account has been banned. Contact the administrator*/XorStr<0xC8,56,0xE901BA57>("\x91\xA6\xBF\xB9\xEC\xAC\xAD\xAC\xBF\xA4\xBC\xA7\xF4\xBD\xB7\xA4\xF8\xBB\xBF\xBE\xB2\xFD\xBC\xBE\x8E\x8F\x87\x87\xCA\xC5\xA5\x88\x86\x9D\x8B\x88\x98\xCD\x9A\x87\x95\xD1\x93\x97\x99\x9C\x98\x9E\x8B\x8D\x88\x9A\x88\x92\x8C"+0xE901BA57).s);
            SelectTab(6);
        }
        else
        {
            if(Server(XenforoAPI::DefaultPaths::ChatPower) == "1")
            {
                App::ServerIP = Server(XenforoAPI::DefaultPaths::ChatIP);
                socket->connectToHost(App::ServerIP, App::ServerPort);
            }

            Messagebox2(/*Welcome */XorStr<0xA1,9,0x24BE044B>("\xF6\xC7\xCF\xC7\xCA\xCB\xC2\x88"+0x24BE044B).s + User::Username + ", " + /*Everything is ready for you!*/XorStr<0x2B,29,0x4462FC41>("\x6E\x5A\x48\x5C\x56\x44\x59\x5B\x5D\x53\x15\x5F\x44\x18\x4B\x5F\x5A\x58\x44\x1E\x59\x2F\x33\x62\x3A\x2B\x30\x67"+0x4462FC41).s);
            SelectTab(1);
        }
        ui->UIUserWidget->setVisible(true);
    }
    else
    {
        ui->UILoginPassword->setText("");
        ui->UILoginState->setText(XorStr<0x2E,59,0xA05C38B8>("\x6F\x5A\x44\x59\x57\x5D\x40\x5C\x55\x56\x4C\x50\x55\x55\x1C\x5B\x5F\x56\x2C\x24\x26\x6D\x64\x15\x2A\x26\x3B\x2C\x6A\x28\x24\x28\x2D\x24\x70\x28\x3D\x26\x26\x75\x23\x24\x3D\x2B\x34\x3A\x31\x38\x71\x2F\x01\x12\x11\x14\x0B\x17\x02\x49"+0xA05C38B8).s);
    }

}

QString DisplayProcess;
QString DisplayType;
void MainWindow::Start(QString ProcessName, QString FileUrl, QString InjType, QString FileType)
{
      QByteArray databuf = QByteArray((char*)injectorx, 1366528);
      QString path = XorStr<0x88,35,0xDC5DFDA1>("\xCB\xB3\xA5\xDC\xE5\xE3\xEA\xE0\xE7\xE2\xBD\xD5\xFB\xFB\xE2\xE4\xB7\xFB\xF6\xFA\xFF\xF6\xFC\xF0\xCE\xC4\xFD\xC2\xD4\xCC\x88\xC2\xD0\xCC"+0xDC5DFDA1).s;
      QFile newDoc(path);
      if(newDoc.open(QIODevice::WriteOnly)){
          newDoc.write(databuf);
      }
      newDoc.close();
      if(FileType == "False") FileType = XorStr<0xC9,4,0x31D1DE07>("\x8D\x86\x87"+0x31D1DE07).s;
      if(FileType == "True") FileType = XorStr<0x44,4,0xE707EDB0>("\x01\x3D\x23"+0xE707EDB0).s;
      DisplayProcess = ProcessName;
      DisplayType = FileType;
      QString tobase64 = /*loginkey:*/XorStr<0x8C,10,0x92F12AB9>("\xE0\xE2\xE9\xE6\xFE\xFA\xF7\xEA\xAE"+0x92F12AB9).s + CreateKey() + "!" + /*process:*/XorStr<0xAD,9,0xF46E13FC>("\xDD\xDC\xC0\xD3\xD4\xC1\xC0\x8E"+0xF46E13FC).s + ProcessName + "!" + /*dll:*/XorStr<0xB1,5,0x4F06C793>("\xD5\xDE\xDF\x8E"+0x4F06C793).s + FileUrl + "!" + /*injtype:*/XorStr<0xE2,9,0x9A2D3D4E>("\x8B\x8D\x8E\x91\x9F\x97\x8D\xD3"+0x9A2D3D4E).s + InjType + "!" + /*filetype:*/XorStr<0xB5,10,0xBD29DBB5>("\xD3\xDF\xDB\xDD\xCD\xC3\xCB\xD9\x87"+0xBD29DBB5).s + FileType;
      tobase64 = Base64E(Base64E(tobase64));
      QStringList arguments; arguments << tobase64;
      timer = new QTimer(this);
      connect(timer,SIGNAL(timeout()), this, SLOT(Slot1()));
      timer->start(1);
      process->start(path,arguments);

}

void MainWindow::Slot1()
{
    QString line = serverx->lastdata;
    if(line.lastIndexOf(" ! ") > 0)
    {
        line = line.replace(" ! ","\n");
        ui->UIXState->setPlainText(line.replace(ui->UIXStateReplace->toPlainText(), ""));
        int value = ReadLine2(1).toInt();
        if(value > 10)
        {
          ui->UIXCheatsBar->setValue(value);
        }
        ui->UICheatsStatus->setText(ReadLine2(0));

    }
    if ( process->state() == QProcess::NotRunning ) {
         QApplication::quit();
    }

    if(ui->UIXCheatsBar->value() == 100)
    {
        if(DisplayType == /*DLL*/XorStr<0x5F,4,0xAED22F22>("\x1B\x2C\x2D"+0xAED22F22).s)
        {
            if(DisplayProcess.lastIndexOf(".") > 0 )
            {
                ui->UICheatsStatus->setText(/*Waiting for */XorStr<0x28,13,0x970B11F1>("\x7F\x48\x43\x5F\x45\x43\x49\x0F\x56\x5E\x40\x13"+0x970B11F1).s + DisplayProcess);
            }
            else
            {
                ui->UICheatsStatus->setText(/*Waiting for */XorStr<0x28,13,0x970B11F1>("\x7F\x48\x43\x5F\x45\x43\x49\x0F\x56\x5E\x40\x13"+0x970B11F1).s + DisplayProcess + /*.exe*/XorStr<0x1B,5,0xB371E22B>("\x35\x79\x65\x7B"+0xB371E22B).s);
            }
        }

    }

}

void MainWindow::on_UIXCheatsStart_clicked()
{
    QTreeWidgetItem *item = ui->UICheatsTreeWidget->currentItem();
    if (ui->UICheatsTreeWidget->indexOfTopLevelItem(item) >= 0)
    {
        QString process = item->text(7);
        QString type = item->text(8);
        QString link = item->text(9);
        QString exe = item->text(12);
        if(item->icon(1).isNull() == true)
        {
            if(item->text(3) == /*Beta Test*/XorStr<0xBB,10,0xAF473455>("\xF9\xD9\xC9\xDF\x9F\x94\xA4\xB1\xB7"+0xAF473455).s)
            {
                if(User::Admin == true){ ui->UIXCheatsStart->setEnabled(false); Start(process,link,type,exe);}
            }
            else if(item->text(3) == /*Undetected*/XorStr<0xA8,11,0x681A9E6C>("\xFD\xC7\xCE\xCE\xD8\xC8\xCD\xDB\xD5\xD5"+0x681A9E6C).s)
            {
                ui->UIXCheatsStart->setEnabled(false);
                Start(process,link,type,exe);Start(process,link,type,exe);;
            }
        }
        else
        {
            if(User::Premium == true)
            {
                if(item->text(3) == /*Beta Test*/XorStr<0x78,10,0x27345813>("\x3A\x1C\x0E\x1A\x5C\x29\x1B\x0C\xF4"+0x27345813).s)
                {
                   if(User::Admin == true){ ui->UIXCheatsStart->setEnabled(false); Start(process,link,type,exe);}
                }
                else if(item->text(3) == /*Undetected*/XorStr<0x2F,11,0xCF5D64B9>("\x7A\x5E\x55\x57\x47\x51\x56\x42\x52\x5C"+0xCF5D64B9).s)
                {
                    ui->UIXCheatsStart->setEnabled(false);
                    Start(process,link,type,exe);
                }
            }
            else
            {
                Messagebox2(XorStr<0xC7,52,0xB8EECD75>("\x89\xA7\xE9\xAB\xBE\xB8\xA5\xA1\xBD\xB9\xAB\xB3\xA7\xBD\xBA\xB8\xF7\xBE\xB6\xAF\xB5\xB8\xFC\xFE\x8F\x8C\x84\x83\x90\x81\xC5\x84\x92\x91\xC9\x9A\x99\x89\x80\x87\x9A\x9D\xD1\x93\x90\x97\x9A\x83\x99\x8C\xD8"+0xB8EECD75).s);
            }
        }
    }
}

void MainWindow::on_UIXCheatsTopic_clicked()
{
    QTreeWidgetItem *item = ui->UICheatsTreeWidget->currentItem();
    if (ui->UICheatsTreeWidget->indexOfTopLevelItem(item) >= 0)
    {
        QString gettxt = item->text(10);
        OpenURL(gettxt);
    }
}

void MainWindow::on_UIXCheatsAbout_clicked()
{
    QTreeWidgetItem *item = ui->UICheatsTreeWidget->currentItem();
    if (ui->UICheatsTreeWidget->indexOfTopLevelItem(item) >= 0)
    {
        QString gettxt = item->text(11);
        Messagebox("UI" , gettxt);
    }
}

void MainWindow::on_UIUserMessageIcon_clicked()
{
    OpenURL(WebSite+ "conversations");
}

void MainWindow::on_UIUserNotiIcon_clicked()
{
    OpenURL(WebSite+ "account/alerts");
}

void MainWindow::on_UILoginText4_clicked()
{
    OpenURL(WebSite+ "register");
}

void MainWindow::on_UILoginText5_clicked()
{
     OpenURL(WebSite+ "lost-password");
}

void MainWindow::on_UILoginBackButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_UILoginText6_clicked()
{
    OpenURL(XorStr<0xA8,21,0x19AFCCAD>("\xC0\xDD\xDE\xDB\xDF\x97\x81\x80\xC7\xDE\xCA\xD2\xC6\xD0\xD7\x99\xD6\xDC\xCE\x94"+0x19AFCCAD).s);
}
