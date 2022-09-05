#include<stdio.h>
#include<string.h>
#define total_chars 256
int calc_nextstate(char *pat, int M, int state, int x) {
   if (state < M && x == pat[state])
      return state+1;
   int ns, i;
   for (ns = state; ns > 0; ns--) {
      if (pat[ns-1] == x) {
         for (i = 0; i < ns-1; i++)
            if (pat[i] != pat[state-ns+1+i])
               break;
         if (i == ns-1)
            return ns;
      }
   }
   return 0;
}
//builds Finite Automata
void calc_TF(char *pat, int M, int TF[][total_chars]) {
   int state, x;
   for (state = 0; state <= M; ++state)
      for (x = 0; x < total_chars; ++x)
         TF[state][x] = calc_nextstate(pat, M, state, x);
}
//prints all occurrences of pattern in text
void calc_occur(char *pat, char *txt) {
   int M = strlen(pat);
   int N = strlen(txt);
   int TF[M+1][total_chars];
   calc_TF(pat, M, TF);
   int i, state=0;
   for (i = 0; i < N; i++){
      state = TF[state][txt[i]];
      if (state == M)
         printf ("\n Given pattern is found at the index%d",i-M+1);
   }
}
int main() {
   char *txt = "AABCDAABBDCAABADAABDABAABA";
   char *pat = "AABA";
   calc_occur(pat, txt);
   return 0;
}