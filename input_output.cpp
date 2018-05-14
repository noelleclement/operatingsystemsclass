/*
    TODO:
        char to morse (with same technique as decodeMorse)
        check if rest of code needs reorganization
        raspberry pi setup
        connect pi to program



*/



#include <stdlib.h>
#include <string>
#include <iostream>
#include <wiringPi.h>

#define OUTPUT_PIN 0
#define INPUT_PIN 2

using namespace std;

//decodeMorse: incoming morse 'character string' to regular character
char decodeMorse(string s) {
    
    
    /*
    original string (without numbers and punctuation marks): 

    const string morse("EISHVUF*ARL*WPJTNDBXKCYMGZQO");
    int p = -1;
  
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            p += (1 << (4 - i));
        }
        else p++;
    }
    return morse[p];

    */



    /*
    notes:
        morse tree (string) order is based on the order of .'s and -'s, fe E=., I=.., S=...
        added characters add one 'layer' to tree, so for bitwise shift 4 becomes 5 
        non-ascii table characters are added as *
        spaces in tree are _
    */

    const string morse("EISH54V*3UF*_**2ARL_**+_WP**J*1TNDB6=X/_KC*_Y*_MGZ7_Q**O*8_*90"); //"EISH54V(´S)3UF(É)_(Ü)(-D)2ARL_(È)(Ä)+_WP('P)(À)J(^J)1   TNDB6=X/_KC(,C)_Y(^H)_MGZ7_Q(^G)(~N)O(Ö)8_(CH)90" 
    int p = -1;
  
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            p += (1 << (5 - i));
        }
        else p++;
    }
    return morse[p];


}

void switchChanged() {
    static string buffer;
    static unsigned int previousTime = 0, currentTime, timePassed;
    currentTime = millis();
    if (previousTime == 0) { // first pulse
        previousTime = currentTime;
        return;
    }
    timePassed = currentTime - previousTime;
    previousTime = currentTime;
    if (digitalRead(INPUT_PIN) == LOW) { // switch pressed
        if (timePassed > 200) {

        // TO DO

        }
        if (timePassed > 600) {

        // TO DO

        }
    } 
    else { // switch released
        if (timePassed > 200) {

        // TO DO

        }
        else {

        // TO DO

        }
    }
}

void wait(int n) {
  delay(100 * n);
}

void dot() {
  digitalWrite(OUTPUT_PIN, HIGH);

  // TO DO

}

void dash() {

  // TO DO

}

void sendMorse(char character) {
  switch (character) {
    case 'A':
      dot();
      dash();
      break;
    case 'B':
      dash();
      dot();
      dot();
      dot();
      break;
    case 'C':
      dash();
      dot();
      dash();
      dot();
      break;
    case 'D':
      dash();
      dot();
      dot();
      break;
    case 'E':
      dot();
      break;
    case 'F':
      dot();
      dot();
      dash();
      dot();
      break;
    case 'G':
      dash();
      dash();
      dot();
      break;
    case 'H':
      dot();
      dot();
      dot();
      dot();
      break;
    case 'I':
      dot();
      dot();
      break;
    case 'J':
      dot();
      dash();
      dash();
      dash();
      break;
    case 'K':
      dash();
      dot();
      dash();
      break;
    case 'L':
      dot();
      dash();
      dot();
      dot();
      break;
    case 'M':
      dash();
      dash();
      break;
    case 'N':
      dash();
      dot();
      break;
    case 'O':
      dash();
      dash();
      dash();
      break;
    case 'P':
      dot();
      dash();
      dash();
      dot();
      break;
    case 'Q':
      dash();
      dash();
      dot();
      dash();
      break;
    case 'R':
      dot();
      dash();
      dot();
      break;

    // to do

    default:
      break;
  }
  wait(2); // wait 1 + 2 = 3 dots in total
}

int main() {

  // to do

  pullUpDnControl(INPUT_PIN, PUD_UP);
  wiringPiISR(INPUT_PIN, INT_EDGE_BOTH, &switchChanged);
  int character;
  while (true) {
    character = getchar();
    if (character == ' ') {

      // TO DO: wait 1 + 2 + 4 = 7 dots in total

    }
    else {

      // TO DO

    }
  }
}
