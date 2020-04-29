#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "wave.h"

#define WAIT 100000000

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "%s: file name not given\n", argv[0]);
        exit(1);
    }

    MONO_PCM pcm;
    FILE *GPLT;
    int n;

    mono_wave_read(&pcm, argv[1]);
    // gnuplot用のパイプ接続されたストリームを開く
    GPLT = popen("gnuplot", "w");
    // 1行ずつデータを読み込むために '-' をつかう
    // w l => with line
    fprintf(GPLT, "plot '-' w l\n ");
    // すべて表示すると見づらいので表示範囲を狭める
    for (n = 0; n < pcm.length / 10; n++)
    {
        fprintf(GPLT, "%d %f\n", n, pcm.s[n]);
    }
    // 'e'で始まる行に出会うとデータ読み込みが終了
    fprintf(GPLT, "e\n");
    // ストリームに溜まっているデータをwrite
    fflush(GPLT);
    // 即時に終了するのを阻止
    usleep(WAIT);
    pclose(GPLT);
}