#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <QVariant>
#include <QVariantList>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Player : public QObject
{
    Q_OBJECT

public:

    Q_PROPERTY(int id READ getId)
    Q_PROPERTY(QString name READ getName)
    Q_PROPERTY(QVariantList cards READ getCards)

    Player(int id, QString name);
    Player() = default;
    Player(const Player& player) : _cards(player._cards), _id(player._id), _name(player._name) {}

    int getId() const;
    QString getName() const;
    QVariantList getCards() const;

    void addCard(Card& card);
    void removeCard(Card& card);
    static Player parseFromJson(const json& j) {
        Player player;
        j.at("id").get_to(player._id);
        std::string name =  j.at("name");
        player._name = QString::fromStdString(name);
        j.at("fines").get_to(player._fines);
        j.at("additionalCards").get_to(player._additionalCards);

        return player;
    }
private:
    QVariantList _cards = QVariantList();
    int _id;
    QString _name;
    int _fines = 0;
    int _additionalCards = 0;

};


Q_DECLARE_METATYPE(Player)

#endif // PLAYER_H
