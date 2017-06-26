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
    char sp2[80];
    int i;
    char latitude[10];
    char longitude[10];
    char UTCtime[7];
    char date[7];
    int year;
    int month;
    int day;
    int hours;
    int minute;
    int second;
    char latitude_direction[2];
    char longitude_direction[2];
    char altitude[5];
    fp=fopen("/Users/w20161104571/Desktop/gps test/GPS170510.log","r+");
    fscanf(fp,"%s",sp1);
    printf("结果:%s\n",sp1);
                  
    fscanf(fp,"%s",sp2);
    printf("结果:%s\n",sp2);
              
    for(i=0;i<8;i++)
        latitude[i]=sp1[i+16];
    latitude[10]='\0';
    printf("纬度:%s\n",latitude);
    
    for(i=0;i<1;i++)
        latitude_direction[i]=sp1[i+25];
    latitude_direction[2]='\0';
    printf("纬度方向:%s\n",latitude_direction);
    
    for(i=0;i<9;i++)
        longitude[i]=sp1[i+27];
    longitude[10]='\0';
    printf("经度:%s\n",longitude);
    
    for(i=0;i<1;i++)
        longitude_direction[i]=sp1[i+37];
    longitude_direction[2]='\0';
    printf("经度方向:%s\n",longitude_direction);
    
    for(i=0;i<4;i++)
        altitude[i]=sp2[i+43];
    altitude[5]='\0';
    printf("海拔高度:%s\n",altitude);
    
    for(i=0;i<6;i++)
        UTCtime[i]=sp1[i+7];
    UTCtime[7]='\0';
    printf("UTC时间:%s\n",UTCtime);
    
    
    
    for(i=0;i<6;i++)
        date[i]=sp1[i+51];
    date[7]='\0';
    printf("日期:%s\n",date);
    
    fclose(fp);
    return 0;
}