/*  JOHN LOEFFLER
 *  CISC 3150
 *  SUMMER II 2017
 *
 *      POKERHANDCOMPARATOR::CARD
 */
#ifndef CARD_H
#define CARD_H
#include "Suit.h"
#include "Value.h"
#include <string>

/**
*   @DESCRIPTION    A CLASS REPRESENTING A STANDARD PLAYING CARD
*/
class   Card{
            //      PRIVATE     DATA    MEMBERS     //
    Suit        suit;                   //  THE SUIT OF THE CARD
    Value       value;                  //  THE FACE VALUE OF THE CARD
    std::string face;                   //  THE NAME FOR THE CARD, IE 2 OF CLUBS

public:
            //      PUBLIC      MEMBER      FUNCTIONS       //
                    //  CONSTRUCTORS    //
/**
 *  DEFAULT CONSTRUCTOR
 */
    Card(){};
/**
 *  PARAMETERIZED CONSTRUCTOR
 *  @param  (s)  SUIT ENUM OF THE CARD
 *  @param  (v)  VALUE ENUM OF THE CARD
 */
    Card(Suit s, Value v){
        this->setSuit(s);
        this->setValue(v);
        this->translateValues();
    }

/**
 *  COPY CONSTRUCTOR
 *  @param (c)  A CARD OBJECT
 */
    Card(const Card& c){
        this->setSuit(c.getSuit());
        this->setValue(c.getValue());
        this->setFace(c.getFace());
    }
                    //      SETTERS     //
/**
 *  SETTER FOR SUIT DATA MEMBER
 *  @param  s   A SUIT ENUM
 */
    void        setSuit(Suit s)         {   this->suit  =   s;  }
 /**
  * SETTER FOR VALUE DATA MEMBER
  * @param  v   A VALUE ENUM
  */
    void        setValue(Value v)       {   this->value =   v;  }

/**
 *  SETTER FOR FACE DATA MEMBER
 *  @param  f   A STRING HOLDING THE READABLE NAME OF THE CARD
 */
    void        setFace(std::string f)  {   this->face  =   f;  }
                    //      GETTERS     //
/**
  * GETTER FOR SUIT DATA MEMBER
  * @return A SUIT ENUM
  */
    Suit        getSuit() const         {   return this->suit;  }
 /**
  * GETTER FOR VALUE DATA MEMBER
  * @return A VALUE ENUM
  */
    Value       getValue()const         {   return this->value; }

/**
 *  GETTER FOR FACE DATA MEMBER
 *  @return A STRING HOLDING THE READABLE NAME OF THE CARD
 */
    std::string getFace() const         {   return this->face;  }

                    //      UTILITY     //
/**
 *   TAKES THE ENUMS OF SUIT AND VALUE AND CREATES A READABLE NAME AS STRING
 */
    void    translateValues(){
        std::string name;
        switch(this->getValue()){
            case 0:
                name = "Two of";
                break;
            case 1:
                name = "Three of";
                break;
            case 2:
                name = "Four of";
                break;
            case 3:
                name = "Five of";
                break;
            case 4:
                name = "Six of";
                break;
            case 5:
                name = "Seven of";
                break;
            case 6:
                name = "Eight of";
                break;
            case 7:
                name = "Nine of";
                break;
            case 8:
                name = "Ten of";
                break;
            case 9:
                name = "Jack of";
                break;
            case 10:
                name = "Queen of";
                break;
            case 11:
                name = "King of";
                break;
            case 12:
                name = "Ace of";
                break;
            default:
                name = "Invalid value";
                break;
        }
        switch(this->getSuit()){
            case 0:
                name += " Clubs";
                break;
            case 1:
                name += " Diamonds";
                break;
            case 2:
                name += " Hearts";
                break;
            case 3:
                name += " Spades";
                break;
            default:
                name += "invalid card!";
                break;
        }
        this->setFace(name);
    }

                    //  OVERLOADED OPERATORS    //
    inline bool operator< (const Card& rhs) {
        return this->value < rhs.value;
    }
    inline bool operator> (const Card& rhs) {return rhs.value < this->value; }
    inline bool operator<=(const Card& rhs) {return !(this->value > rhs.value);}
    inline bool operator>=(const Card& rhs) {return !(this->value < rhs.value);}
    inline bool operator==(const Card& rhs) {return this->value ==  rhs.value; }
    inline bool operator!=(const Card& rhs) {return !(this->value== rhs.value);}
};
#endif // CARD_H
