#pragma once

#include <QObject>
#include <QAction>
#include <QString>

class Action : public QAction {
    Q_OBJECT
public:
    explicit Action(QString name, QString iconName, QObject *parent);
};

class CopyAction : public Action {
    Q_OBJECT
public:
    explicit CopyAction(QObject *parent);
};

class CutAction : public Action {
    Q_OBJECT
public:
    explicit CutAction(QObject *parent);
};

class PasteAction : public Action {
    Q_OBJECT
public:
    explicit PasteAction(QObject *parent);
};

class RedoAction : public Action {
    Q_OBJECT
public:
    RedoAction(QObject *parent);
};

class SelectAllAction : public Action {
    Q_OBJECT
public:
    explicit SelectAllAction(QObject *parent);
};

class UndoAction : public Action {
    Q_OBJECT
public:
    explicit UndoAction(QObject *parent);
};

