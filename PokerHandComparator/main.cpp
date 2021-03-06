#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

#include "Hand.h"
using namespace std;

//  PROTOTYPES  //
int testHands();

int main()
{
    //fstream     outfile("Output.txt");
    vector<Card>    c, hand;
    Card            card[52];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
        Card temp(Card(static_cast<Suit>(i), static_cast<Value>(j)));
        card[i*13 + j]  =   temp;
        //c.push_back(card);
        //std::random_shuffle(c.begin(), c.end());
        }
    }

    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 5; i++){
            for(int l = 0; l <1; l++)
                std::rand();
            Card a(card[(std::rand()%52)]);
            hand.push_back(a);
        }
        std::sort(hand.begin(), hand.end());
        std::reverse(hand.begin(), hand.end());
        for(int i = 0; i < 5; i++){
            cout << hand[i].getFace() << endl;
        }
        Hand pokerHand(hand);
        cout << "Hand Quality is " << pokerHand.getRank().getQuality() << " and " <<
                " the values stored in the hand are ";
        for(int i = 0; i<pokerHand.getRank().getValues().size(); i++){
            cout << "[" << pokerHand.getRank().getValues()[i] << "]";
        }
        cout << endl;
        std::random_shuffle(c.begin(), c.end());
    }
    return 0;
}
