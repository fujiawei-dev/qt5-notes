// Generated by [Toolkit-Py](https://github.com/fujiawei-dev/toolkit-py) Generator
// Created at 2022-03-17 10:46:59.925306, Version 0.12.13

#ifndef QML_GRID_LAYOUT__CORE_H
#define QML_GRID_LAYOUT__CORE_H

#include <QDebug>
#include <QObject>
#include <QSettings>
#include <QTimer>
#include <QWebSocket>

class Core : public QObject {
    Q_OBJECT

public:
    explicit Core(QObject *parent = nullptr);

    bool DebugMode;

    void InitConfig(QSettings *);

    Q_PROPERTY(bool debugMode MEMBER DebugMode);
    Q_PROPERTY(QList<QString> specialties MEMBER specialties);
    Q_PROPERTY(QString exportProperty MEMBER exportProperty);

    Q_INVOKABLE static QString getUuid();
    Q_INVOKABLE void connectToWebsocketServer(const QString &);
    Q_INVOKABLE void sendTextMessageToWebsocketServer(const QString &);

    static std::string AESEncryptStr(const QString &msgStr, const QString &keyStr);
    static std::string AESDecryptStr(const QString &msgStr, const QString &keyStr);

signals:
    void signalsExample();

public slots:
    void onExit();

private Q_SLOTS:
    void onWebsocketTimeout();
    void onWebsocketConnected();
    void onWebsocketDisconnected();
    void onWebsocketTextMessageReceived(const QString &message);

private:
    // variables from config file
    QSettings *settings{};
    QString exportProperty;

    QString remoteServerHttp;
    QString remoteServerHttpBasePath;

    QWebSocket *websocketClient;
    QString websocketUri;
    QString websocketUrl;
    QTimer websocketTimer;

    QList<QString> specialties = {};
};

#endif//QML_GRID_LAYOUT__CORE_H
