#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT GameObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString created_at;
    QString updated_at;
    int lock_revision {0};

    enum PropertyIndex {
        Id = 0,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QLatin1String("game"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QString, created_at)
    Q_PROPERTY(QString updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QString, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // GAMEOBJECT_H
