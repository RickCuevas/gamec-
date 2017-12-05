#ifndef PLACECONTROLLER_H
#define PLACECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PlaceController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    PlaceController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // PLACECONTROLLER_H
