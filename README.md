# libft-tester
My set of tests for libft functions

## Getting started
Just copy the `libft` folder to the root of the repository

## Running
Run it with 
```sh
make
./main
```
If you run `make test` it will compile your lib with both `-fsanitize=address` and `-g` gcc flags. This will allow you to catch memory errors.
This will, tho, stop the tester execution so you'll need to fix the current error in order to catch the next.
