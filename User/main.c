#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"
#include "Encoder.h"
#include "MPU6050.h"

uint8_t KeyNum;
int8_t Speed;
int16_t AX, AY, AZ, GX, GY, GZ;

int main(void)
{
	OLED_Init();
	Motor_Init();
	Key_Init();
	Encoder_Init();
	MPU6050_Init();
	
	OLED_ShowString(1, 1, "Speed:");
	
	while (1)
	{
		Speed += Encoder_Get();
		if (Speed > 60)
			{
				Speed = 60;
			}
		if (Speed < -60)
			{
				Speed = -60;
			}
		Motor_SetSpeed(Speed);
		OLED_ShowSignedNum(1, 7, Speed, 3);
		
		MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);
		OLED_ShowSignedNum(2, 1, AX, 5);
		OLED_ShowSignedNum(3, 1, AY, 5);
		OLED_ShowSignedNum(4, 1, AZ, 5);
		OLED_ShowSignedNum(2, 8, GX, 5);
		OLED_ShowSignedNum(3, 8, GY, 5);
		OLED_ShowSignedNum(4, 8, GZ, 5);
		
		
		
	}
}
