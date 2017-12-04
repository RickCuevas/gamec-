#ifndef PLAYER_H
#define PLAYER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PlayerObject;
class QJsonArray;


class T_MODEL_EXPORT Player : public TAbstractModel
{
public:
    Player();
    Player(const Player &other);
    Player(const PlayerObject &object);
    ~Player();

    int id() const;
    int hp() const;
    void setHp(int hp);
    int xp() const;
    void setXp(int xp);
    int space() const;
    void setSpace(int space);
    QString alignment() const;
    void setAlignment(const QString &alignment);
    QString name() const;
    void setName(const QString &name);
    QString createdAt() const;
    QString updatedAt() const;
    int lockRevision() const;
    Player &operator=(const Player &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Player create(int hp, int xp, int space, const QString &alignment, const QString &name);
    static Player create(const QVariantMap &values);
    static Player get(int id);
    static Player get(int id, int lockRevision);
    static int count();
    static QList<Player> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<PlayerObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Player &model);
    friend QDataStream &operator>>(QDataStream &ds, Player &model);
};

Q_DECLARE_METATYPE(Player)
Q_DECLARE_METATYPE(QList<Player>)

#endif // PLAYER_H
