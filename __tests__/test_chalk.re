open Chalk;

open Jest;

open Expect;

test
  "don't add any styling when called as the base function"
  (fun () => expect (chalk "foo") |> toBe "foo");

Skip.test "support multiple arguments in base function" (fun () => fail "not implemented");

test "style string" (fun () => expect (underline "foo") |> toBe {js|\u001B[4mfoo\u001B[24m|js});

test "style string" (fun () => expect (red "foo") |> toBe {js|\u001B[31mfoo\u001B[39m|js});

test "style string" (fun () => expect (bgRed "foo") |> toBe {js|\u001B[41mfoo\u001B[49m|js});

test
  "support applying multiple styles at once"
  (
    fun () =>
      expect ("foo" |> underline |> bgGreen |> red) |>
      toBe {js|\u001B[31m\u001B[42m\u001B[4mfoo\u001B[24m\u001B[49m\u001B[39m|js}
  );

test
  "support applying multiple styles at once"
  (
    fun () =>
      expect ("foo" |> bgGreen |> red |> underline) |>
      toBe {js|\u001B[4m\u001B[31m\u001B[42mfoo\u001B[49m\u001B[39m\u001B[24m|js}
  );

test
  "support nesting styles"
  (
    fun () =>
      expect (red ("foo" ^ ("bar" |> bgBlue |> underline) ^ "!")) |>
      toBe {js|\u001B[31mfoo\u001B[4m\u001B[44mbar\u001B[49m\u001B[24m!\u001B[39m|js}
  );

test
  "support nesting styles of the same type (color, underline, bg)"
  (
    fun () =>
      expect (red ("a" ^ yellow ("b" ^ green "c" ^ "b") ^ "c")) |>
      toBe {js|\u001B[31ma\u001B[33mb\u001B[32mc\u001B[33mb\u001B[31mc\u001B[39m|js}
  );

test
  "reset all styles with `.reset()`"
  (
    fun () =>
      expect (reset (("foo" |> underline |> bgGreen |> red) ^ "foo")) |>
      toBe {js|\u001B[0m\u001B[31m\u001B[42m\u001B[4mfoo\u001B[24m\u001B[49m\u001B[39mfoo\u001B[0m|js}
  );

test
  "support caching multiple styles"
  (
    fun () => {
      let myRed = red;
      let myGreen = green;
      expect (myRed "foo") |> not_ |> toBe (myGreen "foo")
    }
  );

test
  "support caching multiple styles"
  (
    fun () => {
      let myRed = red;
      let myGreen = green;
      let myRedBold x => x |> bold |> myRed;
      let myGreenBold x => x |> bold |> myGreen;
      expect (myRedBold "bar") |> not_ |> toBe (myGreenBold "bar")
    }
  );

test
  "support caching multiple styles"
  (
    fun () => {
      let myGreen = green;
      let myGreenBold x => x |> bold |> green;
      expect (myGreen "baz") |> not_ |> toBe (myGreenBold "baz")
    }
  );

test "alias gray to grey" (fun () => expect (grey "foo") |> toBe {js|\u001B[90mfoo\u001B[39m|js});

Skip.test "support variable number of arguments" (fun () => fail "not implemented");

test "don't output escape codes if the input is empty" (fun () => expect (red "") |> toBe "");

test
  "don't output escape codes if the input is empty"
  (fun () => expect ("" |> black |> blue |> red) |> toBe "");

test
  "line breaks should open and close colors"
  (
    fun () =>
      expect (grey "hello\nworld") |>
      toBe {js|\u001B[90mhello\u001B[39m\n\u001B[90mworld\u001B[39m|js}
  );

Skip.test
  "properly convert RGB to 16 colors on basic color terminals" (fun () => fail "not implemented");

Skip.test
  "properly convert RGB to 256 colors on basic color terminals" (fun () => fail "not implemented");

Skip.test "don't emit RGB codes if level is 0" (fun () => fail "not implemented");

test
  "RGB triplet"
  (
    fun () =>
      expect ("Orange!" |> bold |> rgb (255, 136, 0)) |>
      toBe {js|\u001b[38;5;214m\u001b[1mOrange!\u001b[22m\u001b[39m|js}
  );

test
  "RGB hexadecimal string"
  (
    fun () =>
      expect ("Orange!" |> bold |> hex "#FF8800") |>
      toBe {js|\u001b[38;5;214m\u001b[1mOrange!\u001b[22m\u001b[39m|js}
  );

test
  "CSS color keyword"
  (
    fun () =>
      expect ("Orange!" |> bold |> keyword "orange") |>
      toBe {js|\u001b[38;5;214m\u001b[1mOrange!\u001b[22m\u001b[39m|js}
  );

test
  "HSL triplet"
  (
    fun () =>
      expect ("Orange!" |> bold |> hsl (32, 100, 50)) |>
      toBe {js|\u001b[38;5;214m\u001b[1mOrange!\u001b[22m\u001b[39m|js}
  );

test
  "HSV triplet"
  (
    fun () =>
      expect ("Orange!" |> bold |> hsv (32, 100, 100)) |>
      toBe {js|\u001b[38;5;214m\u001b[1mOrange!\u001b[22m\u001b[39m|js}
  );

test
  "HWB triplet"
  (
    fun () =>
      expect ("Orange!" |> bold |> hwb (32, 0, 50)) |>
      toBe {js|\u001b[38;5;130m\u001b[1mOrange!\u001b[22m\u001b[39m|js}
  );
