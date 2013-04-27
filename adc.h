#ifndef ADC_H
#define ADC_H

// function prototypes and macros for adc.c
#define R_SENSOR     0
#define L_SENSOR     1
#define RF_SENSOR    2
#define LF_SENSOR    3

void ADC_Init(void);

int ADC_Sample(int buf_num);
#endif
