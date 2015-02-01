
#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server(173,194,33,104); // Google
int lightLevel;

const int sensorPin = 1;


// Initialize the Ethernet client library
// with the IP address and port of the server 
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  delay(2000);
  system("ifup eth0"); 
  system("ifconfig eth0 > /dev/ttyGS0");

  // give the Ethernet shield a second to initialize:
  delay(2000);
  Serial.println("connecting...");
 lightLevel = analogRead(sensorPin);
  // if you get a connection, report back via serial:
  if (client.connect("api-flow.att.io", 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.print("GET /sandbox/hackathon/m2mhack5/in/flow/hack/echo?value=");
    client.print(lightLevel);
    client.println(" HTTP/1.1");
    client.println("Connection: close");
    client.println();
  } 
  else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
}void loop()
{
  // if there are incoming bytes available 
  // from the server, read them and print them:
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }



 
}

