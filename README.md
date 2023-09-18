# mp3_player
Code for HW player like MP3-TF-16P and similar DFPlayers and ESP32-cam
Create at 2023/09/18 so pay attention for actuality


## HERE IS SOME DETAILS
Used hardware MP3-TF-16P mp3 player and the ESP32-cam

Serial port library EspSoftwareSerial:
https://github.com/plerup/espsoftwareserial/

MP3 player for MP3-TF-16P and similar DFPlayers library DFPlayerMini_Fast
https://github.com/PowerBroker2/DFPlayerMini_Fast/tree/master

Use 5V individual power (from power bank) for each MP3-TF-16P and ESP32-cam Do not try to get 3.3V power from ESP32-cam. 
It does not have LDO and even GND for 5V is differ from GND for 3.3V

## Note 
that MP3 files should be named like 0001_FirstFile, 0002_SecondFile e.t.g where the 0001 ... 9999 is iterated track numbers and _FirstFile, _SecondFile e.t.g are the custom names that can be used for display on LCD screen.
Example how to name files and calalogues:
- music
  - playlist1
    - 001_song1.mp3
    - 002_song2.mp3
  - playlist2
    - 001_track1.mp3
    - 002_track2.mp3

Wire ESP32-cam pins RX - 13,  TX - 14 and MP3-TF-16P pins TX, RX through 1kOhm resistors

This sketch play 2000ms fragments of every track.
If you need longer play, please change the logic accordigly.


## Library API:
- bool begin(Stream& stream, bool debug, unsigned long threshold=100);

- void playNext();
- void playPrevious();
- void play(uint16_t trackNum);
- void stop();
- void playFromMP3Folder(uint16_t trackNum);
- void playAdvertisement(uint16_t trackNum);
- void stopAdvertisement();
- void incVolume();
- void decVolume();
- void volume(uint8_t volume);
- void EQSelect(uint8_t setting);
- void loop(uint16_t trackNum);
- void playbackSource(uint8_t source);
- void standbyMode();
- void normalMode();
- void reset();
- void resume();
- void pause();
- void playFolder(uint8_t folderNum, uint8_t trackNum);
- void playLargeFolder(uint8_t folderNum, uint16_t trackNum);
- void volumeAdjustSet(uint8_t gain);
- void startRepeatPlay();
- void stopRepeatPlay();
- void repeatFolder(uint16_t folder);
- void randomAll();
- void startRepeat();
- void stopRepeat();
- void startDAC();
- void stopDAC();
- void sleep();
- void wakeUp();

- bool isPlaying();
- int16_t currentVolume();
- int16_t currentEQ();
- int16_t currentMode();
- int16_t currentVersion();
- int16_t numUsbTracks();
- int16_t numSdTracks();
- int16_t numFlashTracks();
- int16_t currentUsbTrack();
- int16_t currentSdTrack();
- int16_t currentFlashTrack();
- int16_t numTracksInFolder(uint8_t folder);
- int16_t numFolders();

- void setTimeout(unsigned long threshold);
- void findChecksum(stack& _stack);
- void sendData();
- void flush();
- int16_t query(uint8_t cmd, uint8_t msb=0, uint8_t lsb=0);
- bool parseFeedback();

- void printStack(stack _stack);
- void printError();

