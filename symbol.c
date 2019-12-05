#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct symbol{
//      char token[3];
        int val;
        int token;
}symbol;
int ascii(char *s){
   int cnt=0;
   while (1){
      if (s[cnt] == ' '){
         break;
      }
      else cnt++;
   }
   int sum = 0;
   for (int i = 0; i < cnt; i++){
      sum += s[i];
   }
   return sum;
}
int main(){
        FILE *symbolFile = fopen("./inputSytmbols.txt","r");
        char strtmp[10] = {0};
        int cnt = 0;
        symbol table[15];
        symbol a;
        a.token=9999;
        if(symbolFile == NULL){
                printf("NULLLLL");
                return 0;
        }
        while(fgets(strtmp,10,symbolFile)!=NULL){
                char *tmp = strchr(strtmp,0x20)+1;
                a.token = ascii(strtmp);
                a.val = atoi(tmp);
                table[cnt] = a;
                cnt++;
        }
        fclose(symbolFile);
        for(int i=0;i<cnt;i++){
                printf("%d %d \n",table[i].token,table[i].val);
        }
        return 0;

}
