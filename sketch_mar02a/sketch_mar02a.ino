/**
 *  Haili Cai
 *  Kyle Leung
 *  Zhuo Chen
 *  
 */
 
 
// three row
int row1 = 13;  //Row 1
int row2 = 12;  //Row 2
int row3 = 11;  //Row 3


// nine column
int col1 = 10;
int col2 = 9;
int col3 = 8;
int col4 = 7;
int col5 = 6;
int col6 = 5;
int col7 = 4;
int col8 = 3;
int col9 = 2;


//the number of rows and columns
int rowmax = 3;
int colmax = 9;
//make arrays of col and row
int ledCol[9];
int ledRow[3];



/////////////////////music//////////////////

int speakerPin = 0;
int length = 26;
char notes[] = "eeeeeeegcde fffffeeeeddedg";
int beats[] = { 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};

int tempo = 300;

// the setup routine runs once when you press reset:
void setup() {                
  
  //used for random value
  //Serial.begin(9600);
  // initialize the digital pin as an output.
  
  //3 rows
  pinMode(row1, OUTPUT); //Top
  pinMode(row2, OUTPUT); //Middle
  pinMode(row3, OUTPUT); //Bottom
  
  //9 Columns
  pinMode(col1, OUTPUT); //Left
  pinMode(col2, OUTPUT); //Middle
  pinMode(col3, OUTPUT); //Right
  pinMode(col4, OUTPUT); //Left
  pinMode(col5, OUTPUT); //Middle
  pinMode(col6, OUTPUT); //Right
  pinMode(col7, OUTPUT); //Left
  pinMode(col8, OUTPUT); //Middle
  pinMode(col9, OUTPUT); //Right
  pinMode(speakerPin, OUTPUT);
  
  
  //fill array
  ledCol[0] = col1;
  ledCol[1] = col2;
  ledCol[2] = col3;
  ledCol[3] = col4;
  ledCol[4] = col5;
  ledCol[5] = col6;
  ledCol[6] = col7;
  ledCol[7] = col8;
  ledCol[8] = col9;
  
  ledRow[0] = row1;
  ledRow[1] = row2;
  ledRow[2] = row3;

  testAll(); //checks all the LEDS make sure they can all light. 
}

// the loop routine runs over and over again forever:
void loop() {

   for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    
    // pause between notes
    delay(tempo / 2); 
  }
  
  frontFigure();
  rightFigure();
  backFigure();
  leftFigure();
  middleMove();

  panelRotate();
  panelRotate();
  panelRotate();
  panelRotate();
  panelRotate();
  panelRotate();
  panelRotate();

  antiClock(70);
  antiClock(80);
  antiClock(90);
 
  Clock(90);
  Clock(80);
  Clock(70);
  
  
  frontToBackPane();
  rightToLeftPane();
  backToFrontPane();
  leftToRightPane();
  bottomToTopPanel();
  topToBottomPanel();
  
 
  
  antiPanelRotate();
  antiPanelRotate();
  antiPanelRotate();
  antiPanelRotate();
  antiPanelRotate();
  antiPanelRotate();
  antiPanelRotate();
  
  delay(200);

   
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();
  
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();
  
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();
  paneFTR();
  paneRTB();
  
  paneBTL();
  paneLTF();
  
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();

  delay(300);
}
//end main loop




//All helper functions used to create designs and patters throughout the loop
//LED movements

//flashes both top and bottom panes
void lightning(){
    topon();
    bottomon();
    delay(30);
    topOff();
    bottomOff();
    delay(120);
    topon();
    bottomon();
    delay(30);
    topOff();
    bottomOff();
    topon();
    bottomon();
    delay(30);
    topOff();
    bottomOff();
    delay(120);
}


//animate
void paneLTF(){
  int del = 100;
    lefton();
    delay(del);
    leftOff();
    diagonalFTBPaneon();
    delay(del);
    diagonalFTBPaneOff();
    fronton();
    delay(del);
    frontOff();
}


//animate
void paneBTL(){
  int del = 100;
    backon();
    delay(del);
    backOff();
    diagonalBTFPaneon();
    delay(del);
    diagonalBTFPaneOff();
    lefton();
    delay(del);
    leftOff();
}

//animate
void paneRTB(){
  int del = 100;
    rightPaneon();
    delay(del);
    rightOff();
    diagonalFTBPaneon();
    delay(del);
    diagonalFTBPaneOff();
    backon();
    delay(del);
    backOff();
}

//animate
void paneFTR(){
  int del = 100;
    fronton();
    delay(del);
    frontOff();
    diagonalBTFPaneon();
    delay(del);
    diagonalBTFPaneOff();
    rightPaneon();
    delay(del);
    rightOff();
}


void panelRotate(){
    int del = 80;
    
    middleon();
    delay(del);
    middleOff();
    
    diagonalBTFPaneon();
    delay(del);
    diagonalBTFPaneOff();
    
    middleLRPaneon();
    delay(del);
    middleLRPaneOff();
    
    diagonalFTBPaneon();
    delay(del);
    diagonalFTBPaneOff();
    
    
    //back to start.
    //middleon();
    //delay(del);
    //middleOff();
    
}


void antiPanelRotate(){
    int del = 80;
    
    middleon();
    delay(del);
    middleOff();
    
    diagonalFTBPaneon();
    delay(del);
    diagonalFTBPaneOff();
    
    middleLRPaneon();
    delay(del);
    middleLRPaneOff();
    
    diagonalBTFPaneon();
    delay(del);
    diagonalBTFPaneOff();
    
}

// turn on the diagonal light
void diagonalBTFPaneon(){
    digitalWrite(row1, HIGH);
    digitalWrite(row2, HIGH);
    digitalWrite(row3, HIGH);
    digitalWrite(col7, HIGH);
    digitalWrite(col9, HIGH);
    digitalWrite(col3, HIGH);
}

// turn off the diagonal light
void diagonalBTFPaneOff(){
    digitalWrite(row1, LOW);
    digitalWrite(row2, LOW);
    digitalWrite(row3, LOW);    
    digitalWrite(col3, LOW);
    digitalWrite(col9, LOW);
    digitalWrite(col7, LOW);
}

// turn on the diagonal light
void diagonalFTBPaneon(){
    digitalWrite(row1, HIGH);
    digitalWrite(row2, HIGH);
    digitalWrite(row3, HIGH);  
    digitalWrite(col1, HIGH);
    digitalWrite(col9, HIGH);
    digitalWrite(col5, HIGH);

}

// turn off the diagonal light
void diagonalFTBPaneOff(){
    digitalWrite(row1, LOW);
    digitalWrite(row2, LOW);
    digitalWrite(row3, LOW);  
    digitalWrite(col5, LOW);
    digitalWrite(col9, LOW);
    digitalWrite(col1, LOW);

}

void frontToBackPane(){
    int del = 300;
    fronton();
    delay(del);
    frontOff();
    middleon();
    delay(del);
    middleOff();
    backon();
    delay(del);
    backOff();
    middleon();
    delay(del);
    middleOff();
    fronton();
    delay(del);
    frontOff();
}

//animation
void rightToLeftPane(){
    int del = 300;
    rightPaneon();
    delay(del);
    rightOff();
    middleLRPaneon();
    delay(del);
    middleLRPaneOff();
    lefton();
    delay(del);
    leftOff();
    middleLRPaneon();
    delay(del);
    middleLRPaneOff();
    rightPaneon();
    delay(del);
    rightOff();
}

//animation
void backToFrontPane(){
    int del = 300;
    backon();
    delay(del);
    backOff();
    middleon();
    delay(del);
    middleOff();
    fronton();
    delay(del);
    frontOff();
    middleon();
    delay(del);
    middleOff();
    backon();
    delay(del);
    backOff();
}

//animation
void leftToRightPane(){
    int del = 300;
    lefton();
    delay(del);
    leftOff();
    middleLRPaneon();
    delay(del);
    middleLRPaneOff();
    rightPaneon();
    delay(del);
    rightOff();
    middleLRPaneon();
    delay(del);
    middleLRPaneOff();
    lefton();
    delay(del);
    leftOff();
}

//animation
void topToBottomPanel(){
    int del = 300;
    topon();
    delay(del);
    topOff();
    middleTBPaneon();
    delay(del);
    middleTBPaneOff();
    bottomon();
    delay(del);
    bottomOff();
    middleTBPaneon();
    delay(del);
    middleTBPaneOff();
    topon();
    delay(del);
    topOff();

}

//animation
void bottomToTopPanel(){
    int del = 300;
    bottomon();
    delay(del);
    bottomOff();
    middleTBPaneon();
    delay(del);
    middleTBPaneOff();
    topon();
    delay(del);
    topOff();
    middleTBPaneon();
    delay(del);
    middleTBPaneOff();
    bottomon();
    delay(del);
    bottomOff();

}


//turn on the first layer
void topon(){
    digitalWrite(row1, HIGH);   
    digitalWrite(col1, HIGH);
    digitalWrite(col2, HIGH);
    digitalWrite(col3, HIGH);
    digitalWrite(col4, HIGH);
    digitalWrite(col5, HIGH);
    digitalWrite(col6, HIGH);
    digitalWrite(col7, HIGH);
    digitalWrite(col8, HIGH);
    digitalWrite(col9, HIGH);
}

// turn off the first layer
void topOff(){
    digitalWrite(row1, LOW);  
    digitalWrite(col1, LOW);
    digitalWrite(col2, LOW);
    digitalWrite(col3, LOW);
    digitalWrite(col4, LOW);
    digitalWrite(col5, LOW);
    digitalWrite(col6, LOW);
    digitalWrite(col7, LOW);
    digitalWrite(col8, LOW);
    digitalWrite(col9, LOW);
}

// turn on the second layer
void middleTBPaneon(){
    digitalWrite(row2, HIGH);
    
    digitalWrite(col1, HIGH);
    digitalWrite(col2, HIGH);
    digitalWrite(col3, HIGH);
    digitalWrite(col4, HIGH);
    digitalWrite(col5, HIGH);
    digitalWrite(col6, HIGH);
    digitalWrite(col7, HIGH);
    digitalWrite(col8, HIGH);
    digitalWrite(col9, HIGH);
}

// turn off the second layer
void middleTBPaneOff(){
    digitalWrite(row2, LOW);
    
    digitalWrite(col1, LOW);
    digitalWrite(col2, LOW);
    digitalWrite(col3, LOW);
    digitalWrite(col4, LOW);
    digitalWrite(col5, LOW);
    digitalWrite(col6, LOW);
    digitalWrite(col7, LOW);
    digitalWrite(col8, LOW);
    digitalWrite(col9, LOW);
}

// turn on the bottom layer
void bottomon(){
    digitalWrite(row3, HIGH);    
    digitalWrite(col1, HIGH);
    digitalWrite(col2, HIGH);
    digitalWrite(col3, HIGH);
    digitalWrite(col4, HIGH);
    digitalWrite(col5, HIGH);
    digitalWrite(col6, HIGH);
    digitalWrite(col7, HIGH);
    digitalWrite(col8, HIGH);
    digitalWrite(col9, HIGH);
}

// turn off the bottom layer
void bottomOff(){
    digitalWrite(row3, LOW);  
    digitalWrite(col1, LOW);
    digitalWrite(col2, LOW);
    digitalWrite(col3, LOW);
    digitalWrite(col4, LOW);
    digitalWrite(col5, LOW);
    digitalWrite(col6, LOW);
    digitalWrite(col7, LOW);
    digitalWrite(col8, LOW);
    digitalWrite(col9, LOW);
}

// turn on the right pane
void rightPaneon(){
    digitalWrite(row1, HIGH);
    digitalWrite(row2, HIGH);
    digitalWrite(row3, HIGH);
    
    digitalWrite(col3, HIGH);
    digitalWrite(col4, HIGH);
    digitalWrite(col5, HIGH);
}

// turn off the right pane
void rightOff(){
    digitalWrite(row1, LOW);
    digitalWrite(row2, LOW);
    digitalWrite(row3, LOW);
    
    digitalWrite(col3, LOW);
    digitalWrite(col4, LOW);
    digitalWrite(col5, LOW);
}

// turn on the middle left right pane
void middleLRPaneon(){
    digitalWrite(row1, HIGH);
    digitalWrite(row2, HIGH);
    digitalWrite(row3, HIGH);
    
    digitalWrite(col2, HIGH);
    digitalWrite(col9, HIGH);
    digitalWrite(col6, HIGH);
}

// turn off the middle left right pane
void middleLRPaneOff(){
    digitalWrite(row1, LOW);
    digitalWrite(row2, LOW);
    digitalWrite(row3, LOW);
    
    digitalWrite(col2, LOW);
    digitalWrite(col9, LOW);
    digitalWrite(col6, LOW);
}

// turn on the left pane
void lefton(){
    digitalWrite(row1, HIGH);
    digitalWrite(row2, HIGH);
    digitalWrite(row3, HIGH);
    
    digitalWrite(col7, HIGH);
    digitalWrite(col8, HIGH);
    digitalWrite(col1, HIGH);
}

// turn off the left pane
void leftOff(){
    digitalWrite(row1, LOW);
    digitalWrite(row2, LOW);
    digitalWrite(row3, LOW);
    
    digitalWrite(col7, LOW);
    digitalWrite(col8, LOW);
    digitalWrite(col1, LOW);
}

// turn on the back pane
void backon(){
    digitalWrite(row1, HIGH);
    digitalWrite(row2, HIGH);
    digitalWrite(row3, HIGH);
    
    digitalWrite(col5, HIGH);
    digitalWrite(col6, HIGH);
    digitalWrite(col7, HIGH);
}

// turn off the back pane
void backOff(){
    digitalWrite(row1, LOW);
    digitalWrite(row2, LOW);
    digitalWrite(row3, LOW);
    
    digitalWrite(col5, LOW);
    digitalWrite(col6, LOW);
    digitalWrite(col7, LOW);
}

// turn on the middle pane
void middleon(){
    digitalWrite(row1, HIGH);
    digitalWrite(row2, HIGH);
    digitalWrite(row3, HIGH);
    
    digitalWrite(col4, HIGH);
    digitalWrite(col8, HIGH);
    digitalWrite(col9, HIGH);
}

// turn off the middle pane
void middleOff(){
    digitalWrite(row1, LOW);
    digitalWrite(row2, LOW);
    digitalWrite(row3, LOW);
    
    digitalWrite(col4, LOW);
    digitalWrite(col8, LOW);
    digitalWrite(col9, LOW);
}

// turn on the front pane
void fronton(){
    digitalWrite(row1, HIGH);
    digitalWrite(row2, HIGH);
    digitalWrite(row3, HIGH);
    
    digitalWrite(col1, HIGH);
    digitalWrite(col2, HIGH);
    digitalWrite(col3, HIGH);
}

// turn off the front pane
void frontOff(){
    digitalWrite(row1, LOW);
    digitalWrite(row2, LOW);
    digitalWrite(row3, LOW);
    
    digitalWrite(col1, LOW);
    digitalWrite(col2, LOW);
    digitalWrite(col3, LOW);
}

// antil clockwise rotate
void antiClock(int mov){
    int del = mov;
   
    for(int x=0; x<3; x++){
      for(int y=0; y<8; y++){
        on(ledRow[x],ledCol[y]);
        delay(del);
        off(ledRow[x],ledCol[y]);
      }
    }
}

// clockwise rotate
void Clock(int mov){
    int del = mov;
    
    for(int x=2; x>-1; x--){
      for(int y=7; y>-1; y--){
        on(ledRow[x],ledCol[y]);
        delay(del);
        off(ledRow[x],ledCol[y]);
      }
    }
}



//snake movement on front pane
void frontFigure(){
  
  int del = 100;

    for(int y=0;y<3;y++){
      on(ledRow[0],ledCol[y]);
      delay(del);
      off(ledRow[0],ledCol[y]);
    }
    for(int y=2;y>-1;y--){
      on(ledRow[1],ledCol[y]);
      delay(del);
      off(ledRow[1],ledCol[y]);
    }
    for(int y=0;y<3;y++){
      on(ledRow[2],ledCol[y]);
      delay(del);
      off(ledRow[2],ledCol[y]);
    }
    for(int y=2;y>-1;y--){
      on(ledRow[1],ledCol[y]);
      delay(del);
      off(ledRow[1],ledCol[y]);
    }

}


void rightFigure(){
  
  int del = 130;

    for(int y=2;y<5;y++){
      on(ledRow[0],ledCol[y]);
      delay(del);
      off(ledRow[0],ledCol[y]);
    }
    for(int y=4;y>1;y--){
      on(ledRow[1],ledCol[y]);
      delay(del);
      off(ledRow[1],ledCol[y]);
    }
    for(int y=2;y<5;y++){
      on(ledRow[2],ledCol[y]);
      delay(del);
      off(ledRow[2],ledCol[y]);
    }
    for(int y=4;y>1;y--){
      on(ledRow[1],ledCol[y]);
      delay(del);
      off(ledRow[1],ledCol[y]);
    }

}

void backFigure(){
  
  int del = 130;

    for(int y=4;y<7;y++){
      on(ledRow[0],ledCol[y]);
      delay(del);
      off(ledRow[0],ledCol[y]);
    }
    for(int y=6;y>3;y--){
      on(ledRow[1],ledCol[y]);
      delay(del);
      off(ledRow[1],ledCol[y]);
    }
    for(int y=4;y<7;y++){
      on(ledRow[2],ledCol[y]);
      delay(del);
      off(ledRow[2],ledCol[y]);
    }
    for(int y=6;y>3;y--){
      on(ledRow[1],ledCol[y]);
      delay(del);
      off(ledRow[1],ledCol[y]);
    }

}

void leftFigure(){
  
  int del = 130;

    for(int y=6;y<8;y++){
      on(ledRow[0],ledCol[y]);
      delay(del);
      off(ledRow[0],ledCol[y]);
    }
      
      //back to first
      on(ledRow[0],ledCol[0]);
      delay(del);
      off(ledRow[0],ledCol[0]);
    
    
      //back to first
      on(ledRow[1],ledCol[0]);
      delay(del);
      off(ledRow[1],ledCol[0]);
    
    
    for(int y=7;y>5;y--){
      on(ledRow[1],ledCol[y]);
      delay(del);
      off(ledRow[1],ledCol[y]);
    }
    
    for(int y=6;y<8;y++){
      on(ledRow[2],ledCol[y]);
      delay(del);
      off(ledRow[2],ledCol[y]);
    }
    
      //back to first
      on(ledRow[2],ledCol[0]);
      delay(del);
      off(ledRow[2],ledCol[0]);
    
    
      //back to first
      on(ledRow[1],ledCol[0]);
      delay(del);
      off(ledRow[1],ledCol[0]);
    
    for(int y=6;y>5;y--){
      on(ledRow[1],ledCol[y]);
      delay(del);
      off(ledRow[1],ledCol[y]);
    }

}



void middleMove(){
      int del = 130;
      on(ledRow[0],ledCol[8]);
      delay(del);
      off(ledRow[0],ledCol[8]);
      
      on(ledRow[1],ledCol[8]);
      delay(del);
      off(ledRow[1],ledCol[8]);
      
      on(ledRow[2],ledCol[8]);
      delay(del);
      off(ledRow[2],ledCol[8]);
      
      on(ledRow[1],ledCol[8]);
      delay(del);
      off(ledRow[1],ledCol[8]);
      
      on(ledRow[0],ledCol[8]);
      delay(del);
      off(ledRow[0],ledCol[8]);
}

//turn on all LEDs one by one.
void testAll(){
    int del = 500;
    
    for(int x=0;x<3;x++){
      for(int y=0;y<9;y++){
        //Serial.print(x + " " + y);
        on(ledRow[x],ledCol[y]);
        delay(del);
        off(ledRow[x],ledCol[y]);
        delay(200);
      }
    }
}




//turn on LED based on row number and column number
void on(int row, int col){
  
  digitalWrite(row, HIGH); //turn on row
  digitalWrite(col, HIGH); //turn on col
  
}

//overload funtion - used to turn LED on with certain intensity
void on(int row, int col, int value){
  digitalWrite(row, HIGH); //turn on row
  analogWrite(col, value); //turn on col
}


//turn off LED based on row number and column number
void off(int row, int col){
  digitalWrite(row, LOW); //turn on row
  digitalWrite(col, LOW); //turn on col
}






////////////////////////////////music///////////////////////////




void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}
void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

