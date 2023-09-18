/*
Serial port library EspSoftwareSerial:
https://github.com/plerup/espsoftwareserial/

MP3 player for MP3-TF-16P and similar DFPlayers library DFPlayerMini_Fast
https://github.com/PowerBroker2/DFPlayerMini_Fast/tree/master

Use 5V individual power for each MP3-TF-16P and ESP32-cam Do not try to get 3.3V power from ESP32-cam. 
It does not have LDO and even GND for 5V is differ from GND for 3.3V

Library API:
bool begin(Stream& stream, bool debug, unsigned long threshold=100);

void playNext();
void playPrevious();
void play(uint16_t trackNum);
void stop();
void playFromMP3Folder(uint16_t trackNum);
void playAdvertisement(uint16_t trackNum);
void stopAdvertisement();
void incVolume();
void decVolume();
void volume(uint8_t volume);
void EQSelect(uint8_t setting);
void loop(uint16_t trackNum);
void playbackSource(uint8_t source);
void standbyMode();
void normalMode();
void reset();
void resume();
void pause();
void playFolder(uint8_t folderNum, uint8_t trackNum);
void playLargeFolder(uint8_t folderNum, uint16_t trackNum);
void volumeAdjustSet(uint8_t gain);
void startRepeatPlay();
void stopRepeatPlay();
void repeatFolder(uint16_t folder);
void randomAll();
void startRepeat();
void stopRepeat();
void startDAC();
void stopDAC();
void sleep();
void wakeUp();

bool isPlaying();
int16_t currentVolume();
int16_t currentEQ();
int16_t currentMode();
int16_t currentVersion();
int16_t numUsbTracks();
int16_t numSdTracks();
int16_t numFlashTracks();
int16_t currentUsbTrack();
int16_t currentSdTrack();
int16_t currentFlashTrack();
int16_t numTracksInFolder(uint8_t folder);
int16_t numFolders();

void setTimeout(unsigned long threshold);
void findChecksum(stack& _stack);
void sendData();
void flush();
int16_t query(uint8_t cmd, uint8_t msb=0, uint8_t lsb=0);
bool parseFeedback();

void printStack(stack _stack);
void printError();
*/
#include <DFPlayerMini_Fast.h>

#if !defined(UBRR1H)
#include <SoftwareSerial.h>
SoftwareSerial mySerial(13, 14);  // RX, TX
#endif

DFPlayerMini_Fast myMP3;

void setup() {
  Serial.begin(115200);

#if !defined(UBRR1H)
  mySerial.begin(9600);
  myMP3.begin(mySerial, true);
#else
  Serial1.begin(9600);
  myMP3.begin(Serial1, true);
#endif
  delay(3000);
  Serial.println("Setting volume to 5/30");
  myMP3.volume(5);
  long int play_timer = millis();
  myMP3.play(1);
  while (millis() - play_timer < 2000) {
  }
  myMP3.stop();
  play_timer = millis();
  for (int i = 1; i < 10; i++) {
    Serial.printf("Looping track %d\n", i);
    myMP3.playNext();
    while (millis() - play_timer < 2000) {
    }
    myMP3.stop();
    play_timer = millis();
    while (millis() - play_timer < 500) {
    }
    play_timer = millis();
  }
}

void loop() {

  //do nothing
}
