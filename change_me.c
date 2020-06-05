//
// Created by vlado on 4/6/20.
//

#define _POSIX_C_SOURCE 200112L

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"

void clear(void *parlcd_mem_base) {
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    int i, j;
    unsigned c;

    for (i = 0; i < 320 ; i++) {
        for (j = 0; j < 480 ; j++) {
            c = 0;
            parlcd_write_data(parlcd_mem_base, c);
        }
    }
}

struct timespec loop_delay = {.tv_sec = 0, .tv_nsec = 0};
void sleep_ms(int milliseconds) {
    loop_delay.tv_sec = 0;
    loop_delay.tv_nsec = milliseconds * 1000000;
    clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
}

uint16_t *fb;

void draw_pixel(int x, int y, uint16_t color) {
    if (x>=0 && x<480 && y>=0 && y<320) {
        fb[x+480*y] = color;
    }
}

void run_led() {
    /*
     * Setup memory mapping which provides access to the peripheral
     * registers region of RGB LEDs, knobs and line of yellow LEDs.
     */
    unsigned char* mem_base = map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
    uint32_t val_line=5;

    /* If mapping fails exit with error code */
    if (mem_base == NULL)
        exit(1);

    for (int i=0; i<30; i++) {
        *(volatile uint32_t*)(mem_base + SPILED_REG_LED_LINE_o) = val_line;
        val_line<<=1;
        printf("LED val 0x%x\n", val_line);
        sleep_ms(10);
    }
}

int main(int argc, char *argv[]) {
    unsigned char *mem_base;
    unsigned char *parlcd_mem_base;
    uint32_t val_line=5;
    int i,j,k;
    int ptr;
    unsigned int c;
    fb = (uint16_t *)malloc(sizeof(uint16_t) * 320*480);

    printf("Hello world\n");

    // run_led();

    parlcd_mem_base = map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);

    if (parlcd_mem_base == NULL)
        exit(1);

    printf("Drawing\n");

    parlcd_hx8357_init(parlcd_mem_base);

    clear(parlcd_mem_base);

    // parlcd_write_cmd(parlcd_mem_base, 0x2c);
    // for (i = 0; i < 320 ; i++) {
    //     for (j = 0; j < 480 ; j++) {
    //         c = ((i & 0x1f) << 11) | (j & 0x1f);
    //         parlcd_write_data(parlcd_mem_base, c);
    //     }
    // }

    // uint16_t* fb = (uint16_t*)malloc(sizeof(uint16_t)*320*480);
    // parlcd_write_cmd(parlcd_mem_base, 0x2c);
    // for (int z = 1; z < 320*480; z++) {
    //     // fb[z-1] = 0;
    //     fb[z] = 0x1f<<5;

    //     for (int ptr = 0; ptr < 480*320 ; ptr++) {
    //         parlcd_write_data(parlcd_mem_base, fb[ptr]);
    //     }

    //     sleep_ms(20);
    // }


    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    ptr=0;
    for (i = 0; i < 320 ; i++) {
        for (j = 0; j < 480 ; j++) {
            c = 0;
            fb[ptr]=c;
            parlcd_write_data(parlcd_mem_base, fb[ptr++]);
        }
    }

    // loop_delay.tv_sec = 0;
    // loop_delay.tv_nsec = 150 * 1000 * 1000;
    for (k=0; k<220; k++) {

        // Clear frame buffer
        for (ptr = 0; ptr < 320*480 ; ptr++) {
            fb[ptr]=0u;
        }

        // Write to frame buffer
        // pixel (x,y) -> fb[x+y*480]
        for (i=0; i<10; i++) {
            for (j=0; j<10; j++) {
                fb[j+(i+k)*480]=~0u;
            }
        }

        parlcd_write_cmd(parlcd_mem_base, 0x2c);
        for (ptr = 0; ptr < 480*320; ptr++) {
            parlcd_write_data(parlcd_mem_base, fb[ptr]);
        }

        // sleep_ms(1);
    }

    // parlcd_write_cmd(parlcd_mem_base, 0x2c);
    // for (k = 0; k < 20; k++) {
    // for (i = 0; i < 320 ; i++) {
    // for (j = 0; j < 480 ; j++) {
    // c = 0x1f<<5;
    // c = (((i+k) & 0x1f) << 11) | ((j+k) & 0x1f);
    // parlcd_write_data(parlcd_mem_base, c);
    // }
    // }
    // sleep_ms(100);
    // }

    printf("Goodbye world\n");

    return 0;
}