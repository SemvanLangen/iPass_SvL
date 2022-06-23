#ifndef YOUR_PROJECT_NAME_PCA9685_CONSTANTS_HPP
#define YOUR_PROJECT_NAME_PCA9685_CONSTANTS_HPP

// slave address
constexpr uint8_t address_slave        = 0x40;

// MODE1 status
constexpr uint8_t MODE1_reg            = 0x00;
constexpr uint8_t MODE1_reg_sleep      = 0x11;
constexpr uint8_t MODE1_reg_normal     = 0x01;

// prescale register location
constexpr uint8_t PRE_SCALE_reg        = 0xFE;

constexpr uint8_t standard_led_on_h    = 0x00;
constexpr uint8_t standard_led_on_l    = 0xCC;

// all neccescary addressess of the led outputs
constexpr uint8_t LED0_ON_L            = 0x06;
constexpr uint8_t LED0_ON_H            = 0x07;
constexpr uint8_t LED0_OFF_L           = 0x08;
constexpr uint8_t LED0_OFF_H           = 0x09;

constexpr uint8_t LED1_ON_L            = 0x0A;
constexpr uint8_t LED1_ON_H            = 0x0B;
constexpr uint8_t LED1_OFF_L           = 0x0C;
constexpr uint8_t LED1_OFF_H           = 0x0D;

constexpr uint8_t LED2_ON_L            = 0x0E;
constexpr uint8_t LED2_ON_H            = 0x0F;
constexpr uint8_t LED2_OFF_L           = 0x10;
constexpr uint8_t LED2_OFF_H           = 0x11;

constexpr uint8_t LED3_ON_L            = 0x12;
constexpr uint8_t LED3_ON_H            = 0x13;
constexpr uint8_t LED3_OFF_L           = 0x14;
constexpr uint8_t LED3_OFF_H           = 0x15;

constexpr uint8_t LED4_ON_L            = 0x16;
constexpr uint8_t LED4_ON_H            = 0x17;
constexpr uint8_t LED4_OFF_L           = 0x18;
constexpr uint8_t LED4_OFF_H           = 0x19;

constexpr uint8_t LED5_ON_L            = 0x1A;
constexpr uint8_t LED5_ON_H            = 0x1B;
constexpr uint8_t LED5_OFF_L           = 0x1C;
constexpr uint8_t LED5_OFF_H           = 0x1D;

constexpr uint8_t LED6_ON_L            = 0x1E;
constexpr uint8_t LED6_ON_H            = 0x1F;
constexpr uint8_t LED6_OFF_L           = 0x20;
constexpr uint8_t LED6_OFF_H           = 0x21;

constexpr uint8_t LED7_ON_L            = 0x22;
constexpr uint8_t LED7_ON_H            = 0x23;
constexpr uint8_t LED7_OFF_L           = 0x24;
constexpr uint8_t LED7_OFF_H           = 0x25;

#endif
