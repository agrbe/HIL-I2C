#include <stdio.h>
#include <signal.h>
#include <getopt.h>
#include <rc/mpu.h>
#include <rc/time.h>
#include "inc/bmp.h"

#define BMP
#define MPU

rc_bmp_data_t bmp_data;
rc_mpu_config_t mpu_conf;
rc_mpu_data_t mpu_data;

int main()
{
    #ifdef BMP
    //* Barometer Configuration *//
    rc_bmp_init(BMP_OVERSAMPLE_16, BMP_FILTER_16);
    rc_bmp_read(&bmp_data);
    #endif

    #ifdef MPU
    //* Accelerometer Configuration Variables *//
    mpu_conf = rc_mpu_default_config();
    mpu_conf.i2c_bus = 1;
    mpu_conf.gpio_interrupt_pin_chip = 3;
    mpu_conf.gpio_interrupt_pin = 20;
    mpu_conf.dmp_sample_rate = 200;
    mpu_conf.dmp_fetch_accel_gyro = 1;

    rc_mpu_initialize_dmp(&mpu_data, mpu_conf);
    #endif
}
