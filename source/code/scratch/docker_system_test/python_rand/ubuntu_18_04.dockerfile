#!dockerfile-shebang.sh
FROM ubuntu:18.04
RUN apt update
RUN apt install -y software-properties-common
RUN apt install -y python2
RUN echo "#!/usr/bin/env python2" >> main.py
RUN echo "import random" >> main.py
RUN echo "random.seed(1)" >> main.py
RUN echo "print(\"{} {} {} {} {} {}\".format(random.random(),random.random(),random.random(),random.random(),random.random(),random.random()))" >> main.py
RUN chmod 777 main.py
ENTRYPOINT ["./main.py"]