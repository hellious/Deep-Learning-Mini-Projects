#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <locale>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include "linear_reg.h"


using namespace std;

//vector< vector<float> > dataset;
std::vector<std::vector<float> > label;
vector< vector<float> > read_csv(string filename){
    std::vector<std::vector<float> > data;
    clock_t start=clock();
    ifstream infile(filename); //"/Users/saur_navigator/CLionProjects/Demo/temp.csv");
    while (infile)
    {
        string s;
        if (!getline( infile, s )) break;

        istringstream ss(s);
        vector <float> record;
        vector <float> lbl;
        // adding input for label x0 for bias
        record.push_back(1.0);
        while (ss)
        {
            string s;
            if (!getline( ss, s, ',' )) break;
            record.push_back(atof(s.c_str()));
        }
        // adding to the label y
        float lbl_val = record.back();
        lbl.push_back(lbl_val);
        label.push_back(lbl);
        // removing label from the data converted to csv
        record.pop_back();
        data.push_back( record );
    }
    if (!infile.eof())
    {
        cerr << "Fooey!\n";
    }
    return data;

}

void print(vector<float> vect){
    for(int i=0; i<vect.size(); i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}

vector<float> initilize_wt(int len){
    vector<float> wt;
    for(int i=0; i<len; i++){
        wt.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
    }
    return wt;
}


int main() {

        std::vector<float> wt; // first element in the vector will be treated as bias

        std::vector<std::vector<float> > train_label;
        std::vector<std::vector<float> > test_label;
        std::vector<std::vector<float> >::iterator iter_lbl;
        std::vector<std::vector<float> > dataset;
        std::vector<std::vector<float> > test;
        std::vector<std::vector<float> > train;
        std::vector<std::vector<float> >::iterator iter;

        clock_t start=clock();
    // code to learn

        // read csv file
        dataset = read_csv("/Users/saur_navigator/CLionProjects/Demo/temp.csv");
    // removing first row as it contains headline
        dataset.erase(dataset.begin());
        label.erase(label.begin());
        int no_rows = dataset.size();
        int no_cols = dataset[0].size();
        //cout<<" rows: "<<no_rows<<" column "<<no_cols<<endl;
        //cout<<" rows: "<<label.size()<<" column "<<label[0].size()<<endl;
        // divide into datset for train and test
        int row_train_end_index = .8 * no_rows;
        int row_test_start_index = no_rows - row_train_end_index;
        iter = dataset.begin();
        iter_lbl = label.begin();
        // assigning x input labels
        train.assign(iter, iter + row_train_end_index);
        test.assign(iter + row_train_end_index + 1,dataset.end());
        // assing y labels
        train_label.assign(iter_lbl, iter_lbl + row_train_end_index);
        test_label.assign(iter_lbl + row_train_end_index + 1, label.end());
        //cout<<"train  x rows : "<<train.size()<<" y train rows "<<train_label.size()<<std::endl;
        //cout<<"test  x rows : "<<test.size()<<" y test rows "<<test_label.size()<<std::endl;

        // create weight and bias
        wt = initilize_wt(no_cols);

        //Above code would be similar foe every model

        //performTraining and return trained weight using Liear regression
        LinearReg *lr = new LinearReg(wt,no_rows,no_cols);
        lr->performTrain(train,train_label);
        //float rmse = lr->predict(test,test_label);

    // code to learn
        clock_t stop=clock();
        std::cout<<double(stop-start)/CLOCKS_PER_SEC << " seconds\n";





    return 0;
}

