#include "code/utilities/data_structures/fpsclock/fps_clock.hpp"

FpsClock::FpsClock( int skipTime_ ) {
    presentTime = clock.getElapsedTime();
    skipTime = sf::milliseconds( int(1000/skipTime_) );
    prevTime = sf::milliseconds( presentTime.asMilliseconds() );
}

bool FpsClock::tick() {
    presentTime = clock.getElapsedTime();
    if( presentTime >= prevTime + skipTime ) {
        prevTime = presentTime;
        return true;
    } else
        return false;
}

double FpsClock::interpolation() {
    presentTime = clock.getElapsedTime();
    double interpolation = double( ( presentTime - prevTime ) / skipTime );
    return interpolation;
}
