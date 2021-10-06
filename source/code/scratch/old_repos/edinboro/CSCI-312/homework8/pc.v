//: version "2.0-b10"
//: property encoding = "iso8859-1"
//: property locale = "en"
//: property prefix = "_GG"
//: property title = "new.v"
//: property timingViolationMode = 2
//: property initTime = "0 ns"

`timescale 1ns/1ns

//: /netlistBegin main
module main;    //: root_module
reg w7;    //: /sn:0 {0}(460,92)(471,92)(471,116)(446,116)(446,173)(419,173){1}
reg [11:0] w3;    //: /sn:0 {0}(#:564,150)(564,211)(468,211)(468,235){1}
supply0 w1;    //: /sn:0 {0}(476,245)(491,245)(491,251){1}
reg w10;    //: /sn:0 {0}(308,239)(329,239)(329,178)(343,178){1}
supply0 w9;    //: /sn:0 {0}(445,193)(445,183)(419,183){1}
wire w4;    //: /sn:0 {0}(428,249)(413,249){1}
wire [11:0] w0;    //: /sn:0 {0}(436,235)(436,204)(#:380,204)(#:380,189){1}
wire [11:0] w2;    //: /sn:0 {0}(#:452,264)(452,331)(213,331)(213,165){1}
//: {2}(#:215,163)(380,163)(380,168){3}
//: {4}(213,161)(213,142){5}
//: enddecls

  //: joint g8 (w2) @(213, 163) /w:[ 2 4 -1 1 ]
  //: LED g3 (w2) @(213,135) /sn:0 /w:[ 5 ] /type:3
  //: GROUND g2 (w1) @(491,257) /sn:0 /w:[ 1 ]
  _GGREG12 #(10, 10, 20) PC (.Q(w0), .D(w2), .EN(w9), .CLR(w7), .CK(w10));   //: @(380,178) /w:[ 1 3 1 1 1 ]
  //: DIP g1 (w3) @(564,140) /sn:0 /w:[ 0 ] /st:4 /dn:1
  //: GROUND g6 (w9) @(445,199) /sn:0 /w:[ 0 ]
  //: comment g9 @(302,113) /sn:0
  //: /line:"Program Counter"
  //: /end
  //: SWITCH g7 (w7) @(443,92) /sn:0 /w:[ 0 ] /st:1 /dn:1
  //: SWITCH g5 (w10) @(291,239) /sn:0 /w:[ 0 ] /st:1 /dn:1
  _GGADD12 #(100, 102, 94, 96) g0 (.A(w0), .B(w3), .S(w2), .CI(w1), .CO(w4));   //: @(452,251) /sn:0 /w:[ 0 1 0 0 0 ]

endmodule
//: /netlistEnd

