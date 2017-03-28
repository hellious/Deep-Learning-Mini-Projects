#include<iostream>
#include "linear_reg.h"
#include "vectorOp.h"


void LinearReg::performTrain(std::vector< std::vector<float> > train, std::vector<std::vector<float> > label){

    vectorOp vop;
    wt = vop.trans(wt);
    //std::vector<std::vector<float> > wt_old;//(wt.size(),std::vector<float>(wt[0].size(),0.0));
    for(int i=0; this->no_iteration; i++) {
        std::cout<<"loop number : "<<i<<std::endl;
        std::vector<std::vector<float> > a = vop.scalarMulMat(vop.mulMat(vop.trans(train), label), -2);
        //std::cout<<"###################"<<std::endl;
        std::vector<std::vector<float> > b = vop.scalarMulMat(vop.mulMat(vop.mulMat(vop.trans(train), train), wt), 2);
        std::cout<<"--------------------"<<std::endl;
        std::vector<std::vector<float> > d = vop.createIdentinyMat(wt.size());
        std::cout<<"@@@@@@@@@@@@@@@@@@@@@"<<std::endl;
        std::vector<std::vector<float> > c = vop.scalarMulMat(vop.mulMat(d, wt), 2 * alpha);
        wt = vop.diff(wt, vop.sum(vop.sum(a, b), c));
       // vop.print(wt);
    }

}
double LinearReg::predict(std::vector< std::vector<float> > test, std::vector<std::vector<float> > label){
    vectorOp vop;
    std::vector< std::vector<float> > a = vop.mulMat(test,wt);
    double rmse = vop.computCost(a,label);
    std::cout<<" rmse error : "<<rmse<<std::endl;
}



