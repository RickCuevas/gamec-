#include <TreeFrogModel>
#include "place.h"
#include "placeobject.h"

Place::Place()
    : TAbstractModel(), d(new PlaceObject())
{
    d->id = 0;
    d->space = 0;
    d->lock_revision = 0;
}

Place::Place(const Place &other)
    : TAbstractModel(), d(new PlaceObject(*other.d))
{ }

Place::Place(const PlaceObject &object)
    : TAbstractModel(), d(new PlaceObject(object))
{ }

Place::~Place()
{
    // If the reference count becomes 0,
    // the shared data object 'PlaceObject' is deleted.
}

int Place::id() const
{
    return d->id;
}

int Place::space() const
{
    return d->space;
}

void Place::setSpace(int space)
{
    d->space = space;
}

QString Place::name() const
{
    return d->name;
}

void Place::setName(const QString &name)
{
    d->name = name;
}

QString Place::url() const
{
    return d->url;
}

void Place::setUrl(const QString &url)
{
    d->url = url;
}

QString Place::createdAt() const
{
    return d->created_at;
}

QString Place::updatedAt() const
{
    return d->updated_at;
}

int Place::lockRevision() const
{
    return d->lock_revision;
}

Place &Place::operator=(const Place &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Place Place::create(int space, const QString &name, const QString &url)
{
    PlaceObject obj;
    obj.space = space;
    obj.name = name;
    obj.url = url;
    if (!obj.create()) {
        return Place();
    }
    return Place(obj);
}

Place Place::create(const QVariantMap &values)
{
    Place model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Place Place::get(int id)
{
    TSqlORMapper<PlaceObject> mapper;
    return Place(mapper.findByPrimaryKey(id));
}

Place Place::get(int id, int lockRevision)
{
    TSqlORMapper<PlaceObject> mapper;
    TCriteria cri;
    cri.add(PlaceObject::Id, id);
    cri.add(PlaceObject::LockRevision, lockRevision);
    return Place(mapper.findFirst(cri));
}

int Place::count()
{
    TSqlORMapper<PlaceObject> mapper;
    return mapper.findCount();
}

QList<Place> Place::getAll()
{
    return tfGetModelListByCriteria<Place, PlaceObject>(TCriteria());
}

QJsonArray Place::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<PlaceObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<PlaceObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Place(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Place::modelData()
{
    return d.data();
}

const TModelObject *Place::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Place &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Place &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Place)
