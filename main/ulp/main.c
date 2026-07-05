//LP RAM Usage of this exemple: 4936 bytes, from 16KB
#include "ulp_lp_core_utils.h"
#include "ssd1306_lp.h"

uint32_t ulp_lp_perf_counter = 0; 
volatile uint32_t ulp_lp_done_flag = 0;
uint32_t ulp_lp_memory_usage = 0;
extern uint32_t _bss_end;    

int main(void) {
    oled_lp_init();
    oled_lp_set_fps(30);

    uint8_t frame_count = 0;

    while (ulp_lp_done_flag == 0) {
        ulp_lp_memory_usage = (uint32_t)&_bss_end - 0x50000000;
        ulp_lp_perf_counter++;
        frame_count++;

            oled_lp_draw_string(30, 10, "DISLPAY TEST", 1, false);
            oled_lp_draw_frame();
        oled_lp_refresh_sync();
    }
    return 0;
}
