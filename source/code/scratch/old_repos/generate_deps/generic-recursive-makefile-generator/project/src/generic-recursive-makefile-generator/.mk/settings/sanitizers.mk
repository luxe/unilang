#Doing as many as you can at the same time:
SANITIZERS := -fsanitize=undefined -fsanitize=address -fsanitize=leak -fsanitize-recover=all -fuse-ld=gold
#SANITIZERS := -fsanitize=undefined -fsanitize=thread -fsanitize-recover=all
#SANITIZERS := -fsanitize=undefined -fsanitize=memory -fsanitize-recover=all
#SANITIZERS := -fsanitize=undefined -fsanitize=kernel-address -fsanitize-recover=all
#SANITIZERS := -fsanitize=safe-stack -fsanitize-recover=all
#something with data flow? -fsanitize=dataflow
#something about flow integrity? -fsanitize=cfi -flto -fvisibility=hidden.  need gold plugin?
#stats?
#coverage?


#Might as well do one at a time so we can target the problem is.  
#It will require a lot more running, but oh well.  
#SANITIZERS := -fsanitize=undefined -fsanitize-recover=all
#SANITIZERS := -fsanitize=address -fsanitize-recover=all
#SANITIZERS := -fsanitize=leak -fsanitize-recover=all
#SANITIZERS := -fsanitize=thread -fsanitize-recover=all
#SANITIZERS := -fsanitize=memory -fsanitize-recover=all
#SANITIZERS := -fsanitize=undefined -fsanitize=kernel-address -fsanitize-recover=all
#SANITIZERS := -fsanitize=safe-stack -fsanitize-recover=all
#something with data flow? -fsanitize=dataflow
#something about flow integrity? -fsanitize=cfi -flto -fvisibility=hidden.  need gold plugin?
#stats?
#coverage?
