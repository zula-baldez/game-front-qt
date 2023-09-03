#ifndef ROOMMODEL_H
#define ROOMMODEL_H
#pragma once
#include "StompSocket/stompsocket.h"
#include <QAbstractListModel>
#include "screen-manager/global.h"
#include <nlohmann/json.hpp>
#include "room.h"
#include <unordered_map>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

class RoomModel :  public QAbstractListModel
{
    Q_OBJECT
public:

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    bool isPositionValid(const size_t position) const;
    enum CoordinateRoles {
        capacityRole = Qt::UserRole + 1,
        nameRole = Qt::UserRole + 2,
        idRole = Qt::UserRole + 3,
        hostIdRole = Qt::UserRole + 4,
        countRole = Qt::UserRole + 5,
    };
    QHash<int,QByteArray> roleNames() const override;
    virtual ~RoomModel();
    void addRoomToModel(Room room);
    void setModel(std::vector<Room> rooms);
private:
    GlobalPropertyHolder* _globalPropertyHolder =  GlobalPropertyHolder::instance();
    //todo  globalPropertyHolder->token()
    std::mutex _mutex;
    std::condition_variable _condition;
    bool _functionCallComplete = false;
    std::vector<Room> _model;

public:
    RoomModel();
};

#endif // ROOMMODEL_H
