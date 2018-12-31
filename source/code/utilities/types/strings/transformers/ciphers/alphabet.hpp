#pragma once
#include <string>
#include <cstdlib>

// An alphabet is a collection of characters.
// Here, a generic alphabet class will provide an interface over any container that holds letters. (probably a string type).
// You don't actually create an alphabet though, because you're not going to change it. So it provides a bit of a safety guarantee.
// In summary, the alphabet namespace is simply a lot of static templated object oriented classes built around a constant string type;
namespace alphabet{

	// base class for an alphabet
	template <class Alphabet_Type>
	class Alphabet {

		//non-constructible static class
		Alphabet()=delete;

		//negative 1 means the char is not valid in the alphabet
		public: static int Char_To_Index(char const& c) {
			return Alphabet_Type::Char_To_Index(c);
		}

		//if the index is valid, the appropriate letter is returned
		//else an exception is thrown
		public: static char At(int const& index) {
			return Alphabet_Type::At(index);
		}

		public: static int Size() {
			return Alphabet_Type::Size();
		}

	public: static bool Exists(char const& c) {
		return Alphabet_Type::Exists(c);
	}

	};

	//derived class for an English alphabet
	class English_Alphabet: Alphabet<English_Alphabet>{

		//non-constructible static class
		English_Alphabet()=delete;

		//utility for getting index based on letter
		public: static int Char_To_Index(char const& c) {
			auto index = static_cast<int>(c) - 97;
			return (index < 0  || index > alphabet.size())  ? -1 : index;
		}

		//get letter from the alphabet
		public: static char At(int const& index) {
			return alphabet.at(index);
		}

		//return the alphabet's character count
		public: static int Size() {return alphabet.size();}

		public: static bool Exists(char const& c) {
			for (auto const& it: alphabet) {
				if (it ==  c) {
					return true;
				}
			}
			return false;
		}


	private:

		//data members
		//the English alphabet
		static const std::string alphabet;
	};

	const std::string English_Alphabet::alphabet = "abcdefghijklmnopqrstuvwxyz";
}