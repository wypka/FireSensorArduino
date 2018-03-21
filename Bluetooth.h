#include <SoftwareSerial.h>
class Bluetooth : public SoftwareSerial{
  public :
    Bluetooth(int rx, int tx, long boardrate);
    String readLine();
};

