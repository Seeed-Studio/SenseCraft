#include <TFT_eSPI.h>
#include "Free_Fonts.h"

TFT_eSPI tft;
TFT_eSprite spr = TFT_eSprite(&tft);

#define SCREEN_WIDTH 320                        // Wio Terminal Maximum Width
#define SCREEN_HIGH 240                         // Wio Terminal Maximum Height
#define PIXEL 4                                 // Width of one letter
const static unsigned int FONT_ROW_HEIGHT = 22; // The height of a letter

void DISPLAY_INIT() // Display initialization, black background rotation
{
    pinMode(A0, INPUT);
    pinMode(WIO_LIGHT, INPUT);
    pinMode(WIO_KEY_A, INPUT_PULLUP);
    pinMode(WIO_KEY_B, INPUT_PULLUP);
    pinMode(WIO_KEY_C, INPUT_PULLUP);
    tft.begin();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
}

// 320 * 25 = 8000
void Network_state(int s_key)
{
    spr.createSprite(140, 25);
    spr.setFreeFont(FSSB9);
    spr.fillSprite(TFT_BLACK);

    switch (s_key)
    {
    case 0:
        spr.setTextColor(TFT_RED);
        spr.drawString("OFF", 60, 0, 2);
        break;
    case 1:
        spr.setTextColor(TFT_GREEN, TFT_BLACK);           // Networking status indication：ON
        spr.drawString("LoRa", 60, 0, 2); // Show the network you are in
        break;
    case 2:
        spr.setTextColor(TFT_GREEN, TFT_BLACK);          // Networking status indication：ON
        spr.drawString("WiFi", 60, 0, 2); // Show the network you are in
        break;
    default:;
    }
    spr.setTextColor(TFT_WHITE);
    spr.drawString("Network:", 5, 0, 2);
    spr.setFreeFont(FSS9);
    
    spr.pushSprite(0, 215);
    spr.deleteSprite();
}

int GG;

//320*70 = 22400
void Sense_Display(int CHOOSE_PAGE) // Sense interface display
{
    spr.createSprite(320, 50);
    spr.setFreeFont(FSSB9);
    switch (CHOOSE_PAGE)
    {
    case 0:
        spr.fillRect(4 * PIXEL, 0, 21 * PIXEL, FONT_ROW_HEIGHT + 15, tft.color565(135, 206, 235));
        spr.fillRect(30 * PIXEL, 0, 21 * PIXEL, FONT_ROW_HEIGHT + 15, TFT_WHITE);
        spr.fillRect(56 * PIXEL, 0, 21 * PIXEL, FONT_ROW_HEIGHT + 15, TFT_WHITE);
        break;
    case 1:
        spr.fillRect(4 * PIXEL, 0, 21 * PIXEL, FONT_ROW_HEIGHT + 15, TFT_WHITE);
        spr.fillRect(30 * PIXEL, 0, 21 * PIXEL, FONT_ROW_HEIGHT + 15, tft.color565(135, 206, 235));
        spr.fillRect(56 * PIXEL, 0, 21 * PIXEL, FONT_ROW_HEIGHT + 15, TFT_WHITE);
        break;
    case 2:
        spr.fillRect(4 * PIXEL, 0, 21 * PIXEL, FONT_ROW_HEIGHT + 15, TFT_WHITE);
        spr.fillRect(30 * PIXEL, 0, 21 * PIXEL, FONT_ROW_HEIGHT + 15, TFT_WHITE);
        spr.fillRect(56 * PIXEL, 0, 21 * PIXEL, FONT_ROW_HEIGHT + 15, tft.color565(135, 206, 235));
        break;
    default:
        break;
    }

    spr.setFreeFont(FSSB9);
    spr.setTextColor(TFT_BLACK);
    spr.drawString("Sense", 32, 11, GFXFF);
    spr.drawString("Process", 127, 11, GFXFF);
    spr.drawString("Network", 231, 11, GFXFF);
    spr.drawLine(0, 2 * FONT_ROW_HEIGHT, SCREEN_WIDTH, 2 * FONT_ROW_HEIGHT, TFT_WHITE);

    spr.pushSprite(0, 0);
    spr.deleteSprite();
}

void Below_Right_State_Content(int gg_state)  // SD 插拔状态 Grove 插拔状态
{
    
    spr.createSprite(320, 25);
    spr.setFreeFont(FSSB9);
    spr.fillSprite(TFT_BLACK);
    // int s_key = 1;
    switch (gg_state)
    {
    case 0:
        spr.setFreeFont(FSS9);
        spr.setTextColor(TFT_YELLOW);
        spr.drawString("Plug in a Grove sensor", 0, 0, 2);
        spr.pushSprite(170, 215);
        break;
    case 1:
        spr.setFreeFont(FSS9);
        spr.drawTriangle(0, 18, 11, 0, 22, 18, TFT_YELLOW);
        spr.setTextColor(TFT_YELLOW);
        spr.drawString("! ", 10, 4, 2);
        spr.drawString("TF card storage is full", 28, 0, 2);
        spr.pushSprite(140, 215);
        break;
    case 2:
        spr.setFreeFont(FSS9);
        spr.setTextColor(TFT_GREEN);
        spr.drawString("Vision AI Sensor connected", 22, 0, 2);
        spr.pushSprite(120, 215);
        break;
    case 3:
        spr.setFreeFont(FSS9);
        spr.setTextColor(TFT_GREEN);
        spr.drawString("Saving has been started", 22, 0, 2);
        spr.pushSprite(140, 215);
        break;
    case 4:
        spr.setFreeFont(FSS9);
        spr.setTextColor(TFT_YELLOW);
        spr.drawString("Please insert TF card", 22, 0, 2);
        spr.pushSprite(148, 215);
        break;
    
    default:;
    }
    
    spr.setTextColor(TFT_WHITE);
    spr.drawString("Network :", 5, 0, GFXFF);
    
    spr.deleteSprite();
}
void network(){
    spr.createSprite(78, 30);
    spr.fillSprite(tft.color565(100, 100, 100));
    spr.setFreeFont(FSS9);
    spr.setTextColor(TFT_WHITE);
    spr.drawString("Network", 6 , 6, GFXFF);
    spr.pushSprite(122, 50);
    spr.deleteSprite();
  }
void lora(){
    spr.createSprite(155, 30);
    spr.fillSprite(tft.color565(100, 100, 100));
    spr.setFreeFont(FSS9);
    spr.setTextColor(TFT_WHITE);
    spr.drawString("LoRa(SenseCAP)", 6 , 6, GFXFF);
    spr.pushSprite(85, 50);
    spr.deleteSprite();
  }
  
void wifi(){
    spr.createSprite(120, 30);
    spr.fillSprite(tft.color565(100, 100, 100));
    spr.setFreeFont(FSS9);
    spr.setTextColor(TFT_WHITE);
    spr.drawString("WiFi(Ubidots)", 6 , 6, GFXFF);
    spr.pushSprite(102, 50);
    spr.deleteSprite();
}


void network_select(int joystick){
  switch (joystick){
  case 0:
    network();
    spr.createSprite(110, 60);
    spr.fillSprite(TFT_BLACK);
    spr.setFreeFont(FSS9);
    spr.setTextColor(TFT_WHITE);
    spr.drawString("LoRa",6 ,6, GFXFF);
    spr.drawString("(SenseCAP)",5 ,36, GFXFF);
    spr.pushSprite(30,95);
    spr.deleteSprite();

    spr.createSprite(110, 60);
    spr.fillSprite(TFT_BLACK);
    spr.setFreeFont(FSS9);
    spr.setTextColor(TFT_WHITE);
    spr.drawString("WIFI",6 ,6, GFXFF);
    spr.drawString("(Ubidots)",6 ,36, GFXFF);
    spr.pushSprite(200,95);
    spr.deleteSprite();

    spr.createSprite(240, 50);
    spr.fillSprite(TFT_BLACK);
    spr.setFreeFont(FSS9);
    spr.setTextColor(TFT_WHITE);
    spr.drawString("Please toggle the bottom right button", 6,6,2);
    spr.drawString("left and right to select the network.", 6,26,2);
    spr.pushSprite(35,160);
    spr.deleteSprite();
    break;

  case 1:
    lora();
    spr.createSprite(110, 60);
    spr.fillSprite(tft.color565(0, 139, 0));
    spr.setFreeFont(FSS9);
    spr.setTextColor(TFT_WHITE);
    spr.drawString("LoRa",6 ,6, GFXFF);
    spr.drawString("(SenseCAP)",5 ,36, GFXFF);
    spr.pushSprite(30,95);
    spr.deleteSprite();

    spr.createSprite(110, 60);
    spr.fillSprite(TFT_BLACK);
    spr.setFreeFont(FSS9);
    spr.setTextColor(TFT_WHITE);
    spr.drawString("WIFI",6 ,6, GFXFF);
    spr.drawString("(Ubidots)",6 ,36, GFXFF);
    spr.pushSprite(200,95);
    spr.deleteSprite();

    spr.createSprite(240, 50);
    spr.fillSprite(TFT_BLACK);
    spr.setFreeFont(FSS9);
    spr.setTextColor(TFT_WHITE);
    spr.drawString("Please press the bottom right button", 6,6,2);
    spr.drawString("to confirm your network selection.", 6,26,2);
    spr.pushSprite(35,160);
    spr.deleteSprite();
    break;

    case 2:
    wifi();
    spr.createSprite(110, 60);
    spr.fillSprite(TFT_BLACK);
    spr.setFreeFont(FSS9);
    spr.setTextColor(TFT_WHITE);
    spr.drawString("LoRa",6 ,6, GFXFF);
    spr.drawString("(SenseCAP)",5 ,36, GFXFF);
    spr.pushSprite(30,95);
    spr.deleteSprite();

    spr.createSprite(110, 60);
    spr.fillSprite(tft.color565(0, 139, 0));
    spr.setFreeFont(FSS9);
    spr.setTextColor(TFT_WHITE);
    spr.drawString("WIFI",6 ,6, GFXFF);
    spr.drawString("(Ubidots)",6 ,36, GFXFF);
    spr.pushSprite(200,95);
    spr.deleteSprite();

    spr.createSprite(300, 50);
    spr.fillSprite(TFT_BLACK);
    spr.setFreeFont(FSS9);
    spr.setTextColor(TFT_WHITE);
    spr.drawString("Please refer to the wikito modify the", 6,6,2);
    spr.drawString("configuration file and send it to this device.", 6,26,2);
    spr.pushSprite(15,160);
    spr.deleteSprite();
    break;
    
  }
}

void setup()
{
    DISPLAY_INIT();
}

int test_flag = 0;
int test_flag_1 = 0;
int joystick = 0;
void loop()
{
    if (digitalRead(WIO_KEY_A) == LOW){
       test_flag_1++;
       delay(300);
    }

    Sense_Display(test_flag_1%3);

    if (digitalRead(WIO_KEY_B) == LOW){
       test_flag++;
       delay(300);
    }

    Network_state(test_flag%3); // 修改网络状态  左下角
    network_select(2);
    Below_Right_State_Content(test_flag%5);  // 修改 右下角 状态 
    
    delay(20);
}