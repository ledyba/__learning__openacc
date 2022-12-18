#include <stdio.h>

void loop(int const n, float* acc, float* x, float* y) {
  #pragma acc data copyout(acc[:n]), copyin(x[:n], y[:n])
  #pragma acc kernels
  #pragma acc independent
  for (int i = 0; i < n; ++i) {
    acc[i] = x[i] + y[i];
  }
}

int main(char* args[]) {
  float acc[128];
  float x[128];
  float y[128];
  for (int i = 0; i < 128; ++i) {
    x[i] = i;
    y[i] = i;
  }
  loop(128, acc, x, y);
  for (int i = 0; i < 128; ++i) {
    printf("%f, \n", acc[i]);
  }
  printf("\n");
  return 0;
}
