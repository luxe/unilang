#!dockerfile-shebang.sh
FROM fedora:32
RUN yum -y update
RUN yum -y install gcc gcc-c++
RUN dnf install gcc-c++
RUN dnf group install "C Development Tools and Libraries" -y
RUN echo "#include <iostream>" >> main.cpp
RUN echo "#include <cstdlib>" >> main.cpp
RUN echo "int main(){ srand(1); for (int i = 0; i < 6; ++i){std::cout << rand() << ' ';} std::cout << std::endl; }" >> main.cpp
RUN g++ -o main main.cpp
ENTRYPOINT ["./main"]