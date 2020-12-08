QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      =  WoXSys
TEMPLATE    =  app



FORMS       += mainwindow.ui

RESOURCES   += \
    theme/resources.qrc \
    theme/resources.qrc \
    darkstyle.qrc

HEADERS += \
    theme/qtmaterialappbar.h \
    theme/qtmaterialappbar_p.h \
    theme/qtmaterialautocomplete.h \
    theme/qtmaterialautocomplete_internal.h \
    theme/qtmaterialautocomplete_p.h \
    theme/qtmaterialavatar.h \
    theme/qtmaterialavatar_p.h \
    theme/qtmaterialbadge.h \
    theme/qtmaterialbadge_p.h \
    theme/qtmaterialcheckable.h \
    theme/qtmaterialcheckable_internal.h \
    theme/qtmaterialcheckable_p.h \
    theme/qtmaterialcheckbox.h \
    theme/qtmaterialcheckbox_p.h \
    theme/qtmaterialcircularprogress.h \
    theme/qtmaterialcircularprogress_internal.h \
    theme/qtmaterialcircularprogress_p.h \
    theme/qtmaterialdialog.h \
    theme/qtmaterialdialog_internal.h \
    theme/qtmaterialdialog_p.h \
    theme/qtmaterialdrawer.h \
    theme/qtmaterialdrawer_internal.h \
    theme/qtmaterialdrawer_p.h \
    theme/qtmaterialfab.h \
    theme/qtmaterialfab_p.h \
    theme/qtmaterialflatbutton.h \
    theme/qtmaterialflatbutton_internal.h \
    theme/qtmaterialflatbutton_p.h \
    theme/qtmaterialiconbutton.h \
    theme/qtmaterialiconbutton_p.h \
    theme/qtmateriallist.h \
    theme/qtmateriallist_p.h \
    theme/qtmateriallistitem.h \
    theme/qtmateriallistitem_p.h \
    theme/qtmaterialmenu.h \
    theme/qtmaterialmenu_internal.h \
    theme/qtmaterialmenu_p.h \
    theme/qtmaterialoverlaywidget.h \
    theme/qtmaterialpaper.h \
    theme/qtmaterialpaper_p.h \
    theme/qtmaterialprogress.h \
    theme/qtmaterialprogress_internal.h \
    theme/qtmaterialprogress_p.h \
    theme/qtmaterialradiobutton.h \
    theme/qtmaterialradiobutton_p.h \
    theme/qtmaterialraisedbutton.h \
    theme/qtmaterialraisedbutton_p.h \
    theme/qtmaterialripple.h \
    theme/qtmaterialrippleoverlay.h \
    theme/qtmaterialscrollbar.h \
    theme/qtmaterialscrollbar_internal.h \
    theme/qtmaterialscrollbar_p.h \
    theme/qtmaterialslider.h \
    theme/qtmaterialslider_internal.h \
    theme/qtmaterialslider_p.h \
    theme/qtmaterialsnackbar.h \
    theme/qtmaterialsnackbar_internal.h \
    theme/qtmaterialsnackbar_p.h \
    theme/qtmaterialstatetransition.h \
    theme/qtmaterialstatetransitionevent.h \
    theme/qtmaterialstyle.h \
    theme/qtmaterialstyle_p.h \
    theme/qtmaterialtable.h \
    theme/qtmaterialtable_p.h \
    theme/qtmaterialtabs.h \
    theme/qtmaterialtabs_internal.h \
    theme/qtmaterialtabs_p.h \
    theme/qtmaterialtextfield.h \
    theme/qtmaterialtextfield_internal.h \
    theme/qtmaterialtextfield_p.h \
    theme/qtmaterialtheme.h \
    theme/qtmaterialtheme_p.h \
    theme/qtmaterialtoggle.h \
    theme/qtmaterialtoggle_internal.h \
    theme/qtmaterialtoggle_p.h \
    DarkStyle.h \
    mainwindow.h \
    windowdragger.h \
    xfapi.h \
    mycrypt.h \
    base64.h \
    xor.h \
    popup.h \
    chatterboxserver.h \
    injector.h

SOURCES += \
    theme/qtmaterialappbar.cpp \
    theme/qtmaterialautocomplete.cpp \
    theme/qtmaterialautocomplete_internal.cpp \
    theme/qtmaterialavatar.cpp \
    theme/qtmaterialbadge.cpp \
    theme/qtmaterialcheckable.cpp \
    theme/qtmaterialcheckable_internal.cpp \
    theme/qtmaterialcheckbox.cpp \
    theme/qtmaterialcircularprogress.cpp \
    theme/qtmaterialcircularprogress_internal.cpp \
    theme/qtmaterialdialog.cpp \
    theme/qtmaterialdialog_internal.cpp \
    theme/qtmaterialdrawer.cpp \
    theme/qtmaterialdrawer_internal.cpp \
    theme/qtmaterialfab.cpp \
    theme/qtmaterialflatbutton.cpp \
    theme/qtmaterialflatbutton_internal.cpp \
    theme/qtmaterialiconbutton.cpp \
    theme/qtmateriallist.cpp \
    theme/qtmateriallistitem.cpp \
    theme/qtmaterialmenu.cpp \
    theme/qtmaterialmenu_internal.cpp \
    theme/qtmaterialoverlaywidget.cpp \
    theme/qtmaterialpaper.cpp \
    theme/qtmaterialprogress.cpp \
    theme/qtmaterialprogress_internal.cpp \
    theme/qtmaterialradiobutton.cpp \
    theme/qtmaterialraisedbutton.cpp \
    theme/qtmaterialripple.cpp \
    theme/qtmaterialrippleoverlay.cpp \
    theme/qtmaterialscrollbar.cpp \
    theme/qtmaterialscrollbar_internal.cpp \
    theme/qtmaterialslider.cpp \
    theme/qtmaterialslider_internal.cpp \
    theme/qtmaterialsnackbar.cpp \
    theme/qtmaterialsnackbar_internal.cpp \
    theme/qtmaterialstatetransition.cpp \
    theme/qtmaterialstyle.cpp \
    theme/qtmaterialtable.cpp \
    theme/qtmaterialtabs.cpp \
    theme/qtmaterialtabs_internal.cpp \
    theme/qtmaterialtextfield.cpp \
    theme/qtmaterialtextfield_internal.cpp \
    theme/qtmaterialtheme.cpp \
    theme/qtmaterialtoggle.cpp \
    theme/qtmaterialtoggle_internal.cpp \
    DarkStyle.cpp \
    main.cpp \
    mainwindow.cpp \
    windowdragger.cpp \
    mycrypt.cpp \
    base64.cpp \
    popup.cpp \
    chatterboxserver.cpp
