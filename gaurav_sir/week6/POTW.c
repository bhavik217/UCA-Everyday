#include <stdio.h>

int main(){
    // 4 bits will store card no. and 2 bits will store suit

    // Diamond - 0, Heart - 1, Spade - 2, Club - 3

    // 40 - 101000(10 Diamond)     44 - 101100(11 Diamond) 
    int card1 = 40, card2 = 44;

    // For checking same or different suit
    int suit_mask = 3;
    if(!((card1 & suit_mask) ^ (card2 & suit_mask))) printf("Same Suit\n");
    else printf("Different Suit\n");


    // For checking larger card
    if(card1 > card2) printf("Card1 is large\n");
    else if(card1 < card2) printf("Card2 is large\n");
    else printf("Both cards are equal\n");
}