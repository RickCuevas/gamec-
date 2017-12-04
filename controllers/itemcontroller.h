#ifndef ITEMCONTROLLER_H
#define ITEMCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ItemController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    ItemController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // ITEMCONTROLLER_H
