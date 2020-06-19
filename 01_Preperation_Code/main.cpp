/*
# This implements a k-means clustering algorithm as described on:
# https://en.wikipedia.org/wiki/K-means_clustering
# You are free to use, change, or redistribute the code in any way you wish for
# any purposes.
*/

#include <iostream>
#include <vector>
#include "Point2D.h"
#include "KMeans.h"
#include "PointND.h"
using namespace std;

int main(){
    vector<float> v1 =  {0.0,0.0};
    vector<float> v2 = {0.0,1.0};
    vector<float> v3 = {0.7,0.1};
    vector<float> v4 = {1.0,0.0};
    vector<float> v5 = {0.3,1.3};
    vector<float> v6 = {1.0,1.0};

    PointND pn1(v1);
    PointND pn2(v2);
    cout << pn2.getDistance(pn1) << endl;


    vector<PointND> pointVector = {v1, v2, v3, v4, v5, v6};

    KMeans clusterer(2, pointVector);

    clusterer.cluster(4);

    cout<< "centroid 0: ";
    clusterer.getCentroid(0).print();
    cout<< "centroid 1: ";
    clusterer.getCentroid(1).print();

    for (int i=0; i<pointVector.size();i++){
        cout<< "class: " << clusterer.getClassLabel(i) << " point: ";
        pointVector[i].print();
    }

    return 0;
}
