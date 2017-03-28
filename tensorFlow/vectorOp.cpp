#include<iostream>
#include<cmath>
#include "vectorOp.h"


std::vector<std::vector<float> > vectorOp::createIdentinyMat(int len){
   // std::cout<<"inside identiry matrix"<<std::endl;
    std::vector<std::vector<float> > iden;
    iden = std::vector<std::vector<float> >(len, std::vector<float>(len,0.0));
    for(int i=0; i<len; i++)
        iden[i][i] = 1;
    //std::cout<<"bye identiry matrix iden (x,y) "<<iden.size()<<" , "<<iden[0].size()<<std::endl;
    return iden;
}

std::vector<std::vector<float> > vectorOp::diff(std::vector<std::vector<float> > a, std::vector<std::vector<float> > b){
        std::vector<std::vector<float> > temp;
        if(a.size() == b.size() && a[0].size() == b[0].size()){
            for(int i=0; i<a.size(); i++){
                for(int j=0; j<a[0].size(); j++)
                    a[i][j] = a[i][j] - b[i][j];
            }
            return a;
        }else{
        //    std::cout<<"subtraction not possible as size of both vector not same"<<std::endl;
            return temp;
        }
    }

std::vector<std::vector<float> > vectorOp::sum(std::vector<std::vector<float> > a, std::vector<std::vector<float> > b){
    std::vector<std::vector<float> > temp;
    if(a.size() == b.size() && a[0].size() == b[0].size()){
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<a[0].size(); j++)
                a[i][j] = a[i][j] + b[i][j];
        }
        return a;
    }else{
    //    std::cout<<"subtraction not possible as size of both vector not same"<<std::endl;
        return temp;
    }
}


std::vector<std::vector<float> > vectorOp::trans(std::vector<std::vector<float> > a){
   // std::cout<<"inside matrix transpose input matric (x,y) "<<a.size()<<" , "<<a[0].size()<<std::endl;
    std::vector<std::vector<float> > b(a[0].size(),
                                    std::vector<float>(a.size()));
    for (size_t i = 0; i < a.size(); ++i)
        for (size_t j = 0; j < a[0].size(); ++j)
            b[j][i] = a[i][j];
   // std::cout<<"bye matrix transpose output matric (x,y) "<<b.size()<<" , "<<b[0].size()<<std::endl;
    return b;
}


std::vector<std::vector<float> > vectorOp::mulMat(std::vector<std::vector<float> > a, std::vector<std::vector<float> > b){
    int x,y,x1,y1,x3,y3;
    x =  a.size();
    x1 = b.size();
    y = a[0].size();
    y1 = b[0].size();
    std::cout<<" inside multilplicayion x ,y ,x1, y1 "<<x<<" , "<<y<<" , "<<x1<<" , "<<y1<<std::endl ;
    std::vector<std::vector<float> > result;
    if(y==x1){ // multiply
        result = std::vector<std::vector<float> >(x, std::vector<float>(y1,0.0));
        for(int i=0; i<x;i++)
        {
            for(int j=0;j<y1;j++)
            {
                for(int k=0;k<y;k++)
                {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;

    }else{
        std::cout<<" matrix dimension are not valid for multilplicayion "<<std::endl;
        return result;
    }


}



 std::vector<std::vector<float> > vectorOp::scalarMulMat(std::vector<std::vector<float> >  a, double b){
    for(int i=0; i<a.size(); i++)
        for(int j=0; j<a[0].size(); j++)
            a[i][j] = a[i][j]*b;
    return a;
}


double vectorOp::computCost(std::vector<std::vector<float> > a,std::vector<std::vector<float> > b){
    int len = a.size();
    int len2 = b.size();
    double val = 0.0;
    if(len != len2){
     //   std::cout<<" Both vector length are different len , len2 "<<len<<" , "<<len2<<std::endl;
        return -1.0;
    }
    for(int i; i<len; i++){
        val = val + (a[i][0]  - b[i][0])*(a[i][0]  - b[i][0]);
    }
    double mean = val/len;
    return sqrt(mean);
}

std::vector<std::vector<float> > vectorOp::print(std::vector<std::vector<float> > a){
   // std::cout<<" pringint weight for weigth matrix "<<std::endl;
    for(int i=0; i<a.size(); i++){
        std::cout<<"  "<<a[i][0];
    }
    std::cout<<std::endl;
}