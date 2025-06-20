#ifndef SYSCALLS_H
#define SYSCALLS_H
#include <stdint.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define SYSCALL_READ 0
#define SYSCALL_WRITE 1
#define SYSCALL_ISKEYPRESSED 2
#define SYSCALL_GET_BOOTTIME 3
#define SYSCALL_GET_TIME 4
#define SYSCALL_GET_DATE 5
#define SYSCALL_GET_REGISTERS 6

#define SYSCALL_GET_VIDEO_DATA 9
#define SYSCALL_PUT_PIXEL 10
#define SYSCALL_SET_FRAMEBUFFER 11
#define SYSCALL_SET_FRAMEBUFFER_REGION 12

#define SYSCALL_PLAY_SOUND 20
#define SYSCALL_STOP_SOUND 21


int sys_read(int fd, char* buffer, uint64_t count);

int sys_write(int fd, const char* buffer, uint64_t count);

int sys_isKeyPressed(uint16_t makecode);

uint64_t sys_getBootTime();

void sys_getTime(uint8_t* hours, uint8_t* minutes, uint8_t* seconds);

void sys_getDate(uint8_t* year, uint8_t* month, uint8_t* day);

void saveRegisters(uint64_t * regs);

void sys_getRegisters(uint64_t * regs);

void sys_get_video_data(uint16_t* width, uint16_t* height, uint16_t* bpp, uint16_t* pitch);

void sys_put_pixel(uint32_t hexColor, uint64_t x, uint64_t y);

void sys_set_framebuffer(uint8_t * fb);

void sys_set_framebuffer_region(uint32_t topLeftX, uint32_t topLeftY, uint32_t width, uint32_t height, uint8_t* bmp, uint32_t maskColor);

void sys_playSound(uint16_t freq);
void sys_stopSound();


#endif
