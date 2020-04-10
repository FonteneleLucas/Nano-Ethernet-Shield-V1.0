
#include <UIPEthernet.h>

byte mac[] = { 0x54, 0x34, 0x41, 0x30, 0x30, 0x31 };

EthernetClient client;
char server[] = "xxx.xxx.xxx.xxx";
int  interval = 1000; // Interval to send data

long randNumber;
bool _connected = false;
int pmm = 0;
int pi = 0;
int pe = 0;
int v = 0;
int f = 0;

void setup() {

  Serial.begin(9600);
  UIPEthernet.begin(mac);

  randomSeed(analogRead(0));

}

void loop() {
  n = random(1, 100);
  
  if (_connected == false) {
    if (client.connect(server, 8000)) {
      Serial.println("-> Connected");
      _connected = true;
      //    client.stop();
    }
    else {
      Serial.println("--> Failed to Connect /n");
    }
  }


  if (_connected == true) {
    client.print(n);
  }

  delay(interval);
}
