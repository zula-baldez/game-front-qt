#ifndef ROOMCHANGERESPONSE_H
#define ROOMCHANGERESPONSE_H

#include <QString>
#include <nlohmann/json.hpp>
#include <QObject>
using json = nlohmann::json;
class Room : public QObject
{
    Q_OBJECT



public:
    Q_PROPERTY(long capacity READ getCapacity)
    Q_PROPERTY(QString name READ getName)
    Q_PROPERTY(long id READ getId)
    Q_PROPERTY(long hostId READ getHostId )
    Q_PROPERTY(long count READ getCount WRITE setCount NOTIFY countChanged)

    Room();
    Room(const Room& room) {
        this->capacity = room.capacity;
        this->name = room.name;
        this->id = room.id;
        this->hostId = room.hostId;
        this->count = room.count;
    }
    Room& operator=(const Room& room) {
        this->capacity = room.capacity;
        this->name = room.name;
        this->id = room.id;
        this->hostId = room.hostId;
        return *this;
    }

    static Room parseFromJson(const json& j) {
        Room roomChangeResponse;
        j.at("capacity").get_to(roomChangeResponse.capacity);
        std::string name =  j.at("name");
        roomChangeResponse.name = QString::fromStdString(name);
        j.at("id").get_to(roomChangeResponse.id);
        j.at("hostId").get_to(roomChangeResponse.hostId);
        j.at("count").get_to(roomChangeResponse.count);

        return roomChangeResponse;
    }

    long getCapacity() const {
        return capacity;
    }
    QString getName() const {
        return name;
    }
    long getId()  const {
        return id;
    }
    long getHostId()const {
        return hostId;
    }
    long getCount() const {
        return count;
    }
    void setCount(long count) {
        this->count = count;
    }
    virtual  ~Room();
signals:
    void countChanged();
private:
    int capacity;
    QString name;
    long id;
    long hostId;
    int count;
};
Q_DECLARE_METATYPE(Room)

#endif // ROOMCHANGERESPONSE_H
