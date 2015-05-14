gcc -shared -llua -lm -lclang -fPIC -o clangc.so clangc.c constants.c indexlib.c translationunitlib.c
