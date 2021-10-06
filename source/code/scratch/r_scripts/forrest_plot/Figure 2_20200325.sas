********Inadequate weight gain*******;
data inadequatea;
input variable racea OR LCL UCL;
datalines;
1 1 1.66 1.64 1.68
1 2 1.57 1.53 1.60
2 1 1.52 1.50 1.53
2 2 1.34 1.31 1.37
3 1 0.7 0.69 0.71
3 2 0.7 0.68 0.73
4 1 2.0 1.97 2.03
4 2 1.72 1.68 1.75
5 1 0.64 0.63 0.65
5 2 0.64 0.61 0.67
6 1 1.79 1.73 1.86
6 2 1.86 1.75 1.98
;
run;
data inadequateb;set inadequatea;
if variable=1 then variablea='Preterm birth';
if variable=2 then variablea='SGA';
if variable=3 then variablea='LGA';
if variable=4 then variablea='LBW';
if variable=5 then variablea='Macrosomia';
if variable=6 then variablea='Low Apgar';
if racea=1 then race='white';
if racea=2 then race='black';
run;

ods graphics on / width=5in height=3.5in;
proc sgplot data=inadequateb;
Title 'Odds ratios of birth outcomes among inadequate weight gain stratified by race: normal weight gain as reference group';
scatter x=OR y= variablea/xerrorlower=lcl xerrorupper=ucl markerattrs=or (symbol=diamondfilled size=4) group=race groupdisplay=cluster;
refline 1/axis=x;
xaxis label="OR and 95%CI" values=(0.5 to 2.1 by 0.1 );
yaxis label="Outcomes"; 
footnote 'Adjusted for maternal age, maternal education status, parity, pre-pregnancy BMI, WIC status, and smoking status during pregnancy';
run;
ods graphics off;

********Adequate weight gain*******;
data adequatea;
input variable racea OR LCL UCL;
datalines;
    
** var, black/white, odds ratio, confidence interval
1 1 0.74 0.73 0.75
1 2 0.75 0.73 0.77
2 1  0.63 0.63 0.64
2 2 0.71 0.69 0.72
3 1 1.89 1.87 1.91
3 2 1.78 1.74 1.84
4 1 0.61 0.60 0.62
4 2 0.66 0.64 0.67
5 1 2.01 1.99 2.03
5 2 1.95 1.89 2.02
6 1 0.82 0.79 0.85
6 2 0.76 0.71 0.81
;
run;
data adequateb;set adequatea;
if variable=1 then variablea='Preterm birth';
if variable=2 then variablea='SGA';
if variable=3 then variablea='LGA';
if variable=4 then variablea='LBW';
if variable=5 then variablea='Macrosomia';
if variable=6 then variablea='Low Apgar';
if racea=1 then race='white';
if racea=2 then race='black';
run;

ods graphics on / width=5in height=3.5in;
proc sgplot data=adequateb;
Title 'Odds ratios of birth outcomes among excessive weight gain stratified by race: normal weight gain as reference group';
scatter x=OR y= variablea/xerrorlower=lcl xerrorupper=ucl markerattrs=or (symbol=diamondfilled size=4) group=race groupdisplay=cluster;
refline 1/axis=x;
xaxis label="OR and 95%CI" values=(0.5 to 2.1 by 0.1 );
yaxis label="Outcomes"; 
footnote 'Adjusted for maternal age, maternal education status, parity, pre-pregnancy BMI, WIC status, and smoking status during pregnancy';
run;
ods graphics off;






