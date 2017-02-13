#include <MCP3008.h>
#include <SPI.h>

MCP3008::MCP3008(int csPin) {
  _csPin = csPin;
};

void MCP3008::begin() {
  pinMode(_csPin, OUTPUT);
}

int MCP3008::readADC(int channel) {
  if((channel > 7) || (channel < 0)) return -1;
  digitalWrite(_csPin, LOW);
  SPI.beginTransaction(SPISettings(1000, MSBFIRST, SPI_MODE0));
  SPI.transfer(1);
  uint8_t r1 = SPI.transfer((channel + 8) << 4);
  uint8_t r2 = SPI.transfer(0);
  digitalWrite(_csPin, HIGH);
  SPI.endTransaction();
  return ((r1 & 3) << 8) + r2;
};
