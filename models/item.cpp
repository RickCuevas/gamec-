#include <TreeFrogModel>
#include "item.h"
#include "itemobject.h"

Item::Item()
    : TAbstractModel(), d(new ItemObject())
{
    d->id = 0;
    d->space = 0;
    d->lock_revision = 0;
}

Item::Item(const Item &other)
    : TAbstractModel(), d(new ItemObject(*other.d))
{ }

Item::Item(const ItemObject &object)
    : TAbstractModel(), d(new ItemObject(object))
{ }

Item::~Item()
{
    // If the reference count becomes 0,
    // the shared data object 'ItemObject' is deleted.
}

int Item::id() const
{
    return d->id;
}

int Item::space() const
{
    return d->space;
}

void Item::setSpace(int space)
{
    d->space = space;
}

QString Item::name() const
{
    return d->name;
}

void Item::setName(const QString &name)
{
    d->name = name;
}

QString Item::url() const
{
    return d->url;
}

void Item::setUrl(const QString &url)
{
    d->url = url;
}

QString Item::createdAt() const
{
    return d->created_at;
}

QString Item::updatedAt() const
{
    return d->updated_at;
}

int Item::lockRevision() const
{
    return d->lock_revision;
}

Item &Item::operator=(const Item &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Item Item::create(int space, const QString &name, const QString &url)
{
    ItemObject obj;
    obj.space = space;
    obj.name = name;
    obj.url = url;
    if (!obj.create()) {
        return Item();
    }
    return Item(obj);
}

Item Item::create(const QVariantMap &values)
{
    Item model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Item Item::get(int id)
{
    TSqlORMapper<ItemObject> mapper;
    return Item(mapper.findByPrimaryKey(id));
}

Item Item::get(int id, int lockRevision)
{
    TSqlORMapper<ItemObject> mapper;
    TCriteria cri;
    cri.add(ItemObject::Id, id);
    cri.add(ItemObject::LockRevision, lockRevision);
    return Item(mapper.findFirst(cri));
}

int Item::count()
{
    TSqlORMapper<ItemObject> mapper;
    return mapper.findCount();
}

QList<Item> Item::getAll()
{
    return tfGetModelListByCriteria<Item, ItemObject>(TCriteria());
}

QJsonArray Item::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ItemObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ItemObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Item(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Item::modelData()
{
    return d.data();
}

const TModelObject *Item::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Item &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Item &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Item)
