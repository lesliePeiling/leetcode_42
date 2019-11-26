//keep in mind
#define max(x,y) (((x)>(y))?(x):(y))



int recursionF(int *height, int indexL,int indexR, int hL,int hR){
    
    if(indexL==indexR) return 0;
    
    int fill=0;
    
    //fill is max(hL,height[indexL+1])-height[indexL+1]  or max(hR,height[indexR-1])-height[indexR-1]
    
    //hL is max of height[0:indexL] with considering height[indexL]
    
    //hR is max of height[indexR:L-1] with considering height[indexR]
    
    //Rule to move small (hL,hR) side, update hL/hR ; fill;
    if(hL<hR){
        indexL=indexL+1;
        hL=max(height[indexL],hL);
        fill=hL-height[indexL];        
    }
    else{
        indexR=indexR-1;
        hR=max(hR,height[indexR]);
        fill=hR-height[indexR];
    }
    return fill+recursionF(height,indexL,indexR,hL,hR);
    
    
}



int trap(int* height, int heightSize){
    if(heightSize==0) return 0;
    return recursionF(height,0,heightSize-1,height[0],height[heightSize-1]);
}

