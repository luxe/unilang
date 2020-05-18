bool& Flip(bool & b);
bool& Make_False(bool & b);
bool& Make_True(bool & b);
bool& Yes(bool & b);
bool& On(bool & b);
bool& No(bool & b);
bool& Off(bool & b);


//*consider using fold expressions now

//returning true amount
template<typename T>
int Amount_True(T v) {
    if (v) return 1;
    return 0;
}
template<typename T, typename... Args>
int Amount_True(T first, Args... args) {
    if (first) return 1 + Amount_True(args...);
    return 0 + Amount_True(args...);
}

//returning false amount
template<typename T>
int Amount_False(T v) {
    if (!v) return 1;
    return 0;
}
template<typename T, typename... Args>
int Amount_False(T first, Args... args) {
    if (!first) return 1 + Amount_False(args...);
    return 0 + Amount_False(args...);
}

//comparing true and false amount
template<typename T, typename... Args>
bool More_Trues_Than_Falses (T first, Args... args) {
    return Amount_True(first,args...) > Amount_False(first,args...);
}
template<typename T, typename... Args>
bool Less_Trues_Than_Falses (T first, Args... args) {
    return Amount_True(first,args...) < Amount_False(first,args...);
}
template<typename T, typename... Args>
bool More_Falses_Than_Trues (T first, Args... args) {
    return Amount_False(first,args...) > Amount_True(first,args...);
}
template<typename T, typename... Args>
bool Less_Falses_Than_Trues (T first, Args... args) {
    return Amount_False(first,args...) < Amount_True(first,args...);
}
template<typename T, typename... Args>
bool Same_Amount_Of_Trues_And_Falses (T first, Args... args) {
    return Amount_False(first,args...) == Amount_True(first,args...);
}
