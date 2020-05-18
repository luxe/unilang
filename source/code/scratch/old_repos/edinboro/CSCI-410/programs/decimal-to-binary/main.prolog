% Trevor Hickey
% April 11, 2014
% Decimal to Binary Converter (Prolog)

% How to use:
% consult('main.pr').
% makit(23.125, X).
% X = [1, 0, 1, 1, 1, p, 0, 0, 1].


% fixing an answer like this: X = [1, 0, 1, 1, 1, p, 0, 0, 1|...]
/*
?- current_prolog_flag(toplevel_print_options, V).

It will say something like V = [quoted(true), portray(true), max_depth(10), priority(699)]. Now, do:

?- set_prolog_flag(toplevel_print_options, [quoted(true), portray(true), max_depth(50), priority(699)]).

Change the max_depth option to something bigger like 50 or 100. Probably safest to retype the three other options as they are. Now, try the goal again.
 */




%this is the main function that will be queried by the user.
%the first parameter is a decimal number, and the second
%parameter bindes to the binary equivalent of decimal number.
makit(Decimal_Input, Binary_Output) :-

	%based on the input, derive the whole portion of the number
	% (the left side of the decimal)
	Whole_Part is truncate(Decimal_Input),

	%based on the decimal input, derive the decimal portion of the number
	% (the right side of the decimal)
	Decimal_Part  is Decimal_Input - Whole_Part,

	%use these two numbers to bind a binary representation
	derive_a_binary_number(Whole_Part, Decimal_Part, Binary_Output).

%given a whole number and a binary number, this function will derive
%a binary number.  It does this by deriving a binary representation for each part,
%and then appending the two results together with a 'p' in the middle to represent the decimal point
derive_a_binary_number(Whole_Part, Decimal_Part, Binary_Output):-

	%based on the whole part and the decimal part, create the binary equivalences
	%we'll represent these equivalences as the first_half and the second_half
	make_first_half(Whole_Part,First_Half),
	make_second_half(Decimal_Part,Second_Half),

	%append the two halves together with a p in the middle representing the decimal point
	append(First_Half,[p],First_Half_And_Decimal),
	append(First_Half_And_Decimal,Second_Half,Binary_Output).


make_first_half(Whole_Part,First_Half) :-
	recursively_build_first_half(Whole_Part, First_Half).

make_second_half(Decimal_Part,Second_Half) :-
	recursively_build_second_half(Decimal_Part, Second_Half).

%base case
recursively_build_first_half(0, First_Half) :- !.

%detects where 0s are
recursively_build_first_half(Number, First_Half) :-
	Remainder is Number mod 2,
	Remainder == 0,
	Truncated is truncate(Number/2),
	recursively_build_first_half(Truncated,Part),
	append(Part,[0],First_Half).

%detects where 1s are
recursively_build_first_half(Number, First_Half) :-
	Remainder is Number mod 2,
	Remainder == 1,
	Truncated is truncate(Number/2),
	recursively_build_first_half(Truncated,Part),
	append(Part,[1],First_Half).

%base case
recursively_build_second_half(0.0, Second_Half) :- !.

%detects where 1s are
recursively_build_second_half(Number, Second_Half) :-
	Decimal is Number * 2,
	Decimal >= 1,
	Truncated is truncate(Decimal),
	New_Number is Decimal - Truncated,
	recursively_build_second_half(New_Number,Part),
	append([1],Part,Second_Half).

%detects where 0s are
recursively_build_second_half(Number, Second_Half) :-
	Decimal is Number * 2,
	Decimal < 1,
	Truncated is truncate(Decimal),
	New_Number is Decimal - Truncated,
	recursively_build_second_half(New_Number,Part),
	append([0],Part,Second_Half).
