#include <SPI.h>
#include <MCP3008.h>
const int PIN_CS = A5;

MCP3008 mcp = MCP3008(PIN_CS);

void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  mcp.begin(); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<8; i++) {
    Serial.println(mcp.readADC(i));
  }
  delay(1000);
}
