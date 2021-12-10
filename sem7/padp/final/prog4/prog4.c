#include<stdio.h>
#include<gd.h>
#include<error.h>
#include<omp.h>

int main(int argc,char *argv[]){
    
    int x,y,h,w,red,green,blue,temp,pixelColor,numberOfThreads=4;
    x = y = h = w = green = blue = temp = pixelColor = 0;
    char *iname = NULL;
    char *oname = NULL;
    FILE *fp = NULL;
    gdImagePtr img;
    if(argc!=3)
        error(1,0,"");
    else{
        iname = argv[1];
        oname = argv[2];
    }

    if((fp=fopen(iname,"r")) == NULL)
        error(1,0,"error:fopen:%s\n",iname);
    else{
        img = gdImageCreateFromPng(fp);
        w = gdImageSX(img);
        h = gdImageSY(img);
    }
    
    double start_time = omp_get_wtime();
    omp_set_num_threads(numberOfThreads);
    #pragma omp parallel for private(x,y,red,green,blue,temp) schedule(static,50)
    for(x=0;x<w;x++){
        for(y=0;y<h;y++){
            pixelColor = gdImageGetPixel(img,x,y);
            red = gdImageRed(img,pixelColor);
            blue = gdImageBlue(img,pixelColor);
            green = gdImageGreen(img,pixelColor);
            temp = (red+green+blue)/3;
            pixelColor = gdImageColorAllocate(img,temp,temp,temp);
            gdImageSetPixel(img,x,y,pixelColor);
        }
    }
    double end_time = omp_get_wtime();
    printf("\nTime Taken : %lf, Number Of Threads : %d\n",end_time-start_time,numberOfThreads);
    if((fp = fopen(oname,"w"))==NULL)
        error(1,0,"error:fopen:%s\n",oname);
    else{
        gdImagePng(img,fp);
        fclose(fp);
    }
    gdImageDestroy(img);
    return 0;
}
