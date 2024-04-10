#include <Arduino.h>


#define MAX_FRAME_SIZE          224
#define MODBUS_FN_READHOLDINGREG 0x03
#define MODBUS_FN_READINPUTREG 0x04
#define MODBUS_FN_WRITEMULREG 0x10
#define SOFAR_FN_PASSIVEMODE    0x42
#define SOFAR_PARAM_STANDBY     0x5555

// This is the return object for the sendModbus() function. Since we are a modbus master, we
// are primarily interested in the responses to our commands.
struct modbusResponse
{
  uint8_t errorLevel;
  uint8_t data[MAX_FRAME_SIZE];
  uint8_t dataSize;
  uint8_t frame[MAX_FRAME_SIZE];
  uint8_t frameSize;  
  char* errorMessage;
};


bool checkTimer(unsigned long *lastRun, unsigned long interval);
void sendMqtt(char* topic, String msg_str);
void drawCentreString(const String &buf, int x, int y);
void loopRuns();
int readBulkReg(uint8_t id, uint16_t reg, uint8_t bulkSize, modbusResponse *rs);
int readSingleReg(uint8_t id, uint16_t reg, modbusResponse *rs);
int sendModbus(uint8_t frame[], byte frameSize, modbusResponse *resp);
void calcCRC(uint8_t frame[], byte frameSize);
bool checkCRC(uint8_t frame[], byte frameSize);
int sendPassiveCmdV2(uint8_t id, uint16_t cmd, int32_t param, String pubTopic);
void printScreen(String text);
void printScreenText(String text1, String text2);
void printScreen2(String text) ;
void printScreen2text(String text1, String text2);
void resetConfig();
int listen(modbusResponse *resp);
void displayBatterySave(String mode);
int sendPassiveCmd(uint8_t id, uint16_t cmd, uint16_t param, String pubTopic);
int sendPassiveCmdV2(uint8_t id, uint16_t cmd, int32_t param, String pubTopic);
int16_t batteryWatts();