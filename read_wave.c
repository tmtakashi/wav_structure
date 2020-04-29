#include <stdio.h>
#include "wave.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "%s: file name not given\n", argv[0]);
        exit(1);
    }
    MONO_PCM pcm;
    mono_wave_read(&pcm, argv[1]);
    printf("Sampling frequency: %d\n", pcm.fs);
    printf("Quantization bit rate: %d\n", pcm.bits);
    printf("Signal length: %d\n", pcm.length);
}