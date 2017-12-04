#include <TreeFrogModel>
#include "game.h"
#include "gameobject.h"

Game::Game()
    : TAbstractModel(), d(new GameObject())
{
    d->id = 0;
    d->lock_revision = 0;
}

Game::Game(const Game &other)
    : TAbstractModel(), d(new GameObject(*other.d))
{ }

Game::Game(const GameObject &object)
    : TAbstractModel(), d(new GameObject(object))
{ }

Game::~Game()
{
    // If the reference count becomes 0,
    // the shared data object 'GameObject' is deleted.
}

int Game::id() const
{
    return d->id;
}

QString Game::createdAt() const
{
    return d->created_at;
}

QString Game::updatedAt() const
{
    return d->updated_at;
}

int Game::lockRevision() const
{
    return d->lock_revision;
}

Game &Game::operator=(const Game &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Game Game::create(const QString &)
{
    GameObject obj;
    if (!obj.create()) {
        return Game();
    }
    return Game(obj);
}

Game Game::create(const QVariantMap &values)
{
    Game model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Game Game::get(int id)
{
    TSqlORMapper<GameObject> mapper;
    return Game(mapper.findByPrimaryKey(id));
}

Game Game::get(int id, int lockRevision)
{
    TSqlORMapper<GameObject> mapper;
    TCriteria cri;
    cri.add(GameObject::Id, id);
    cri.add(GameObject::LockRevision, lockRevision);
    return Game(mapper.findFirst(cri));
}

int Game::count()
{
    TSqlORMapper<GameObject> mapper;
    return mapper.findCount();
}

QList<Game> Game::getAll()
{
    return tfGetModelListByCriteria<Game, GameObject>(TCriteria());
}

QJsonArray Game::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<GameObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<GameObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Game(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Game::modelData()
{
    return d.data();
}

const TModelObject *Game::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Game &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Game &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Game)
