#ifndef ITEM_H
#define ITEM_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ItemObject;
class QJsonArray;


class T_MODEL_EXPORT Item : public TAbstractModel
{
public:
    Item();
    Item(const Item &other);
    Item(const ItemObject &object);
    ~Item();

    int id() const;
    int space() const;
    void setSpace(int space);
    QString name() const;
    void setName(const QString &name);
    QString url() const;
    void setUrl(const QString &url);
    QString createdAt() const;
    QString updatedAt() const;
    int lockRevision() const;
    Item &operator=(const Item &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Item create(int space, const QString &name, const QString &url);
    static Item create(const QVariantMap &values);
    static Item get(int id);
    static Item get(int id, int lockRevision);
    static int count();
    static QList<Item> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ItemObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Item &model);
    friend QDataStream &operator>>(QDataStream &ds, Item &model);
};

Q_DECLARE_METATYPE(Item)
Q_DECLARE_METATYPE(QList<Item>)

#endif // ITEM_H
