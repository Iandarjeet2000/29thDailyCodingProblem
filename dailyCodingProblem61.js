/*  Ques-61:- Implement integer exponentiation. That is, implement the pow(x, y)
      function, where x and y are integers and returns x^y. Do this faster than
      the naive method of repeated multiplication. For example, pow(2, 10)
      should return 1024. */

      function power(x, y) {
        var s;

        if (y == 0) return 1;

        s = power(x, parseInt(y / 2));

        if (y % 2 == 0) return s * s;
        else {
          if (y > 0) return x * s * s;
          else return (s * s) / x;
        }
      }

      var x = 2;
      var y = 10;

      console.log(power(x, y));
    
