(*
    Trevor Hickey
    CSCI 430
    Program 3
    Just Some Cool Computations
*)


--------------------------------------------
--represents one frame of the stack
--------------------------------------------
class Element{

--observers
    value(): String{{
        value;
    }};
    next(): Element{{
        next;
    }};

--transformers
    set_value(value_in: String): Element{{
        value <- value_in;
        self;
    }};
    set_next(next_in: Element): Element{{
        next <- next_in;
        self;
    }};
    set(value_in: String, next_in: Element): Element{{
        value <- value_in;
        next <- next_in;
        self;
    }};

--attributes
    value: String;
    next: Element;
};

--------------------------------------------
--represents a collection of element frames
--------------------------------------------
class Stack{

--observers
    top(): Element{{
        top_item;
    }};
    top_value(): String{{
        top_item.value();
    }};

--transformers
    push(item: Element): Stack{{
        item.set_next(top_item);
        top_item <- item;
        self;
    }};
    pop(): Element{{
        (let popped_item : Element <- top_item in{
        top_item <- top_item.next();
        popped_item;
        });
    }};
    is_empty(): Bool{{
        IsVoid top_item;
    }};


--attributes
    top_item: Element;
};

--------------------------------------------------------------
--handles user input and proccesses data with the stack class
--------------------------------------------------------------
class Main inherits IO{

-----------------------------------------------------------------------------
    --gets user input as string
    get_user_input() : String {{
        out_string("<");
        in_string();
    }};
-----------------------------------------------------------------------------
    --evaluate stack
    evaluate(stack: Stack): Object{{
        if not stack.is_empty() then{
            let element: Element <- stack.pop() in{
            if element.value() = "+" then
                add(stack) else{

                    if element.value() = "s" then
                    swap(stack) else
                    stack.push(element)

                    fi;
                }fi;
            };
        }else 0 fi;
    }};
-----------------------------------------------------------------------------
    --display the stack
    display(stack: Stack) : Object{{
        let element : Element <- stack.top() in{
            while not stack.is_empty() loop
                {
                    out_string(element.value());
                    out_string("\n");
                    stack.pop();
                    element <- stack.top();

                }
            pool;
        };
    }};
-----------------------------------------------------------------------------
    --swap the top two elements on the stack
    swap(stack: Stack) : Object{{
        let s1 : String, s2: String, e1: Element <- new Element, e2: Element <- new Element in{
            s1 <- stack.top_value(); stack.pop();
            s2 <- stack.top_value(); stack.pop();
            e1.set_value(s1);
            e2.set_value(s2);
            stack.push(e1);
            stack.push(e2);

        };
    }};
-----------------------------------------------------------------------------
    --add the top two stack elements together, and push the result onto the stack
    add(stack: Stack) : Object{{
    let s1 : String, s2: String, i1: Int, i2: Int, element: Element <- new Element, con: A2I <- new A2I in{
            s1 <- stack.top_value(); stack.pop();
            s2 <- stack.top_value(); stack.pop();

            i1 <- con.a2i(s1);
            i2 <- con.a2i(s2);

            element.set_value(con.i2a(i1 + i2));
            stack.push(element);

        };
    }};
-----------------------------------------------------------------------------
    --decide what to do on a particular set of inputs
    process_command(command: String, stack: Stack) : Object{{
        let element: Element <- new Element.set_value(command) in{
            if command = "+" then
            stack.push(element) else{

                if command = "s"
                then stack.push(element) else{

                    if command = "e"
                    then evaluate(stack) else{

                        if command = "d"
                        then display(stack.copy()) else{

                            if command = "x"
                            then 0 else
                            stack.push(element)

                            fi;
                        }fi;
                    }fi;
                }fi;
            }fi;
        };
    }};
-----------------------------------------------------------------------------
    main(): SELF_TYPE {{

            --process user input on the stack until the user asks to quit
            let user_input : String <- get_user_input() in{
                let stack : Stack <- new Stack in{
                    while not user_input = "x" loop
                        {
                        process_command(user_input,stack);
                        user_input <- get_user_input();
                        }
                    pool;
                };
            };

        self;
    }};
-----------------------------------------------------------------------------


};


