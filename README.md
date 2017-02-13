# mcp3008-Arduino-Library
Arduino library for MCP3008 ADC (using hardware SPI)

## Usage:
```
#include <SPI.h>
#include <MCP3008.h>

#define CS_PIN A5 //A5 is convenient on Feather boards, choose any pin you like.

MCP3008 mcp = MCP3008(CS_PIN);

void setup() {
  SPI.begin();
  mcp.begin();
}

void loop() {
  int v0 = mcp.readADC(0);
}

```
