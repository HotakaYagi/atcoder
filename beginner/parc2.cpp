// interactive heap sort
#include <cstdio>
#include <string>

using namespace std;

static void heapify(char *ar, int idx, int max){
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest;
    char ans;

    if(left<max){
        printf("? %c %c\n", ar[left], ar[idx]);
        fflush(stdout);
        scanf(" %c", &ans);
    }
    if(left < max && ans == '>'){
        largest = left;
    }else{
        largest = idx;
    }

    if(right < max){
        printf("? %c %c\n", ar[right], ar[largest]);
        fflush(stdout);
        scanf(" %c", &ans);
    }
    if(right < max && ans == '>'){
        largest = right;
    }

    if(largest != idx){
        char tmp;
        tmp = ar[idx];
        ar[idx] = ar[largest];
        ar[largest] = tmp;
        heapify(ar, largest, max);
    }
}

static void buildHeap(char *ar, int n){
    int i;
    for(i = n / 2 - 1; i >= 0; i--){
        heapify(ar, i, n);
    }
}

int main(void){
  int N,Q,i,j;

  scanf("%d%d", &N, &Q);

  char* s;
  s = (char*)malloc(sizeof(char)*N);
  for(i=0;i<N;i++) {
      s[i] = (char)('A' + i);
  }
//    char*[N ar = &s;

  buildHeap(s, N);
  for(i = N-1; i >= 1; i--){
      char tmp;
      tmp = s[0];
      s[0] = s[i];
      s[i] = tmp;
      heapify(s, 0, i);
  }
  string ans;
  for(i=0;i<N;i++){
      ans = ans + s[i];
  }
  printf("! %s\n", ans.c_str());
  fflush(stdout);

  return 0;
}