#include "code/utilities/time/calendar/months/lib.hpp"
#include "code/utilities/time/calendar/tm_wrappers/lib.hpp"

bool Its_January(){ return Current_Month() == 1;}
bool Its_February(){ return Current_Month() == 2;}
bool Its_March(){ return Current_Month() == 3;}
bool Its_April(){ return Current_Month() == 4;}
bool Its_May(){ return Current_Month() == 5;}
bool Its_June(){ return Current_Month() == 6;}
bool Its_July(){ return Current_Month() == 7;}
bool Its_August(){ return Current_Month() == 8;}
bool Its_September(){ return Current_Month() == 9;}
bool Its_October(){ return Current_Month() == 10;}
bool Its_November(){ return Current_Month() == 11;}
bool Its_December(){ return Current_Month() == 12;}

bool Its_Not_January(){ return Current_Month() != 1;}
bool Its_Not_February(){ return Current_Month() != 2;}
bool Its_Not_March(){ return Current_Month() != 3;}
bool Its_Not_April(){ return Current_Month() != 4;}
bool Its_Not_May(){ return Current_Month() != 5;}
bool Its_Not_June(){ return Current_Month() != 6;}
bool Its_Not_July(){ return Current_Month() != 7;}
bool Its_Not_August(){ return Current_Month() != 8;}
bool Its_Not_September(){ return Current_Month() != 9;}
bool Its_Not_October(){ return Current_Month() != 10;}
bool Its_Not_November(){ return Current_Month() != 11;}
bool Its_Not_December(){ return Current_Month() != 12;}

bool Its_January_Or_Later(){ return Current_Month() >= 1;}
bool Its_February_Or_Later(){ return Current_Month() >= 2;}
bool Its_March_Or_Later(){ return Current_Month() >= 3;}
bool Its_April_Or_Later(){ return Current_Month() >= 4;}
bool Its_May_Or_Later(){ return Current_Month() >= 5;}
bool Its_June_Or_Later(){ return Current_Month() >= 6;}
bool Its_July_Or_Later(){ return Current_Month() >= 7;}
bool Its_August_Or_Later(){ return Current_Month() >= 8;}
bool Its_September_Or_Later(){ return Current_Month() >= 9;}
bool Its_October_Or_Later(){ return Current_Month() >= 10;}
bool Its_November_Or_Later(){ return Current_Month() >= 11;}
bool Its_December_Or_Later(){ return Current_Month() >= 12;}

bool Its_January_Or_Earlier(){ return Current_Month() <= 1;}
bool Its_February_Or_Earlier(){ return Current_Month() <= 2;}
bool Its_March_Or_Earlier(){ return Current_Month() <= 3;}
bool Its_April_Or_Earlier(){ return Current_Month() <= 4;}
bool Its_May_Or_Earlier(){ return Current_Month() <= 5;}
bool Its_June_Or_Earlier(){ return Current_Month() <= 6;}
bool Its_July_Or_Earlier(){ return Current_Month() <= 7;}
bool Its_August_Or_Earlier(){ return Current_Month() <= 8;}
bool Its_September_Or_Earlier(){ return Current_Month() <= 9;}
bool Its_October_Or_Earlier(){ return Current_Month() <= 10;}
bool Its_November_Or_Earlier(){ return Current_Month() <= 11;}
bool Its_December_Or_Earlier(){ return Current_Month() <= 12;}

bool Its_Before_January(){ return Current_Month() < 1;}
bool Its_Before_February(){ return Current_Month() < 2;}
bool Its_Before_March(){ return Current_Month() < 3;}
bool Its_Before_April(){ return Current_Month() < 4;}
bool Its_Before_May(){ return Current_Month() < 5;}
bool Its_Before_June(){ return Current_Month() < 6;}
bool Its_Before_July(){ return Current_Month() < 7;}
bool Its_Before_August(){ return Current_Month() < 8;}
bool Its_Before_September(){ return Current_Month() < 9;}
bool Its_Before_October(){ return Current_Month() < 10;}
bool Its_Before_November(){ return Current_Month() < 11;}
bool Its_Before_December(){ return Current_Month() < 12;}

bool Its_After_January(){ return Current_Month() > 1;}
bool Its_After_February(){ return Current_Month() > 2;}
bool Its_After_March(){ return Current_Month() > 3;}
bool Its_After_April(){ return Current_Month() > 4;}
bool Its_After_May(){ return Current_Month() > 5;}
bool Its_After_June(){ return Current_Month() > 6;}
bool Its_After_July(){ return Current_Month() > 7;}
bool Its_After_August(){ return Current_Month() > 8;}
bool Its_After_September(){ return Current_Month() > 9;}
bool Its_After_October(){ return Current_Month() > 10;}
bool Its_After_November(){ return Current_Month() > 11;}
bool Its_After_December(){ return Current_Month() > 12;}

bool Its_January_1(){ return Its_January() && (Current_Month_Day() == 1); }
bool Its_Before_January_1(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 1);}
bool Its_After_January_1(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 1);}
bool Its_January_1_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 1);}
bool Its_January_1_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 1);}
  
bool Its_January_2(){ return Its_January() && (Current_Month_Day() == 2); }
bool Its_Before_January_2(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 2);}
bool Its_After_January_2(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 2);}
bool Its_January_2_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 2);}
bool Its_January_2_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 2);}
  
bool Its_January_3(){ return Its_January() && (Current_Month_Day() == 3); }
bool Its_Before_January_3(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 3);}
bool Its_After_January_3(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 3);}
bool Its_January_3_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 3);}
bool Its_January_3_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 3);}
  
bool Its_January_4(){ return Its_January() && (Current_Month_Day() == 4); }
bool Its_Before_January_4(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 4);}
bool Its_After_January_4(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 4);}
bool Its_January_4_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 4);}
bool Its_January_4_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 4);}

bool Its_January_5(){ return Its_January() && (Current_Month_Day() == 5); }
bool Its_Before_January_5(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 5);}
bool Its_After_January_5(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 5);}
bool Its_January_5_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 5);}
bool Its_January_5_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 5);}
  
bool Its_January_6(){ return Its_January() && (Current_Month_Day() == 6); }
bool Its_Before_January_6(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 6);}
bool Its_After_January_6(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 6);}
bool Its_January_6_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 6);}
bool Its_January_6_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 6);}

bool Its_January_7(){ return Its_January() && (Current_Month_Day() == 7); }
bool Its_Before_January_7(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 7);}
bool Its_After_January_7(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 7);}
bool Its_January_7_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 7);}
bool Its_January_7_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 7);}

bool Its_January_8(){ return Its_January() && (Current_Month_Day() == 8); }
bool Its_Before_January_8(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 8);}
bool Its_After_January_8(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 8);}
bool Its_January_8_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 8);}
bool Its_January_8_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 8);}

bool Its_January_9(){ return Its_January() && (Current_Month_Day() == 9); }
bool Its_Before_January_9(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 9);}
bool Its_After_January_9(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 9);}
bool Its_January_9_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 9);}
bool Its_January_9_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 9);}

bool Its_January_10(){ return Its_January() && (Current_Month_Day() == 10); }
bool Its_Before_January_10(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 10);}
bool Its_After_January_10(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 10);}
bool Its_January_10_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 10);}
bool Its_January_10_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 10);}

bool Its_January_11(){ return Its_January() && (Current_Month_Day() == 11); }
bool Its_Before_January_11(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 11);}
bool Its_After_January_11(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 11);}
bool Its_January_11_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 11);}
bool Its_January_11_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 11);}
  
bool Its_January_12(){ return Its_January() && (Current_Month_Day() == 12); }
bool Its_Before_January_12(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 12);}
bool Its_After_January_12(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 12);}
bool Its_January_12_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 12);}
bool Its_January_12_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 12);}
  
bool Its_January_13(){ return Its_January() && (Current_Month_Day() == 13); }
bool Its_Before_January_13(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 13);}
bool Its_After_January_13(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 13);}
bool Its_January_13_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 13);}
bool Its_January_13_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 13);}
  
bool Its_January_14(){ return Its_January() && (Current_Month_Day() == 14); }
bool Its_Before_January_14(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 14);}
bool Its_After_January_14(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 14);}
bool Its_January_14_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 14);}
bool Its_January_14_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 14);}

bool Its_January_15(){ return Its_January() && (Current_Month_Day() == 15); }
bool Its_Before_January_15(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 15);}
bool Its_After_January_15(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 15);}
bool Its_January_15_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 15);}
bool Its_January_15_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 15);}
  
bool Its_January_16(){ return Its_January() && (Current_Month_Day() == 16); }
bool Its_Before_January_16(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 16);}
bool Its_After_January_16(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 16);}
bool Its_January_16_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 16);}
bool Its_January_16_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 16);}

bool Its_January_17(){ return Its_January() && (Current_Month_Day() == 17); }
bool Its_Before_January_17(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 17);}
bool Its_After_January_17(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 17);}
bool Its_January_17_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 17);}
bool Its_January_17_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 17);}

bool Its_January_18(){ return Its_January() && (Current_Month_Day() == 18); }
bool Its_Before_January_18(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 18);}
bool Its_After_January_18(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 18);}
bool Its_January_18_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 18);}
bool Its_January_18_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 18);}

bool Its_January_19(){ return Its_January() && (Current_Month_Day() == 19); }
bool Its_Before_January_19(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 19);}
bool Its_After_January_19(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 19);}
bool Its_January_19_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 19);}
bool Its_January_19_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 19);}

bool Its_January_20(){ return Its_January() && (Current_Month_Day() == 20); }
bool Its_Before_January_20(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 20);}
bool Its_After_January_20(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 20);}
bool Its_January_20_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 20);}
bool Its_January_20_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 20);}

bool Its_January_21(){ return Its_January() && (Current_Month_Day() == 21); }
bool Its_Before_January_21(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 21);}
bool Its_After_January_21(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 21);}
bool Its_January_21_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 21);}
bool Its_January_21_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 21);}

bool Its_January_22(){ return Its_January() && (Current_Month_Day() == 22); }
bool Its_Before_January_22(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 22);}
bool Its_After_January_22(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 22);}
bool Its_January_22_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 22);}
bool Its_January_22_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 22);}
  
bool Its_January_23(){ return Its_January() && (Current_Month_Day() == 23); }
bool Its_Before_January_23(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 23);}
bool Its_After_January_23(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 23);}
bool Its_January_23_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 23);}
bool Its_January_23_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 23);}
  
bool Its_January_24(){ return Its_January() && (Current_Month_Day() == 24); }
bool Its_Before_January_24(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 24);}
bool Its_After_January_24(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 24);}
bool Its_January_24_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 24);}
bool Its_January_24_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 24);}

bool Its_January_25(){ return Its_January() && (Current_Month_Day() == 25); }
bool Its_Before_January_25(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 25);}
bool Its_After_January_25(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 25);}
bool Its_January_25_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 25);}
bool Its_January_25_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 25);}
  
bool Its_January_26(){ return Its_January() && (Current_Month_Day() == 26); }
bool Its_Before_January_26(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 26);}
bool Its_After_January_26(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 26);}
bool Its_January_26_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 26);}
bool Its_January_26_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 26);}

bool Its_January_27(){ return Its_January() && (Current_Month_Day() == 27); }
bool Its_Before_January_27(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 27);}
bool Its_After_January_27(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 27);}
bool Its_January_27_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 27);}
bool Its_January_27_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 27);}

bool Its_January_28(){ return Its_January() && (Current_Month_Day() == 28); }
bool Its_Before_January_28(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 28);}
bool Its_After_January_28(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 28);}
bool Its_January_28_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 28);}
bool Its_January_28_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 28);}

bool Its_January_29(){ return Its_January() && (Current_Month_Day() == 29); }
bool Its_Before_January_29(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 29);}
bool Its_After_January_29(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 29);}
bool Its_January_29_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 29);}
bool Its_January_29_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 29);}

bool Its_January_30(){ return Its_January() && (Current_Month_Day() == 30); }
bool Its_Before_January_30(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 30);}
bool Its_After_January_30(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 30);}
bool Its_January_30_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 30);}
bool Its_January_30_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 30);}

bool Its_January_31(){ return Its_January() && (Current_Month_Day() == 31); }
bool Its_Before_January_31(){ return Its_Before_January() || (Its_January() && Current_Month_Day() < 31);}
bool Its_After_January_31(){ return Its_After_January() || (Its_January() && Current_Month_Day() > 31);}
bool Its_January_31_Or_Before(){ return Its_Before_January() || (Its_January() && Current_Month_Day() <= 31);}
bool Its_January_31_Or_After(){ return Its_After_January() || (Its_January() && Current_Month_Day() >= 31);}













bool Its_February_1(){ return Its_February() && (Current_Month_Day() == 1); }
bool Its_Before_February_1(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 1);}
bool Its_After_February_1(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 1);}
bool Its_February_1_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 1);}
bool Its_February_1_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 1);}
  
bool Its_February_2(){ return Its_February() && (Current_Month_Day() == 2); }
bool Its_Before_February_2(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 2);}
bool Its_After_February_2(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 2);}
bool Its_February_2_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 2);}
bool Its_February_2_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 2);}
  
bool Its_February_3(){ return Its_February() && (Current_Month_Day() == 3); }
bool Its_Before_February_3(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 3);}
bool Its_After_February_3(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 3);}
bool Its_February_3_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 3);}
bool Its_February_3_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 3);}
  
bool Its_February_4(){ return Its_February() && (Current_Month_Day() == 4); }
bool Its_Before_February_4(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 4);}
bool Its_After_February_4(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 4);}
bool Its_February_4_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 4);}
bool Its_February_4_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 4);}

bool Its_February_5(){ return Its_February() && (Current_Month_Day() == 5); }
bool Its_Before_February_5(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 5);}
bool Its_After_February_5(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 5);}
bool Its_February_5_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 5);}
bool Its_February_5_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 5);}
  
bool Its_February_6(){ return Its_February() && (Current_Month_Day() == 6); }
bool Its_Before_February_6(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 6);}
bool Its_After_February_6(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 6);}
bool Its_February_6_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 6);}
bool Its_February_6_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 6);}

bool Its_February_7(){ return Its_February() && (Current_Month_Day() == 7); }
bool Its_Before_February_7(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 7);}
bool Its_After_February_7(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 7);}
bool Its_February_7_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 7);}
bool Its_February_7_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 7);}

bool Its_February_8(){ return Its_February() && (Current_Month_Day() == 8); }
bool Its_Before_February_8(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 8);}
bool Its_After_February_8(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 8);}
bool Its_February_8_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 8);}
bool Its_February_8_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 8);}

bool Its_February_9(){ return Its_February() && (Current_Month_Day() == 9); }
bool Its_Before_February_9(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 9);}
bool Its_After_February_9(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 9);}
bool Its_February_9_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 9);}
bool Its_February_9_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 9);}

bool Its_February_10(){ return Its_February() && (Current_Month_Day() == 10); }
bool Its_Before_February_10(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 10);}
bool Its_After_February_10(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 10);}
bool Its_February_10_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 10);}
bool Its_February_10_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 10);}

bool Its_February_11(){ return Its_February() && (Current_Month_Day() == 11); }
bool Its_Before_February_11(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 11);}
bool Its_After_February_11(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 11);}
bool Its_February_11_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 11);}
bool Its_February_11_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 11);}
  
bool Its_February_12(){ return Its_February() && (Current_Month_Day() == 12); }
bool Its_Before_February_12(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 12);}
bool Its_After_February_12(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 12);}
bool Its_February_12_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 12);}
bool Its_February_12_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 12);}
  
bool Its_February_13(){ return Its_February() && (Current_Month_Day() == 13); }
bool Its_Before_February_13(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 13);}
bool Its_After_February_13(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 13);}
bool Its_February_13_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 13);}
bool Its_February_13_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 13);}
  
bool Its_February_14(){ return Its_February() && (Current_Month_Day() == 14); }
bool Its_Before_February_14(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 14);}
bool Its_After_February_14(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 14);}
bool Its_February_14_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 14);}
bool Its_February_14_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 14);}

bool Its_February_15(){ return Its_February() && (Current_Month_Day() == 15); }
bool Its_Before_February_15(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 15);}
bool Its_After_February_15(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 15);}
bool Its_February_15_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 15);}
bool Its_February_15_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 15);}
  
bool Its_February_16(){ return Its_February() && (Current_Month_Day() == 16); }
bool Its_Before_February_16(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 16);}
bool Its_After_February_16(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 16);}
bool Its_February_16_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 16);}
bool Its_February_16_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 16);}

bool Its_February_17(){ return Its_February() && (Current_Month_Day() == 17); }
bool Its_Before_February_17(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 17);}
bool Its_After_February_17(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 17);}
bool Its_February_17_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 17);}
bool Its_February_17_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 17);}

bool Its_February_18(){ return Its_February() && (Current_Month_Day() == 18); }
bool Its_Before_February_18(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 18);}
bool Its_After_February_18(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 18);}
bool Its_February_18_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 18);}
bool Its_February_18_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 18);}

bool Its_February_19(){ return Its_February() && (Current_Month_Day() == 19); }
bool Its_Before_February_19(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 19);}
bool Its_After_February_19(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 19);}
bool Its_February_19_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 19);}
bool Its_February_19_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 19);}

bool Its_February_20(){ return Its_February() && (Current_Month_Day() == 20); }
bool Its_Before_February_20(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 20);}
bool Its_After_February_20(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 20);}
bool Its_February_20_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 20);}
bool Its_February_20_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 20);}

bool Its_February_21(){ return Its_February() && (Current_Month_Day() == 21); }
bool Its_Before_February_21(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 21);}
bool Its_After_February_21(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 21);}
bool Its_February_21_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 21);}
bool Its_February_21_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 21);}

bool Its_February_22(){ return Its_February() && (Current_Month_Day() == 22); }
bool Its_Before_February_22(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 22);}
bool Its_After_February_22(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 22);}
bool Its_February_22_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 22);}
bool Its_February_22_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 22);}
  
bool Its_February_23(){ return Its_February() && (Current_Month_Day() == 23); }
bool Its_Before_February_23(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 23);}
bool Its_After_February_23(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 23);}
bool Its_February_23_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 23);}
bool Its_February_23_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 23);}
  
bool Its_February_24(){ return Its_February() && (Current_Month_Day() == 24); }
bool Its_Before_February_24(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 24);}
bool Its_After_February_24(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 24);}
bool Its_February_24_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 24);}
bool Its_February_24_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 24);}

bool Its_February_25(){ return Its_February() && (Current_Month_Day() == 25); }
bool Its_Before_February_25(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 25);}
bool Its_After_February_25(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 25);}
bool Its_February_25_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 25);}
bool Its_February_25_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 25);}
  
bool Its_February_26(){ return Its_February() && (Current_Month_Day() == 26); }
bool Its_Before_February_26(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 26);}
bool Its_After_February_26(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 26);}
bool Its_February_26_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 26);}
bool Its_February_26_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 26);}

bool Its_February_27(){ return Its_February() && (Current_Month_Day() == 27); }
bool Its_Before_February_27(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 27);}
bool Its_After_February_27(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 27);}
bool Its_February_27_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 27);}
bool Its_February_27_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 27);}

bool Its_February_28(){ return Its_February() && (Current_Month_Day() == 28); }
bool Its_Before_February_28(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 28);}
bool Its_After_February_28(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 28);}
bool Its_February_28_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 28);}
bool Its_February_28_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 28);}

bool Its_February_29(){ return Its_February() && (Current_Month_Day() == 29); }
bool Its_Before_February_29(){ return Its_Before_February() || (Its_February() && Current_Month_Day() < 29);}
bool Its_After_February_29(){ return Its_After_February() || (Its_February() && Current_Month_Day() > 29);}
bool Its_February_29_Or_Before(){ return Its_Before_February() || (Its_February() && Current_Month_Day() <= 29);}
bool Its_February_29_Or_After(){ return Its_After_February() || (Its_February() && Current_Month_Day() >= 29);}










