byte charset[93][5] = {         // written in y-direction, 1 byte = 7y-coordinates
  {0,0,0,0,0},           // 
  {0,0,95,0,0},         // !
  {0,7,0,7,0},       // "
  {20,127,20,127,20},    // #
  {36,42,127,42,18},     // $
  {35,19,8,100,98},      // %
  {54,73,85,34,80},       // &
  {0,28,34,65,0},        // (
  {0,65,34,28,0},        // )
  {20,8,62,8,20},        // *
  {8,8,62,8,8},          // +
  {0,80,48,0,0},           // ,
  {8,8,8,8,8},           // -
  {0,96,96,0,0},           // .
  {32,16,8,4,2},         // /
  {62,81,73,69,62},      // 0
  {0,66,127,64,0},        // 1
  {66,97,81,73,70},      // 2 
  {33,65,69,75,49},     // 3  
  {24,20,18,127,16},      // 4  
  {71,69,69,69,57},     // 5
  {60,74,73,73,48},       // 6  
  {1,113,9,5,3},      // 7
  {54,73,73,73,54},      // 8 
  {6,73,73,41,30},      // 9
  {0,54,54,0,0},         // : 
  {0,86,54,0,0},         // ; 
  {8,20,34,65,0},        // <
  {20,20,20,20,20},      // = 
  {0,65,34,20,8},        // >
  {2,1,81,9,6},      // ? 
  {50,73,121,65,62},      // @
  {126,17,17,17,126},      // A
  {127,73,73,73,54},     // B
  {62,65,65,65,34},      // C
  {127,65,65,34,28},     // D
  {127,73,73,73,65},     // E
  {127,9,9,9,1},     // F
  {62,65,73,73,122},      // G
  {127,8,8,8,127},       // H
  {65,65,127,65,65},     // I
  {32,64,65,63,1},       // J
  {127,8,20,34,65},      // K
  {127,64,64,64,64},         // L
  {127,2,12,2,127},    // M
  {127,4,8,16,127},      // N
  {62,65,65,65,62},      // O
  {127,9,9,9,6},     // P 
  {62,65,81,33,94},      // Q
  {127,9,25,41,70},     // R
  {70,73,73,73,49},      // S
  {1,1,127,1,1},     // T
  {63,64,64,64,63},       // U
  {31,32,64,32,31},       // V
  {63,64,56,64,63},      // W
  {99,28,8,28,99},       // X
  {7,8,112,8,7},       // Y
  {97,81,73,69,67},      // Z
  {0,127,65,65,0},       // [
  {0,65,65,127,0},       // ]
  {4,2,1,2,4},      // ^
  {64,64,64,64,64},           // _
  {0,1,2,4,0},        // `
  {32,84,84,84,120},       // a
  {127,72,68,68,56},      // b
  {56,68,68,68,40},       // c
  {56,68,68,72,127},      // d 
  {56,84,84,84,24},      // e
  {8,126,9,1,2},       // f
  {12,82,82,82,62},      // g
  {127,8,4,4,120},      // h
  {0,68,125,64,0},         // i
  {32,64,64,61,0},          // j
  {127,16,40,68,0},       // k
  {0,65,127,64,0},        // l
  {124,4,24,4,120},      // m
  {124,8,4,4,120},       // n
  {56,68,68,68,56},      // o
  {124,20,20,20,8},       // p
  {8,20,20,12,124},       // q
  {124,8,4,4,8},        // r
  {72,84,84,84,32},        // s 9,21,21,21,2
  {4,63,68,64,32},       // t
  {60,64,64,32,124},         // u
  {28,32,64,32,28},         // v
  {60,64,48,64,60},         // w
  {68,40,16,40,68},       // x
  {12,80,80,80,60},         // y
  {68,100,84,76,68},      // z
  {0,8,54,65,0},         // {
  {0,0,127,0,0},         // |
  {0,65,54,8,0},         // }
  {85,42,85,42,85},      // $UNKOWNCHAR
};

// ArrayOfLedArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up three WS2812B strips on three
// different pins, each strip getting its own CRGB array to be played with, only this time they're going
// to be all parts of an array of arrays.

#include <FastLED.h>

#define NUM_STRIPS 7
#define NUM_LEDS_PER_STRIP 42
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

// needed for buttonRead()
const int  buttonPin = 2;   // the pin that the pushbutton is attached to
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int maxButtonValue = 5;      // the maximum value buttonPushCounter can be

// needed for potRead()
int potPin1 = 0;              // the pin the poti-Abgreifer is connected to
int potPin2 = 1;              // the pin the poti-Abgreifer is connected to
int potPin3 = 2;              // the pin the poti-Abgreifer is connected to
int timedelay = 15;          // unused if poti enabled

// allowed characters:   ! " # $ % & ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M
//               N O P Q R S T U V W X Y Z [ ] ^ _ ` a b c d e f g h i j k l m n o p q r s t u v w x y z { | }
//char InputString[] = {"!#$%&()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}"};
//char InputString[] = {"Sprich Deutsch du Hurensohn!"};
char InputString[] = {"Social Distancing is key!    Stay at home!    Stay Healthy!    "};
//char InputString[24f] = {"Abonniert Hand Of Blood!"};
const int Stringsize = sizeof(InputString) / sizeof(InputString[0]);
//byte OLDledsMirror[NUM_STRIPS][Stringsize*6]; // [Y] * [X]           
byte ledsMirror[Stringsize*6]; // Y ~ bit; X ~ [Byte] aka. ||||||||||||||||

int offset = 5; // still used?!?!?

bool scrollingIsEnabled = true;
int scrollcounter = 0;

void writetomirror();
void writetomirrorsub(int field, int B, int b);

void setup() {
  // tell FastLED there's 60 WS2812B leds on pin 5
  FastLED.addLeds<WS2812B, 5, GRB>(leds[0], NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 WS2812B leds on pin 6
  FastLED.addLeds<WS2812B, 6, GRB>(leds[1], NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 WS2812B leds on pin 7
  FastLED.addLeds<WS2812B, 7, GRB>(leds[2], NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 WS2812B leds on pin 8
  FastLED.addLeds<WS2812B, 8, GRB>(leds[3], NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 WS2812B leds on pin 9
  FastLED.addLeds<WS2812B, 9, GRB>(leds[4], NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 WS2812B leds on pin 10
  FastLED.addLeds<WS2812B, 10, GRB>(leds[5], NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 WS2812B leds on pin 11
  FastLED.addLeds<WS2812B, 11, GRB>(leds[6], NUM_LEDS_PER_STRIP);
  Serial.begin(9600);
  delay(50);

  writetomirror(); // only runs once
}

void writetomirror() {
  for(int field = 0; field < Stringsize; field++) {   //field:  0->(Stringsize-1)
//    for(int b = 6; b >= 0; b--) {                     //bit:    6,5,4,3,2,1,0    ~Y
    for(int b = 0; b < NUM_STRIPS; b++) {
      for(int B = 0; B < 5; B++) {                    //Byte:   0,1,2,3,4        ~X

        writetomirrorsub(field, B, b); 
           
      }
    }
  }
                
}

void writetomirrorsub(int field, int B, int b) {

        if (InputString[field] == ' ') {
          if(bitRead(charset[0][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '!') {
          if(bitRead(charset[1][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '"') {
          if(bitRead(charset[2][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '#') {
          if(bitRead(charset[3][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '$') {
          if(bitRead(charset[4][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '%') {
          if(bitRead(charset[5][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '&') {
          if(bitRead(charset[6][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '(') {
          if(bitRead(charset[7][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == ')') {
          if(bitRead(charset[8][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '*') {
          if(bitRead(charset[9][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '+') {
          if(bitRead(charset[10][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == ',') {
          if(bitRead(charset[11][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '-') {
          if(bitRead(charset[12][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '.') {
          if(bitRead(charset[13][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '/') {
          if(bitRead(charset[14][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '0') {
          if(bitRead(charset[15][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '1') {
          if(bitRead(charset[16][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '2') {
          if(bitRead(charset[17][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '3') {
          if(bitRead(charset[18][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '4') {
          if(bitRead(charset[19][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '5') {
          if(bitRead(charset[20][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '6') {
          if(bitRead(charset[21][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '7') {
          if(bitRead(charset[22][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '8') {
          if(bitRead(charset[23][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '9') {
          if(bitRead(charset[24][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == ':') {
          if(bitRead(charset[25][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == ';') {
          if(bitRead(charset[26][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '<') {
          if(bitRead(charset[27][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '=') {
          if(bitRead(charset[28][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '>') {
          if(bitRead(charset[29][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '?') {
          if(bitRead(charset[30][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '@') {
          if(bitRead(charset[31][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'A') {
          if(bitRead(charset[32][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'B') {
          if(bitRead(charset[33][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'C') {
          if(bitRead(charset[34][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'D') {
          if(bitRead(charset[35][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'E') {
          if(bitRead(charset[36][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'F') {
          if(bitRead(charset[37][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'G') {
          if(bitRead(charset[38][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'H') {
          if(bitRead(charset[39][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'I') {
          if(bitRead(charset[40][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'J') {
          if(bitRead(charset[41][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'K') {
          if(bitRead(charset[42][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'L') {
          if(bitRead(charset[43][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'M') {
          if(bitRead(charset[44][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'N') {
          if(bitRead(charset[45][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'O') {
          if(bitRead(charset[46][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'P') {
          if(bitRead(charset[47][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'Q') {
          if(bitRead(charset[48][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'R') {
          if(bitRead(charset[49][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'S') {
          if(bitRead(charset[50][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'T') {
          if(bitRead(charset[51][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'U') {
          if(bitRead(charset[52][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'V') {
          if(bitRead(charset[53][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'W') {
          if(bitRead(charset[54][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'X') {
          if(bitRead(charset[55][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'Y') {
          if(bitRead(charset[56][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'Z') {
          if(bitRead(charset[57][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '[') {
          if(bitRead(charset[58][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == ']') {
          if(bitRead(charset[59][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '^') {
          if(bitRead(charset[60][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '_') {
          if(bitRead(charset[61][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '`') {
          if(bitRead(charset[62][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'a') {
          if(bitRead(charset[63][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'b') {
          if(bitRead(charset[64][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'c') {
          if(bitRead(charset[65][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'd') {
          if(bitRead(charset[66][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'e') {
          if(bitRead(charset[67][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'f') {
          if(bitRead(charset[68][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'g') {
          if(bitRead(charset[69][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'h') {
          if(bitRead(charset[70][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'i') {
          if(bitRead(charset[71][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'j') {
          if(bitRead(charset[72][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'k') {
          if(bitRead(charset[73][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'l') {
          if(bitRead(charset[74][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'm') {
          if(bitRead(charset[75][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'n') {
          if(bitRead(charset[76][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'o') {
          if(bitRead(charset[77][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'p') {
          if(bitRead(charset[78][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'q') {
          if(bitRead(charset[79][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'r') {
          if(bitRead(charset[80][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 's') {
          if(bitRead(charset[81][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 't') {
          if(bitRead(charset[82][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'u') {
          if(bitRead(charset[83][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'v') {
          if(bitRead(charset[84][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'w') {
          if(bitRead(charset[85][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'x') {
          if(bitRead(charset[86][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'y') {
          if(bitRead(charset[87][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == 'z') {
          if(bitRead(charset[88][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '{') {
          if(bitRead(charset[89][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '|') {
          if(bitRead(charset[90][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else if (InputString[field] == '}') {
          if(bitRead(charset[91][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }
        else {
          if(bitRead(charset[92][B],b) == 0b0) {
            bitWrite(ledsMirror[B + (6 * field)], b, 0);
          }
          else {
            bitWrite(ledsMirror[B + (6 * field)], b, 1);
          }
        }

        if(B == 5) { // spaces between characters
          bitWrite(ledsMirror[B + (6 * field)],b,0b0);
        }
        
}

void makeLedsBackground(int ystripe, int xled) {
  leds[ystripe][xled].setRGB(0,0,0);
}

void makeLedsForeground(int ystripe, int xled) {
  leds[ystripe][xled].setHue(150);
}

void mirrortoleds(int scrollcounter) { // Der text ist überkopft , weil 'ystripe' anders iteriert als 'b'
  for(int ystripe = 0; ystripe < NUM_STRIPS; ystripe++) {   
    for(int xled = 0; xled < NUM_LEDS_PER_STRIP; xled++) {  
      
      if(scrollcounter + xled >= Stringsize*6) { // wenn scrollcounter(+offset) größer/gleich als nachricht(letzes zeichen ganz rechts, dann mache schwarz
        if(bitRead(ledsMirror[xled + scrollcounter - Stringsize*6], ystripe) == 0b0) {
          makeLedsBackground(ystripe,xled);
        }    
      }
      
      else if(scrollcounter + xled < 0) { // wenn scrollcounter(+offset) kleiner als 0 ist, mache schwarz
        if(bitRead(ledsMirror[xled + scrollcounter - Stringsize*6], ystripe) == 0b0) {
          makeLedsBackground(ystripe,xled);
        }        
      }
      
      else if(scrollcounter + xled >= 0 && scrollcounter + xled < Stringsize*6) {
        if(bitRead(ledsMirror[xled + scrollcounter], ystripe) == 0b0) {
          makeLedsBackground(ystripe,xled);
        }
        if(bitRead(ledsMirror[xled + scrollcounter], ystripe) == 0b1) {
          makeLedsForeground(ystripe,xled);
        }    
      }
              
    }
  } 
}


void loop() {
/*
//  for(int c = 0; c < sizeof(charset) / sizeof(charset[0]); c++) {
  int c = 8;
    for(int B = 0; B < 5; B++) { // x
      for(int b = 6; b >= 0; b--) { // y
        Serial.println(bitRead(charset[c][B],b));
      }
      Serial.println();
    }
    Serial.println("stop");
    delay(1000); 
//  }
*/
  mirrortoleds(scrollcounter);
  FastLED.show();

  delay(100);

  if(scrollingIsEnabled) {
    if(scrollcounter < Stringsize*6 + offset) {
      scrollcounter++;
    }
    else {
      scrollcounter = -NUM_LEDS_PER_STRIP; 
    }
  }

  
}
