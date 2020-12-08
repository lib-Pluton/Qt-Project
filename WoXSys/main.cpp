#include <QApplication>
#include "darkstyle.h"
#include "mainwindow.h"
#include <QSslSocket>
#include <iostream>
#include <windows.h>
#include <QtWidgets>
#include <QtNetwork>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QTimer>
#include <QSplashScreen>
#include "xor.h"
#include "tlhelp32.h"
bool IsElevated() {
    BOOL fRet = FALSE;
    HANDLE hToken = NULL;
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
        TOKEN_ELEVATION Elevation;
        DWORD cbSize = sizeof(TOKEN_ELEVATION);
        if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
            fRet = Elevation.TokenIsElevated;
        }
    }
    if (hToken) {
        CloseHandle(hToken);
    }
    return fRet;
}

bool IsNetwork()
{
    QList<QNetworkInterface> ifaces = QNetworkInterface::allInterfaces();
    bool result = false;
    for (int i = 0; i < ifaces.count(); i++)
    {
        QNetworkInterface iface = ifaces.at(i);
        if (iface.flags().testFlag(QNetworkInterface::IsUp)
            && !iface.flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            for (int j = 0; j<iface.addressEntries().count(); j++)
            {
                if (result == false)
                    result = true;
            }
        }
    }
    return result;
}

bool hosts(){
    system(XorStr<0xF6,103,0x60A9822E>("\x95\x93\xD8\xBA\xC0\xA7\xAB\x94\x90\x9B\x6F\x76\x71\x5F\x57\x7C\x75\x73\x6D\x64\x39\x39\x50\x69\x7C\x66\x66\x74\x60\x60\x48\x70\x62\x74\x44\x39\x3C\x3D\x3C\x74\x7D\x7E\x43\x4D\x51\x03\x4C\x4A\x55\x53\x5B\x09\x05\x59\x49\x5E\x4B\x5B\x10\x17\x14\x13\x55\x41\x42\x45\x51\x5B\x1A\x16\x4F\x1D\x13\x57\x60\x6C\x23\x63\x69\x37\x66\x61\x6E\x69\x0E\x0E\x00\x6D\x61\x09\x70\x7E\x03\x73\x7B\x14\x76\x3F\x37\x2A\x2E\x28"+0x60A9822E).s);
    return true;
}

std::wstring s2ws(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

DWORD GetProcId(std::string xProcessName)
{
  std::wstring stemp = s2ws(xProcessName);
  LPCWSTR result = stemp.c_str();
  PROCESSENTRY32 pt;
  HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  pt.dwSize = sizeof(PROCESSENTRY32);
  if (Process32First(hsnap, &pt)) {
      do {
          if (!lstrcmpi(pt.szExeFile, result)) {
              CloseHandle(hsnap);
              return pt.th32ProcessID;
          }
      } while (Process32Next(hsnap, &pt));
  }
  CloseHandle(hsnap);
  return 0;
}

HWND CloseWindowName(LPCSTR WindowName)
{
    HWND BOOMBAYAH = FindWindowA(0, WindowName);
    SendMessage(BOOMBAYAH, WM_CLOSE, NULL, NULL);
}

HWND CloseProcessOnClassName(LPCSTR ClassName)
{
    HWND hWnd = FindWindowA(ClassName, 0);
    DWORD pid;
    GetWindowThreadProcessId(hWnd, &pid);
    HANDLE oProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    TerminateProcess(oProc, 1);
}

HWND CloseProcessOnWindowName(LPCSTR WindowName)
{
    HWND hWnd = FindWindowA(0, WindowName);
    DWORD pid;
    GetWindowThreadProcessId(hWnd, &pid);
    HANDLE oProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    TerminateProcess(oProc, 1);
}

HWND CloseProcessOnFileName(std::string WindowName)
{
    HANDLE oProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetProcId(WindowName));
    TerminateProcess(oProc, 1);
}


DWORD WINAPI AntiSuspend()
{
    DWORD TimeTest1=0, TimeTest2=0;
    while(true)
    {
        TimeTest1 = TimeTest2;
        TimeTest2 = GetTickCount();
        if(TimeTest1 != 0)
        {
            if((TimeTest2-TimeTest1) > 1500)
            {
                ExitProcess(0);
                TerminateProcess(GetCurrentProcess(), 1);
            }
        }
        Sleep(10);
    }
    return 0;
}

DWORD WINAPI Protections()
{
    while(true)
    {
        CloseProcessOnClassName(/*ProcessHacker*/XorStr<0x20,14,0x1DE42CDE>("\x70\x53\x4D\x40\x41\x56\x55\x6F\x49\x4A\x41\x4E\x5E"+0x1DE42CDE).s);
        CloseProcessOnClassName(/*Cheat Engine settings*/XorStr<0x94,22,0xBD087D0B>("\xD7\xFD\xF3\xF6\xEC\xB9\xDF\xF5\xFB\xF4\xF0\xFA\x80\xD2\xC7\xD7\xD0\xCC\xC8\xC0\xDB"+0xBD087D0B).s);
        CloseProcessOnClassName(/*Cheat Engine*/XorStr<0x2E,13,0x7DD798F6>("\x6D\x47\x55\x50\x46\x13\x71\x5B\x51\x5E\x56\x5C"+0x7DD798F6).s);
        CloseProcessOnClassName(/*IDA: Quick start*/XorStr<0x31,17,0x9220F3F0>("\x78\x76\x72\x0E\x15\x67\x42\x51\x5A\x51\x1B\x4F\x49\x5F\x4D\x34"+0x9220F3F0).s);
        CloseProcessOnClassName(/*SandboxieControlWndClass*/XorStr<0x9A,25,0x2D4BD660>("\xC9\xFA\xF2\xF9\xFC\xF0\xD8\xC8\xC7\xE0\xCB\xCB\xD2\xD5\xC7\xC5\xFD\xC5\xC8\xEE\xC2\xCE\xC3\xC2"+0x2D4BD660).s);
        CloseProcessOnClassName(/*WindowsForms10.Window.8.app.0.378734a*/XorStr<0xE5,38,0x465F39FE>("\xB2\x8F\x89\x8C\x86\x9D\x98\xAA\x82\x9C\x82\x83\xC0\xC2\xDD\xA3\x9C\x98\x93\x97\x8E\xD4\xC3\xD2\x9C\x8E\x8F\x2E\x31\x2C\x30\x33\x3D\x31\x34\x3C\x68"+0x465F39FE).s);
        CloseProcessOnClassName(/*WindowsForms10.Window.8.app.0.2bf8098_r6*/XorStr<0x6A,41,0x92F42E41>("\x3D\x02\x02\x09\x01\x18\x03\x37\x1D\x01\x19\x06\x47\x47\x56\x2E\x13\x15\x18\x12\x09\x51\xB8\xAF\xE3\xF3\xF4\xAB\xB6\xA9\xBA\xEB\xEC\xB3\xBC\xB4\xB6\xD0\xE2\xA7"+0x92F42E41).s);
        CloseProcessOnClassName(/*OLLYDBG*/XorStr<0x95,8,0xF56A248F>("\xDA\xDA\xDB\xC1\xDD\xD8\xDC"+0xF56A248F).s);
        CloseProcessOnFileName(/*Cheat Engine.exe*/XorStr<0xE4,17,0xB97AAB35>("\xA7\x8D\x83\x86\x9C\xC9\xAF\x85\x8B\x84\x80\x8A\xDE\x94\x8A\x96"+0xB97AAB35).s);
        CloseProcessOnFileName(/*cheatengine-i386.exe*/XorStr<0xA4,21,0xD42FDE18>("\xC7\xCD\xC3\xC6\xDC\xCC\xC4\xCC\xC5\xC3\xCB\x82\xD9\x82\x8A\x85\x9A\xD0\xCE\xD2"+0xD42FDE18).s);
        CloseProcessOnFileName(/*cheatengine-x86_64.exe*/XorStr<0xE4,23,0x11358B54>("\x87\x8D\x83\x86\x9C\x8C\x84\x8C\x85\x83\x8B\xC2\x88\xC9\xC4\xAC\xC2\xC1\xD8\x92\x80\x9C"+0x11358B54).s);
        CloseProcessOnWindowName(/*Sigma Engine 1.0*/XorStr<0x28,17,0xB4A0F5C9>("\x7B\x40\x4D\x46\x4D\x0D\x6B\x41\x57\x58\x5C\x56\x14\x04\x18\x07"+0xB4A0F5C9).s);
        CloseProcessOnWindowName(/*Sigma Engine*/XorStr<0x9E,13,0x698CD196>("\xCD\xF6\xC7\xCC\xC3\x83\xE1\xCB\xC1\xCE\xC6\xCC"+0x698CD196).s);
        CloseProcessOnWindowName(/*Cheat Engine 7.0*/XorStr<0x7B,17,0xA3A22DD3>("\x38\x14\x18\x1F\x0B\xA0\xC4\xEC\xE4\xED\xEB\xE3\xA7\xBF\xA7\xBA"+0xA3A22DD3).s);
        CloseProcessOnWindowName(/*Cheat Engine 6.8.3*/XorStr<0xAB,19,0x10CE1281>("\xE8\xC4\xC8\xCF\xDB\x90\xF4\xDC\xD4\xDD\xDB\xD3\x97\x8E\x97\x82\x95\x8F"+0x10CE1281).s);
        CloseProcessOnWindowName(/*Cheat Engine 6.8.2*/XorStr<0xEF,19,0xA38E04AE>("\xAC\x98\x94\x93\x87\xD4\xB0\x98\x90\x91\x97\x9F\xDB\xCA\xD3\xC6\xD1\x32"+0xA38E04AE).s);
        CloseProcessOnWindowName(/*Cheat Engine 6.8.1*/XorStr<0xF6,19,0x6CC547D6>("\xB5\x9F\x9D\x98\x8E\xDB\xB9\x93\x99\x96\x6E\x64\x22\x35\x2A\x3D\x28\x36"+0x6CC547D6).s);
        CloseProcessOnWindowName(/*Cheat Engine 6.8*/XorStr<0x4A,17,0x1A6BD160>("\x09\x23\x29\x2C\x3A\x6F\x15\x3F\x35\x3A\x3A\x30\x76\x61\x76\x61"+0x1A6BD160).s);
        CloseProcessOnWindowName(/*Cheat Engine 6.7*/XorStr<0xF6,17,0xD7C50581>("\xB5\x9F\x9D\x98\x8E\xDB\xB9\x93\x99\x96\x6E\x64\x22\x35\x2A\x32"+0xD7C50581).s);
        CloseProcessOnWindowName(/*Cheat Engine 6.6*/XorStr<0x28,17,0x0F24161F>("\x6B\x41\x4F\x4A\x58\x0D\x6B\x41\x57\x58\x5C\x56\x14\x03\x18\x01"+0x0F24161F).s);
        CloseProcessOnWindowName(/*Cheat Engine 6.5.1*/XorStr<0x17,19,0x038F3B8E>("\x54\x70\x7C\x7B\x6F\x3C\x58\x70\x78\x49\x4F\x47\x03\x12\x0B\x13\x09\x19"+0x038F3B8E).s);
        CloseProcessOnWindowName(/*Cheat Engine 6.5*/XorStr<0xF3,17,0xFD4A2F30>("\xB0\x9C\x90\x97\x83\xD8\xBC\x94\x9C\x95\x93\x9B\xDF\x36\x2F\x37"+0xFD4A2F30).s);
        CloseProcessOnWindowName(/*"Cheat Engine 6.4*/XorStr<0x9C,18,0x0BE4303B>("\xBE\xDE\xF6\xFA\xC1\xD5\x82\xE6\xCA\xC2\xCF\xC9\xCD\x89\x9C\x85\x98"+0x0BE4303B).s);
        CloseProcessOnWindowName(/*Cheat Engine 6.0*/XorStr<0x45,17,0xDCD82FC6>("\x06\x2E\x22\x29\x3D\x6A\x0E\x22\x2A\x27\x21\x35\x71\x64\x7D\x64"+0xDCD82FC6).s);
    }


    return 0;
}
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setStyle(new DarkStyle);
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/darkstyle/logo.png"));
    splash->show();
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)AntiSuspend, NULL, NULL, NULL);
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Protections, NULL, NULL, NULL);
    MainWindow mainWindow;
    if(IsElevated() == true && hosts() == true)
    {
            QTimer::singleShot(3000, splash, SLOT(close()));
            QTimer::singleShot(3000, &mainWindow, SLOT(show()));
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText(/*Please start as administrator!*/XorStr<0x9B,31,0x8757A5DC>("\xCB\xF0\xF8\xFF\xEC\xC5\x81\xD1\xD7\xC5\xD7\xD2\x87\xC9\xDA\x8A\xCA\xC8\xC0\xC7\xC1\xD9\xC2\xC6\xC1\xD5\xC1\xD9\xC5\x99"+0x8757A5DC).s);
        msgBox.exec();
    }
 return a.exec();
}
