//
// Created by saurabh singh on 3/13/17.
//

#ifndef DEMO_VECTOROP_H
#define DEMO_VECTOROP_H

    #include<vector>

    class vectorOp{
    public :
        std::vector<std::vector<float> > createIdentinyMat(int);
        std::vector<std::vector<float> > diff(std::vector<std::vector<float> >, std::vector<std::vector<float> >);
        std::vector<std::vector<float> > sum(std::vector<std::vector<float> >, std::vector<std::vector<float> >);
        std::vector<std::vector<float> > trans(std::vector<std::vector<float> >);
        std::vector<std::vector<float> > mulMat(std::vector<std::vector<float> >,std::vector<std::vector<float> >);
        double computCost(std::vector<std::vector<float> >,std::vector<std::vector<float> >);
        std::vector<std::vector<float> > scalarMulMat(std::vector<std::vector<float> >,double);
        std::vector<std::vector<float> > print(std::vector<std::vector<float> > );
    };

#endif //DEMO_ARRAYOP_H
