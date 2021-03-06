#ifndef RANK_H
#define RANK_H

#include "Value.h"
#include "Quality.h"
#include <deque>

class   Rank{
     //      INTERNAL    STRUCTURES      //
    /**
     *  AN ENUM LISTING ALL POSSIBLE WINNING POKER HANDS
     */
private:
    //      PRIVATE DATA MEMBERS        //
    Quality             qual;
    std::deque<Value>   hValue;

public:
    //      PUBLIC MEMBER FUNCTIONS     //
        //      CONSTRUCTORS        //

    /**
     *  DEFAULT CONSTRUCTOR
     */
    Rank(){};

    /**
     *  PARAMETERIZED CONSTRUCTOR
     *  @param  q   A QUALITY ENUM
     *  @param  v   A DEQUE OF VALUE ENUMS
     */
     Rank(Quality q, std::deque<Value> v){
         this->setQuality(q);
         this->setValues(v);
    }

        //  SETTERS //
    /**
     *  SETS THE QUALITY DATA MEMBER
     *  @param  q   A QUALITY ENUM
     */
    void                setQuality(Quality q)           {this->qual =   q;}

    /**
    *   SETS THE HVALUE DATA MEMBER
    *   @param  v   A DEQUE OF VALUE ENUMS
    */
    void                setValues(std::deque<Value> v)  {this->hValue=   v;}

        //  GETTERS //
    /**
     *  GETS THE QUALITY OF THE HAND
     *  @return     A QUALITY ENUM
     */
    Quality             getQuality() const              {return this->qual;}

    /**
     *  GETS THE DEQUE OF VALUE ENUMS
     *  @return         A DEQUE OF VALUE ENUM
     */
    std::deque<Value>  getValues() const    {return this->hValue;}

        //  UTILITY //

    /**
    *   COMPARES A RANK OBJECT AGAINST ITSELF
    *   @param  A CONST REFERENCE TO A RANK OBJECT
    *   @return -1 IF CALLER IS LOWER THAN OTHER RANK, 0 IF EQUAL, 1 IF HIGHER
    */
    int     beats(const Rank& rhs) const{
        if(this->getQuality() == rhs.getQuality()){
            if(this->getValues() == rhs.getValues())
                return 0;
            else if(this->getValues() < rhs.getValues())
                return -1;
            else
                return 1;
        }
        else if(this->getQuality() < rhs.getQuality())
            return -1;
        else
            return 1;
    }
};

#endif // RANK_H
