void square(float a1, float b1, float c1,float d1, float a2, float b2, float c2, float d2){
    glBegin(GL_POLYGON);
    glColor3f(0.5,0,0);
    
    glVertex2f(a1,a2);
    glVertex2f(b1,b2);
    glVertex2f(c1,c2);
    glVertex2f(d1,d2);
    glEnd();

}

void divide_square(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, int n){

    //float a21b1 = (a1*1 + b1*2)/3.0;
    float a21b2 = (a2*1 + b2*2)/3.0;
    //float a12b1 = (a1*2 + b1*1)/3.0;
    float a12b2 = (a2*2 + b2*1)/3.0;

    // float b21c1 = (b1*1 + c1*2)/3.0;
    // float b21c2 = (b2*1 + c2*2)/3.0;
    // float b12c1 = (b1*2 + c1*1)/3.0;
    // float b12c2 = (b2*2 + c2*1)/3.0;

    // float c21d1 = (c1*1 + d1*2)/3.0;
    // float c21d2 = (c2*1 + d2*2)/3.0;
    // float c12d1 = (c1*2 + d1*1)/3.0;
    // float c12d2 = (c2*2 + d2*1)/3.0;

    float d21a1 = (d1*1 + a1*2)/3.0;
    //float d21a2 = (d2*1 + a2*2)/3.0;
    float d12a1 = (d1*2 + a1*1)/3.0;
    //float d12a2 = (d2*2 + a2*1)/3.0;
    

    if(n > 0)
    {   
        square(a1,a1,d21a1,d21a1,a12b2,a21b2,a21b2,a12b2);
        square(d21a1,d21a1,d12a1,d12a1,a21b2,b2,b2,a21b2);
        square(d12a1,d12a1,d1,d1,a12b2,a21b2,a21b2,a12b2);
        square(d21a1,d21a1,d12a1,d12a1,a2,a12b2,a12b2,a2);

        divide_square(a1,a1,d21a1,d21a1,a2,a12b2,a12b2,a2,n-1);
        divide_square(b1,b1,d21a1,d21a1,a21b2,b2,b2,a21b2,n-1);
        divide_square(d12a1,d12a1,d1,d1,a21b2,b2,b2,a21b2,n-1);
        divide_square(d12a1,d12a1,d1,d1,a2,a12b2,a12b2,a2,n-1);
        
    }else{

        square(a1,b1,c1,d1,a2,b2,c2,d2);
    }

}
