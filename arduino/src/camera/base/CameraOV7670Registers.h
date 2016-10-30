//
// Created by indrek on 30.10.2016.
//

#ifndef LIVEOV7670_CAMERAOV7670REGISTERS_H
#define LIVEOV7670_CAMERAOV7670REGISTERS_H


#include "Arduino.h"
#include "Wire.h"
#include "CameraOV7670RegisterDefinitions.h"




class CameraOV7670Registers {


private:
    uint8_t i2cAddress;

public:
    static const RegisterData regsDefault[];
    static const RegisterData regsRGB565[];
    static const RegisterData regsBayerRGB[];
    static const RegisterData regsYUV422[];
    static const RegisterData regsQQVGA[];
    static const RegisterData regsQVGA[];
    static const RegisterData regsVGA[];

    CameraOV7670Registers(uint8_t i2cAddress) : i2cAddress(i2cAddress) {}


    void resetSettings();
    void setRegisters(const RegisterData *registerData);
    void setRegister(uint8_t addr, uint8_t val);
    uint8_t readRegister(uint8_t addr);
    void addBitsToRegister(uint8_t addr, uint8_t bits);

    void setDisablePixelClockDuringBlankLines();
    void setInternalClockPreScaler(int preScaler);

};


#endif //LIVEOV7670_CAMERAOV7670REGISTERS_H