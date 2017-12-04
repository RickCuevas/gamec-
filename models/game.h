#ifndef GAME_H
#define GAME_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class GameObject;
class QJsonArray;


class T_MODEL_EXPORT Game : public TAbstractModel
{
public:
    Game();
    Game(const Game &other);
    Game(const GameObject &object);
    ~Game();

    int id() const;
    QString createdAt() const;
    QString updatedAt() const;
    int lockRevision() const;
    Game &operator=(const Game &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Game create(const QString &);
    static Game create(const QVariantMap &values);
    static Game get(int id);
    static Game get(int id, int lockRevision);
    static int count();
    static QList<Game> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<GameObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Game &model);
    friend QDataStream &operator>>(QDataStream &ds, Game &model);
};

Q_DECLARE_METATYPE(Game)
Q_DECLARE_METATYPE(QList<Game>)

#endif // GAME_H
