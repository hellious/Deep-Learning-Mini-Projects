
#ifndef DEMO_LINEAR_REG_H
#define DEMO_LINEAR_REG_H
    #include<vector>
    class LinearReg{

        std::vector< std::vector<float> > wt;
        int no_row;
        int no_col;
        std::vector< std::vector<float> > train;
        std::vector< std::vector<float> > test;
        double eta; // for learning rate
        int no_iteration;
        double alpha; // for regularisation


    public:
        LinearReg(std::vector<float>wt, int no_row, int no_col) {

            this->wt.push_back(wt);
            this->no_row = no_row;
            this->no_col = no_col;
            eta = 0.0000001;
            no_iteration = 100;
            alpha = 0.5;
        }

        void performTrain(std::vector< std::vector<float> > , std::vector<std::vector<float> > );
        double predict(std::vector< std::vector<float> > , std::vector<std::vector<float> > );
    };
#endif //DEMO_LINEAR_REG_H
