#include "./BSP/BTIM/btim.h"
#include "./SYSTEM/delay/delay.h"


TIM_HandleTypeDef g_timx_handle;
/*��ʱ���жϳ�ʼ������*/

void bitm_timx_int_init( uint16_t arr,uint16_t psc)
{
    g_timx_handle.Instance = TIM2;                              /*����Ĵ�������ַ*/
    g_timx_handle.Init.Prescaler = psc;                         /*��Ƶϵ��*/
    g_timx_handle.Init.Period=arr;                              /*�Զ�����ֵARR*/
    g_timx_handle.Init.CounterMode=TIM_COUNTERMODE_UP;
    HAL_TIM_Base_Init (&g_timx_handle);
    
    __HAL_TIM_CLEAR_FLAG (&g_timx_handle, TIM_SR_UIF);
    
    HAL_TIM_Base_Start_IT(&g_timx_handle);                      /*ʹ�ܸ����жϲ�������ʱ��*/
}
/*��ʱ������MSP��ʼ������*/
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM2)
    {
        __HAL_RCC_TIM2_CLK_ENABLE();                            /*ʱ��ʹ��*/
        HAL_NVIC_SetPriority(TIM2_IRQn,0,0);                    /*�ж����ȼ�����*/
        HAL_NVIC_EnableIRQ(TIM2_IRQn);                          /*ʹ���ж�*/
        
    }
}

/*��ʱ��6�жϷ�����*/
void TIM2_IRQHandler (void)
{
    HAL_TIM_IRQHandler(&g_timx_handle);                         /*�жϹ���������*/
}

/*��ʱ������жϻص�����*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{   if(htim->Instance == TIM2)
    {
        HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
    }
}








