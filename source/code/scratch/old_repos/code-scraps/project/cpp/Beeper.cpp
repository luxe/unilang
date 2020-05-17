#include "SDL/SDL.h"
#include <algorithm>
#include <cmath>
#include <queue>


const int AMPLITUDE = 8000; //higer amplitude = louder volume
const int FREQUENCY = 4100; //number of bytes per second

struct BeepObject
{
    double freq;
    int samplesLeft;
};

class Beeper
{
private:
    double v;
    std::queue<BeepObject> beeps;
public:
    Beeper();
    ~Beeper();
    void beep(double freq, int duration);
    void generateSamples(Sint16 *stream, int length);
    void wait();
};

void audio_callback(void *_beeper, Uint8 *_stream, int _length)
{
    Sint16 *stream = (Sint16*) _stream;
    int length = _length / 2;
    Beeper* beeper = (Beeper*) _beeper;
    
    beeper->generateSamples(stream, length);
}

Beeper::Beeper()
{
    SDL_AudioSpec desiredSpec;
    
    desiredSpec.freq = FREQUENCY;
    desiredSpec.format = AUDIO_S16SYS;
    desiredSpec.channels = 1;
    desiredSpec.samples = 2048;
    desiredSpec.callback = audio_callback;
    desiredSpec.userdata = this;
    
    SDL_AudioSpec obtainedSpec;
    
    // you might want to look for errors here
    SDL_OpenAudio(&desiredSpec, &obtainedSpec);

    // start play audio
    SDL_PauseAudio(0);
}

Beeper::~Beeper()
{
    SDL_CloseAudio();
}

void Beeper::beep(double freq, int duration)
{
    BeepObject bo;
    bo.freq = freq;
    bo.samplesLeft = duration * FREQUENCY / 1000;
    
    SDL_LockAudio();
    beeps.push(bo);
    SDL_UnlockAudio();
}

void Beeper::generateSamples(Sint16 *stream, int length)
{
    int i = 0;
    while (i < length) {
        
        // If no beep, zero fill the rest
        if (beeps.empty()) {
            while (i < length) {
                stream[i] = 0;
                i++;
            }
            return;
        }
        
        BeepObject& bo = beeps.front();
        
        int samplesToDo = std::min(i + bo.samplesLeft, length);
        bo.samplesLeft -= samplesToDo - i;
        
        while (i < samplesToDo) {
            stream[i] = AMPLITUDE * std::sin(v * 2 * M_PI / FREQUENCY);
            i++;
            v += bo.freq;
        }

        if (bo.samplesLeft == 0) {
            beeps.pop();
        }
    }
}

void Beeper::wait()
{
    int size;
    do {
        SDL_Delay(20);
        SDL_LockAudio();
        size = beeps.size();
        SDL_UnlockAudio();
    } while (size > 0);
    
}

int main(int argc, char *argv[])
{
    // init SDL Audio
    SDL_Init(SDL_INIT_AUDIO); 
    
    // Here we use the same duration for all beeps
    int duration = 500;
    
    double D = 293.665;
    double E = 329.628;
    double F = 349.228;
    double G = 391.995;
    double A = 440.000;
    double B = 493.883;
    double c = 554.365;
    double d = 587.330;
    
    Beeper b;
    
    b.beep(G, duration);

    // wait for music to end
    b.wait();
}
