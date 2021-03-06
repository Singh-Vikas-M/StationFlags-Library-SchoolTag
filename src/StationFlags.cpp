
#include "Arduino.h"
#include "EEPROM.h"
#include "StationFlags.h"

//constructor
StationFlags::StationFlags() {}

//method that sets RTC communication error flag
void StationFlags::setRTCComErrorFlag()
{
    byte newFlag = (EEPROM.read(FLAG_START_ADDR) | 1); // OR 1 = 00000001 with flag byte
    EEPROM.write(FLAG_START_ADDR, newFlag);
}

//method that sets RTC Power Lost error flag
void StationFlags::setRTCPowerLostFlag()
{

    byte newFlag = (EEPROM.read(FLAG_START_ADDR) | 2); // OR 1 = 00000010 with flag byte
    EEPROM.write(FLAG_START_ADDR, newFlag);
}

//method that sets low battery flag
void StationFlags::setLowBatteryFlag()
{
    byte newFlag = (EEPROM.read(FLAG_START_ADDR) | 4); // OR 2 = 00000100 with flag byte
    EEPROM.write(FLAG_START_ADDR, newFlag);
}

void StationFlags::printFlagByte()
{
    Serial.print(EEPROM.read(FLAG_START_ADDR), BIN);
}

void StationFlags::clearFlagByte()
{
    for (int eepromAddress = 0; eepromAddress < EEPROM.length(); eepromAddress++)
    {
        EEPROM.write(eepromAddress, 0);
    }
}