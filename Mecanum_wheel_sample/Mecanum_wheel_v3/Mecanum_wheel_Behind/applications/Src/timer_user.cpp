<<<<<<< HEAD
#include "timer_user.h"
#include "chassic.h"
#include "tim.h"



ROBOT::CHASSIC::Motor motor1;
ROBOT::CHASSIC::Motor motor2;



extern "C"
/**
 * @brief       ???????????????��??????????
 * @param       htim???????��?????????
 * @retval      void
 * @note        ?��??????��??????????????????????????��?????????????????????C++?????��?????????extern "C"?????????extern "C"{}??????
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM1)  //?????????��??????10ms
	{
		robot.chassic.encoder.Encoder_Obtain();
		robot.chassic.encoder.Encoder_filtering();
		Motor_Move();
		Send_Data();
	}


//??????????��?
	if(htim->Instance == TIM2)
	{

	}
	if(htim->Instance == TIM3)
	{

	}

}

void ROBOT::CHASSIC::ENCODER::Encoder_Obtain()
{
   if (__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim2)) /*?��?????????????????*/
   {
     motor1.Encoder = __HAL_TIM_GetCounter(&htim2) -65535;         /* CR1??DIR��??1??????????????????*/
     __HAL_TIM_SetCounter(&htim2, 0);

   } 
   else 																 /*CR1??DIR��??0????????????????????*/
   {
     motor1.Encoder =__HAL_TIM_GetCounter(&htim2);               
     __HAL_TIM_SetCounter(&htim2, 0);

   }

   if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim3))
   {
     motor2.Encoder = __HAL_TIM_GetCounter(&htim3) - 65535;
	 __HAL_TIM_SetCounter(&htim3, 0);
   }
   else
   {
     motor2.Encoder = __HAL_TIM_GetCounter(&htim3);	
	 __HAL_TIM_SetCounter(&htim3, 0);
   }
}

void ROBOT::CHASSIC::ENCODER::Encoder_filtering()
{
	if (motor1.Encoder == -65535)
	{
		motor1.Encoder=0;
	}
	if(motor2.Encoder == -65535)
	{
		motor2.Encoder=0;
	}
//��ͨ�˲�
	motor1.Encoder=P*motor1.Encoder+(1-P)*motor1.last_speed;
	motor1.last_speed=motor1.Encoder;
	motor2.Encoder=P*motor2.Encoder+(1-P)*motor2.last_speed;
	motor2.last_speed=motor2.Encoder;

=======
#include "timer_user.h"
#include "chassic.h"
#include "tim.h"



ROBOT::CHASSIC::Motor motor1;
ROBOT::CHASSIC::Motor motor2;



extern "C"
/**
 * @brief       ???????????????��??????????
 * @param       htim???????��?????????
 * @retval      void
 * @note        ?��??????��??????????????????????????��?????????????????????C++?????��?????????extern "C"?????????extern "C"{}??????
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM1)  //?????????��??????10ms
	{
		robot.chassic.encoder.Encoder_Obtain();
		robot.chassic.encoder.Encoder_filtering();
		Motor_Move();
		Send_Data();
	}


//??????????��?
	if(htim->Instance == TIM2)
	{

	}
	if(htim->Instance == TIM3)
	{

	}

}

void ROBOT::CHASSIC::ENCODER::Encoder_Obtain()
{
   if (__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim2)) /*?��?????????????????*/
   {
     motor1.Encoder = __HAL_TIM_GetCounter(&htim2) -65535;         /* CR1??DIR��??1??????????????????*/
     __HAL_TIM_SetCounter(&htim2, 0);

   } 
   else 																 /*CR1??DIR��??0????????????????????*/
   {
     motor1.Encoder =__HAL_TIM_GetCounter(&htim2);               
     __HAL_TIM_SetCounter(&htim2, 0);

   }

   if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim3))
   {
     motor2.Encoder = __HAL_TIM_GetCounter(&htim3) - 65535;
	 __HAL_TIM_SetCounter(&htim3, 0);
   }
   else
   {
     motor2.Encoder = __HAL_TIM_GetCounter(&htim3);	
	 __HAL_TIM_SetCounter(&htim3, 0);
   }
}

void ROBOT::CHASSIC::ENCODER::Encoder_filtering()
{
	if (motor1.Encoder == -65535)
	{
		motor1.Encoder=0;
	}
	if(motor2.Encoder == -65535)
	{
		motor2.Encoder=0;
	}
//��ͨ�˲�
	motor1.Encoder=P*motor1.Encoder+(1-P)*motor1.last_speed;
	motor1.last_speed=motor1.Encoder;
	motor2.Encoder=P*motor2.Encoder+(1-P)*motor2.last_speed;
	motor2.last_speed=motor2.Encoder;

>>>>>>> 00ac74e (9.6)
}