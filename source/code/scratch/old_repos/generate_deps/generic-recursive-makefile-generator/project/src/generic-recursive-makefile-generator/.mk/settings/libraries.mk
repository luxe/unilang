#Libraries
BOOST_LIBS := -lboost_program_options -lboost_filesystem -lboost_system -lboost_iostreams -lboost_serialization -lboost_python -lpython2.7
GMP_LIBS := -lgmpxx -lgmp
NCURSES_LIBS := -lncurses -lmenu -lpanel -lform -lncurses++
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system
DATABASE_LIBS := -lsqlite3
OTHER_LIBS := -lxdo
LIBS := $(BOOST_LIBS) $(GMP_LIBS) $(NCURSES_LIBS) $(SFML_LIBS) $(DATABASE_LIBS) $(OTHER_LIBS)
