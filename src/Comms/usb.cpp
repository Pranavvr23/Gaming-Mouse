#include "usb.h"

int initializeMouse(Adafruit_USBD_HID &usb, const uint8_t *descReport, int descSize){
    usb.setBootProtocol(HID_ITF_PROTOCOL_MOUSE);
    usb.setPollInterval(1);
    usb.setReportDescriptor(descReport, descSize);
    usb.begin();
    while(!TinyUSBDevice.mounted()) delay(1);
    return 1;
}