#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wave.h"

int main()
{
    MONO_PCM pcm1;
    int n;
    double A, f0;

    pcm1.fs = 8000;
    pcm1.bits = 16;
    pcm1.length = 8000;
    pcm1.s = calloc(pcm1.length, sizeof(double));

    A = 0.25;
    f0 = 250.0;

    for (n = 0; n < pcm1.length; n++)
    {
        pcm1.s[n] = A * sin(2.0 * M_PI * f0 * n / pcm1.fs);
    }
    mono_wave_write(&pcm1, "sine.wav");
    free(pcm1.s);

    return 0;
}