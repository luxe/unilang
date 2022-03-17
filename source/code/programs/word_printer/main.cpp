#include "code/utilities/linguistics/dictionary/three_letter_words.hpp"
#include "code/utilities/linguistics/dictionary/wordle.hpp"
#include "code/utilities/types/strings/transformers/casing/lib.hpp"
#include "code/utilities/types/vectors/operators/lib.hpp"


bool valid(std::string word, std::vector<std::string> const middle_words){
    
    for (auto possible: middle_words){
        
        Lowercase(word);
        Lowercase(possible);
        
        if (word[1] == possible[0] && word[2] == possible[1] && word[3] == possible[2]){
            return true;
        }
    }
    
    return false;
}

int main(){
    
    
    // valid answers
    auto answer_words = Wordle::Get_Answers();
    auto answer_middle_words = Three_Letter_Words::Get_Answers();
    
    
    // synthesize answers
    std::vector<std::string> final_valids;
    for (auto word: answer_words){
        
        if (valid(word,answer_middle_words)){
            final_valids.emplace_back(word);
        }
    }


    // print data
    // std::cout << "export const WORDS = [" << std::endl;
    // for (auto word: final_valids){
    //     Lowercase(word);
    //     std::cout << "'" << word << "'," << std::endl;
    // }
    // std::cout << "]\n\n";
    
    
    
    // std::cout << "export const MIDDLE_WORDS = [" << std::endl;
    // for (auto word: answer_middle_words){
    //     Lowercase(word);
    //     std::cout << "'" << word << "'," << std::endl;
    // }
    // std::cout << "]\n\n";
    
    
    
    
    
    auto guess_words = Wordle::Get_Allowed_Guesses();
    guess_words += Wordle::Get_Answers();
    auto guess_middle_words = Three_Letter_Words::Get_Allowed_Guesses();
    
    
    std::cout << "export const VALID_GUESSES = [" << std::endl;
    for (auto word: guess_words){
        Lowercase(word);
        std::cout << "'" << word << "'," << std::endl;
    }
    std::cout << "]\n\n";
    
    std::cout << "export const VALID_MIDDLE_GUESSES = [" << std::endl;
    for (auto word: guess_middle_words){
        Lowercase(word);
        std::cout << "'" << word << "'," << std::endl;
    }
    std::cout << "]\n\n";
    
    



}