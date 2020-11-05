/*
 * gyroAccel.h
 *
 *  Created on: Nov 5, 2020
 *      Author: ellatorregrosa
 */

#ifndef GYROACCEL_H_
#define GYROACCEL_H_

#include "Arduino.h"
#include <Wire.h>

class GyroAccel{
public:
    GyroAccel(){}
//    ~GyroAccel(){}
    void debug();
    void push(uint8_t* buf, uint8_t len);
    void pull(uint8_t* buf, uint8_t len);

    int gyro_x, gyro_y, gyro_z;
    long acc_x, acc_y, acc_z;
    int temperature;
    long gyro_x_cal, gyro_y_cal, gyro_z_cal;

    uint8_t values[12];

    void gyroStart();
    void getGyroValues();
    void gyroCalibrate();
};



#endif /* GYROACCEL_H_ */
