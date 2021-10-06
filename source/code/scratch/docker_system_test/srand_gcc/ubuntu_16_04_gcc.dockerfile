#!dockerfile-shebang.sh
FROM ubuntu:16.04
RUN echo "#include <iostream>\n #include <cstdlib>\n int main(){ srand(1); for (int i = 0; i < 6; ++i){std::cout << rand() << ' ';} std::cout << std::endl; }" > main.cpp
RUN apt-get update
RUN apt-get install -y software-properties-common
RUN apt-get install -y gcc
RUN apt-get install -y g++
RUN g++ -o main main.cpp
ENTRYPOINT ["./main"]