
#ifndef CARD_H
#define CARD_H

#include <QObject>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Card  : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int strenght READ getStrenght)
    Q_PROPERTY(QString suit READ getSuit)
    Q_PROPERTY(int id READ getId)
    Q_PROPERTY(QString imgUrl READ getImgUrl)


public:
    Card(int strenght, QString suit, int id, QString imgUrl);
    Card() = default;
    Card(const Card& card) : _strenght(card._strenght), _suit(card._suit), _id(card._id), _imgUrl(card._imgUrl) {}
    int getStrenght();
    QString getSuit();
    int getId();
    QString getImgUrl();
    static Card parseFromJson(const json& j) {
        Card card;
        j.at("id").get_to(card._id);
        j.at("strenght").get_to(card._strenght);
        j.at("secret").get_to(card._secret);

        std::string suit =  j.at("suit");

        card._suit = QString::fromStdString(suit);
        card._imgUrl = QString::fromStdString("../UI/Assets/"+std::to_string(card._id)+".png");

        return card;
    }


private:
    int _strenght;
    QString _suit;
    bool _secret;
    int _id;
    QString _imgUrl = "";
};
Q_DECLARE_METATYPE(Card)

#endif // CARD_H
