#include <stdio.h>
#include <stdlib.h>
#define VALUE_ACE 14
#define VALUE_KING 13
#define VALUE_QUEEN 12
#define VALUE_JACK 11

typedef enum {
  SPADES,
  HEARTS,
  DIAMONDS,
  CLUBS,
  NUM_SUITS
} suit_t;

struct card_tag {
  unsigned value;
  suit_t suit;
};
typedef struct card_tag card_t;

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch (value_let) {
  case '2': temp.value = 2; break;
  case '3': temp.value = 3; break;
  case '4': temp.value = 4; break;
  case '5': temp.value = 5; break;
  case '6': temp.value = 6; break;  
  case '7': temp.value = 7; break;
  case '8': temp.value = 8; break;
  case '9': temp.value = 9; break;
  case '0': temp.value = 10; break;
  case 'J': temp.value = VALUE_JACK; break;
  case 'Q': temp.value = VALUE_QUEEN; break;
  case 'K': temp.value = VALUE_KING; break;
  case 'A': temp.value = VALUE_ACE; break;
  }
  switch (suit_let) {
  case 's': temp.suit = SPADES; break;
  case 'h': temp.suit = HEARTS; break;
  case 'd': temp.suit = DIAMONDS; break;
  case 'c': temp.suit = CLUBS; break;
  }
  return(temp);
}

char suit_letter(card_t c) {
  switch(c.suit) {
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  case CLUBS: return 'c';
  default: return '?';  
  }
}

char value_letter(card_t c) {
  switch (c.value) {
  case 2: return '2';
  case 3: return '3';
  case 4: return '4';
  case 5: return '5';
  case 6: return '6';
  case 7: return '7';
  case 8: return '8';
  case 9: return '9';
  case 10: return '0';
  case VALUE_ACE: return 'A';
  case VALUE_KING: return 'K';
  case VALUE_QUEEN: return 'Q';
  case VALUE_JACK: return 'J';
  default: return '?';
  }
}
  
void print_card(card_t c) {
  char value = value_letter(c);
  char suit = suit_letter(c);
  printf("%c%c\n", value, suit);
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = (c / 4) + 2;
  temp.suit = c%4;
  return temp;
}

int main() {

card_t mycard = card_from_letters('A','d');
card_t mycard2 = card_from_num(50);

printf("%d%d\n", mycard.value, mycard.suit);
print_card(mycard);
print_card(mycard2);




  return 0;
}