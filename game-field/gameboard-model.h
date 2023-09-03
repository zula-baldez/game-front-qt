
#ifndef GAMEBOARD-MODEL_H
#define GAMEBOARD-MODEL_H
#include <QAbstractListModel>
#include "player.h"
#include "screen-manager/global.h"
#include "StompSocket/stompsocket.h"

class GameBoard : public QAbstractListModel
{
    Q_OBJECT
public:
    enum CoordinateRoles {
        idRole = Qt::UserRole + 1,
        nameRole = Qt::UserRole + 2,
        cardsRole = Qt::UserRole + 3,
    };
    static constexpr size_t DEFAULT_PLAYERS  {5};
    GameBoard(QObject *parent = nullptr, size_t players_num = DEFAULT_PLAYERS);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int,QByteArray> roleNames() const override;
    Q_INVOKABLE  bool move (int index);

    void setPlayers(QVariantList data) {this->m_raw_board = data;};
    void addPlayer(Player player);
    void removeCardFromPlayer(Card card, int playerId);
    void addCardToPlayer(Card card, int playerId);

private:
    const size_t m_players_num;
    QVariantList m_raw_board;
    std::unordered_map<int, int> idToIndex;
    bool isPositionValid(const size_t position) const;

};

#endif // GAMEBOARD-MODEL_H
