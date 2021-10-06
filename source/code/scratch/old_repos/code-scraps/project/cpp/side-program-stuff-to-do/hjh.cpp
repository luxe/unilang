//Name: Trevor Hickey
//Email: TrevorJamesHickey@gmail.com
//Brief: Interview problem from SeeGrid
//For: Brennan Sellner (Director of Software Development)

//I'm going to sprinkle discussion comments through my implementation;
//that way you can follow my train of thought.
//Obviously I wouldn't leave comments like this in production code,
//but I think it'll be helpful for the interview process.
//Apologizes up front if it just turns into rambling.

//Also, I'm using modern language features where appropriate.
//It was just quicker and looked more concise.
//If your compiler is out-of-date, consider compiling this code on:
//ideone.com with the C++14 option.

#include <iostream>
#include <vector>
#include <functional>

//Let's start with some type aliases to better fit our problem domain.
//see: "Prefer Domain-Specific Types to Primitive Types"
//(this is c++11 syntax for templated typedefs.)
//*It's just a nicer syntax for aliasing generic types.
namespace abstract_types{
    template<typename T> using Row = std::vector<T>;
    template<typename T> using Matrix = std::vector<std::vector<T>>;
}

//now we'll utilize our template types.
//that way we're not repeating ourselves in the implementation.
//It'll just make the solution look cleaner in general.
namespace board_types{
    using namespace abstract_types;

    //Some objects to make the implementation easier:
    struct Element{
        int item;
    };

    using Board_Row = Row<int>;
    using Board_Row_Refs = Row<std::reference_wrapper<int>>;
    using Board     = Matrix<int>;
}

namespace board_utilities{
    
    using namespace board_types;
    
    Board& Add_Row(Board & board, Board_Row const& board_row){
        board.push_back(board_row);
        return board;
    }
    
    //get rows from element focal point
    Board_Row_Refs Get_North_Elements(Board & board, int x, int y){
        Board_Row_Refs refs;
        
        while (y >= 0){
            refs.push_back(board[y][x]);
            --y;
        }
        
        return refs;
    }
    
    Board_Row_Refs Get_West_Elements(Board & board, int x, int y){
        Board_Row_Refs refs;
        
        while (x >= 0){
            refs.push_back(board[y][x]);
            --x;
        }
        
        return refs;
    }
    
    Board_Row_Refs Get_South_Elements(Board & board, int x, int y){
        Board_Row_Refs refs;
        while (y < board.size()){
            refs.push_back(board[y][x]);
            ++y;
        }
        
        return refs;
    }
    Board_Row_Refs Get_East_Elements(Board & board, int x, int y){
        Board_Row_Refs refs;
        while (x < board[0].size()){
            refs.push_back(board[y][x]);
            ++x;
        }
        
        return refs;
    }
    
    
    template <typename T>
    std::string As_String(T const& row){
        std::string str;
        for (auto x: row){
            str+= "[" + std::to_string(x) + "]";
        }
        return str;
    }
    
    std::string As_String(Board const& board){
        std::string str;
        for (auto y: board){
            str+= As_String(y) + '\n';
        }
        
        return str;
    }
};

//a few functions for reading and writing to the console.
namespace stream_utilities{
}



using namespace board_utilities;
using namespace board_types;


int main(){
    
    //
    
    
    //create a board
    Board b {{10,11,12,13,14,15}
            ,{16,17,18,19,20,21}
            ,{22,23,24,25,26,27}
            ,{28,29,30,31,32,33}};
    
    auto row = Get_West_Elements(b,4,1);
    std::cout << As_String(row) << std::endl;
    
    //for (auto& it: row){
    //    it.get() = 5;
    //}
    
    //std::cout << As_String(b);
    
    
    
    
    
    
    //Board_Row row;
    
    //Add_Row(b,row);
    
    
    //Q: No "return 0"?
    //A: Just like void functions,
    //there is no requirement to actually provide a return statement.
    //Many prefer to leave it out.
}




// > The competent programmer is fully aware of the strictly limited size of his own skull;
// > therefore he approaches the programming task in full humility, 
// > and among other things he avoids clever tricks like the plague. --Dijkstra



//Discussion points:
//Speed:
//Size:
//Clarity:
//Testability:

//End with a joke?
//Q: What’s the best naming prefix for a global variable in Python?
//A: #