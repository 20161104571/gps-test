//
//  main.c
//  gps test
//
//  Created by w20161104571 on 17/6/22.
//  Copyright © 2017年 w20161104571. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    FILE *fp;
    char sp1[80];
    int i;
    char latitude[10];
    char longitude[10];
    int time;
    fp=fopen("/Users/w20161104571/Desktop/gps test/GPS170510.log","r+");
    fscanf(fp,"%s",sp1);
    printf("结果：%s\n",sp1);
    for(i=0;i<8;i++)
        latitude[i]=sp1[i+16];
    latitude[10]='\0';
    printf("纬度：%s\n",latitude);
    for(i=0;i<9;i++)
        longitude[i]=sp1[i+28];
    longitude[10]='\0';
    printf("经度：%s\n",latitude);
    fclose(fp);
    return 0;
}
