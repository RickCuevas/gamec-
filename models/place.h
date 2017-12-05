#ifndef PLACE_H
#define PLACE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PlaceObject;
class QJsonArray;


class T_MODEL_EXPORT Place : public TAbstractModel
{
public:
    Place();
    Place(const Place &other);
    Place(const PlaceObject &object);
    ~Place();

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
    Place &operator=(const Place &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Place create(int space, const QString &name, const QString &url);
    static Place create(const QVariantMap &values);
    static Place get(int id);
    static Place get(int id, int lockRevision);
    static int count();
    static QList<Place> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<PlaceObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Place &model);
    friend QDataStream &operator>>(QDataStream &ds, Place &model);
};

Q_DECLARE_METATYPE(Place)
Q_DECLARE_METATYPE(QList<Place>)

#endif // PLACE_H
