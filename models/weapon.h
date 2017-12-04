#ifndef WEAPON_H
#define WEAPON_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WeaponObject;
class QJsonArray;


class T_MODEL_EXPORT Weapon : public TAbstractModel
{
public:
    Weapon();
    Weapon(const Weapon &other);
    Weapon(const WeaponObject &object);
    ~Weapon();

    int id() const;
    int space() const;
    void setSpace(int space);
    int attack() const;
    void setAttack(int attack);
    QString name() const;
    void setName(const QString &name);
    QString equipped() const;
    void setEquipped(const QString &equipped);
    QString main() const;
    void setMain(const QString &main);
    QString url() const;
    void setUrl(const QString &url);
    QString createdAt() const;
    QString updatedAt() const;
    int lockRevision() const;
    Weapon &operator=(const Weapon &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Weapon create(int space, int attack, const QString &name, const QString &equipped, const QString &main, const QString &url);
    static Weapon create(const QVariantMap &values);
    static Weapon get(int id);
    static Weapon get(int id, int lockRevision);
    static int count();
    static QList<Weapon> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<WeaponObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Weapon &model);
    friend QDataStream &operator>>(QDataStream &ds, Weapon &model);
};

Q_DECLARE_METATYPE(Weapon)
Q_DECLARE_METATYPE(QList<Weapon>)


#endif // WEAPON_H
