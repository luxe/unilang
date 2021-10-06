#include <vector>
#include <iostream>
#include <initializer_list>


template <typename... Ts>
class Vector
{
        //wrapped vector
        private: std::vector<Ts...> v;
        
        //constructor
        public: template<typename... Params>
        Vector(Params&&... params)
        : v(std::vector<Ts...>(std::forward<Params>(params)...)){}
        
        //initalizer list constructor
        //not perfect.  misses allocator
        public: template<typename T, typename... Params>
        Vector(std::initializer_list<T> init)
        : v(std::vector<Ts...>(init)){}
        
        //assigning with a std::vector is needed though
        auto operator= (std::vector<Ts...> const& m)->decltype(auto)
        {v=m; return *this;}
        
        //other
        public: template<typename...Params>
        auto assign(Params&&...params)->decltype(auto)
        {return v.assign(std::forward<Params>(params)...);};
        
        public: template<typename...Params>
        auto get_allocator(Params&&...params)->decltype(auto)
        {return v.get_allocator(std::forward<Params>(params)...);};
        
        //Element access
        public: template<typename...Params>
        auto at(Params&&...params)->decltype(auto)
        {return v.at(std::forward<Params>(params)...);};
        
        public: auto operator[]( size_t pos )->decltype(auto)
        { return v[pos]; }
        
        public: template<typename...Params>
        auto front(Params&&... params)->decltype(auto)
        {return v.front(std::forward<Params>(params)...);};
        
        public: template<typename...Params>
        auto back(Params&&... params)->decltype(auto)
        {return v.back(std::forward<Params>(params)...);};
        
        public: template<typename...Params>
        auto data(Params&&...params)->decltype(auto)
        {return v.data(std::forward<Params>(params)...);};
        
        //Iterators
        public: template<typename...Params>
        auto begin(Params&&...params)->decltype(auto)
        {return v.begin(std::forward<Params>(params)...);};
        
        public: template<typename...Params>
        auto cbegin(Params&&...params)->decltype(auto)
        {return v.cbegin(std::forward<Params>(params)...);};
        
        public: template<typename...Params>
        auto rbegin(Params&&...params)->decltype(auto)
        {return v.rbegin(std::forward<Params>(params)...);};
        
        public: template<typename...Params>
        auto crbegin(Params&&...params)->decltype(auto)
        {return v.crbegin(std::forward<Params>(params)...);};
        
        public: template<typename...Params>
        auto end(Params&&...params)->decltype(auto)
        {return v.end(std::forward<Params>(params)...);};
        
        public: template<typename...Params>
        auto cend(Params&&...params)->decltype(auto)
        {return v.cend(std::forward<Params>(params)...);};
        
        public: template<typename...Params>
        auto rend(Params&&...params)->decltype(auto)
        {return v.rbegin(std::forward<Params>(params)...);};
        
        public: template<typename...Params>
        auto crend(Params&&...params)->decltype(auto)
        {return v.crbegin(std::forward<Params>(params)...);};
        
        //Capacity
        public: template<typename... Params>
        auto empty(Params&&... params)->decltype(auto)
        {return v.empty(std::forward<Params>(params)...);};
        
        public: template<typename... Params>
        auto size(Params&&... params)->decltype(auto)
        {return v.size(std::forward<Params>(params)...);};
        
        public: template<typename... Params>
        auto max_size(Params&&... params)->decltype(auto)
        {return v.max_size(std::forward<Params>(params)...);};
        
        public: template<typename... Params>
        auto reserve(Params&&... params)->decltype(auto)
        {return v.reserve(std::forward<Params>(params)...);};

        public: template<typename... Params>
        auto capacity(Params&&... params)->decltype(auto)
        {return v.capacity(std::forward<Params>(params)...);};
        
        public: template<typename... Params>
        auto shrink_to_fit(Params&&... params)->decltype(auto)
        {return v.shrink_to_fit(std::forward<Params>(params)...);};
        
        //Modifiers
        public: template<typename... Params>
        auto clear(Params&&... params)->decltype(auto)
        {return v.clear(std::forward<Params>(params)...);};
        
        public: template<typename... Params>
        auto insert(Params&&... params)->decltype(auto)
        {return v.insert(std::forward<Params>(params)...);};
        
        public: template<typename... Params>
        auto emplace(Params&&... params)->decltype(auto)
        {return v.emplace(std::forward<Params>(params)...);};
        
        public: template<typename... Params>
        auto erase(Params&&... params)->decltype(auto)
        {return v.erase(std::forward<Params>(params)...);};
        
        public: template<typename... Params>
        auto push_back(Params&&... params)->decltype(auto)
        {return v.push_back(std::forward<Params>(params)...);};
        
        public: template<typename... Params>
        auto emplace_back(Params&&... params)->decltype(auto)
        {return v.emplace_back(std::forward<Params>(params)...);};
        
        public: template<typename... Params>
        auto pop_back(Params&&... params)->decltype(auto)
        {return v.pop_back(std::forward<Params>(params)...);};
        
        public: template<typename... Params>
        auto resize(Params&&... params)->decltype(auto)
        {return v.resize(std::forward<Params>(params)...);};
        
        public: template<typename... Params>
        auto swap(Params&&... params)->decltype(auto)
        {return v.swap(std::forward<Params>(params)...);};      
        
        //hmmm
        public: operator std::vector<Ts...>() const { return std::vector<Ts...>(); }
        
        void test(){
        }

};


int main(){
Vector<int> a{1,2,3,4,5};


//std::vector<int> e = static_cast<std::vector<int>>(v);


}
