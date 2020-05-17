template <typename Datum>
class Base{
	
protected:
	Datum datum;
};

template <typename Datum>
class D: public Base<Datum>{
public:
	
	int Get_Datum(){
		return this->datum;
	}
	
};


int main(){}