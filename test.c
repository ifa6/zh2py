#include "zh2py.h"
int main(int argc,char ** argv){
    int result = 0;
    if ( argc < 2 ){
        printf("usage:%s {text_dict_file}",argv[0]);
        exit(0);
    }
    char * dict_path = argv[1];

    printf("read file:%s",dict_path);
    zh2py_res_table_root= zh2py_read_transform_table_file(dict_path);
    if(zh2py_res_table_root == NULL){
        printf("Cant load table file\n");
    }

    int l;
    int i=0;
    int code=0;
    int code_more=0;
    int index=0;

    char * final_result;
    int e=0;
    for(e=0;e<100;e++){
        FILE * fp = fopen("./gbkall","r");
        char buf[1024];
        int result_len = 0;
        while(fgets(buf,1024,fp)){
            l=strlen(buf);
            final_result = NULL;
            final_result = zh2py_transform(zh2py_res_table_root,(char *)buf,&result_len);
            if(final_result==NULL){
                printf("Got an error");
            }
            printf("result len:%d\n",result_len);
            printf("%s\n",final_result);
        }
        fclose(fp);
    }
    int ret = zh2py_free_table(zh2py_res_table_root);
    printf("free_table return:%d\n",ret);
    return 0;
}

