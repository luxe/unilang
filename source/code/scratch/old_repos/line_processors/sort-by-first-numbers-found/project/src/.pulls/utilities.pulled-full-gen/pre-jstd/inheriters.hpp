//yeah, there's things like boost::noncopyable
//but I needed one to prevent any construction at all
//it's really simple too, I just wanted a place to put it.
//Any access specifier for inherting will work fine
class Non_Constructible { Non_Constructible();};
