main(a) {
  a > 100
    || (
      (a % 15
        && (a % 3
          && (a % 5
            && printf("%d\n", a)
            || printf("Buzz\n"))
          || printf("Fizz\n"))
        || printf("FizzBuzz\n")),
      main(++a));
}
