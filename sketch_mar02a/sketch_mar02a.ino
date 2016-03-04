/*
    3x3x3 LED cube with shift register (using 9 output pins).

    For details, see:
    http://hblok.net

    http://hblok.net/blog/posts/tag/led-cube

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Digital output pins

const int data =  5;
const int latch = 6;
const int clock = 7;

const int layer0 =  9;
const int layer1 = 10;
const int layer2 = 11;

const int layers[3] = {
  layer0, layer1, layer2};

const int outputPinCount = 6;
int outputPins[outputPinCount] = {
  data, clock, latch, layer0, layer1, layer2};

// Frame buffer
const int lights = 27;
int buf[lights];


void setupPins() {
  for (int i = 0; i < outputPinCount; i++) {
      pinMode(outputPins[i], OUTPUT);
  }
  clearAll();
}

void setup() {
  Serial.begin(9600);
  Serial.println("reset");

  setupPins();
  setAll(1);
}

int c = 0;
unsigned long now = 0, last_trigger = 0;
bool show = true;
int rate = 0;
String tmp;

void loop() {
  now = millis();
  if (now >= last_trigger + 1000 && now != last_trigger) {
    count(c++);
    c = c >= 27 ? 0 : c;

    last_trigger = now; 
    show = true;

    tmp = "";
    tmp += now; tmp += ": "; tmp += rate;
    Serial.println(tmp); 
    rate = 0;
  }

  display();
  rate++; 
}

void count(int i) {
  clearAll();
  buf[i] = 1;
}

void clearAll() {
  setAll(0);
}

void setAll(int v) {
  for (int i = 0; i < lights; i++) {
    buf[i] = v;
  }
}

void display() {
  for(int l = 0; l < 3; l++) {
    digitalWrite(layers[l], HIGH);

    digitalWrite(latch, LOW);
    for(int i = 0; i <= 7; i++) {
      digitalWrite(clock, LOW);
      int bit = buf[l*9 + 7-i];
      digitalWrite(data, bit);
      digitalWrite(clock, HIGH);
    }
    digitalWrite(latch, HIGH);

    if (buf[l*9 + 7] != buf[l*9 + 8]) {
      digitalWrite(data, buf[l*9 + 8]);
      for(int i = 0; i <= 8; i++) {
  digitalWrite(clock, LOW);
  digitalWrite(clock, HIGH);
      }
    }

    digitalWrite(layers[l], LOW);
    delay(3);
    digitalWrite(layers[l], HIGH);
  }
}
