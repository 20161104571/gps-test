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
    char sp1[80];
    char sp2[80];
    char latitude[10];//纬度
    char longitude[10];//经度
    char time[7];//时间
    char date[7];//日期
    char latitude_direction[2];//纬度方向
    char longitude_direction[2];//经度方向
    char altitude[5];//海拔
    char rate[7];//速率
    char satellites[3];//卫星颗数
    char course[6];//航向
    double speed;//速度
    int i;
    int math,math1,math2;
    FILE *fp;
    FILE *fr;
    fp=fopen("/Users/w20161104571/Desktop/gps test/GPS170510.log","r");
    fr=fopen("/Users/w20161104571/Desktop/gps test/out.csv","w");
    
    if (fp == NULL)
    {
        printf("打开文件错误!\n");
    }
    else
    {
        fprintf(fr," 日期 ,时间(时:分:秒) ,纬度(度) ,纬度方向 ,经度(度) ,经度方向 ,航向(度),海拔(m) ,速度(km/h) ,卫星颗数(颗) \n");
    }
    
    while(fscanf(fp,"%s %s",sp1,sp2)!=EOF)
    {
        for(i=0; i<2; i++)
            date[i]=sp1[i+55];
        date[2]='\0';
        fprintf(fr,"20%s年",date);
            
        for(i=0; i<2; i++)
            date[i]=sp1[i+53];
        date[2]='\0';
        fprintf(fr,"%s月",date);
            
        for(i=0; i<6; i++)
            date[i]=sp1[i+51];
        date[2]='\0';
        fprintf(fr,"%s日, ",date);
            
        for(i=0; i<2; i++)
            time[i]=sp1[i+7];
        math1=10*(time[0]-'0');
        math2=1*(time[1]-'0');
        math=math1+math2+8;
        fprintf(fr,"%d:",math);
         //时
        for(i=0; i<2; i++)
            time[i]=sp1[i+9];
        math1=10*(time[0]-'0');
        math2=1*(time[1]-'0');
        math=math1+math2;
        time[2]='\0';
        fprintf(fr,"%d:",math);
         //分
        for(i=0; i<2; i++)
            time[i]=sp1[i+11];
        math1=10*(time[0]-'0');
        math2=1*(time[1]-'0');
        math=math1+math2;
        time[2]='\0';
        fprintf(fr,"%d, ",math);
         //秒
        for(i=0; i<8; i++)
            latitude[i]=sp1[i+16];
        latitude[9]='\0';
        fprintf(fr,"%s, ",latitude);
            //纬度
        for(i=0; i<1; i++)
            latitude_direction[i]=sp1[i+25];
        latitude_direction[1]='\0';
        fprintf(fr,"%s, ",latitude_direction);
            //纬度方向
        for(i=0; i<9; i++)
            longitude[i]=sp1[i+27];
        longitude[9]='\0';
        fprintf(fr,"%s, ",longitude);
            //经度
        for(i=0; i<1; i++)
            longitude_direction[i]=sp1[i+37];
        longitude_direction[1]='\0';
        fprintf(fr,"%s, ",longitude_direction);
            //经度方向
        for(i=0; i<5; i++)
            course[i]=sp1[i+45];
        course[5]='\0';
        fprintf(fr,"%s, ",course);
            //航向
        for(i=0; i<4; i++)
            altitude[i]=sp2[i+43];
        altitude[4]='\0';
        fprintf(fr,"%s, ",altitude);
            //海拔
        for(i=0; i<5; i++)
            rate[i]=sp1[i+39];
        speed=atoi(rate);
        speed=speed*1.852;
        fprintf(fr,"%.2lf, ",speed);
            //速度
        for(i=0; i<2; i++)
            satellites[i]=sp2[i+39];
        satellites[2]='\0';
        fprintf(fr,"%s\n",satellites);
            //卫星颗数
        }
        fclose(fp);
        fclose(fr);
        fp=NULL;
    
        return 0;
    }