
#ifndef __SYSCONFIG_H__
#define __SYSCONFIG_H__
#include <Seeed_Arduino_ooFreeRTOS.h>
#include <Adafruit_TinyUSB.h>
#include <Seeed_Arduino_FS.h>
#include <Seeed_SFUD.h>
#include <sfud.h>


#include <stdint.h>
using namespace cpp_freertos;
class SysConfig
{
public:
	/* lora */
	String ssid;
	String password;
	String lora_frequency;

	static SemaphoreHandle_t lock;

public:
	SysConfig(/* args */);
	~SysConfig();
	void init();
	void ReadAllConfig();
	void WriteConfigParam(char* filename , char *prefix_param, char *param);
private:
	/* data */
    bool spi_flash_mount;
	Adafruit_USBD_MSC usb_msc;
	

	void ReadConfigParam(const String filename,  char *prefix_param, String *param);
};

#endif // __SYSCONFIG_H__