; this program adds two binary values together and prints out the result in 
; decimal.  It supports negative numbers as well as floating point numbers.
;
; Here are a few examples and their results:
;
;   (addem '(1 0 1) '(1))
;   6
;
;   (addem '(- 1 0 1 1 p 1) '(p 0 1))
;   -11.25
;
;   (addem '(1 0 1 p) '(0 0 0 1 1 1))
;   12

;-------------------------------------------------------------------------------
; The main function.
; This function adds two binary numbers together and prints them out in decimal.
; In order to do this, we will convert both binary numbers to decimal before 
; performing the add.
;-------------------------------------------------------------------------------
(define (addem left right)
    (+ 
        (binary_to_base_10 left) 
        (binary_to_base_10 right)
    )
)

;-------------------------------------------------------------------------------
; This function converts a binary number to a decimal number, by first looking
; to see if the number is negative.  If the number is negative, it will convert
; the rest of the number knowing that the rest is an unsigned binary 
; and then multiply by a negative 1.  If the binary number was already positive,
; it will simply pass the number to a function that converts unsigned binary
; numbers to decimal
;-------------------------------------------------------------------------------
(define (binary_to_base_10 number)
    (if (equal? (car number) (car '(-)))
        (* -1 (unsigned_binary_to_base_10 (cdr number)))
        (unsigned_binary_to_base_10 number)
    )
)

;-------------------------------------------------------------------------------
; This function will split a binary number by its decimal point, calculate
; both sides, and add them together to get the correct decimal value.
; We reverse both of the split lists so that it is easier to iterate over 
; and calculate both sides.
;-------------------------------------------------------------------------------
(define (unsigned_binary_to_base_10 number)
    (+
    
        (unsigned_int_binary_to_base_10 
            (rev (get_integer_part number))
            1
        )
        
        (unsigned_decimal_binary_to_base_10 
            (get_decimal_part number)
            .5
        )
    )
)

;-------------------------------------------------------------------------------
; gets a list to the left of the decimal place (if there is one)
; the decimal occurs as the element 'p' in a list
;-------------------------------------------------------------------------------
(define (get_integer_part number)
    (split_at_p_element_and_take_left number)
)

;-------------------------------------------------------------------------------
; gets a list to the right of the decimal place (if there is one)
; the decimal occurs as the element 'p' in a list
;-------------------------------------------------------------------------------
(define (get_decimal_part number)
    (split_at_p_element_and_take_right number)
)

;-------------------------------------------------------------------------------
; performs the split and returns the left portion of the list once encountering
; the 'p' or reaching the end
;-------------------------------------------------------------------------------
(define (split_at_p_element_and_take_left number)(
    if (> (length number) 0)
    (if (equal? (car number) (car '(p)))
    '()
    (cons (car number) (get_integer_part (cdr number)))
    )
    '()
))

;-------------------------------------------------------------------------------
; performs the split and returns the right portion of the list once encountering
; the 'p' or reaching the end
;-------------------------------------------------------------------------------
(define (split_at_p_element_and_take_right number)(
    if (> (length number) 0)
    (if (equal? (car number) (car '(p)))
    (cdr number)
    (get_decimal_part (cdr number))
    )
    '()
))

;-------------------------------------------------------------------------------
; performs the binary to decimal conversion assuming the number is an integer
; and does not contain a floating point portion
; it also assumes that the binary number sent in, is in reveresed
;-------------------------------------------------------------------------------
(define (unsigned_int_binary_to_base_10 number multiplier)(
    if (> (length number) 0)
    (if (equal? (car number) (car '(1)))
        (+ (unsigned_int_binary_to_base_10 (cdr number) (* 2 multiplier)) (* 1 multiplier))
        (+ (unsigned_int_binary_to_base_10 (cdr number) (* 2 multiplier)) 0)
    )
    0
))

;-------------------------------------------------------------------------------
; performs the binary float to decimal conversion assuming the number is the
; float portion and does not contain any '-'s or 'p's
;-------------------------------------------------------------------------------
(define (unsigned_decimal_binary_to_base_10 number multiplier)(
    if (> (length number) 0)
    (if (equal? (car number) (car '(1)))
        (+ (unsigned_int_binary_to_base_10 (cdr number) (* .5 multiplier)) (* 1 multiplier))
        (+ (unsigned_int_binary_to_base_10 (cdr number) (* .5 multiplier)) 0)
    )
    0
))

;-------------------------------------------------------------------------------
; reverses a list
; I used this to make converting from binary to decimal easier
;-------------------------------------------------------------------------------
(define (rev l)(
if (> (length l) 0)
    (if (null? (cdr l))
        l
        (append (rev (cdr l)) (list (car l))))
        
   '()
))
