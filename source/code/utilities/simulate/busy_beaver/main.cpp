#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef vector<char> Tape;
typedef map<string, string> Program;

class TuringMachine {
private:
    Tape tape;
    Program program;
    char start, halt, init, state;
    bool tape_changed;
    int moves;
    int pos;
public:
    TuringMachine(Program program, char start, char halt, char init):
        tape(1, init), program(program), start(start), halt(halt),
        init(init), state(start), moves(0), tape_changed(1), pos(0)
    { }

    void run() {
        while (state != halt) {
            print_tape();
            string lhs = get_lhs();
            string rhs = get_rhs(lhs);

            char new_state = rhs[0];
            char new_symbol = rhs[1];
            char move = rhs[2];

            char old_symbol = lhs[1];
            update_tape(old_symbol, new_symbol);
            update_state(new_state);
            move_head(move);
        }
        print_tape();
    }

    int get_moves() {
        return moves;
    }

private:
    inline void print_tape() {
        if (tape_changed) {
            for (int i=0; i<tape.size(); i++)
                cout << tape[i];
            cout << endl;
        }
    }

    inline string get_lhs() {
        char sp[3] = {0};
        sp[0] = state;
        sp[1] = tape[pos];
        return string(sp);
    }

    inline string get_rhs(string &lhs) {
        return program[lhs];
    }

    inline void update_tape(char old_symbol, char new_symbol) {
        if (old_symbol != new_symbol) {
            tape[pos] = new_symbol;
            tape_changed++;
        }
        else {
            tape_changed = 0;
        }
    }

    inline void update_state(char new_state) {
        state = new_state;
    }

    inline void move_head(char move) {
        if (move == 'l')
            pos -= 1;
        else if (move == 'r')
            pos += 1;
        else
            throw string("unknown state");

        if (pos < 0) {
            tape.insert(tape.begin(), init);
            pos = 0;
        }
        if (pos >= tape.size()) {
            tape.push_back(init);
        }
        moves++;
    }

};

vector<Program> busy_beavers;

void init_bb6()
{
    Program bb6;
    bb6.insert(make_pair("a0", "b1r"));
    bb6.insert(make_pair("b0", "c1l"));
    bb6.insert(make_pair("c0", "d1l"));
    bb6.insert(make_pair("d0", "e1l"));
    bb6.insert(make_pair("e0", "a1l"));
    bb6.insert(make_pair("f0", "e1l"));

    bb6.insert(make_pair("a1", "e0l"));
    bb6.insert(make_pair("b1", "a0r"));
    bb6.insert(make_pair("c1", "c0r"));
    bb6.insert(make_pair("d1", "f0l"));
    bb6.insert(make_pair("e1", "c1l"));
    bb6.insert(make_pair("f1", "h1r"));

    busy_beavers.push_back(bb6);
}

void init_bb5() 
{
    Program bb5;
    bb5.insert(make_pair("a0", "b1l"));
    bb5.insert(make_pair("b0", "c1r"));
    bb5.insert(make_pair("c0", "a1l"));
    bb5.insert(make_pair("d0", "a1l"));
    bb5.insert(make_pair("e0", "h1r"));

    bb5.insert(make_pair("a1", "a1l"));
    bb5.insert(make_pair("b1", "b1r"));
    bb5.insert(make_pair("c1", "d1r"));
    bb5.insert(make_pair("d1", "e1r"));
    bb5.insert(make_pair("e1", "c0r"));

    busy_beavers.push_back(bb5);
}

void init_bb4()
{
    Program bb4;
    bb4.insert(make_pair("a0", "b1r"));
    bb4.insert(make_pair("b0", "a1l"));
    bb4.insert(make_pair("c0", "h1r"));
    bb4.insert(make_pair("d0", "d1r"));

    bb4.insert(make_pair("a1", "b1l"));
    bb4.insert(make_pair("b1", "c0l"));
    bb4.insert(make_pair("c1", "d1l"));
    bb4.insert(make_pair("d1", "a0r"));

    busy_beavers.push_back(bb4);

}

void init_bb3()
{
    Program bb3;
    bb3.insert(make_pair("a0", "b1r"));
    bb3.insert(make_pair("b0", "c0r"));
    bb3.insert(make_pair("c0", "c1l"));

    bb3.insert(make_pair("a1", "h1r"));
    bb3.insert(make_pair("b1", "b1r"));
    bb3.insert(make_pair("c1", "a1l"));

    busy_beavers.push_back(bb3);
}

void init_bb2()
{
    Program bb2;
    bb2.insert(make_pair("a0", "b1r"));
    bb2.insert(make_pair("b0", "a1l"));

    bb2.insert(make_pair("a1", "b1l"));
    bb2.insert(make_pair("b1", "h1r"));

    busy_beavers.push_back(bb2);
}

void init_bb1()
{
    Program bb1;
    bb1.insert(make_pair("a0", "h1r"));

    busy_beavers.push_back(bb1);
}

void init_busy_beavers()
{
    busy_beavers.push_back(Program());
    init_bb1();
    init_bb2();
    init_bb3();
    init_bb4();
    init_bb5();
    init_bb6();
}

void busy_beaver(int n)
{
    cout << "Running Busy Beaver with " << n << " states." << endl;
    cout << busy_beavers[n]["a0"] << endl;
    TuringMachine tm(busy_beavers[n], 'a', 'h', '0');
    tm.run();
    cout << "Busy Beaver finished in " << tm.get_moves() << " steps." << endl;
}

void usage(const char *prog)
{
    cout << "Usage: " << prog << " [1|2|3|4|5|6]\n";
    cout << "Runs Busy Beaver problem for 1 or 2 or 3 or 4 or 5 or 6 states." << endl;
    exit(1);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        usage(argv[0]);
    }

    int n = atoi(argv[1]);
    if (n < 1 || n > 6) {
        cout << "n must be between 1 and 6 inclusive!\n";
        cout << "\n";
        usage(argv[0]);
    }

    init_busy_beavers();
    busy_beaver(n);
}

