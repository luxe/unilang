#include "code/utilities/time/calendar/days_of_week/lib.hpp"
#include "code/utilities/time/calendar/tm_wrappers/lib.hpp"

bool Its_Monday(){ return Current_Day_Of_Week() == 1;}
bool Its_Tuesday(){ return Current_Day_Of_Week() == 2;}
bool Its_Wednesday(){ return Current_Day_Of_Week() == 3;}
bool Its_Thursday(){ return Current_Day_Of_Week() == 4;}
bool Its_Friday(){ return Current_Day_Of_Week() == 5;}
bool Its_Saturday(){ return Current_Day_Of_Week() == 6;}
bool Its_Sunday(){ return Current_Day_Of_Week() == 7;}

bool Its_Not_Monday(){ return Current_Day_Of_Week() != 1;}
bool Its_Not_Tuesday(){ return Current_Day_Of_Week() != 2;}
bool Its_Not_Wednesday(){ return Current_Day_Of_Week() != 3;}
bool Its_Not_Thursday(){ return Current_Day_Of_Week() != 4;}
bool Its_Not_Friday(){ return Current_Day_Of_Week() != 5;}
bool Its_Not_Saturday(){ return Current_Day_Of_Week() != 6;}
bool Its_Not_Sunday(){ return Current_Day_Of_Week() != 7;}

bool Its_Monday_Or_Later(){ return Current_Day_Of_Week() >= 1;}
bool Its_Tuesday_Or_Later(){ return Current_Day_Of_Week() >= 2;}
bool Its_Wednesday_Or_Later(){ return Current_Day_Of_Week() >= 3;}
bool Its_Thursday_Or_Later(){ return Current_Day_Of_Week() >= 4;}
bool Its_Friday_Or_Later(){ return Current_Day_Of_Week() >= 5;}
bool Its_Saturday_Or_Later(){ return Current_Day_Of_Week() >= 6;}
bool Its_Sunday_Or_Later(){ return Current_Day_Of_Week() >= 7;}

bool Its_Monday_Or_Earlier(){ return Current_Day_Of_Week() <= 1;}
bool Its_Tuesday_Or_Earlier(){ return Current_Day_Of_Week() <= 2;}
bool Its_Wednesday_Or_Earlier(){ return Current_Day_Of_Week() <= 3;}
bool Its_Thursday_Or_Earlier(){ return Current_Day_Of_Week() <= 4;}
bool Its_Friday_Or_Earlier(){ return Current_Day_Of_Week() <= 5;}
bool Its_Saturday_Or_Earlier(){ return Current_Day_Of_Week() <= 6;}
bool Its_Sunday_Or_Earlier(){ return Current_Day_Of_Week() <= 7;}

bool Its_Before_Monday(){ return Current_Day_Of_Week() < 1;}
bool Its_Before_Tuesday(){ return Current_Day_Of_Week() < 2;}
bool Its_Before_Wednesday(){ return Current_Day_Of_Week() < 3;}
bool Its_Before_Thursday(){ return Current_Day_Of_Week() < 4;}
bool Its_Before_Friday(){ return Current_Day_Of_Week() < 5;}
bool Its_Before_Saturday(){ return Current_Day_Of_Week() < 6;}
bool Its_Before_Sunday(){ return Current_Day_Of_Week() < 7;}

bool Its_After_Monday(){ return Current_Day_Of_Week() > 1;}
bool Its_After_Tuesday(){ return Current_Day_Of_Week() > 2;}
bool Its_After_Wednesday(){ return Current_Day_Of_Week() > 3;}
bool Its_After_Thursday(){ return Current_Day_Of_Week() > 4;}
bool Its_After_Friday(){ return Current_Day_Of_Week() > 5;}
bool Its_After_Saturday(){ return Current_Day_Of_Week() > 6;}
bool Its_After_Sunday(){ return Current_Day_Of_Week() > 7;}

//monday
bool Its_Between_Monday_And_Monday_Inclusive(){ return Its_Monday_Or_Later() || Its_Monday_Or_Earlier(); }
bool Its_Between_Monday_And_Tuesday_Inclusive(){ return Its_Monday_Or_Later() && Its_Tuesday_Or_Earlier(); }
bool Its_Between_Monday_And_Wednesday_Inclusive(){ return Its_Monday_Or_Later() && Its_Wednesday_Or_Earlier(); }
bool Its_Between_Monday_And_Thursday_Inclusive(){ return Its_Monday_Or_Later() && Its_Thursday_Or_Earlier(); }
bool Its_Between_Monday_And_Friday_Inclusive(){ return Its_Monday_Or_Later() && Its_Friday_Or_Earlier(); }
bool Its_Between_Monday_And_Saturday_Inclusive(){ return Its_Monday_Or_Later() && Its_Saturday_Or_Earlier(); }
bool Its_Between_Monday_And_Sunday_Inclusive(){ return Its_Monday_Or_Later() && Its_Sunday_Or_Earlier(); }

bool Its_Between_Monday_And_Monday_Exclusive(){ return Its_After_Monday() || Its_Before_Monday(); }
bool Its_Between_Monday_And_Tuesday_Exclusive(){ return Its_After_Monday() && Its_Before_Tuesday(); }
bool Its_Between_Monday_And_Wednesday_Exclusive(){ return Its_After_Monday() && Its_Before_Wednesday(); }
bool Its_Between_Monday_And_Thursday_Exclusive(){ return Its_After_Monday() && Its_Before_Thursday(); }
bool Its_Between_Monday_And_Friday_Exclusive(){ return Its_After_Monday() && Its_Before_Friday(); }
bool Its_Between_Monday_And_Saturday_Exclusive(){ return Its_After_Monday() && Its_Before_Saturday(); }
bool Its_Between_Monday_And_Sunday_Exclusive(){ return Its_After_Monday() && Its_Before_Sunday(); }

//tuesday
bool Its_Between_Tuesday_And_Monday_Inclusive(){ return Its_Tuesday_Or_Later() || Its_Monday_Or_Earlier(); }
bool Its_Between_Tuesday_And_Tuesday_Inclusive(){ return Its_Tuesday_Or_Later() || Its_Tuesday_Or_Earlier(); }
bool Its_Between_Tuesday_And_Wednesday_Inclusive(){ return Its_Tuesday_Or_Later() && Its_Wednesday_Or_Earlier(); }
bool Its_Between_Tuesday_And_Thursday_Inclusive(){ return Its_Tuesday_Or_Later() && Its_Thursday_Or_Earlier(); }
bool Its_Between_Tuesday_And_Friday_Inclusive(){ return Its_Tuesday_Or_Later() && Its_Friday_Or_Earlier(); }
bool Its_Between_Tuesday_And_Saturday_Inclusive(){ return Its_Tuesday_Or_Later() && Its_Saturday_Or_Earlier(); }
bool Its_Between_Tuesday_And_Sunday_Inclusive(){ return Its_Tuesday_Or_Later() && Its_Sunday_Or_Earlier(); }

bool Its_Between_Tuesday_And_Monday_Exclusive(){ return Its_After_Tuesday() || Its_Before_Monday(); }
bool Its_Between_Tuesday_And_Tuesday_Exclusive(){ return Its_After_Tuesday() || Its_Before_Tuesday(); }
bool Its_Between_Tuesday_And_Wednesday_Exclusive(){ return Its_After_Tuesday() && Its_Before_Wednesday(); }
bool Its_Between_Tuesday_And_Thursday_Exclusive(){ return Its_After_Tuesday() && Its_Before_Thursday(); }
bool Its_Between_Tuesday_And_Friday_Exclusive(){ return Its_After_Tuesday() && Its_Before_Friday(); }
bool Its_Between_Tuesday_And_Saturday_Exclusive(){ return Its_After_Tuesday() && Its_Before_Saturday(); }
bool Its_Between_Tuesday_And_Sunday_Exclusive(){ return Its_After_Tuesday() && Its_Before_Sunday(); }

//wednesday
bool Its_Between_Wednesday_And_Monday_Inclusive(){ return Its_Wednesday_Or_Later() || Its_Monday_Or_Earlier(); }
bool Its_Between_Wednesday_And_Tuesday_Inclusive(){ return Its_Wednesday_Or_Later() || Its_Tuesday_Or_Earlier(); }
bool Its_Between_Wednesday_And_Wednesday_Inclusive(){ return Its_Wednesday_Or_Later() || Its_Wednesday_Or_Earlier(); }
bool Its_Between_Wednesday_And_Thursday_Inclusive(){ return Its_Wednesday_Or_Later() && Its_Thursday_Or_Earlier(); }
bool Its_Between_Wednesday_And_Friday_Inclusive(){ return Its_Wednesday_Or_Later() && Its_Friday_Or_Earlier(); }
bool Its_Between_Wednesday_And_Saturday_Inclusive(){ return Its_Wednesday_Or_Later() && Its_Saturday_Or_Earlier(); }
bool Its_Between_Wednesday_And_Sunday_Inclusive(){ return Its_Wednesday_Or_Later() && Its_Sunday_Or_Earlier(); }

bool Its_Between_Wednesday_And_Monday_Exclusive(){ return Its_After_Wednesday() || Its_Before_Monday(); }
bool Its_Between_Wednesday_And_Tuesday_Exclusive(){ return Its_After_Wednesday() || Its_Before_Tuesday(); }
bool Its_Between_Wednesday_And_Wednesday_Exclusive(){ return Its_After_Wednesday() || Its_Before_Wednesday(); }
bool Its_Between_Wednesday_And_Thursday_Exclusive(){ return Its_After_Wednesday() && Its_Before_Thursday(); }
bool Its_Between_Wednesday_And_Friday_Exclusive(){ return Its_After_Wednesday() && Its_Before_Friday(); }
bool Its_Between_Wednesday_And_Saturday_Exclusive(){ return Its_After_Wednesday() && Its_Before_Saturday(); }
bool Its_Between_Wednesday_And_Sunday_Exclusive(){ return Its_After_Wednesday() && Its_Before_Sunday(); }

//thursday
bool Its_Between_Thursday_And_Monday_Inclusive(){ return Its_Thursday_Or_Later() || Its_Monday_Or_Earlier(); }
bool Its_Between_Thursday_And_Tuesday_Inclusive(){ return Its_Thursday_Or_Later() || Its_Tuesday_Or_Earlier(); }
bool Its_Between_Thursday_And_Wednesday_Inclusive(){ return Its_Thursday_Or_Later() || Its_Wednesday_Or_Earlier(); }
bool Its_Between_Thursday_And_Thursday_Inclusive(){ return Its_Thursday_Or_Later() || Its_Thursday_Or_Earlier(); }
bool Its_Between_Thursday_And_Friday_Inclusive(){ return Its_Thursday_Or_Later() && Its_Friday_Or_Earlier(); }
bool Its_Between_Thursday_And_Saturday_Inclusive(){ return Its_Thursday_Or_Later() && Its_Saturday_Or_Earlier(); }
bool Its_Between_Thursday_And_Sunday_Inclusive(){ return Its_Thursday_Or_Later() && Its_Sunday_Or_Earlier(); }

bool Its_Between_Thursday_And_Monday_Exclusive(){ return Its_After_Thursday() || Its_Before_Monday(); }
bool Its_Between_Thursday_And_Tuesday_Exclusive(){ return Its_After_Thursday() || Its_Before_Tuesday(); }
bool Its_Between_Thursday_And_Wednesday_Exclusive(){ return Its_After_Thursday() || Its_Before_Wednesday(); }
bool Its_Between_Thursday_And_Thursday_Exclusive(){ return Its_After_Thursday() || Its_Before_Thursday(); }
bool Its_Between_Thursday_And_Friday_Exclusive(){ return Its_After_Thursday() && Its_Before_Friday(); }
bool Its_Between_Thursday_And_Saturday_Exclusive(){ return Its_After_Thursday() && Its_Before_Saturday(); }
bool Its_Between_Thursday_And_Sunday_Exclusive(){ return Its_After_Thursday() && Its_Before_Sunday(); }

//friday
bool Its_Between_Friday_And_Monday_Inclusive(){ return Its_Friday_Or_Later() || Its_Monday_Or_Earlier(); }
bool Its_Between_Friday_And_Tuesday_Inclusive(){ return Its_Friday_Or_Later() || Its_Tuesday_Or_Earlier(); }
bool Its_Between_Friday_And_Wednesday_Inclusive(){ return Its_Friday_Or_Later() || Its_Wednesday_Or_Earlier(); }
bool Its_Between_Friday_And_Thursday_Inclusive(){ return Its_Friday_Or_Later() || Its_Thursday_Or_Earlier(); }
bool Its_Between_Friday_And_Friday_Inclusive(){ return Its_Friday_Or_Later() || Its_Friday_Or_Earlier(); }
bool Its_Between_Friday_And_Saturday_Inclusive(){ return Its_Friday_Or_Later() && Its_Saturday_Or_Earlier(); }
bool Its_Between_Friday_And_Sunday_Inclusive(){ return Its_Friday_Or_Later() && Its_Sunday_Or_Earlier(); }

bool Its_Between_Friday_And_Monday_Exclusive(){ return Its_After_Friday() || Its_Before_Monday(); }
bool Its_Between_Friday_And_Tuesday_Exclusive(){ return Its_After_Friday() || Its_Before_Tuesday(); }
bool Its_Between_Friday_And_Wednesday_Exclusive(){ return Its_After_Friday() || Its_Before_Wednesday(); }
bool Its_Between_Friday_And_Thursday_Exclusive(){ return Its_After_Friday() || Its_Before_Thursday(); }
bool Its_Between_Friday_And_Friday_Exclusive(){ return Its_After_Friday() || Its_Before_Friday(); }
bool Its_Between_Friday_And_Saturday_Exclusive(){ return Its_After_Friday() && Its_Before_Saturday(); }
bool Its_Between_Friday_And_Sunday_Exclusive(){ return Its_After_Friday() && Its_Before_Sunday(); }

//saturday
bool Its_Between_Saturday_And_Monday_Inclusive(){ return Its_Saturday_Or_Later() || Its_Monday_Or_Earlier(); }
bool Its_Between_Saturday_And_Tuesday_Inclusive(){ return Its_Saturday_Or_Later() || Its_Tuesday_Or_Earlier(); }
bool Its_Between_Saturday_And_Wednesday_Inclusive(){ return Its_Saturday_Or_Later() || Its_Wednesday_Or_Earlier(); }
bool Its_Between_Saturday_And_Thursday_Inclusive(){ return Its_Saturday_Or_Later() || Its_Thursday_Or_Earlier(); }
bool Its_Between_Saturday_And_Friday_Inclusive(){ return Its_Saturday_Or_Later() || Its_Friday_Or_Earlier(); }
bool Its_Between_Saturday_And_Saturday_Inclusive(){ return Its_Saturday_Or_Later() || Its_Saturday_Or_Earlier(); }
bool Its_Between_Saturday_And_Sunday_Inclusive(){ return Its_Saturday_Or_Later() && Its_Sunday_Or_Earlier(); }

bool Its_Between_Saturday_And_Monday_Exclusive(){ return Its_After_Saturday() || Its_Before_Monday(); }
bool Its_Between_Saturday_And_Tuesday_Exclusive(){ return Its_After_Saturday() || Its_Before_Tuesday(); }
bool Its_Between_Saturday_And_Wednesday_Exclusive(){ return Its_After_Saturday() || Its_Before_Wednesday(); }
bool Its_Between_Saturday_And_Thursday_Exclusive(){ return Its_After_Saturday() || Its_Before_Thursday(); }
bool Its_Between_Saturday_And_Friday_Exclusive(){ return Its_After_Saturday() || Its_Before_Friday(); }
bool Its_Between_Saturday_And_Saturday_Exclusive(){ return Its_After_Saturday() || Its_Before_Saturday(); }
bool Its_Between_Saturday_And_Sunday_Exclusive(){ return Its_After_Saturday() && Its_Before_Sunday(); }

//sunday
bool Its_Between_Sunday_And_Monday_Inclusive(){ return Its_Sunday_Or_Later() || Its_Monday_Or_Earlier(); }
bool Its_Between_Sunday_And_Tuesday_Inclusive(){ return Its_Sunday_Or_Later() || Its_Tuesday_Or_Earlier(); }
bool Its_Between_Sunday_And_Wednesday_Inclusive(){ return Its_Sunday_Or_Later() || Its_Wednesday_Or_Earlier(); }
bool Its_Between_Sunday_And_Thursday_Inclusive(){ return Its_Sunday_Or_Later() || Its_Thursday_Or_Earlier(); }
bool Its_Between_Sunday_And_Friday_Inclusive(){ return Its_Sunday_Or_Later() || Its_Friday_Or_Earlier(); }
bool Its_Between_Sunday_And_Saturday_Inclusive(){ return Its_Sunday_Or_Later() || Its_Saturday_Or_Earlier(); }
bool Its_Between_Sunday_And_Sunday_Inclusive(){ return Its_Sunday_Or_Later() || Its_Sunday_Or_Earlier(); }

bool Its_Between_Sunday_And_Monday_Exclusive(){ return Its_After_Sunday() || Its_Before_Monday(); }
bool Its_Between_Sunday_And_Tuesday_Exclusive(){ return Its_After_Sunday() || Its_Before_Tuesday(); }
bool Its_Between_Sunday_And_Wednesday_Exclusive(){ return Its_After_Sunday() || Its_Before_Wednesday(); }
bool Its_Between_Sunday_And_Thursday_Exclusive(){ return Its_After_Sunday() || Its_Before_Thursday(); }
bool Its_Between_Sunday_And_Friday_Exclusive(){ return Its_After_Sunday() || Its_Before_Friday(); }
bool Its_Between_Sunday_And_Saturday_Exclusive(){ return Its_After_Sunday() || Its_Before_Saturday(); }
bool Its_Between_Sunday_And_Sunday_Exclusive(){ return Its_After_Sunday() || Its_Before_Sunday(); }
