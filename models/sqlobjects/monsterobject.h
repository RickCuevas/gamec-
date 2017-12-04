#ifndef MONSTEROBJECT_H
#define MONSTEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MonsterObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    int space {0};
    int hp {0};
    int attack {0};
    QString name;
    QString battle;
    QString url;
    QString created_at;
    QString updated_at;
    int lock_revision {0};

    enum PropertyIndex {
        Id = 0,
        Space,
        Hp,
        Attack,
        Name,
        Battle,
        Url,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QLatin1String("monster"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int space READ getspace WRITE setspace)
    T_DEFINE_PROPERTY(int, space)
    Q_PROPERTY(int hp READ gethp WRITE sethp)
    T_DEFINE_PROPERTY(int, hp)
    Q_PROPERTY(int attack READ getattack WRITE setattack)
    T_DEFINE_PROPERTY(int, attack)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
    Q_PROPERTY(QString battle READ getbattle WRITE setbattle)
    T_DEFINE_PROPERTY(QString, battle)
    Q_PROPERTY(QString url READ geturl WRITE seturl)
    T_DEFINE_PROPERTY(QString, url)
    Q_PROPERTY(QString created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QString, created_at)
    Q_PROPERTY(QString updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QString, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // MONSTEROBJECT_H
