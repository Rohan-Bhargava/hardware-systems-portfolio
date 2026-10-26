#include<mysystem_stm32h5xx.h>

void MySystemBringUp(void){
    PWR->VOSCR |= PWR_VOSCR_VOS_0;
    uint32_t pwr_stepup_cycles_to_wait = TIMEOUT_PWR_VOS;
    uint32_t pwr_stepup_cycles_waited = 0U;
    uint32_t pwr_stepup_success = 1U;

    while (!(PWR->VOSSR & PWR_VOSSR_VOSRDY))
    {
        if (pwr_stepup_cycles_waited>pwr_stepup_cycles_to_wait)
        {
            pwr_stepup_success=0U;
            break;
        }
        pwr_stepup_cycles_waited++;
    }

    uint32_t pwr_fallback_cycles_to_wait = TIMEOUT_PWR_VOS;
    uint32_t pwr_fallback_cycles_waited = 0U;
    uint32_t pwr_fallback_success = 1U;

    if (!pwr_stepup_success)
    {
        PWR->VOSCR &= 0xCF;

        while (!(PWR->VOSSR & PWR_VOSSR_VOSRDY))
        {
            if (pwr_fallback_cycles_waited>pwr_fallback_cycles_to_wait)
            {
                pwr_fallback_success=0U;
                break;
            }
            pwr_fallback_cycles_waited++;
        }
    }

    if (!pwr_fallback_success)
    {
        /* code */
    }
    
    

    uint32_t icache_init_cycles_to_wait = TIMEOUT_ICACHE;
    uint32_t icache_init_cycles_waited = 0U;
    uint32_t icache_init_success = 1U;

    while (!(ICACHE->SR & 0xFFFFFFFE))
    {
        if (icache_init_cycles_waited >icache_init_cycles_to_wait )
        {
            icache_init_success=0U;
            break;
        }
        icache_init_cycles_waited++;
    }

    if (icache_init_success)
    {
        ICACHE->CR |= 0x1;
        uint32_t icache_en_cycles_to_wait = 1000000U;
        uint32_t icache_en_cycles_waited = 0U;
        uint32_t icache_en_success = 1U;

        while (!(ICACHE->CR & 0x1))
        {
            if (icache_en_cycles_waited >icache_en_cycles_to_wait )
            {
                icache_en_success=0U;
                break;
            }
            icache_en_cycles_waited++;
        }
    }
    
    
    if (icache_init_success && pwr_stepup_success)
    {
        FLASH->ACR = FLASH->ACR | FLASH_ACR_LATENCY_5WS | FLASH_ACR_PRFTEN;
        uint32_t flash_setup_cycles_to_wait = TIMEOUT_FLASH;
        uint32_t flash_setup_cycles_waited = 0U;
        uint32_t flash_setup_success = 1U;

        while (!(FLASH->ACR & 0x135))
        {
            if (flash_setup_cycles_waited >flash_setup_cycles_to_wait )
            {
                flash_setup_success=0U;
                break;
            }
            flash_setup_cycles_waited++;
        }
    }
}