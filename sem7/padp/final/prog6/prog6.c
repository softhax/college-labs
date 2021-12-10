#include<string.h>
#include<ctype.h>
#include<omp.h>
#include<stdio.h>
#define COUNT 7
#define FILE_NAME "words.txt"
char search_words[COUNT][20]={"The", "lorem", "ipsum", "present", "dolor", "sit", "in"};
long counts[COUNT];

int is_equal(char *a,const char *key,int ignore_case){
    char b[20];
    strcpy(b,key);
    int len_a = strlen(a),len_b=strlen(b);
    if(len_a!=len_b)    return 0;
    if(ignore_case){
        for(int i=0;i<len_a;i++)    a[i] = tolower(a[i]);
        for(int i=0;i<len_b;i++)    b[i] = tolower(b[i]);
    }
    return (strcmp(a,b)==0);
}

void read_word(char *temp,FILE *fp){
    int i =0;char ch;
    while((ch=fgetc(fp))!=EOF && !isalpha(ch));
    while(ch!=EOF && isalpha(ch)){
        temp[i++] = ch;
        ch = fgetc(fp);
    }
    temp[i] = '\0';
}

long determine_count(const char *file_name,const char *key,int ignore_case){
    
    long count = 0;
    FILE *fp = fopen(file_name,"r");
    char temp[40];
    while(feof(fp) == 0) {
        read_word(temp,fp);
        if(is_equal(temp,key,ignore_case) != 0){
            count++;
        }
    }   
    return count;
}

int main(int argc,char *argv[]){

    int i = 0, nt = 0, ignore_case = 1;
    for(nt = 1;nt<=8;nt*=2){
        for(i=0;i<COUNT;i++)    counts[i]=0;
        double start_time = omp_get_wtime();
        #pragma omp parallel for shared(counts,search_words) private(i) num_threads(nt)
        for(i=0;i<COUNT;i++){
            counts[i] = determine_count(FILE_NAME,search_words[i],1);
        }    
        double end_time = omp_get_wtime();
        for(i = 0; i < COUNT; i++) 
        { 
           printf("\n%s: %ld",search_words[i], counts[i]); 
        }
        printf("\n%d Threads, time = %lf\n", nt, end_time-start_time);
    }
    
    return 0;
}
