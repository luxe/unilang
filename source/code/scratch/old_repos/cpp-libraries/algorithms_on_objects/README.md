###Algorithm++
A C++ header file that wraps around STL `<algorithm>` to provide additional functionality.  

####Motivation:
The majority of the time I use an algorithm, I apply that algorithm across the entire container.  However, I always have to type in the iterator range, as two seperate parameters.  This can be dangerous if two iterators from different objects are accidently passed in, and iterator ranges result in more typing and less readability.  If we want to apply an algorithm to an entire container, it is, in my opinion, verbose to specify both its begin and end state.  Although iterators are a great abstraction away from containers, there is no need to always operate on containers through iterators.  If I want to sort a vector, I want to sort the vector; not verbosly sort the vector from beginning to end.  The is where `Algorithm++` comes in.

####What It Adds:
Every function that requires an interator range from the STL, can now accept the actual container as a parameter instead of the container's range.  When a container is used as a parameter, it is asummed that algorithm is to take place on the entire container's range.  All of the other functions that take iterators are still available when needed, but you no longer have to specify a full range; just pass in the container.

####Example of container replacement over full iterator range:
Instead of typing:
```
std::sort(c.begin(),c.end());
```

You can now type:
```
sort(c);
```

These functions will one day be a part of the [Jstd Library](https://github.com/Jstd).

#Update:
I think eric neibler's range library has a better version-- I should just use that.  
Although this might be cake to implement now with variadic templates, so consider that.
