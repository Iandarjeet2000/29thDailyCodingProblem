/* Ques-70:- A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28. */

function findNth(n) {
  let count = 0;

  for (let i = 19; ; i += 9) {
    let s = 0;
    for (let j = i; j > 0; j = parseInt(j / 10)) s = s + (j % 10);
    if (s == 10) count++;
    if (count == n) return i;
  }
  return -1;
}
x=findNth(10);
console.log(x);
