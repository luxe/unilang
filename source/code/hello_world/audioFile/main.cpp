#include "AudioFile.h"
#include "code/utilities/types/vectors/operators/lib.hpp"
#include "code/utilities/peripheral/sound/wav/wav_file_join_settings.hpp"
#include "code/utilities/peripheral/sound/wav/wav_file_joiner.hpp"

int main(){
    
    
    Wav_File_Join_Settings settings;
    settings.output_path = "/home/laptop/Desktop/out.wav";
    settings.input_paths.emplace_back("/home/laptop/Desktop/animalese-generator/sounds/high/sound01.wav");
    settings.input_paths.emplace_back("/home/laptop/Desktop/animalese-generator/sounds/high/sound01.wav");
    settings.input_paths.emplace_back("/home/laptop/Desktop/animalese-generator/sounds/high/sound02.wav");
    settings.input_paths.emplace_back("/home/laptop/Desktop/animalese-generator/sounds/high/sound02.wav");
    settings.input_paths.emplace_back("/home/laptop/Desktop/animalese-generator/sounds/high/sound01.wav");
    
    Wav_File_Joiner::Join(settings);
    
}