#include <Arduino.h>

class MCP3008 {
  public:
    MCP3008(int csPin);
    void begin();
    int readADC(int channel);
  private:
    int _csPin;
};
