#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "Rank.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  @DESCRIPTION    A CLASS REPRESENTING A HAND OF STANDARD PLAYING CARDS
 */
class   Hand{
        //      PRIVATE DATA    MEMBERS     //
    std::vector<Card>   cards;
    Rank                rank;
public:
        //      PUBLIC  MEMBER  METHODS     //
            //  CONSTRUCTORS    //
    /**
    *   PARAMETERIZED CONSTRUCTOR
    *   @param  c   A VECTOR OF CARD OBJECTS
    */
    Hand(std::vector<Card> c)  {this->setCards(c);this->qualify();
    }

            //  SETTERS         //

    /**
    *   SETS THE CARDS IN THE HAND
    *   @param  A VECTOR OF CARD OBJECTS
    */
    void        setCards(std::vector<Card> c)      {this->cards = c;}

    /**
    *   SETS THE RANK OF THE HAND
    *   @param  A RANK OBJECT
    */
    void        setRank(Rank r)             {this->rank = r;}

            //  GETTERS         //

    /**
    *   GETS THE CARDS IN THE HAND
    *   @return A VECTOR OF CARD OBJECTS
    */
    std::vector<Card>  getCards()  const           {return this->cards;}

    /**
    *   GETS THE RANK OF THE HAND
    *   @return A RANK OBJECT
    */
    Rank        getRank()   const           {return this->rank;}

            //  UTILITY FUNCTIONS   //
    /**
    *   COMPARES A HAND OBJECT AGAINST ITSELF
    *   @param  A CONST REFERENCE TO A HAND OBJECT
    *   @return -1 IF CALLER LOSES TO OTHER HAND, 0 IF THEY TIE, 1 IF IT WINS
    */
    int         beats(const Hand& rhs) const{
        return this->getRank().beats(rhs.getRank());
    }
    ////////////////////////////////////////////////////////////
    /**
    *   DETERMINES THE QUALITY OF THE HAND AND RANKS IT
    *
    */
    ////////////////////////////////////////////////////////////
    void    qualify(){
std::cout<<"IN HAND::QUALIFY()"<<std::endl;
        //  DECLARE WORKING VARIABLES
        Rank                r;
        std::deque<Value>   v, test;
std::cout<<"-1-";

        //  CHECKS TO SEE WHETHER THE HAND IS A FLUSH, STRAIGHT, OR BOTH
        //  FLAGS SET TO TRUE BY DEFAULT SINCE ONE BAD CARD CAN BREAK A
        //       FLUSH OR STRAIGHT, SO ONCE FOUND, WE CAN STOP CHECKING
        bool flush = true, straight = true;
std::cout<< std::endl <<"IN FLUSHSTRAIGHTLOOP" << endl;
        for(int i = 1; i <5; i++){
std::cout<< std::endl <<"    Loop " << i << " --- ";
std::cout<<"flush is ";
if(flush)
    std::cout << "true --- ";
else
    std::cout << "false --- ";
            if(flush && this->cards[i].getSuit()
                            != this->cards[i-1].getSuit()){
                flush = false;
            }
std::cout<<"straight is ";
if(straight)
    std::cout << "true";
else
    std::cout << "false";
std::cout<< endl;

            if(straight && this->cards[i].getValue()
                            != this->cards[i-1].getValue()-1){
                straight = false;
            }

        }
std::cout <<"EXITING FLUSHSTRAIGHTLOOP"<<std::endl;
            //  IF YES TO ANY OF THESE,
                //  SET THE APPROPRIATE HAND QUALITY AND SET THE FIRST POSITION
                //      OF RANK.VALUE AS THE HIGH CARD IN THE HAND AND RETURN
std::cout<<"Setting Quality of Hand"<<std::endl;
        if(flush){
std::cout<<"    Flush is true..."<<std::endl;
            if(straight){
std::cout<<"        and Straight is true..."<<std::endl;
                r.setQuality(Quality::STRAIGHTFLUSH);
std::cout<< "Quality = " << r.getQuality() << std::endl;
            }else{
                r.setQuality(Quality::FLUSH);
std::cout<< "Quality = " << r.getQuality() << std::endl;
            }
            v.push_back(this->cards[0].getValue());
            r.setValues(v);
            this->setRank(r);
            test = r.getValues();
std::cout<< "Value of High Card: " << test.at(0) << std::endl;
            return;
        }
        else if(straight){
std::cout<< "Straight is true" << endl;
            r.setQuality(Quality::STRAIGHT);    //  SET QUALITY
std::cout<< "Quality = " << r.getQuality() << std::endl;

            v.push_back(this->cards[0].getValue());// SET HIGHCARD
            r.setValues(v);                       //  ASSIGN VALUES TO R
            this->setRank(r);                     //  ASSIGN R TO CALLING 'HAND'
            test = r.getValues();   /*<-FOR TESTING, TO BE DELETED*/
//TODO:  PRINT OUT THE INFORMATION ABOUT TEST TO CONSOLE, VALUES, SIZE, ETC
std::cout<< "Value of High Card: " << test.at(0) << std::endl;
            return;
        }
        else{
std::cout<< "NO FLUSH OR STRAIGHT" << std::endl;
        }
            //  IF NOT,
                //  CREATE BOOL[] TO HOLD POSITION OF MATCHING VALUES
                //      BOOL[I] VALUE IS TRUE IF CARD IN POSITION [I] MATCHES
                //      VALUE OF CARD IN POSITION [I+1]
                //      THESE VALUES ARE NEEDED FOR SENTINEL FUNCTIONS THAT
                //      WILL ORDER THE FINAL CARD VALUES OF THE HAND FOR PURPOSE
                //      OF COMPARING ONE HAND TO ANOTHER
        bool match[5];
                //  CREATE COUNTERS FOR CARDS, PAIR, THREE, AND FOUR OF A KIND
        int count = 1, pair = 0, three = 0, four = 0;
                //  CREATE FOR LOOP, 4 PASSES
std::cout<< "ENTERING CARD COUNTER LOOP..." << std::endl;
        for(int i = 1; i < 5; i++){
                    //  IF [I] == [I-1]
            if(this->cards[i].getValue() == this->cards[i-1].getValue()){
                count++;            //  INCREMENT COUNT
                match[i-1] = true;  //  FLAG MATCHING POSITION
std::cout<<"Matching card found in [" << i-1 << "]" << std::endl;
std::cout<<"Match["<<(i-1)<<"] == ";
if(match[i-1])
    std::cout << "true";
else
    std::cout << "false";
std::cout<< endl;
            }
            //else{//  [I] != [I-1]
std::cout<<" No Matching card in [" << i-1 << "]" << std::endl;
std::cout<< "    in switch( "<< count <<")" << std::endl;
                switch(count){      ///////////////////////////////
                    case 2:         //
                        pair++;     //  INCREMENT APPROPRIATE
std::cout<< "        pair = " << pair << std::endl;
                        break;      //      QUANTITY COUNTERS
                    case 3:         //
                        three++;    //
std::cout<< "        three = " << three << std::endl;
                        break;      //
                    case 4:         //
                        four++;     //
std::cout<< "        four = " << four << std::endl;
                        break;      //
                    default:
                        break;
                //}
std::cout<< "    leaving switch" << std::endl;
                count = 1;          //  RESET COUNT FOR NEXT POSSIBLE MULTIPLE
                match[i-1] = false; //  FLAG NON-MATCHING POSITION
std::cout<< "resetting count..." << std::endl;
std::cout<<"count = "<<count<<" and match["<<i-1<<"] = "<<match[i-1]<<std::endl;
            }
        }
std::cout<< "--------------------------------------------------" << std::endl;
std::cout<< "              CLASSIFYING THE HAND"                 << std::endl;
std::cout<< "--------------------------------------------------" << std::endl;
                //  CLASSIFY BASED ON COUNTERS{
std::cout<< "Pair = " << pair << " | Three = " << three
            << " | Four = " << four << std::endl;
std::cout<< "--------------------------------------------------" << std::endl;
                    if(pair ==1){
                        if(three ==0){  //  JUST A PAIR
                            r.setQuality(Quality::PAIR);
std::cout<< "Quality = " << r.getQuality() << std::endl;
                            //  DETERMINE VALUE ORDER USING BOOL[]
                                //  FOR LOOP,4 PASSES, C[] == CARDS[]
                                //
                            for(int i = 0; i<4; i++){
                                if(match[i]){// IF C[I] MATCHES C[I+1] IN VALUE
                                //  EMPLACE VALUE IN THE FRONT OF THE VECTOR
                                    auto itr = v.emplace(v.begin(),
                                                    this->cards[i].getValue());
                                    i++; // SKIPS C[I+1] WHICH IS SECOND CARD IN
                                }           //  PAIR, ONLY ONE VALUE NEEDED
                                else{
                                //  ADDS VALUE TO POSITION BEHIND LAST VALUE
                                    v.push_back(this->cards[i].getValue());
                                }
                            }
                        }
                        else{   //  FULL HOUSE
                            r.setQuality(Quality::FULLHOUSE);
std::cout<< "Quality = " << r.getQuality() << std::endl;
                        //  DETERMINE VALUE ORDER
                        //  C[2] WILL ALWAYS BE VALUE OF THREEOFKIND
                            auto itr = v.emplace(v.begin(),
                                                 this->cards[2].getValue());
                            //  PUSH PAIR VALUE ON BACK BASED ON MATCH[]
                            if(match[2]) // C[2:4] MATCH SINCE C[] IS SORTED
                                v.push_back(this->cards[1].getValue());//PAIR
                            else
                                v.push_back(this->cards[3].getValue());//PAIR
                        }
                    }
                    else if(pair == 2){ //  TWO PAIRS
                        r.setQuality(Quality::TWOPAIR);
                        v.push_back(this->cards[1].getValue()); //HIGH PAIR
                        v.push_back(this->cards[3].getValue()); //LOW PAIR
                        //  PUSH KICKER ON BACK BASED ON MATCH[]
                        if(!match[0])   // DOESN'T MATCH C[1]
                            v.push_back(this->cards[0].getValue());
                        else if(!match[2])// DOESN'T MATCH C[3]
                            v.push_back(this->cards[2].getValue());
                        else    //  LAST CARD MATCHES NOTHING
                            v.push_back(this->cards[4].getValue());
                    }
                    else if(three == 1){    //  THREE OF A KIND
                        r.setQuality(Quality::THREEKIND);
                            //  VALUE OF THE THREE OF A KIND ALWAYS IN [2]
                        v.push_back(this->cards[2].getValue());
                                //  PLACE KICKERS ON BACK BASED ON MATCH[]
                        if(!match[0]){  //  NOT THREE OF KIND, [0] THE HIGH CARD
                            v.push_back(this->cards[0].getValue());
                            if(!match[1])   //  NOT THREE OF KIND, 2ND KICKER
                                v.push_back(this->cards[1].getValue());
                            else    //  [1-3] ARE THREE OF KIND,LAST CARD KICKER
                                v.push_back(this->cards[4].getValue());
                        }
                        else{   //  [0-2] ARE THREE OF KIND, [3,4] KICKERS
                            v.push_back(this->cards[3].getValue());
                            v.push_back(this->cards[4].getValue());
                        }
                    }
                    else if (four == 1){    //  FOUR OF A KIND
                        r.setQuality(Quality::FOURKIND);
                        v.push_back(this->cards[2].getValue());//4 OF KIND VALUE
                        if(!match[0])   //  [0] DOESN'T MATCH OTHERS,
                            v.push_back(this->cards[0].getValue());
                        else       //  [4] DOESN'T MATCH OTHERS
                            v.push_back(this->cards[4].getValue());
                    }
                    else{   //  NO CARDS, SUITS MATCH, NO STRAIGHT
                        r.setQuality(Quality::HIGHCARD);
                        for(int i = 0; i<5;i++) //  VALUES ADDED IN NORMAL ORDER
                            v.push_back(this->cards[i].getValue());
                    }
                    r.setValues(v);     //  VALUES ASSIGNED TO RANK OBJECT
                    this->setRank(r);   //  RANK ASSIGNED TO HAND
    }





};
#endif // HAND_H
