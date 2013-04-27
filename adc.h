#ifndef ADC_H
#define ADC_H

// function prototypes and macros for adc.c
#define RF_SENSOR   0
#define LF_SENSOR   1
#define R_SENSOR    2
#define L_SENSOR    3

void ADC_Init(void);

int ADC_Sample(int buf_num);
#endif
