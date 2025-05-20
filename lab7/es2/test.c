
struct Node *powerset_div_conq(int pos, Exercise **val, Exercise **sol, int n, int start, struct Node *h) {
  int i;
  if (start >= n) {
    if(pos <= 5 && countMinDiffDiag(sol, pos))
      if(checkAcro(sol, pos) > 0)
        h = newNode(sol, pos, h);
    return h;
  }
  for (i = start; i < n; i++) {
    sol[pos] = val[i];
    h = powerset_div_conq(pos+1, val, sol, n, i+1, h);
  }
  h = powerset_div_conq(pos, val, sol, n, n, h);
  return h;
}
